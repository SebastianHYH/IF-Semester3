/* Sebastian Hung Yansen */
/* 13523070 */
/* Latihan Praktikum maxxing.c */
/* 15 November 2024 */

#include <stdio.h>
#include "prioqueue.h"

int main() {
    int n; scanf("%d", &n);
    // Tambahkan inisialisasi yang dibutuhkan

    PrioQueue pqA, pqB;
    CreatePrioQueue(&pqA);
    CreatePrioQueue(&pqB);
    
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        // Tambahkan inisialisasi yang dibutuhkan
        enqueue(&pqA, a);
    }

    for (int i = 0; i < n; i++) {
        int b; scanf("%d", &b);
        // Tambahkan inisialisasi yang dibutuhkan
        enqueue(&pqB, b);
    }

    long long ans = 0;
    // Lanjutkan kode perhitungan disini

        for (int i = 0; i < n; i++) {
        int maxA, maxB;
        dequeue(&pqA, &maxA);
        dequeue(&pqB, &maxB);
        ans += (long long)maxA * maxB;
    }

    printf("%lld\n", ans);
    return 0;
}