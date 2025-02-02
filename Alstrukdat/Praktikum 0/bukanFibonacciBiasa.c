/* Sebastian Hung Yansen */
/* 13523070 */

#include <stdio.h>

int fungsi(int n, int a, int b);

int main(){
    int n;
    int a;
    int b;
    int hasil;
    scanf ("%d %d %d", &n, &a, &b);
    hasil = fungsi(n, a, b);
    printf("%d\n", hasil);
    return 0;
}

int fungsi(int n, int a, int b){
    int c;
    if (n == 1)
    {
        return a;
    }
    else if (n == 2)
    {
        return b;
    }
    else
    {
        c = fungsi(n-1, a, b) + fungsi(n-2, a, b);
        return c;
    }
}