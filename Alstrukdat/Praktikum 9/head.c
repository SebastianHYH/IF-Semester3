/* Sebastian Hung Yansen */
/* 13523070 */
/* Latihan Praktikum head.c */
/* 4 Desember 2024 */

#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, listElmt;
    int max = 0;
    List l;
    scanf("%d", &N);
    CreateList(&l);
    for (int i = 0; i < N; i++) {
        scanf("%d", &listElmt);
        insertLast(&l, listElmt);
        if (listElmt > max) {
            max = listElmt;
        }
    }
    // Paramuditya
    int temp;
    while (INFO(FIRST(l)) != max)
    {
        deleteFirst(&l, &temp);
        insertLast(&l, temp);
    }
    displayList(l);
    return 0;
}