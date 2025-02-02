/* Sebastian Hung Yansen */
/* 13523070 */
/* 26 September 2024 */

#include "fraction.h"
#include <stdio.h>

/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsFRACTIONValid(int N, int D)
/* Mengirim TRUE jika pecahan valid */
{
    return D != 0;
}

/* *** Konstruktor: Membentuk FRACTION F dari komponen-komponennya *** */
void CreateFRACTION(FRACTION *F, int N, int R)
/* Membentuk sebuah FRACTION yang valid */
/* Prekondisi : N, R valid */
{
    (*F).N = N;
    (*F).D = R;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadFRACTION(FRACTION *F)
/**
 * I.S. : F tidak terdefinisi
 * F.S. : F terdefinisi dan merupakan FRACTION yang valid
 * Proses : Mengulangi membaca komponen N, R sehingga membentuk F
 *  - Pembacaan dilakukan dengan mengetikkan komponen N, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika FRACTION tidak valid, maka berikan pesan: "FRACTION tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat FRACTION yang valid.
 */
{
    int N, R;
    while (true)
    {
        scanf ("%d %d", &N, &R);
        if (!IsFRACTIONValid(N, R))
        {
            printf("FRACTION tidak valid\n");
        }
        else
        {
            CreateFRACTION(F, N, R);
            break;
        }
    }
}

void WriteFRACTION(FRACTION F)
/**
 * I.S. : F sembarang
 * F.S. : Nilai F ditulis dengan format "N/R"
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 * NOTE: hasil dalam bentuk paling sederhana
 */
{
    SimplifyFRACTION(F);
    printf("%d/%d", F.N, F.D);
}
/* ***************************************************************** */
/* KELOMPOK OPERASI DASAR TERHADAP TYPE                              */
/* ***************************************************************** */
/* NOTE: untuk hasil FRACTION = 0, maka kembalikan 0/1 */

FRACTION AddFRACTION(FRACTION F1, FRACTION F2)
/* Mengirim hasil penjumlahan F1 + F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    int R1 = F1.D;
    int R2 = F2.D;
    FRACTION F;
    if (F1.D != F2.D)
    {
        F1.D = F1.D * R2;
        F1.N = F1.N * R2;
        F2.D = F2.D * R1;
        F2.N = F2.N * R1;
    }
    // Else lanjut kode
    F.N = F1.N + F2.N;
    if (F.N == 0)
    {
        F.D = 1;
    }
    else
    {
        F.D = F1.D;
    }
    return SimplifyFRACTION(F);
}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2)
/* Mengirim hasil pengurangan F1 - F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    int R1 = F1.D;
    int R2 = F2.D;
    FRACTION F;
    if (F1.D != F2.D)
    {
        F1.D = F1.D * R2;
        F1.N = F1.N * R2;
        F2.D = F2.D * R1;
        F2.N = F2.N * R1;
    }
    // Else lanjut kode
    F.N = F1.N - F2.N;
    if (F.N == 0)
    {
        F.D = 1;
    }
    else
    {
        F.D = F1.D;
    }
    return SimplifyFRACTION(F);
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2)
/* Mengirim hasil perkalian F1 * F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    FRACTION F;
    F.N = F1.N * F2.N;
    F.D = F1.D * F2.D;
    if (F.N == 0)
    {
        F.D = 1;
    }
    // else
    return SimplifyFRACTION(F);
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2)
/* Mengirim hasil pembagian F1 / F2 */
/* Prekondisi: F2 tidak nol */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    FRACTION F;
    F.N = F1.N * F2.D;
    F.D = F1.D * F2.N;
    if (F.N == 0)
    {
        F.D = 1;
    }
    // else
    return SimplifyFRACTION(F);
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1)
/* Mengirim hasil perkalian n * F1 */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    F1.N = F1.N * n;
    F1.D = F1.D;
    return SimplifyFRACTION(F1);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
FRACTION SimplifyFRACTION(FRACTION F)
/* Mengembalikan FRACTION dalam bentuk sederhana */
/* NOTE: pastikan hanya numerator yang memiliki nilai negatif */
{
    if (F.D < 0) // Memeriksa negatif
    {
        F.D = F.D * -1;
        F.N = F.N * -1;
    }
    // else
    int gcd = GCD(F.N, F.D);
    F.N = F.N / gcd;
    F.D = F.D / gcd;
    return F;
}

int GCD(int a, int b)
/* Pembagi terbesar dari a dan b */
{
    if (b == 0)
    {
        return a;
    }
    else
        return GCD(b, a % b);
}

float ToDecimal(FRACTION F)
/* Mengonversi FRACTION ke bentuk desimal */
{
    return (float) F.N / F.D;
}
