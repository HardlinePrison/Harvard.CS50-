#include <stdio.h>
#include <cs50.h>

int main(void)
{

    bool inputRight;

    do
    {
    int pHeight = get_int("Please enter pyramide height between 0 and 23: ");
    int lenght = pHeight++;
    int amountHash = 1;



            if(pHeight > 0 && pHeight < 25)
            {
                inputRight = false;
                for(int i = 1; i < pHeight; i++)
                {
                    for(int in = 0; in < lenght; in++)
                    {
                        printf(" ");
                    }

                    for(int it = 0; it < amountHash; it++)
                    {
                        printf("#");
                    }

                    for(int an = 0; an < 2; an++)
                    {
                        printf(" ");
                    }

                    for(int it = 0; it < amountHash; it++)
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
                printf("Input is not correct please try again\n");
            }
    } while(inputRight);
}

