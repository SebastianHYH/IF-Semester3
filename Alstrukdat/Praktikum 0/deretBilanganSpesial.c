/* Sebastian Hung Yansen */
/* 13523070 */

#include <stdio.h>

int main(){
    int a;
    int b;
    scanf ("%d %d", &a, &b);
    printf("%d", a);
    while (a < b)
        {
            if (a % 2 == 0)
                {
                    a = a * 2;
                    if (a < b)
                        {
                            printf(" %d", a);
                        }
                }
            else
                {
                    a = a + 1;
                    if (a < b)
                        {
                            printf(" %d", a);
                        }
                }
        };
    printf("\n");
    return 0;
}