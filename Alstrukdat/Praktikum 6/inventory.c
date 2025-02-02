/* Sebastian Hung Yansen */
/* 13523070 */
/* Pra-Praktikum inventory.c */
/* 13 November 2024 */

#include <stdio.h>
#include "boolean.h"
#include "stack.h"

// HINT: Gunakan (c - '0') untuk mengubah character ke angka

int main() {
    Stack s;
    CreateEmpty(&s);
    char ch;
    int N, i;
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf(" %c", &ch);
        if (ch >= '0' && ch <= '9') {
            Push(&s, ch - '0');
            //printf("Pushed: %d\n", ch - '0');
        }
        else if (ch == '+') {
            int a, b;
            Pop(&s, &a);
            Pop(&s, &b);
            Push(&s, b);
            Push(&s, a);
            Push(&s, a + b);
            //printf("%d + %d = %d\n", a, b, a + b);
        }
        else if (ch == 'X') {
            int a;
            Pop(&s, &a);
            //printf("Popped: %d\n", a);
        }
        else if (ch == 'S') {
            int total = 0;
            while (!IsEmpty(s)) {
                int a;
                Pop(&s, &a);
                total += a;
            }
            if (total > 0) {
                Push(&s, total);
            }
            //printf("Sum: %d\n", total);
        }
        else if (ch == 'A') {
            int div = 0;
            int avg = 0;
            while (!IsEmpty(s)) {
                int a;
                Pop(&s, &a);
                avg += a;
                div++;
            }
            if (div != 0) {
                Push(&s, avg / div);
                //printf("Average: %d\n", avg / div);
            }
        }
    }

    int result = 0;
    while (!IsEmpty(s)) {
        int a;
        Pop(&s, &a);
        result += a;
    }
    printf("%d\n", result);
    return 0;
}