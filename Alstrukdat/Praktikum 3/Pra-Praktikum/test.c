/* Sebastian Hung Yansen */
/* 13523070 */
/* 6 Oktober 2024 */
/* Pra-Praktikum 3 */

#include <stdio.h>
#include <stdlib.h>
#include "listdin.c"

int main()
{
    int max, min, n, i, val;
    max = -999;
    min = 999;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        if (val > max)
        {
            max = val;
        }
        if (val < min)
        {
            min = val;
        }
    }
    if (n <= 1)
    {
        printf("0\n");
    }
    else
    {
    printf("%d\n", max+1 - min);
    }
}