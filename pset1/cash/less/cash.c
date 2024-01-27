#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    bool inputRight = true;

    do
    {
        printf("===============================================================\n");
        // I decide use get_double because if I use get_float and user input 2.34 programm can not count steps correctly because of
        // float type
        double change = get_double("Enter how much change you need to get: ");

        int changeInInt = (change * 100);

        int quart = 25;
        int dime = 10;
        int nickel = 5;
        int penny = 1;

        int howMuchSteps = 0;
        int howMuchQuart = 0;
        int howMuchDime = 0;
        int howMuchNickel = 0;
        int howMuchPenny = 0;

        if (changeInInt >= 0)
        {
            inputRight = false;

            if (changeInInt >= quart)
            {
                do
                {
                    changeInInt = changeInInt - quart;
                    howMuchSteps++;
                    howMuchQuart++;
                }
                while (changeInInt >= quart);
            }

            if (changeInInt >= dime)
            {
                do
                {
                    changeInInt = changeInInt - dime;
                    howMuchSteps++;
                    howMuchDime++;
                }
                while (changeInInt >= dime);
            }

            if (changeInInt >= nickel)
            {
                do
                {
                    changeInInt = changeInInt - nickel;
                    howMuchSteps++;
                    howMuchNickel++;
                }
                while (changeInInt >= nickel);
            }

            if (changeInInt >= penny)
            {
                do
                {
                    changeInInt = changeInInt - penny;
                    howMuchSteps++;
                    howMuchPenny++;
                }
                while (changeInInt >= penny);
            }

            printf("\nYou need to make %i steps to get your change.\n\nYou get: %i quarts, %i dimes, %i nickels, %i penny. \n",
                   howMuchSteps, howMuchQuart, howMuchDime, howMuchNickel, howMuchPenny);
            printf("===============================================================\n");

            bool tryAgainRight = true;

            do
            {
                char tryAgain = get_char("Do you want try again? Enter Y or N:  ");

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
    }
    while (inputRight);
}
