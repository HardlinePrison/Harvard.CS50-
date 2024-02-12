#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

    if (argc == 2)
    {
        for (int i = 0, len = strlen(argv[1]); i <= len; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        int key = atoi(argv[1]);

        string input = get_string("Enter text you want encrypt: ");
        for (int j = 0, len = strlen(input); j <= len; j++)
        {
            int checkMod = (input[j] + key) % 'z';

            if (isalpha(input[j]))
            {
                if (islower(input[j]))
                {
                    if ((input[j] + key) > 'z')
                    {
                        do
                        {
                            checkMod = checkMod % 26;
                            input[j] = 'a' + checkMod - 1;
                        }
                        while (checkMod > 26);
                    }
                    else
                    {
                        input[j] += key;
                    }
                }

                if (isupper(input[j]))
                {
                    if ((input[j] + key) > 'Z')
                    {
                        do
                        {
                            checkMod = checkMod % 26;
                            input[j] = 'a' + checkMod - 2;
                        }
                        while (checkMod > 26);
                    }
                    else
                    {
                        input[j] += key;
                    }
                }
            }
        }
        printf("ciphertext: %s\n", input);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    return 0;
}
