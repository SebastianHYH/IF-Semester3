#include <stdio.h>
#include "complex.h"
#include <math.h>

boolean IsCOMPLEXValid(float Re, float Im) {
    return true;
}

void CreateComplex(COMPLEX *C, float Re, float Im) {
    if (IsCOMPLEXValid(Re, Im))
    {
        (*C).Re = Re;
        (*C).Im = Im;
    }
}

/* Baca / Tulis */

void BacaCOMPLEX(COMPLEX *C) {
    scanf ("%f %f", &(*C).Re, &(*C).Im);
}

void TulisCOMPLEX(COMPLEX C){
    if (C.Im >= 0) 
    {
        printf("(%.2f+%.2fi)\n", C.Re, C.Im);
    }
    else 
    {
        printf("(%.2f%.2fi)\n", C.Re, C.Im);
    }
}

/* Operasi Aritmatika Terhadap Type */

COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX hasil;
    hasil.Re = C1.Re + C2.Re;
    hasil.Im = C1.Im + C2.Im;
    return hasil;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX hasil;
    hasil.Re = C1.Re - C2.Re;
    hasil.Im = C1.Im - C2.Im;
    return hasil;
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX hasil;
    hasil.Re = C1.Re * C2.Re - C1.Im * C2.Im;
    hasil.Im = C1.Im * C2.Re + C1.Im * C2.Re;
    return hasil;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX hasil;
    C2.Im = C2.Im * -1;
    COMPLEX CMult;
    CMult = MultiplyCOMPLEX(C1,C2);

    float denom;
    denom = (C2.Re * C2.Re + C2.Im * C2.Im);
    if (denom == 0)
    {
        hasil.Re = 0;
        hasil.Im = 0;
        return hasil;
    }
    else
    {
        hasil.Re = CMult.Re/denom;
        hasil.Im = CMult.Im/denom;
        return hasil;
    }
}

/* Operasi Lain Terhadap Type */

float AbsCOMPLEX(COMPLEX C){
    return sqrt(C.Re * C.Re + C.Im * C.Im);
}

COMPLEX ConjugateCOMPLEX(COMPLEX C){
    COMPLEX conj;
    conj.Re = C.Re;
    conj.Im = -C.Im;
    return conj;
}


/* Operator Relational*/
boolean CEQ(COMPLEX C1, COMPLEX C2){
    return (C1.Re == C2.Re && C1.Im == C2.Im);
}

boolean CNEQ(COMPLEX C1, COMPLEX C2){
    return (C1.Re != C2.Re || C1.Im != C2.Im);
}