/* Sebastian Hung Yansen */
/* 13523070 */
/* Praktikum ascending.c*/
/* 19 November 2024 */

#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>

int main() {
    int N = 0;
    int i;
    List l, l2;
    CreateList(&l);
    CreateList(&l2);

    // Menerima input
    while (N != -9999) {
        scanf("%d", &N);
        if (N != -9999) {
            if (isEmpty(l)) {
                insertLast(&l, N);
            } else {
                if (N <= getElmt(l, 0)) {
                    insertFirst(&l, N);
                } else if (N >= getElmt(l, length(l) - 1)) {
                    insertLast(&l, N);
                } else {
                    i = 0;
                    while (i < length(l) && N >= getElmt(l, i)) {
                        insertLast(&l2, getElmt(l, i));
                        i++;
                    }
                    insertLast(&l2, N);
                    while (i < length(l)) {
                        insertLast(&l2, getElmt(l, i));
                        i++;
                    }
                    l = l2;
                    CreateList(&l2);
                }
            }
        }
    }

    // OUTPUT
    displayList(l);
    return 0;
}