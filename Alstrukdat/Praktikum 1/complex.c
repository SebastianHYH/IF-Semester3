#include "complex.h"
#include <stdio.h>


boolean IsCOMPLEXValid(float Re, float Im){
    return true;
}

/* Mengirim true jika Re dan Im valid untuk membentuk COMPLEX */
/* Dalam konteks kompleks, semua bilangan real adalah valid */
/* *** Konstruktor: Membentuk sebuah COMPLEX dari komponen-komponennya *** */
void CreateComplex(COMPLEX *C, float Re, float Im){
    (*C).Re = Re;
    (*C).Im = Im;
}
/* Membentuk sebuah COMPLEX dari komponen-komponennya */


void BacaCOMPLEX(COMPLEX *C)
{
    scanf("%f %f", &Real(*C), &Imag(*C));
}
/* I.S. : C tidak terdefinisi */
/* F.S. : C terdefinisi */
/* Proses : Membaca komponen Re dan Im dari pengguna */

void TulisCOMPLEX(COMPLEX C){
    if (Imag(C)>=0){
        printf("%.2f+%.2fi\n", Real(C), Imag(C));
    }
    else{
        printf("%.2f%.2fi\n", Real(C), Imag(C));
    }
}
/* I.S. : C sembarang */
/* F.S. : Nilai C ditulis dengan format "a + bi" atau "a - bi" (tanpa spasi) dan diakhiri newline */
/* Proses : Menulis nilai Re dan Im ke layar */


COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX C3;
    Real(C3) = Real(C1)+Real(C2);
    Imag(C3) = Imag(C1)+Imag(C2);
    return C3;
}
/* Mengirim hasil penjumlahan C1 + C2 */

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX C3;
    Real(C3) = Real(C1)-Real(C2);
    Imag(C3) = Imag(C1)-Imag(C2);
    return C3;
}
/* Mengirim hasil pengurangan C1 - C2 */

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX C3;
    Real(C3) = (Real(C1)*Real(C2))-(Imag(C1)*Imag(C2));
    Imag(C3) = (Real(C1)*Imag(C2))+(Imag(C1)*Real(C2));
    return C3;
}
/* Mengirim hasil perkalian C1 * C2 */
/* Rumus: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i */

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX C3;
    Imag(C2) = Imag(C2)*(-1);
    COMPLEX C4;
    C4 = MultiplyCOMPLEX(C1,C2);
    
    float denom;
    denom = (pow(Real(C2),2) + pow(Imag(C2),2));
    if (denom==0){
        Real(C3) = 0;
        Imag(C3) = 0;
        return C3;
    } else {
        Real(C3) = Real(C4)/denom;
        Imag(C3) = Imag(C4)/denom;
        return C3;
    }
}
/* Mengirim hasil pembagian C1 / C2 */
/* Rumus: (a + bi) / (c + di) = [(a + bi)(c - di)] / (c^2 + d^2) */
/* Jika denominator pecahan bernilai 0, maka kembalikan nilai 0+0i*/

float AbsCOMPLEX(COMPLEX C){
    return sqrt(pow(Real(C),2) + pow(Imag(C),2));
}
/* Mengirim nilai absolut (modulus) dari C */
/* Rumus: |C| = sqrt(Re^2 + Im^2) */

COMPLEX ConjugateCOMPLEX(COMPLEX C){
    Imag(C) = Imag(C)*(-1);
    return C;
}
/* Mengirim hasil konjugasi dari C */
/* Rumus: Conj(C) = Re - i*Im */
// a - i*b
// a + bi

/* *** Kelompok Operator Relational *** */
boolean CEQ(COMPLEX C1, COMPLEX C2){
    return Real(C1)==Real(C2) && Imag(C1)==Imag(C2);
}
/* Mengirimkan true jika C1 = C2 (Re dan Im sama) */

boolean CNEQ(COMPLEX C1, COMPLEX C2){
    return Real(C1)!=Real(C2) || Imag(C1)!=Imag(C2);
}
/* Mengirimkan true jika C1 tidak sama dengan C2 */
