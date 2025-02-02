/* Sebastian Hung Yansen */
/* 13523070 */
/* Praktikum 2 */
/* Soal 2 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "liststatik.h"

int main()
{
    int i, j, val;
    ListStatik l;
    readList(&l);
    if (listLength(l) == 1)
    {
        ELMT(l,IDX_MIN) += 1;
    }
    else
    {
        if (ELMT(l,getLastIdx(l)) != 9)
        {
            ELMT(l,getLastIdx(l)) += 1;
        }
        else // ELMT(l,getLastIdx(l)) == 9
        {
            ELMT(l,getLastIdx(l)) = 0;
            i = listLength(l)-2;
            while (ELMT(l,i) == 9)
            {
                ELMT(l,i) = 0;
                i -= 1;
            }
            ELMT(l,i) += 1;
            if (ELMT(l,getFirstIdx(l)) == 0)
            {
                insertFirst(&l, 1);
            }
        }
    }
    // OUTPUT
    printf("%d", ELMT(l,0));
    for (i = 1; i < listLength(l); i++)
    {
        printf(" %d", ELMT(l, i));
    }
    printf("\n");
    return 0;
}