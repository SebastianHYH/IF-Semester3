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
    hasil.Re = (C1.Re * C2.Re) - (C1.Im * C2.Im);
    hasil.Im = (C1.Re * C2.Im) + (C1.Im * C2.Re);
    return hasil;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX C3;
    C2.Im = C2.Im*(-1);
    COMPLEX C4;
    C4 = MultiplyCOMPLEX(C1,C2);
    
    float denom;
    denom = (pow(C2.Re,2) + pow(C2.Im,2));
    if (denom==0){
        C3.Re = 0;
        C3.Im = 0;
        return C3;
    } else {
        C3.Re = C4.Re/denom;
        C3.Im = C4.Im/denom;
        return C3;
    }
}

/* Operasi Lain Terhadap Type */

float AbsCOMPLEX(COMPLEX C){
    return sqrt((C.Re * C.Re) + (C.Im * C.Im));
}

COMPLEX ConjugateCOMPLEX(COMPLEX C){
    C.Im = C.Im*(-1);
    return C;
}


/* Operator Relational*/
boolean CEQ(COMPLEX C1, COMPLEX C2){
    return (C1.Re == C2.Re && C1.Im == C2.Im);
}

boolean CNEQ(COMPLEX C1, COMPLEX C2){
    return (C1.Re != C2.Re || C1.Im != C2.Im);
}