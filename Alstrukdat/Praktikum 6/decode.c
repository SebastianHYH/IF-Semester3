/* Sebastian Hung Yansen */
/* 13523070 */
/* Latihan Praktikum decode.c */
/* 14 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void decodeString(char *encoded, char *decoded) {
    Stack char_stack;
    Stack count_stack;
    CreateEmpty(&char_stack);
    CreateEmpty(&count_stack);

    int i = 0;
    int len = strlen(encoded);

    while (i < len) {
        if (encoded[i] >= '0' && encoded[i] <= '9') {
            int num = 0;
            while (encoded[i] >= '0' && encoded[i] <= '9') {
                num = num * 10 + (encoded[i] - '0');
                i++;
            }
            Push(&count_stack, num);
        } else if (encoded[i] == '[') {
            Push(&char_stack, encoded[i]);
            i++;
        } else if (encoded[i] == ']') {
            char temp[10000];
            int idx = 0;
            while (!IsEmpty(char_stack) && InfoTop(char_stack) != '[') {
                temp[idx++] = InfoTop(char_stack);
                Pop(&char_stack, &temp[idx-1]);
            }
            char dummy;
            Pop(&char_stack, &dummy);
            int repeatCount = InfoTop(count_stack);
            Pop(&count_stack, &repeatCount);
            char repeated[10000];
            int repeatedLen = 0;
            for (int j = 0; j < repeatCount; j++) {
                for (int k = idx - 1; k >= 0; k--) {
                    repeated[repeatedLen++] = temp[k];
                }
            }
            for (int j = 0; j < repeatedLen; j++) {
                Push(&char_stack, repeated[j]);
            }
            i++;
        } else {
            Push(&char_stack, encoded[i]);
            i++;
        }
    }
    int decodedIdx = 0;
    char temp[10000];
    while (!IsEmpty(char_stack)) {
        temp[decodedIdx++] = InfoTop(char_stack);
        Pop(&char_stack, &temp[decodedIdx - 1]);
    }
    for (int j = decodedIdx - 1; j >= 0; j--) {
        decoded[decodedIdx - j - 1] = temp[j];
    }
    decoded[decodedIdx] = '\0';
}

int main() {
    int N;
    scanf("%d", &N);

    char encoded[N + 1];
    char decoded[10000];

    scanf("%s", encoded);

    decodeString(encoded, decoded);
    printf("%s\n", decoded);

    return 0;
}