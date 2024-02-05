#include <cs50.h>
#include <stdio.h>

int main(void)
{

    bool inputRight;

    do
    {
        int pHeight = get_int("Please enter pyramide height between 1 and 8: ");
        int lenght = pHeight;
        int amountHash = 1;

        if (pHeight >= 1 && pHeight <= 8)
        {
            inputRight = false;
            for (int i = 0; i < pHeight; i++)
            {
                for (int in = 1; in < lenght; in++)
                {
                    printf(" ");
                }

                for (int it = 0; it < amountHash; it++)
                {
                    printf("#");
                }

                amountHash++;
                lenght--;
                printf("\n");
            }
        }
        else
        {
            printf("input is not correct please try again\n");
            inputRight = true;
        }
    }
    while (inputRight);
    return 0;
}
