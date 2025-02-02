/* Sebastian Hung Yansen */
/* 13523070 */

#include <stdio.h>

int main(){
    int n;
    int k;
    int a_i;
    int total = 0;
    int i;
    scanf ("%d %d", &n, &k);
    for (i = 0; i < n; i++)
        {
            scanf ("%d", &a_i);
            if (a_i % k != 0)
            {
                total = total + a_i;
            }
            /* else tidak melakukan apa-apa*/
        };
    printf("%d\n", total);
}