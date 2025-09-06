#include <cs50.h>
#include <stdio.h>

bool checker(int z[16], int length);
void type(int digits[16], int length);

int main(void)
{
    long UserInput;
    int length = 0;

    // prompt
    do
    {
        UserInput = get_long("insert the credit card number: ");
        if (UserInput <= 0)
        {
            printf("please insert a real card number! \n");
        }
        else
        {
            length = 0;
            long x = UserInput;
            while (x > 0)
            {
                x /= 10;
                length++;
            }

            if (length != 13 && length != 15 && length != 16)
            {
                printf("INVALID\n");
                return 0;
            }
        }
    } while (UserInput <= 0 || (length != 13 && length != 15 && length != 16));

    // Store digits
    int digit[16];
    long temp = UserInput;
    for (int i = 0; i < length; i++)
    {
        digit[i] = temp % 10;
        temp /= 10;
    }

    type(digit, length);
}

bool checker(int z[16], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        int digit = z[i];
        if (i % 2 == 1)
        {
            digit *= 2;
            if (digit > 9)
                digit -= 9;
        }
        sum += digit;
    }
    return (sum % 10 == 0);
}

void type(int digits[16], int length)
{
    int FirstDigit = digits[length - 1];
    int SecondDigit = digits[length - 2];

    if (checker(digits, length))
    {
        if (length == 15 && FirstDigit == 3 && (SecondDigit == 4 || SecondDigit == 7))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && FirstDigit == 5 && (SecondDigit >= 1 && SecondDigit <= 5))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && FirstDigit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
