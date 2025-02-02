/* Sebastian Hung Yansen */
/* 13523070 */
/* 15 Oktober 2024 */
/* Praktikum 4 Soal 3 */

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#define MAX_N 100
#define MAX_VAL 100000

void rotateMatrix(int src[2][2], int dest[2][2])
{
    dest[0][0] = src[1][0];
    dest[0][1] = src[0][0];
    dest[1][0] = src[1][1];
    dest[1][1] = src[0][1];
}

int diskChecker(Matrix *board, int disk[2][2], int row, int col)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (disk[i][j] >= ELMT(*board, row + i, col + j))
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    Matrix board;
    int N, i, j, count = 0;
    int disk[2][2], rotatedDisk1[2][2], rotatedDisk2[2][2], rotatedDisk3[2][2];

    // Inisialisasi Matrix/Grid
    while (N < 2 || N > 100)
    {
        scanf("%d", &N);
    }
    readMatrix(&board, N, N);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &disk[i][j]);
        }
    }

    rotateMatrix(disk, rotatedDisk1);
    rotateMatrix(rotatedDisk1, rotatedDisk2);
    rotateMatrix(rotatedDisk2, rotatedDisk3);

    for (int i = 0; i <= N - 2; i++) {
        for (int j = 0; j <= N - 2; j++) {
            if (diskChecker(&board, disk, i, j) ||
                diskChecker(&board, rotatedDisk1, i, j) ||
                diskChecker(&board, rotatedDisk2, i, j) ||
                diskChecker(&board, rotatedDisk3, i, j)) {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}