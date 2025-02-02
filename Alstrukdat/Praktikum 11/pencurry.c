/* Sebastian Hung Yansen */
/* 13523070 */
/* Pra-Praktikum invert.c */
/* 19 Desember 2024 */
#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

// Fungsi bantu untuk menghitung jumlah harta maksimum
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Fungsi rekursif dengan memoization
void mencurryHelper(BinTree T, int *include, int *exclude) {
    if (T == NULL) {
        *include = 0;
        *exclude = 0;
        return;
    }

    int includeLeft, excludeLeft, includeRight, excludeRight;

    // Hitung untuk subtree kiri
    mencurryHelper(LEFT(T), &includeLeft, &excludeLeft);
    // Hitung untuk subtree kanan
    mencurryHelper(RIGHT(T), &includeRight, &excludeRight);

    // Jika kita mengambil node ini, kita tidak bisa mengambil anak-anaknya
    *include = ROOT(T) + excludeLeft + excludeRight;

    // Jika kita tidak mengambil node ini, kita bisa memilih untuk mengambil atau tidak mengambil anak-anaknya
    *exclude = max(includeLeft, excludeLeft) + max(includeRight, excludeRight);
}

int mencurry(BinTree T) {
    int include, exclude;
    mencurryHelper(T, &include, &exclude);
    return max(include, exclude);
}

// int main() {
//     BinTree T = NewTree(10, NewTree(1, NewTree(2, NULL, NULL), NewTree(3, NULL, NULL)), NewTree(4, NewTree(5, NULL, NULL), NewTree(6, NULL, NULL)));
//     printf("%d\n", mencurry(T));
//     return 0;
// }