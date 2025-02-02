/* Sebastian Hung Yansen */
/* 13523070 */
/* 2 Oktober 2024 */

#include "rotating_point.h"
#include <stdio.h>
#include "complex.h"
#include "point.h"

COMPLEX PowerCOMPLEX(COMPLEX C, int p)
{
    COMPLEX result;
    result.Re = 1;
    result.Im = 0;
    for (int i = 0; i < p; i++)
    {
        result = MultiplyCOMPLEX(result, C);
    }
    return result;
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n)
{
    COMPLEX PComplex;
    CreateComplex(&PComplex, Absis(*P), Ordinat(*P));
    for (int i = 1; i <= n; i++)
    {
        COMPLEX powerC = PowerCOMPLEX(C, i);
        float newX = Absis(*P) * powerC.Re - Ordinat(*P) * powerC.Im;
        float newY = Absis(*P) * powerC.Im + Ordinat(*P) * powerC.Re;
        Absis(*P) = newX;
        Ordinat(*P) = newY;
        
        if ((newX * newX + newY * newY) > 1)
        {
            printf("Titik keluar dari lingkaran pada iterasi ke %d\n", i);
            return;
        }
    }
    printf("Titik tetap berada di dalam lingkaran setelah %d iterasi\n", n);
}