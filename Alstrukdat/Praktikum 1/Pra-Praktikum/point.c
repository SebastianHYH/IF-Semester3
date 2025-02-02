#include <stdio.h>
#include "point.h"
#include <math.h>

void CreatePoint (POINT * P, float X, float Y) 
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    (*P).X = X;
    (*P).Y = Y;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 

void BacaPOINT (POINT * P) 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
{
    scanf("%f %f", &(*P).X, &(*P).Y);
}

void TulisPOINT (POINT P) 
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
{
    printf("(%.2f,%.2f)", P.X, P.Y);
}

boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    return (P1.X == P2.X && P1.Y == P2.Y);
}

boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
    return (P1.X != P2.X || P1.Y != P2.Y);
}

/* *** Kelompok menentukan di mana P berada *** */

boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
    return (P.X == 0 && P.Y == 0);
}

boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
    return (P.Y == 0);
}

boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
    return (P.X == 0);
}

int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
    if (P.X > 0 && P.Y > 0) 
    {
        return 1;
    }
    else if (P.X < 0 && P.Y > 0)
    {
        return 2;
    }
    else if (P.X < 0 && P.Y < 0)
    {
        return 3;
    }
    else /* P.X > 0 && P.Y < 0 */
    {
        return 4;
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */ 
{
    P.X++;
    return P;
}   

POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
    P.Y++;
    return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
    P.X = P.X + deltaX;
    P.Y = P.Y + deltaY;
    return P;
}

POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
    if (SbX == true)
    {
        P.Y = P.Y * -1;
        return P;
    }
    else /* SbX == False */
    {
        P.X = P.X * -1;
        return P;
    }
}

float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
    return sqrt((P.X * P.X) + (P.Y * P.Y));
}

float Panjang (POINT P1, POINT P2)
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
{
    float absis;
    float ordinat;
    absis = P2.X - P1.X;
    ordinat = P2.Y - P1.Y;
    return sqrt((absis * absis) + (ordinat * ordinat));
}

void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
    (*P).X = (*P).X + deltaX;
    (*P).Y = (*P).Y + deltaY;
}

void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
    (*P).Y = 0;
}

void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
    (*P).X = 0;
}

void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
    if (SbX == true)
    {
        (*P).Y = (*P).Y * -1;
    }
    else /* SbX = False */
    {
        (*P).X = (*P).X * -1;
    }
}

void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
{
    float pi =  4 * atan(1);
    float rad = -1 * Sudut * pi / 180;
    CreatePoint(P, (*P).X * cos(rad) - (*P).Y * sin(rad), (*P).X * sin(rad) + (*P).Y * cos(rad));
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2)
/* I.S. P1 dan P2 terdefinisi */
/* Prekondisi: dijamin a dan b merupaka bilangan bertipe integer */
/* F.S. Dibentuk sebuah persamaan garis y = ax + b yang memenuhi untuk P1 dan P2 */
/* Keluarkan nilai a dan b */
/* Output a dan b tercetak di layar sebagai bilangan bertipe integer dengan format "(a,b)" */
{
    int a, b;
    a = (P2.Y - P1.Y) / (P2.X - P1.X);
    b = P1.Y - (a * P1.X);

    printf("(%f,%f)", &a, &b);
}