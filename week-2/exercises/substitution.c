#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string cipher(string key, string plain_text);
int validate_key(string key);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    string key = argv[1];

    const int is_valid = validate_key(key);

    if (is_valid > 0)
    {
        return is_valid;
    }

    string plain = get_string("plaintext:  ");

    string ciphertext = cipher(key, plain);

    printf("ciphertext: %s\n", ciphertext);

    return is_valid;
}

string cipher(string key, string plain_text)
{
    const int TEXT_LENGTH = strlen(plain_text);
    string index = calloc(TEXT_LENGTH, sizeof(string));

    for (int i = 0, n = strlen(alphabet); i < n; i++)
    {
        for (int j = 0; j < TEXT_LENGTH; j++)
        {
            if (toupper(plain_text[j]) == alphabet[i])
            {
                index[j] = key[i];
            }

            if (isblank(plain_text[j]))
            {
                index[j] = ' ';
            }

            if (!isalpha(plain_text[j]))
            {
                index[j] = plain_text[j];
            }
        }
    }

    for (int i = 0; i <= TEXT_LENGTH; i++)
    {
        if (isupper(plain_text[i]))
        {
            index[i] = toupper(index[i]);
        }
        else
        {
            index[i] = tolower(index[i]);
        }
    }

    return index;
}

int validate_key(string key)
{
    const int KEY_LENGTH = strlen(key);

    if (KEY_LENGTH != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0, n = KEY_LENGTH; i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    for (int i = 0, n = KEY_LENGTH; i < n; i++)
    {
        for (int j = i + 1, o = KEY_LENGTH; j <= o; j++)
        {
            if (key[i] == key[j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    return 0;
}