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

int changeLetter(char letter, char k);
int shift(char letter);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere kewordy\n");
        return 1;
    }

    string key = argv[1];
    int keyLen = strlen(key);

    for (int i = 0; i < keyLen; i++)
    {
        if(!isalpha(key[i]))
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }

    string input = get_string("Enter text you want to evcrypt: ");
    int inputLen = strlen(input);

    printf("ciphertext: ");

    for (int i = 0, j = 0; i < inputLen; i++)
    {
        char letter = input[i];
        if(isalpha(letter))
        {
            int checkKey = shift(key[j % keyLen]);
            printf("%c", changeLetter(letter, checkKey));
            j++;
        }
        else
        {
            printf("%c", letter);
        }
    }

    printf("\n");

    return 0;
}

int shift(char letter)
{
    if (islower(letter))
    {
        return letter - LOWER_LETTER_MIN;
    }

    else
    {
        return letter - UPPER_LETTER_MIN;
    }
}

int changeLetter(char letter, char k)
{
    int changedLetter = 0;

    if (islower(letter))
    {
        int checkModLower = (letter + k) % LOWER_LETTER_MAX;

        if ((letter + k) > LOWER_LETTER_MAX)
        {
            do
            {
                checkModLower = checkModLower % LETTERS_MAX - 1;
                changedLetter = LOWER_LETTER_MIN + checkModLower;
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
                checkModUpper = checkModUpper % LETTERS_MAX - 1;
                changedLetter = UPPER_LETTER_MIN + checkModUpper;
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

