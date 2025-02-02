/* Sebastian Hung Yansen */
/* 13523070 */
/* Pra-Praktikum hapus-duplikat.c */
/* 14 November 2024 */

#include "hapus-duplikat.h"
#include <stdlib.h>
#include <stdio.h>

List hapusDuplikat(List l) {
/**
 * Menerima masukan sebuah list l yang terurut mengecil
 * Mengembalikan list yang merupakan hasil penghapusan elemen yang mempunyai duplikat pada list l, terurut membesar
 * Contoh: hapusDuplikat(3->3->2->1) = 1->2 (-> adalah panah next pada list linear)
 */
    List l2;
    CreateList(&l2);
    Address(p) = FIRST(l);
    while (p != NULL) {
        if (NEXT(p) == NULL || INFO(p) != INFO(NEXT(p))) {
            insertFirst(&l2, INFO(p));
        }
        else {
            while (NEXT(p) != NULL && INFO(p) == INFO(NEXT(p))) {
                p = NEXT(p);
            }
        }
        p = NEXT(p);
    }
    return l2;
}

// int main() {
//     List l;
//     CreateList(&l);

//     // Example usage
//     insertLast(&l, 3);
//     insertLast(&l, 3);
//     insertLast(&l, 2);
//     insertLast(&l, 1);
//     displayList(l);
//     l = hapusDuplikat(l);
//     displayList(l);
//     return 0;
// }