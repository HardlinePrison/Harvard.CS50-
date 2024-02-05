#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    bool inputRight = true;
    do
    {
        // printf("===============================================================\n");
        long num = get_long_long("Input your card number: ");

        long num2 = num;
        long number = 0;

        bool checked = false;

        while (num2)
        {
            num2 /= 10;
            number++;
        }

        long numbers[number];

        if (number == 13 || number == 15 || number == 16)
        {
            inputRight = false;

            for (long i = 1; i <= number; i++)
            {
                numbers[i] = num % 10;
                num /= 10;
            }

            // is AMEX valid?
            if (number == 15 && ((numbers[15] == 3 && (numbers[14] == 4 || numbers[14] == 7))))
            {
                checked = true;
                long summAMEX = 0;
                for (long i = 2; i <= number; i += 2)
                {
                    if ((numbers[i] * 2) >= 10)
                    {
                        long moreTen = numbers[i] * 2;
                        long rest = moreTen % 10;
                        summAMEX += (rest + 1);
                    }
                    else
                    {
                        summAMEX += (numbers[i] * 2);
                    }
                }

                for (long i = 1; i <= number; i += 2)
                {
                    summAMEX += numbers[i];
                }

                if (summAMEX % 10 == 0)
                {
                    printf("\nAMEX\n");
                }
                else
                {
                    printf("\nINVALID\n");
                }
            }

            // is MASTER valid?
            if (number == 16 && numbers[16] == 5 && (numbers[15] >= 1 && numbers[15] <= 5))
            {
                checked = true;
                long summMASTER = 0;
                for (long i = 2; i <= number; i += 2)
                {
                    if ((numbers[i] * 2) >= 10)
                    {
                        long moreTen = numbers[i] * 2;
                        long rest = moreTen % 10;
                        summMASTER += (rest + 1);
                    }
                    else
                    {
                        summMASTER += (numbers[i] * 2);
                    }
                }

                for (long i = 1; i <= number; i += 2)
                {
                    summMASTER += numbers[i];
                }

                if (summMASTER % 10 == 0)
                {
                    printf("\nMASTERCARD\n");
                }
                else
                {
                    printf("\nINVALID\n");
                }
            }

            // is VISA valid?
            if ((number == 13 && numbers[13] == 4) || (number == 15 && numbers[15] == 4) || (number == 16 && numbers[16] == 4))
            {
                checked = true;
                long summVISA = 0;
                for (long i = 2; i <= number; i += 2)
                {
                    if ((numbers[i] * 2) >= 10)
                    {
                        long moreTen = numbers[i] * 2;
                        long rest = moreTen % 10;
                        summVISA += (rest + 1);
                    }
                    else
                    {
                        summVISA += (numbers[i] * 2);
                    }
                }

                for (long i = 1; i <= number; i += 2)
                {
                    summVISA += numbers[i];
                }

                if (summVISA % 10 == 0)
                {
                    printf("\nVISA\n");
                }
                else
                {
                    printf("\nINVALID\n");
                }
            }
        }

        if (checked == false)
        {
            printf("\nINVALID\n");
            inputRight = false;
        }

        bool tryAgainRight = true;

        do
        {
            char tryAgain = get_char("\nDo you want try again? Enter Y or N:  ");

            if (tryAgain == 'Y' || tryAgain == 'y')
            {
                inputRight = true;
                tryAgainRight = false;
            }
            if (tryAgain == 'N' || tryAgain == 'n')
            {
                printf("\nGoodbye!\n");
                printf("===============================================================\n");
                tryAgainRight = false;
            }
        }
        while (tryAgainRight);
    }
    while (inputRight);

    return 0;
}
