#include <stdio.h>
#include <cs50.h>
#include <string.h>

// start by defining functions; let's do several

float count_chars(char text[]); //unused but was a useful training exercise
float count_letters(char text[]);
float count_words(char text[]);
float count_sentences(char text[]);

// now for the main body. this time I will keep it short
int main(void)
{
    string text = get_string("Text: ");

    float L = ((count_letters(text)) * 100) / count_words(text);
    float S = ((count_sentences(text)) * 100) / count_words(text);
    float index = .0588 * L - .296 * S - 15.8;

    if (index >= 1 && index < 16)
    {
        printf("Grade %.0f\n", index);
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }

    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
}

// function to count CHARACTERS
float count_chars(char text[])
{
    int chars = 0;

    while (text[chars] != '\0')
    {
        chars++;
    }

    return chars;
}

// function to count LETTERS
float count_letters(char text[])
{
    int chars = 0;
    int letters = 0;

    while (text[chars] != '\0')
    {

        if ((text[chars] >= 'A' && text[chars] <= 'Z') || (text[chars] >= 'a' && text[chars] <= 'z'))
        {
            letters++;
        }

        chars++;
    }

    return letters;
}

// function to count WORDS
float count_words(char text[])
{
    int chars = 0;
    int words = 1;

    while (text[chars] != '\0')
    {

        if (text[chars] == ' ' && (text[chars -1] != '.' || text[chars -1] != '?' || text[chars -1] != '!'))
        {
            words++;
        }

        chars++;
    }

    return words;
}

// function to count SENTENCES
float count_sentences(char text[])
{
    int chars = 0;
    int sentences = 0;

    while (text[chars] != '\0')
    {

        if (text[chars] == '.' || text[chars] == '?' || text[chars] == '!')
        {
            sentences++;
        }

        chars++;
    }

    return sentences;
}