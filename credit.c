#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int length = 1, sum1 = 0, sum2 = 0, m = 1;
    long e = 1;
    long number = get_long("Number: ");
    long ref = number;
    // loop for luhn's algorithm
    while (number != 0)
    {
        if ((length % 2) == 1)
        {
            sum1 += number % 10;
        }
        else
        {
            if ((2 * (number % 10)) >= 10)
            {
                sum2 = sum2 + ((2 * (number % 10))) / 10 + ((2 * (number % 10))) % 10;
            }
            else
            {
                sum2 = sum2 + (2 * (number % 10));
            }
        }
        length++;
        number = number / 10;
    }

    length -= 1;
    while (m < length - 1)
    {
        e *= 10;
        m++;
    }

    // to print the name of the card
    if ((sum1 + sum2) % 10 == 0)
    {
        // for visa
        if (length == 13)
        {
            if (ref / (e * 10) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        // for AMEX
        else if (length == 15)
        {
            if (ref / e == 34)
            {
                printf("AMEX\n");
            }
            else if (ref / e == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        // for mastercard and visa
        else if (length == 16)
        {
            if ((ref / e == 51) || (ref / e == 52) || (ref / e == 53) || (ref / e == 54) || (ref / e == 55))
            {
                printf("MASTERCARD\n");
            }
            else if (ref / (10 * e) == 4)
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

    else
    {
        printf("INVALID\n");
    }
}
