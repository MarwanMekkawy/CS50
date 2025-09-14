import sys


def main():

    # prompt user
    while True:
        user_input = input("insert the credit card number: ")
        if not user_input.isdigit():
            continue
        user_input = int(user_input)
        if user_input <= 0:
            print("please insert a real card number! ")
            continue
        else:
            length = 0
            x = user_input
            while x > 0:
                x //= 10
                length += 1

            if length not in (13, 15, 16):
                print("INVALID")
                sys.exit(0)

            break


    # Store digits
    digit = []
    temp = user_input
    for i in range(length):
        digit.append(temp % 10)
        temp = temp//10

    card_type(digit, length)

    return 0

# check if card is valid
def checker(z, length):
    sum = 0
    for i in range(length):
        digit = z[i]
        if i % 2 == 1:
            digit *= 2
            if digit > 9:
                digit -= 9
        sum += digit

    return (sum % 10 == 0)

# check card type
def card_type(digits, length):
    FirstDigit = digits[length - 1]
    SecondDigit = digits[length - 2]

    if checker(digits, length):
        if length == 15 and FirstDigit == 3 and (SecondDigit == 4 or SecondDigit == 7):
            print("AMEX")
        elif length == 16 and FirstDigit == 5 and (SecondDigit >= 1 and SecondDigit <= 5):
            print("MASTERCARD")
        elif (length == 13 or length == 16) and FirstDigit == 4:
            print("VISA")
        else:
            print("INVALID")

    else:
        print("INVALID")

main()
