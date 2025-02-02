/* Sebastian Hung Yansen */
/* 13523070 */
/* 26 September 2024 */

#include "circle.h"
#include <stdio.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsCIRCLEValid(float X, float Y, float R)
/* Mengirim TRUE jika X, Y, R dapat membentuk Lingkaran C yang valid */
{
    return (R > 0);
}
/* *** Konstruktor: Membentuk Lingkaran C dari titik pusat dan radius *** */
void CreateCIRCLE(CIRCLE *C, float X, float Y, float R)
/* Membentuk sebuah CIRCLE dari komponen-komponen yang valid */
/* Prekondisi : X, Y, R, valid */
{
    if (IsCIRCLEValid(X, Y, R))
    {
        (*C).CENTER.X = X;
        (*C).CENTER.Y = Y;
        (*C).R = R;
    }
}
/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadCIRCLE(CIRCLE *C)
/**
 * I.S. : C tidak terdefinisi
 * F.S. : C terdefinisi dan merupakan CIRCLE yang valid
 * Proses : Mengulangi membaca komponen X, Y, R sehingga membentuk C
 *  - Pembacaan dilakukan dengan mengetikkan komponen X, Y, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika CIRCLE tidak valid, maka berikan pesan: "CIRCLE tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat CIRCLE yang valid.
 */
{
    float X, Y, R;
    while (true)
    {
        scanf ("%f %f %f", &X, &Y, &R);
        if (!IsCIRCLEValid(X, Y, R))
        {
            printf("CIRCLE tidak valid\n");
        }
        else
        {
            CreateCIRCLE(C, X, Y, R);
            break;
        }
    }
}

void WriteCIRCLE(CIRCLE C)
/**
 * I.S. : C sembarang
 * F.S. : Nilai C ditulis dengan format "P(X,Y) r=R", ex: P(1,1) r=5
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 */
{
    printf("P(%.2f,%.2f) r=%.2f", C.CENTER.X, C.CENTER.Y, C.R);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI GEOMETRI TERHADAP TYPE                           */
/* ***************************************************************** */
float Circumference(CIRCLE C)
/* Menghitung keliling lingkaran: K = 2 * π * r, π = 3.14 */
{
    float pi =  3.14;
    return (2 * pi * C.R);
}

float Area(CIRCLE C)
/* Menghitung luas lingkaran: A = π * r^2, π = 3.14 */
{
    float pi =  3.14;
    return (pi * C.R * C.R);
}

/*
/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P)
/* Mengirim true jika titik P berada di dalam lingkaran C */
{
    float distanceSquared = (P.X - C.CENTER.X) * (P.X - C.CENTER.X) + (P.Y - C.CENTER.Y) * (P.Y - C.CENTER.Y);
    return distanceSquared < (C.R * C.R);
}

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P)
/* Mengirim true jika titik P berada di tepi lingkaran C */
/* HINT: Gunakan toleransi kecil untuk komparasi float */
{
    float distanceSquared = (P.X - C.CENTER.X) * (P.X - C.CENTER.X) + (P.Y - C.CENTER.Y) * (P.Y - C.CENTER.Y);
    return fabs(distanceSquared - (C.R * C.R)) < 1e-6; //
}

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2)
/* Mengirim true jika C1 di dalam C2 atau C2 di dalam C1 */
/* NOTE: Tidak berpotongan/ bersinggungan */
{
    float distance = sqrt((C1.CENTER.X - C2.CENTER.X) * (C1.CENTER.X - C2.CENTER.X) + (C1.CENTER.Y - C2.CENTER.Y) * (C1.CENTER.Y - C2.CENTER.Y));
    return distance + C1.R < C2.R || distance + C2.R < C1.R;
}
boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2)
/* Mengirim true jika C1 bersinggungan di 1 titik dengan C2 */
/**
 * HINT: Terdapat 2 Kemungkinan:
 *  1. Bersinggungan dalam
 *  2. Bersinggungan luar
 */
{
    float distance = sqrt((C1.CENTER.X - C2.CENTER.X) * (C1.CENTER.X - C2.CENTER.X) + (C1.CENTER.Y - C2.CENTER.Y) * (C1.CENTER.Y - C2.CENTER.Y));
    return fabs(distance - (C1.R + C2.R)) < 1e-6 || fabs(distance - fabs(C1.R - C2.R)) < 1e-6;
}
boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2)
/* Mengirim true jika C1 berpotongan di 2 titik dengan C2 */
{
    float distance = sqrt((C1.CENTER.X - C2.CENTER.X) * (C1.CENTER.X - C2.CENTER.X) + (C1.CENTER.Y - C2.CENTER.Y) * (C1.CENTER.Y - C2.CENTER.Y));
    return fabs(C1.R - C2.R) < distance && distance < (C1.R + C2.R);
}
/* ***************************************************************** */