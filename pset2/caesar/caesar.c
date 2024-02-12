#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LETTERS_MAX 26
#define LOWER_LETTER_MIN 'a'
#define LOWER_LETTER_MAX 'z'
#define UPPER_LETTER_MIN 'A'
#define UPPER_LETTER_MAX 'Z'

int changeLetter(int letter, int k, int checkRemainder);

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
            int checkMod = (input[j] + key) % LOWER_LETTER_MAX;

            if (isalpha(input[j]))
            {
                input[j] = changeLetter(input[j], key, checkMod);
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

int changeLetter(int letter, int k, int checkRemainder)
{
    int changedLetter = 0;

    if (islower(letter))
    {
        if ((letter + k) > LOWER_LETTER_MAX)
        {
            do
            {
                checkRemainder = checkRemainder % LETTERS_MAX;
                changedLetter = LOWER_LETTER_MIN + checkRemainder - 1;
            }
            while (checkRemainder > LETTERS_MAX);
        }
        else
        {
            changedLetter = letter += k;
        }
    }

    if (isupper(letter))
    {
        if ((letter + k) > UPPER_LETTER_MAX)
        {
            do
            {
                checkRemainder = checkRemainder % LETTERS_MAX;
                changedLetter = UPPER_LETTER_MIN + checkRemainder - 1;
            }
            while (checkRemainder > LETTERS_MAX);
        }
        else
        {
            changedLetter = letter += k;
        }
    }

    return changedLetter;
}
