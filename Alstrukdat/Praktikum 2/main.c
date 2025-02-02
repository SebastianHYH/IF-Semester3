/* Sebastian Hung Yansen */
/* 13523070 */
/* Praktikum 2 */
/* Soal 3 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "liststatik.h"

int main()
{
    int i, max = 0, max2 = 0, maxid, max2id;
    boolean allSame = true;
    ListStatik l1;
    int id[101] = {0}; // Inisialisasi array id di antara 0 - 100
    readList(&l1);

    for (i = 0; i < listLength(l1); i++)
    {
        id[ELMT(l1, i)]++;
    }

    // Find the maximum frequency
    for (i = 0; i < 101; i++)
    {
        if (id[i] > max)
        {
            max2 = max;
            max2id = maxid;
            max = id[i];
            maxid = i;
        }
        else if (id[i] > max2 && id[i] < max)
        {
            max2 = id[i];
            max2id = i;
        }
    }

    // Check if there is a second most frequent number
    if (max2 == 0)
    {
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
    }
    else
    {
        printf("%d\n", max2id);
    }

    return 0;
}