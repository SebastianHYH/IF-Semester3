/* Sebastian Hung Yansen */
/* 13523070 */
/* 15 Oktober 2024 */
/* Praktikum 4 Soal 1 */

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#define MOD 1000000007

int main()
{
    Matrix m;
    int N = 0, i, j, k, l, totalKekacauan = 0;
    //int MOD = 10E9 + 7;
    // Inisialisasi Matrix/Papan
    while (N < 2 || N > 100)
    {
        scanf("%d", &N);
    }
    readMatrix(&m, N, N);
    // Pengecekan
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (ELMT(m, i, j) != 0)
            {
                // Cek Baris
                k = i;
                for (l = 0; l < N; l++)
                {
                    if (l != j && ELMT(m, k, l) > 0)
                    {
                        totalKekacauan = (totalKekacauan % MOD + ELMT(m, k, l) % MOD) % MOD;
                    }
                }
                // Cek Kolom
                l = j;
                for (k = 0; k < N; k++)
                {
                    if (k != i && ELMT(m, k, l) > 0)
                    {
                        totalKekacauan = (totalKekacauan % MOD + ELMT(m, k, l) % MOD) % MOD;
                    }
                }
            }
        }
    }
    printf("%d", totalKekacauan);
    printf("\n");
    return 0;
}