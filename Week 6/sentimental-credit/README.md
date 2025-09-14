# Sentimental-Credit (CS50 Week 6)

This project is part of **CS50’s Introduction to Computer Science** — Week 6 (Python).  
The goal is to implement a program that validates credit card numbers and identifies their type (e.g., VISA, AMEX, MASTERCARD).

---

## Problem Description

The program should:

1. Prompt the user for a credit card number.
2. Validate the number using **Luhn’s algorithm**.
3. Determine the type of card based on:
   - **AMEX** → 15 digits, starts with 34 or 37
   - **MASTERCARD** → 16 digits, starts with 51–55
   - **VISA** → 13 or 16 digits, starts with 4

If the number is invalid, the program should print `"INVALID"`.

---

## Files

- `sentimental-credit.py` → main Python program.
- `README.md` → this file.

---

## Usage

Run the program from the terminal:

```bash
python sentimental-credit.py
