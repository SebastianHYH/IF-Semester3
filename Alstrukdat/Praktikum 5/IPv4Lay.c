/* Sebastian Hung Yansen */
/* 13523070 */
/* Praktikum 5 IPv4Lay.c */
/* 22 Oktober 2024 */


#include "mesinkarakter.h"
#include "mesinkata.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

int isValidPart(char *part) {
    int len = strlen(part);
    if (len == 0 || len > 3) return 0;
    if (len > 1 && part[0] == '0') return 0; // No leading zeros
    for (int i = 0; i < len; i++) {
        if (!isdigit(part[i])) return 0;
    }
    int num = atoi(part);
    if (num < 0 || num > 255) return 0;
    return 1;
}

int isIPv4Lay(char *word) {
    char *token;
    char *rest = word;
    int count = 0;

    while ((token = strtok_r(rest, "@", &rest))) {
        if (!isValidPart(token)) return 0;
        count++;
    }
    return count == 4;
}

int main() {
    char input[MAX_WORD_LENGTH + 1];
    while (scanf("%s", input) == 1) {
        if (input[strlen(input) - 1] == '.') {
            input[strlen(input) - 1] = '\0'; // Remove the trailing period
            if (isIPv4Lay(input)) {
                printf("4Lay\n");
            } else {
                printf("ewh\n");
            }
            break;
        } else {
            if (isIPv4Lay(input)) {
                printf("4Lay ");
            } else {
                printf("ewh ");
            }
        }
    }
    return 0;
}