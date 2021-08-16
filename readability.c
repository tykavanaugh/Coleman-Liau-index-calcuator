#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int count_letters(string text);

int count_words(string text);

int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    float total_letters = count_letters(text);
    float total_words = count_words(text);
    float total_sentences = count_sentences(text);
    float index = (0.0588 * ((total_letters / total_words ) * 100.0)) - (0.296 * ((total_sentences / total_words) * 100.0)) - 15.8;
    int indexRound = round(index);
    if (indexRound < 1) {
        printf("Before Grade 1");
    } else if (indexRound > 15) {
        printf("Grade 16+");
    } else {
        printf("Grade %i",indexRound);
    };
};

int count_letters(string text){
    int total = 0;
    int length = strlen(text);
    for (int i = 0 ; i < length ; i++){
        if (isalpha(text[i])) {
            total++;
        };
    };

    return total;
};

int count_words(string text){
    int total = 1;
    int length = strlen(text);
    for (int i = 0 ; i < length ; i++){
        if (isspace(text[i])) {
            total++;
        };
    };

    return total;
};

int count_sentences(string text){
    int total = 0;
    int length = strlen(text);
    for (int i = 0 ; i < length ; i++){
        int c = text[i];
        if (c == 46 || c == 33 || c == 63){
            total++;
        };
    };

    return total;
};
