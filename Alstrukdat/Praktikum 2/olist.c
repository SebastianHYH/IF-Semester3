/* Sebastian Hung Yansen */
/* 13523070 */
/* Praktikum 2 */
/* Soal 1 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "liststatik.h"

int main()
{   
    int i, j, val;
    ListStatik l, l2;
    readList(&l);
    CreateListStatik(&l2);
    for (i = 0; i < listLength(l); i++)
    {
        ELMT(l2,i) = 0;
    }
    for (i = 0; i < listLength(l); i++)
    {
        for (j = 0; j < listLength(l); j++)
        {
            if (ELMT(l,i) == ELMT(l,j) && ELMT(l2,i) == 0)
            {
                ELMT(l2,i) += 1;
            }
            else if (ELMT(l,i) == ELMT(l,j) && ELMT(l2,i) > 0)
            {
                ELMT(l2,i) += 1;
                deleteAt(&l, &val, j);
                j -= 1;
            }
        }
    }
    printList(l);
    printf("\n");
    for (i = 0; i < listLength(l); i++)
    {
        printf("%d %d\n", ELMT(l,i), ELMT(l2,i));
    }
    return 0;
}