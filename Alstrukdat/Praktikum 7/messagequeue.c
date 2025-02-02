/* Sebastian Hung Yansen */
/* 13523070 */
/* Latihan Praktikum messagequeue.c */
/* 15 November 2024 */

#include <stdio.h>
#include "queue.h"

int main() {
    int n, val, val2;
    scanf("%d", &n);

    // Lakukan inisialisasi Queue disini
    Queue q1;
    CreateQueue(&q1); // Urutan Angka

    for (int i = 0; i < n; ++i) {
        int op, insert;
        scanf("%d", &op);

        // Kerjakan keempat tipe query disini
        if (op == 1) {
            scanf("%d", &insert);
            if (isFull(q1)) {
                printf("Queue Penuh\n");
            } else {
                enqueue(&q1, insert);
                printf("Enqueue %d Berhasil\n", insert);
            }
        } else if (op == 2) {
            if (isEmpty(q1)) {
                printf("Queue Kosong\n");
            } else {
                dequeue(&q1, &val);
                printf("Dequeue %d Berhasil\n", val);
            }
        } else if (op == 3) {
            if (isEmpty(q1)) {
                printf("Queue Kosong\n");
            } else {
                printf("Elemen Awal Queue adalah %d\n", HEAD(q1));
            }
        } else if (op == 4) {
            printf("Ukuran Queue saat ini adalah %d\n", length(q1));
        }
    }
    // Display Queue disini
    displayQueue(q1);
    return 0;
}