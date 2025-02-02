/* Sebastian Hung Yansen */
/* 13523070 */
/* 6 Oktober 2024 */
/* Pra-Praktikum 3 */

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    BUFFER(*l) = (int *)malloc(capacity * sizeof(int)); // Alokasi memori
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}

void dealocateList(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(BUFFER(*l)); // Dealokasi memori
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
    return IDX_MIN;
}
IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return NEFF(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i >= IDX_MIN && i < CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
    return (i >= IDX_MIN && i < NEFF(l));
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
    return (NEFF(l) == 0);
}
/* *** Test list penuh *** */
boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    return (NEFF(l) == CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
    int N, i;
    do
    {
        scanf("%d", &N);
    } while (N < 0 || N > CAPACITY(*l));
    NEFF(*l) = N;

    // Pembacaan elemen
    if (N > 0)
    {
        for (i = 0; i < N; i++)
        {
            scanf("%d", &ELMT(*l, i));
        }
    }
}
void printList(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
    int i;
    if (isEmpty(l))
    {
        printf("[]");
    }
    else
    {
        printf("[");
        printf("%d", ELMT(l, 0));
        for (i = 1; i < NEFF(l); i++)
        {
            printf(",%d", ELMT(l, i));
        }
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
    ListDin l;
    int i;
    CreateListDin(&l, CAPACITY(l1));
    NEFF(l) = NEFF(l1);
    for (i = 0; i < listLength(l1); i++)
    {
        if (plus)
        {
            ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
        }
        else // !plus
        {
            ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return l;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
    int i = 0;
    if (listLength(l1) == listLength(l2))
    {
        while (ELMT(l1, i) == ELMT(l2, i) && i != listLength(l1))
        {
            i++;
        }
        return (i == listLength(l1));
    }
    else
    {
        return false;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
    IdxType i = 0;
    boolean found = false;
    while (!found && i < NEFF(l))
    {
        if (ELMT(l, i) == val)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }

    if (found)
    {
        return i;
    }
    else
    {
        return IDX_UNDEF;
    }
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
    int i;
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    for (i = 1; i < NEFF(l); i++)
    {
        if (ELMT(l, i) > *max)
        {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min)
        {
            *min = ELMT(l, i);
        }
    }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
{
    int i;
    dealocateList(lOut);
    CreateListDin(lOut, CAPACITY(lIn));
    for (i = 0; i < NEFF(lIn); i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
    NEFF(*lOut) = NEFF(lIn);
}
ElType sumList(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
    int i, sum = 0;
    if (isEmpty(l))
    {
        return 0;
    }
    else
    {
        for (i = 0; i < NEFF(l); i++)
        {
            sum += ELMT(l, i);
        }
        return sum;
    }

}
int countVal(ListDin l, ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
    int i;
    int count = 0;
    for (i = 0; i < listLength(l); i++)
    {
        if (ELMT(l, i) == val)
        {
            count++;
        }
    }
    return count;
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    int i, j, temp;
    if (asc)
    {
        for (i = 0; i < NEFF(*l) - 1; i++)
        {
            for (j = i + 1; j < NEFF(*l); j++)
            {
                if (ELMT(*l, i) > ELMT(*l, j))
                {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
    }
    else // !asc
    {
        for (i = 0; i < NEFF(*l) - 1; i++)
        {
            for (j = i + 1; j < NEFF(*l); j++)
            {
                if (ELMT(*l, i) < ELMT(*l, j))
                {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l)++;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMT(*l, NEFF(*l) - 1);
    NEFF(*l)--;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    int i;
    int *newBuffer = (int *)malloc((CAPACITY(*l) + num) * sizeof(int));
    for (i = 0; i < NEFF(*l); i++)
    {
        newBuffer[i] = ELMT(*l, i);
    }
    free(BUFFER(*l));
    BUFFER(*l) = newBuffer;
    CAPACITY(*l) += num;
}

void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    int i;
    int *newBuffer = (int *)malloc((CAPACITY(*l) - num) * sizeof(int));
    for (i = 0; i < NEFF(*l); i++)
    {
        newBuffer[i] = ELMT(*l, i);
    }
    free(BUFFER(*l));
    BUFFER(*l) = newBuffer;
    CAPACITY(*l) -= num;
}

void compressList(ListDin *l)
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
{
    int i;
    int *newBuffer = (int *)malloc(NEFF(*l) * sizeof(int));
    for (i = 0; i < NEFF(*l); i++)
    {
        newBuffer[i] = ELMT(*l, i);
    }
    free(BUFFER(*l));
    BUFFER(*l) = newBuffer;
    CAPACITY(*l) = NEFF(*l);
}
/*
int main()
{
    ListDin l1, l2;
    ElType max, min;
    int N, val;
    boolean plus;
    CreateListDin(&l1, 10);
    CreateListDin(&l2, 10);

    readList(&l1);
    readList(&l2);
    printList(l1);
    printList(l2);

    extremeValues(l1, &max, &min);
    printf("%d %d\n", max, min);

    copyList(l1, &l2);
    printList(l2);

    printf("%d\n", sumList(l1));
    scanf("%d", &val);
    printf("%d\n", countVal(l1, val));

    sort(&l1, true);
    printList(l1);
    sort(&l1, false);
    printList(l1);

    // scanf("%d", &plus);
    printList(plusMinusList(l1, l2, true));

    insertLast(&l1, 10);
    printList(l1);
    deleteLast(&l1, &val);
    printList(l1);

    scanf("%d", &N);
    expandList(&l1, N);
    printList(l1);
    shrinkList(&l1, N);
    printList(l1);
    compressList(&l1);
    printList(l1);

    dealocateList(&l1);
    dealocateList(&l2);
    return 0;
} */