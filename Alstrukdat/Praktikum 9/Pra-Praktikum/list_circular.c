/* Sebastian Hung Yansen */
/* 13523070 */
/* Pra-Praktikum list_circular.c */
/* 25 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    return FIRST(l) == NULL;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    FIRST(*l) = NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val) {
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
    Address p = (Address) malloc(sizeof(ElmtList));
    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void deallocate(Address P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val) {
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
    Address(p) = FIRST(l);
    while (p != NULL) {
        if (INFO(p) == val) {
            return p;
        }
        p = NEXT(p);
        if (p == FIRST(l)) {
            break;
        }
    }
    return NULL;
}

boolean addrSearch(List l, Address p) {
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */
    Address(q) = FIRST(l);
    while (q != NULL) {
        if (q == p) {
            return true;
        }
        q = NEXT(q);
        if (q == FIRST(l)) {
            break;
        }
    }
    return false;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
    Address(p) = allocate(val);
    if (p != NULL) {
        if (isEmpty(*l)) {
            FIRST(*l) = p;
            NEXT(p) = p;
        }
        else {
            Address(q) = FIRST(*l);
            while (NEXT(q) != FIRST(*l)) {
                q = NEXT(q);
            }
            NEXT(p) = FIRST(*l);
            NEXT(q) = p;
            FIRST(*l) = p;
        }
    }
}

void insertLast(List *l, ElType val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    Address(p) = allocate(val);
    if (p != NULL) {
        if (isEmpty(*l)) {
            FIRST(*l) = p;
            NEXT(p) = p;
        }
        else {
            Address(q) = FIRST(*l);
            while (NEXT(q) != FIRST(*l)) {
                q = NEXT(q);
            }
            NEXT(p) = FIRST(*l);
            NEXT(q) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val) {
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama list l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Alamat elemen terakhir di-dealokasi */
    Address(p) = FIRST(*l);
    Address(q) = FIRST(*l);
    while (NEXT(q) != FIRST(*l)) {
        q = NEXT(q);
    }
    *val = INFO(p);
    if (p == q) {
        FIRST(*l) = NULL;
    }
    else {
        FIRST(*l) = NEXT(p);
        NEXT(q) = FIRST(*l);
    }
    deallocate(p);
}

void deleteLast(List *l, ElType * val) {
/* I.S. list tidak kosong */
/* F.S. x adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen pertama yg lama, jika ada */
/*      Alamat elemen terakhir di-dealokasi */
    Address(p) = FIRST(*l);
    Address(q) = FIRST(*l);
    while (NEXT(p) != FIRST(*l)) {
        q = p;
        p = NEXT(p);
    }
    *val = INFO(p);
    if (p == q) {
        FIRST(*l) = NULL;
    }
    else {
        NEXT(q) = FIRST(*l);
    }
    deallocate(p);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    if (isEmpty(l)) {
        printf("[]");
    }
    else {
        Address(p) = FIRST(l);
        printf("[");
        while (true) {
            printf("%d", INFO(p));
            p = NEXT(p);
            if (p == FIRST(l)) {
                break;
            }
            printf(",");
        }
        printf("]");
    }
}

// int main () {
//     List l;
//     CreateList(&l);
//     displayList(l);
//     printf("\n");
//     insertFirst(&l, 1);
//     insertFirst(&l, 2);
//     insertFirst(&l, 3);
//     insertFirst(&l, 4);
//     insertFirst(&l, 5);
//     displayList(l);
//     printf("\n");
//     insertLast(&l, 6);
//     insertLast(&l, 7);
//     insertLast(&l, 8);
//     insertLast(&l, 9);
//     insertLast(&l, 10);
//     displayList(l);
//     printf("\n");
//     int val;
//     deleteFirst(&l, &val);
//     printf("%d\n", val);
//     deleteLast(&l, &val);
//     printf("%d\n", val);
//     displayList(l);
//     printf("\n");
//     return 0;
// }