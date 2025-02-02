/* Sebastian Hung Yansen */
/* 13523070 */
/* Pra-Praktikum invert.c */
/* 19 Desember 2024 */


#include <stdio.h>
#include "bintree.h"

void invertTree(BinTree *p) {
    if (*p != NULL) {
        // Tukar subtree kiri dan kanan
        BinTree temp = LEFT(*p);
        LEFT(*p) = RIGHT(*p);
        RIGHT(*p) = temp;

        // Rekursif untuk subtree kiri dan kanan
        invertTree(&LEFT(*p));
        invertTree(&RIGHT(*p));
    }
}

// int main() {
//     BinTree p = NewTree(1, NewTree(2, NewTree(4, NULL, NULL), NewTree(5, NULL, NULL)), NewTree(3, NewTree(6, NULL, NULL), NewTree(7, NULL, NULL)));
//     printTree(p, 2);
//     printf("\n");
//     invertTree(&p);
//     printTree(p, 2);
//     printf("\n");
//     return 0;
// }