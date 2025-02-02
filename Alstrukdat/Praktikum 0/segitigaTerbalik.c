/* Sebastian Hung Yansen */
/* 13523070 */

#include <stdio.h>

int main(){
    /* Kamus */
    int n;
    int i;
    int j;
    int star; // Jumlah Bintang
    /* Program */
    scanf ("%d", &n);
    for (i = 0; i < n; i++)
    {
        //n = n - i;
        star = 2 * (n-i) - 1;
        if (i > 0)
            for (j = 0; j < i; j++)
                {
                    printf(" ");
                }
        for (j = 0; j < star; j++)
            {
                printf("*");
            }
        printf("\n");
    }
    return 0;
}