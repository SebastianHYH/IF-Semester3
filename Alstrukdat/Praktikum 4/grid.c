/* Sebastian Hung Yansen */
/* 13523070 */
/* 15 Oktober 2024 */
/* Praktikum 4 Soal 2 */

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#define MOD 1000000007

int main()
{
    Matrix m;
    int N = 0, i = 0, j = 0;
    // Inisialisasi Matrix/Grid
    while (N < 2 || N > 100)
    {
        scanf("%d", &N);
    }
    readMatrix(&m, N, N);

    int **dp = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        dp[i] = (int *)malloc(N * sizeof(int));
    }

    dp[0][0] = (ELMT(m,0,0) == 0) ? 1 : 0;

    for (int j = 1; j < N; j++)
    {
        dp[0][j] = (ELMT(m,0,j) == 0) ? dp[0][j - 1] : 0;
    }

    for (int i = 1; i < N; i++) {
        dp[i][0] = (ELMT(m, i, 0) == 0) ? dp[i-1][0] : 0;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (ELMT(m,i,j) == 0){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    printf("%d\n", dp[N - 1][N - 1]);
    
    for (int i = 0; i < N; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return 0;
}