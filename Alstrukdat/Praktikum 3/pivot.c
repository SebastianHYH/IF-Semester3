/* Sebastian Hung Yansen */
/* 13523070 */
/* 8 Oktober 2024 */
/* Pivot */

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

int main()
{
    ListDin l;
    int N, i, j;
    int output = 0;
    boolean pivot = true;
    // Pembuatan dan pembacaan list
    do
    {
        scanf("%d", &N);
    } while (N < 3 || N > 100000);
    CreateListDin(&l, N);
    NEFF(l) = N;
    if (N > 0)
    {
        for (i = 0; i < N; i++)
        {
            scanf("%d", &ELMT(l, i));
        }
    }
    // ** Pengecekan **
    // Pengecekan elemen awal
    for (i = 0; i < listLength(l); i++)
    {
        pivot = true;
        for (j = 0; j < listLength(l); j++)
        {
            if (j != i && j < i)
            {
                if (ELMT(l, i) < ELMT(l, j))
                pivot = false;
            }
            else if (j != i && j > i)
            {
                if (ELMT(l, i) > ELMT(l, j))
                pivot = false;
            }
        }
        if (pivot)
        {
            output += 1;
        }
        // else, Do It Again - Steely Dan
    }
    printf("%d\n", output);
    return 0;
}