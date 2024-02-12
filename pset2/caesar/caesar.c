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

int changeLetter(int letter, int k);

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
            if (isalpha(input[j]))
            {
                input[j] = changeLetter(input[j], key);
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

int changeLetter(int letter, int k)
{
    int changedLetter = 0;

    if (islower(letter))
    {
        int checkModLower = (letter + k) % LOWER_LETTER_MAX;

        if ((letter + k) > LOWER_LETTER_MAX)
        {
            do
            {
                checkModLower = checkModLower % LETTERS_MAX;
                changedLetter = LOWER_LETTER_MIN + checkModLower - 1;
            }
            while (checkModLower > LETTERS_MAX);
        }
        else
        {
            changedLetter = letter += k;
        }
    }

    if (isupper(letter))
    {
        int checkModUpper = (letter + k) % UPPER_LETTER_MAX;

        if ((letter + k) > UPPER_LETTER_MAX)
        {
            do
            {
                checkModUpper = checkModUpper % LETTERS_MAX;
                changedLetter = UPPER_LETTER_MIN + checkModUpper - 1;
            }
            while (checkModUpper > LETTERS_MAX);
        }
        else
        {
            changedLetter = letter += k;
        }
    }

    return changedLetter;
}
