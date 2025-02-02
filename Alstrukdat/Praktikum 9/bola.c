/* Sebastian Hung Yansen */
/* 13523070 */
/* Praktikum bola.c */
/* 26 November 2024 */

#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, listElmt, temp;
    int max = 0;
    boolean firstDeletion = true;
    int i, j;
    List l;
    scanf("%d", &N);
    CreateList(&l);
    // Mengisi List
    for (i = 1; i <= N; i++) {
        insertLast(&l, i);
    }
    for (i = 0; i < N-1; i++) {
        scanf("%d", &listElmt);
        if (listElmt > 0) {
            for (j = 0; j < listElmt; j++) {
                deleteFirst(&l, &temp);
                insertLast(&l, temp);
            }
            if (firstDeletion) {
                deleteFirst(&l, &temp);
                firstDeletion = false;
            } else {
                deleteLast(&l, &temp);
            }
            //displayList(l);
        } else if (listElmt < 0) {
            for (j = 0; j < -listElmt; j++) {
                deleteLast(&l, &temp);
                insertFirst(&l, temp);
            }
            deleteFirst(&l, &temp);
            if (firstDeletion) {
                firstDeletion = false;
            }
            //displayList(l);
        }
    }
    printf("%d\n", INFO(FIRST(l)));
    return 0;
}