/* Sebastian Hung Yansen */
/* 13523070 */
/* Latihan Praktikum prioqueue.c */
/* 15 November 2024 */


#include "prioqueue.h"
#include <stdio.h>

/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq) {
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(PrioQueue pq) {
/* Mengirim true jika pq kosong: lihat definisi di atas */
    return (IDX_HEAD(pq) == IDX_UNDEF);// && (IDX_TAIL(pq) == IDX_UNDEF);
}
boolean isFull(PrioQueue pq) {
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    return /* (IDX_HEAD(pq) == 0) && (IDX_TAIL(pq) == CAPACITY-1); */ (length(pq) == CAPACITY);
}

int length(PrioQueue pq) {
/* Mengirimkan banyaknya elemen prioqueue. Mengirimkan 0 jika pq kosong. */
    if (isEmpty(pq)) {
        return 0;
    } else if (IDX_HEAD(pq) <= IDX_TAIL(pq)) {
        return IDX_TAIL(pq) - IDX_HEAD(pq) + 1;
    } else {
        return CAPACITY - IDX_HEAD(pq) + IDX_TAIL(pq) + 1;
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(PrioQueue *pq, ElType val) {
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val disisipkan pada posisi yang sesuai, IDX_TAIL "mundur" dalam buffer melingkar.,
        pq terurut mengecil */
    if (isEmpty(*pq)) {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        TAIL(*pq) = val;
    } else {
        if (IDX_TAIL(*pq) == CAPACITY-1) {
            IDX_TAIL(*pq) = 0;
        } else {
            IDX_TAIL(*pq)++;
        }
        TAIL(*pq) = val;
    

        // Sort using insertion sort
        int i = IDX_TAIL(*pq);
        while (i != IDX_HEAD(*pq) && (*pq).buffer[i] > (*pq).buffer[(i - 1 + CAPACITY) % CAPACITY]) {
            // Swap elements
            ElType temp = (*pq).buffer[i];
            (*pq).buffer[i] = (*pq).buffer[(i - 1 + CAPACITY) % CAPACITY];
            (*pq).buffer[(i - 1 + CAPACITY) % CAPACITY] = temp;
            i = (i - 1 + CAPACITY) % CAPACITY;
        }
    }
}

void dequeue(PrioQueue *pq, ElType *val) {
    *val = HEAD(*pq);
    if (length(*pq) == 1) {
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    } else {
        if (IDX_HEAD(*pq) == CAPACITY-1) {
            IDX_HEAD(*pq) = 0;
        } else {
            IDX_HEAD(*pq)++;
        }
    }
}

/* *** Display Queue *** */
void displayPrioQueue(PrioQueue pq) {
/* Proses : Menuliskan isi PrioQueue dengan traversal, PrioQueue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. pq boleh kosong */
/* F.S. Jika pq tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 30, 20, 1 akan dicetak: [30,20,1] */
/* Jika Queue kosong : menulis [] */
    if(isEmpty(pq)) {
        printf("[]\n");
    } else {
        int i = IDX_HEAD(pq);
        printf("[");
        while (i != IDX_TAIL(pq)) {
            printf("%d,", pq.buffer[i]);
            if (i == CAPACITY-1) {
                i = 0;
            } else {
                i++;
            }
        }
        printf("%d]\n", pq.buffer[i]);
    }
}

// int main()
// {
//     PrioQueue pq;
//     ElType val;
//     CreatePrioQueue(&pq);
//     displayPrioQueue(pq);
//     enqueue(&pq, 1);
//     displayPrioQueue(pq);
//     enqueue(&pq, 2);
//     displayPrioQueue(pq);
//     enqueue(&pq, 3);
//     displayPrioQueue(pq);
//     dequeue(&pq, &val);
//     displayPrioQueue(pq);
//     dequeue(&pq, &val);
//     displayPrioQueue(pq);
//     dequeue(&pq, &val);
//     displayPrioQueue(pq);
//     return 0;
// }