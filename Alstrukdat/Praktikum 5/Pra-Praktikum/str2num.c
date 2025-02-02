#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

typedef struct {
    char *word;
    int value;
} WordToNumber;

WordToNumber wordMap[] = {
    {"nol", 0}, {"kosong", 0}, {"satu", 1}, {"dua", 2}, {"tiga", 3}, {"empat", 4},
    {"lima", 5}, {"enam", 6}, {"tujuh", 7}, {"delapan", 8}, {"sembilan", 9},
    {"sepuluh", 10}, {"sebelas", 11}, {"dua belas", 12}, {"tiga belas", 13},
    {"empat belas", 14}, {"lima belas", 15}, {"enam belas", 16}, {"tujuh belas", 17},
    {"delapan belas", 18}, {"sembilan belas", 19}, {"seratus", 100}
};

WordToNumber multiplier[] = {
    {"ratus", 100}, {"puluh", 10}
};

int getBasicNumber (char *word) {
    for (int i = 0; i < sizeof(wordMap) / sizeof(WordToNumber); i++) {
        if (strcmp(word, wordMap[i].word) == 0) {
            return wordMap[i].value;
        }
    }
    return -1; // Not found
}

int getMultiplier (char *word) {
    for (int i = 0; i < sizeof(multiplier) / sizeof(WordToNumber); i++) {
        if (strcmp(word, multiplier[i].word) == 0) {
            return multiplier[i].value;
        }
    }
    return 1; // Default multiplier 1 if not found
}

int main() {
    STARTWORD();
    while (!EndWord) {
        char phrase[256] = "";
        int isNumber = 0;
        while (!EndWord && wordToNumber(currentWord.TabWord) != -1) {
            strcat(phrase, currentWord.TabWord);
            strcat(phrase, " ");
            isNumber = 1;
            ADVWORD();
        }
        if (isNumber) {
            phrase[strlen(phrase) - 1] = '\0'; // Remove trailing space
            printf("%d ", phraseToNumber(phrase));
        } else {
            printf("%s ", currentWord.TabWord);
            ADVWORD();
        }
    }
    printf("\n");
    return 0;
}            printf("%s ", currentWord.TabWord);
            ADVWORD();
        }
    }
    printf("\n");
    return 0;
}