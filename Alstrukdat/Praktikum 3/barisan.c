/* Sebastian Hung Yansen */
/* 13523070 */
/* 8 Oktober 2024 */
/* Barisan */

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

int main()
{
    ListDin l;
    int N, i, j, temp;
    int output = 0;
    // Pembuatan dan pembacaan list
    do
    {
        scanf("%d", &N);
    } while (N < 0 || N > 1000);
    CreateListDin(&l, N);   
    NEFF(l) = N;
    if (N > 0)
    {
        for (i = 0; i < N; i++)
        {
            scanf("%d", &ELMT(l, i));
        }
    }
    // Sorting
    for (i = 0; i < NEFF(l) - 1; i++)
    {
        for (j = i + 1; j < NEFF(l); j++)
        {
            if (ELMT(l, i) > ELMT(l, j))
            {
                temp = ELMT(l, i);
                ELMT(l, i) = ELMT(l, j);
                ELMT(l, j) = temp;
                output += 1;
            }
        }
    }
    printf("%d\n", output);
    return 0;
}