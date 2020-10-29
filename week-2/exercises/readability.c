#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_sentences(string text);
int count_letters(string text);
int count_words(string text);
int calculate_index(string text, int letter_count, int word_count, int sentence_count);

int main(void)
{
    string text = get_string("Text: ");

    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);

    int readability_index = calculate_index(text, letter_count, word_count, sentence_count);

    if (readability_index <= 0)
    {
        printf("Before grade 1\n");
        return 0;
    }
    else if (readability_index > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }

    // printf("%d letter(s)\n", letter_count);
    // printf("%d word(s)\n", word_count);
    // printf("%d sentence(s)\n\n", sentence_count);
    printf("Grade %d\n", readability_index);

    return 0;
}

int count_letters(string text)
{
    int counter = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
            counter++;
    }
    return counter;
}

int count_words(string text)
{
    int counter = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            counter++;
        }
    }
    return counter;
}

int count_sentences(string text)
{
    int counter = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            counter++;
        }
    }
    return counter;
}

int calculate_index(string text, int letter_count, int word_count, int sentence_count)
{
    // index = 0.0588 * L - 0.296 * S - 15.8

    // L is the average number of letters per 100 words in the text
    // S is the average number of sentences per 100 words in the text.

    // L é a média do número de letras    a cada 100 palavras no texto
    // S é a média do número de sentenças a cada 100 palavras no texto

    float L = (letter_count * 100.0f) / word_count;
    float S = (sentence_count * 100.0f) / word_count;

    // printf("L=%.1f S=%.1f - L_C=%d W_C=%d S_C=%d\n\n", L, S, letter_count, word_count, sentence_count);

    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    return grade;
}