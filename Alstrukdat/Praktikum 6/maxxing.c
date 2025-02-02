/* Sebastian Hung Yansen */
/* 13523070 */
/* Latihan Praktikum maxxing.c */
/* 14 November 2024 */

#include <stdio.h>
#include "boolean.h"
#include "stack.h"

const int MXN = 1e4 + 7;

int main() {
    int N;
    scanf("%d", &N);

    int heights[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &heights[i]);
    }

    int maxStrength[N + 1];
    for (int i = 1; i <= N; i++) {
        maxStrength[i] = 0;
    }

    for (int size = 1; size <= N; size++) {
        int minHeight = heights[0];
        for (int i = 0; i < size; i++) {
            if (heights[i] < minHeight) {
                minHeight = heights[i];
            }
        }
        maxStrength[size] = minHeight;

        for (int i = size; i < N; i++) {
            if (heights[i - size] == minHeight) {
                minHeight = heights[i - size + 1];
                for (int j = i - size + 1; j <= i; j++) {
                    if (heights[j] < minHeight) {
                        minHeight = heights[j];
                    }
                }
            } else if (heights[i] < minHeight) {
                minHeight = heights[i];
            }
            if (minHeight > maxStrength[size]) {
                maxStrength[size] = minHeight;
            }
        }
    }

    for (int i = 1; i <= N-1; i++) {
        printf("%d ", maxStrength[i]);
    }
    printf("%d", maxStrength[N]);
    printf("\n");

    return 0;
}