/* Sebastian Hung Yansen */
/* 13523070 */
/* Praktikum tambah.c*/
/* 19 November 2024 */

#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>

int main() {
    int N = 0;
    int M = 0;
    boolean addOne = false; // Initialize addOne
    boolean maxNum = false; // Initialize maxNum
    List l1, l2, l3;

    CreateList(&l1);
    CreateList(&l2);
    CreateList(&l3);

    // Mengisi list 1
    while (N != -1) {
        scanf("%d", &N);
        if (N != -1) {
            insertLast(&l1, N);
        }
    }

    // Mengisi list 2
    while (M != -1) {
        scanf("%d", &M);
        if (M != -1) {
            insertLast(&l2, M);
        }
    }

    // Proses Penjumlahan
    while (!isEmpty(l1) || !isEmpty(l2)) {
        N = 0;
        M = 0;
        if (!isEmpty(l1)) {
            deleteLast(&l1, &N);
        }
        if (!isEmpty(l2)) {
            deleteLast(&l2, &M);
        }
        int hasil = N + M;
        if (addOne) {
            hasil += 1;
            addOne = false;
        }
        if (hasil >= 10) {
            hasil = hasil % 10;
            addOne = true;
        }
        insertFirst(&l3, hasil);
    }

    if (addOne) {
        insertFirst(&l3, 1);
    }

    // Output
    while (!isEmpty(l3)) {
        deleteFirst(&l3, &N);
        printf("%d", N);
        if (!isEmpty(l3)) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}