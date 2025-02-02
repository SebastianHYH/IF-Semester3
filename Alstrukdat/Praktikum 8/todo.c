/* Sebastian Hung Yansen */
/* 13523070 */
/* Latihan Praktikum todo.c*/
/* 27 November 2024 */

#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>

int main() {
    int N, idx;
    char C;
    List l;
    CreateList(&l);
    while (C != 'X') {
        scanf("%c", &C);
        if (C != 'X') {
            // Perintah 1 = P
            scanf(" %d", &N);
            if (C == 'P') {
                insertFirst(&l, N);
            } else if (C == 'I') {
                insertLast(&l, N);
            } else if (C == 'C') {
                if (!isEmpty(l)) {
                    deleteFirst(&l, &N);
                }
            } else if (C == 'D') {
                if (!isEmpty(l)) {
                    idx = indexOf(l, N);
                    if (idx != IDX_UNDEF) {
                        deleteAt(&l, idx, &N);
                    }
                }
            }
        }
    }

    // Output
    displayList(l);
    return 0;
}