/* Sebastian Hung Yansen */
/* 13523070 */
/* 8 Oktober 2024 */
/* Intervalay */

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

int main()
{
    ListDin l1, l2, l3;
    int N, i, j, interval;
    CreateListDin(&l2, 2); // Pembuatan list newInterval
    /* Pembuatan dan Pembacaan List Intervalay */
    scanf("%d", &N);
    CreateListDin(&l1, N);
    CreateListDin(&l3, N + 2);
    NEFF(l1) = N;
    if (N > 0)
    {
        for (i = 0; i < N; i++)
        {
            scanf("%d", &ELMT(l1, i));
        }
    }
    /* Pembacaan List newInterval */
    NEFF(l2) = 2;
    for (i = 0; i < 2; i++)
    {
        scanf("%d", &ELMT(l2, i));
    }
    /* Pengecekan Interval */
    /* Cek jika kosong */
    if (isEmpty(l1))
    {
        printf("%d %d\n", ELMT(l2, 0), ELMT(l2, 1));
    }
    else
    {
        int newStart = ELMT(l2, 0);
        int newEnd = ELMT(l2, 1);
        boolean merged = false;

        for (i = 0; i < N; i += 2)
        {
            int start = ELMT(l1, i);
            int end = ELMT(l1, i + 1);

            if (newEnd < start)
            {
                if (!merged)
                {
                    ELMT(l3, NEFF(l3)++) = newStart;
                    ELMT(l3, NEFF(l3)++) = newEnd;
                    merged = true;
                }
                ELMT(l3, NEFF(l3)++) = start;
                ELMT(l3, NEFF(l3)++) = end;
            }
            else if (newStart > end)
            {
                ELMT(l3, NEFF(l3)++) = start;
                ELMT(l3, NEFF(l3)++) = end;
            }
            else
            {
                newStart = (newStart < start) ? newStart : start;
                newEnd = (newEnd > end) ? newEnd : end;
            }
        }

        if (!merged)
        {
            ELMT(l3, NEFF(l3)++) = newStart;
            ELMT(l3, NEFF(l3)++) = newEnd;
        }

        for (i = 0; i < NEFF(l3); i += 2)
        {
            printf("%d %d", ELMT(l3, i), ELMT(l3, i + 1));
            if (i + 2 < NEFF(l3))
            {
                printf(" ");
            }
        }
        printf("\n");
    }   
    return 0;
}