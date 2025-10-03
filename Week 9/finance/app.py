import os
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash
from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# index ###########

@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    user_id = session["user_id"]
    balance = db.execute(
        "select cash from users where username=(select username from users where id=?)", user_id)[0]["cash"]
    stocks = db.execute("select * from stocks where user_id=?", user_id)

    for stock in stocks:
        stock["current_price"] = lookup(stock["symbol"])["price"]

    return render_template("index.html", balance=balance, stocks=stocks)


# buy ###########

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        symbol_fetch_result = lookup(symbol)
        user_id = session["user_id"]
        balance = db.execute(
            "select cash from users where username=(select username from users where id=?)", user_id)[0]["cash"]

        if not symbol or not shares:
            return apology("fields cannot be empty")

        else:

            if symbol_fetch_result is None:
                return apology("enter valid company symbol")

            else:

                if not shares.isdigit():
                    return apology("enter valid shares number")

                else:

                    shares = int(shares)
                    if shares <= 0:
                        return apology("enter positive shares number")

                    else:

                        if (symbol_fetch_result["price"]*shares) > balance:
                            return apology("insufficient funds")

                        else:
                            total_price = symbol_fetch_result["price"]*shares
                            balance -= total_price
                            db.execute(
                                "insert into stocks (user_id,symbol,shares) values(?,?,?)", user_id, symbol, shares)
                            db.execute(
                                "update users set cash=? where id=?", balance, user_id)
                            db.execute("insert into transactions (user_id,symbol,shares,price,type) values(?,?,?,?,?)",
                                       user_id, symbol, shares, total_price, "Buy")
                            return apology("purchase completed", 200)

    else:
        return render_template("buy.html")


# history ###########

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    user_history = db.execute(
        "select * from transactions order by timestamp desc")
    return render_template("history.html", History=user_history)


# login ###########

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get(
                "username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


# quote ###########

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":
        symbol = request.form.get("symbol")

        if lookup(symbol) is None:
            return apology("the symbol doesnt exist", 404)

        else:
            name = lookup(symbol)["name"]
            name2 = lookup(symbol)["symbol"]
            price = usd(lookup(symbol)["price"])
            return render_template("symbol.html", name=name, symbol=name2, price=price)

    else:
        return render_template("quote.html")


# register ###########

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":
        name = request.form.get("username")
        password = request.form.get("password")
        repassword = request.form.get("repassword")
        hashed_password = generate_password_hash(password)
        existing_name = db.execute(
            "select * from users where username = ?", name)

        if name and password and repassword and (password == repassword) and not existing_name:
            db.execute("insert into users (username,hash) values (?,?)",
                       name, hashed_password)
            return redirect("/login")

        elif not name or not password or not repassword:
            return apology("All fields are required")

        elif not (password == repassword):
            return apology("passwords should match")

        elif existing_name:
            return apology("the name is already taken", 409)

    # check if user already logged
    else:
        if session.get("user_id") is not None:
            return redirect("/")
        else:
            return render_template("register.html")


# register ###########

@app.route("/profile", methods=["GET", "POST", "DELETE"])
@login_required
def profile():
    """Edit user profile"""

    if request.method == "POST":
        user_id = session["user_id"]
        new_password = request.form.get("new_password")
        repassword = request.form.get("repassword")
        hashed_password = generate_password_hash(new_password)

        if not new_password or not repassword:
            return apology("All fields are required")

        elif new_password != repassword:
            return apology("Passwords should match")

        else:
            db.execute("UPDATE users SET hash=? WHERE id=?",
                       hashed_password, user_id)
            session.clear()
            return redirect("/")

    elif request.method == "DELETE":
        user_id = session["user_id"]
        db.execute("DELETE FROM transactions WHERE user_id=?", user_id)
        db.execute("DELETE FROM stocks WHERE user_id=?", user_id)
        db.execute("DELETE FROM users WHERE id=?", user_id)
        session.clear()
        return {"status": "success"}, 200

    else:
        return render_template("profile.html")


# sell ###########

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    user_id = session["user_id"]
    symbols_owned = db.execute(
        "select symbol,shares from stocks where user_id=?", user_id)
    user_cash = db.execute("select cash from users where id=?", user_id)[
        0]['cash']

    if request.method == "POST":
        sold_symbol = request.form.get("stock")
        available_shares_to_sell = int(
            next((s['shares'] for s in symbols_owned if s['symbol'] == sold_symbol), 0))
        number_of_shares_to_sell = int(request.form.get("shares"))

        if number_of_shares_to_sell < 1:
            return apology("Enter a valid number of shares", 400)

        else:

            if available_shares_to_sell > number_of_shares_to_sell:
                shares_left = available_shares_to_sell-number_of_shares_to_sell
                total_price = lookup(sold_symbol)[
                    "price"]*number_of_shares_to_sell
                user_cash += total_price
                db.execute("update stocks set shares=? where user_id=? and symbol=?",
                           shares_left, user_id, sold_symbol)
                db.execute("update users set cash=? where id=?",
                           user_cash, user_id)
                db.execute("insert into transactions (user_id,symbol,shares,price,type) values(?,?,?,?,?)",
                           user_id, sold_symbol, number_of_shares_to_sell, total_price, "Sell")
                return apology("Selling completed", 200)

            elif available_shares_to_sell == number_of_shares_to_sell:
                total_price = (lookup(sold_symbol)[
                               "price"]*number_of_shares_to_sell)
                user_cash += total_price
                db.execute(
                    "delete from stocks where user_id=? and symbol=?", user_id, sold_symbol)
                db.execute("update users set cash=? where id=?",
                           user_cash, user_id)
                db.execute("insert into transactions (user_id,symbol,shares,price,type) values(?,?,?,?,?)",
                           user_id, sold_symbol, number_of_shares_to_sell, total_price, "Sell")
                return apology("Selling completed", 200)

            else:
                return apology("Not enough shares to sell", 400)

    else:

        return render_template("sell.html", symbols_owned=symbols_owned,)
