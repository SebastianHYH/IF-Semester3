/* Sebastian Hung Yansen */
/* 13523070 */
/* Pra-Praktikum listlinier.c */
/* 14 November 2024 */

#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

Address newNode(ElType val) {

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
/* Mengirim true jika list kosong */
    return FIRST(l) == NULL;
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    Address(p) = FIRST(l);
    int i = 0;
    while (i < idx) {
        p = NEXT(p);
        i++;
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    Address(p) = FIRST(*l);
    int i = 0;
    while (i < idx) {
        p = NEXT(p);
        i++;
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val) {
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    Address(p) = FIRST(l);
    int i = 0;
    while (p != NULL) {
        if (INFO(p) == val) {
            return i;
        }
        p = NEXT(p);
        i++;
    }
    return IDX_UNDEF;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    Address(p) = newNode(val);
    NEXT(p) = FIRST(*l);
    FIRST(*l) = p;
}

void insertLast(List *l, ElType val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if (isEmpty(*l)) {
        insertFirst(l, val);
    }
    else {
        Address(p) = newNode(val);
        if (p != NULL) {
            Address last = FIRST(*l);
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }   
}

void insertAt(List *l, ElType val, int idx) {
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if (idx == 0) {
        insertFirst(l, val);
    }
    else {
        Address(p) = newNode(val);
        if (p != NULL) { // Alokasi Berhasil
            int ctr = 0;
            List loc = FIRST(*l);
            while (ctr < idx - 1) {
                loc = NEXT(loc);
                ctr++;
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    Address(p) = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    Address(p) = FIRST(*l);
    Address(loc) = NULL;
    while (NEXT(p) != NULL) {
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL) {
        FIRST(*l) = NULL;
    }
    else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val) {
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    if (idx == 0) {
        deleteFirst(l, val);
    }
    else {
        int ctr = 0;
        Address(loc) = FIRST(*l);
        while (ctr < idx - 1) {
            loc = NEXT(loc);
            ctr++;
        }
        Address(p) = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    } 
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    printf("[");
    if (!isEmpty(l)) {
        Address(p) = FIRST(l);
        while (p != NULL) {
            printf("%d", INFO(p));
            p = NEXT(p);
            if (p != NULL) {
                printf(",");
            }
        }
    }
    printf("]");

}

int length(List l) {
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int ctr = 0;
    Address(p) = FIRST(l);
    while (p != NULL) {
        ctr++;
        p = NEXT(p);
    }
    return ctr;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    List l3;
    CreateList(&l3);
    Address(p) = FIRST(l1);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}

// int main() {
//     List l;
//     CreateList(&l);
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
//     insertAt(&l, 11, 5);
//     insertAt(&l, 12, 5);
//     insertAt(&l, 13, 5);
//     insertAt(&l, 14, 5);
//     insertAt(&l, 15, 5);
//     displayList(l);
//     printf("\n");
//     int val;
//     deleteFirst(&l, &val);
//     printf("%d\n", val);
//     deleteLast(&l, &val);
//     printf("%d\n", val);
//     deleteAt(&l, 5, &val);
//     printf("%d\n", val);
//     displayList(l);
//     printf("\n");
//     printf("%d\n", length(l));
//     List l2;
//     CreateList(&l2);
//     insertFirst(&l2, 1);
//     insertFirst(&l2, 2);
//     insertFirst(&l2, 3);
//     insertFirst(&l2, 4);
//     insertFirst(&l2, 5);
//     displayList(l2);
//     printf("\n");
//     List l3 = concat(l, l2);
//     displayList(l3);
//     printf("\n");
//     return 0;
// }