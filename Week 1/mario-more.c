#include <cs50.h>
#include <stdio.h>

void brick(int i);
void payramid(int UserInput);

int main(void)
{
    int UserInput;
    do
    {
        UserInput = get_int("insert the height of the pyramid: ");
        if (UserInput <= 0)
        {
            printf("please insert a valid number! \n");
        }
    }
    while (UserInput <= 0);
    
    payramid(UserInput);
}

void payramid(int UserInput)
{
    for (int i = 0; i < UserInput; i++)
    {
        for (int j = 1; j < UserInput - i; j++)
        {
            printf(" ");
        }

        brick(i);

        printf("  ");

        brick(i);

        printf("\n");
    }
}

void brick(int i)
{
    for (int j = 0; j < i + 1; j++)
    {
        printf("#");
    }
}
