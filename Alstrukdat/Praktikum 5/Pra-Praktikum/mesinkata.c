/* Sebastian Hung Yansen */
/* 13523070 */
/* Pra-Praktikum mesinkata.c */
/* 17 Oktober 2024 */

#include <stdio.h>
#include "mesinkata.h"
//#include "mesinkarakter.c"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    while ((currentChar != MARK) && (currentChar != BLANK))
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }

    if (i > NMax)
    {
        currentWord.Length = NMax;
    }
    else
    {
        currentWord.Length = i;
    }
}

// int main()
// {
//     STARTWORD();
//     while (!EndWord)
//     {
//         printf("Kata: ");
//         for (int i = 0; i < currentWord.Length; i++)
//         {
//             printf("%c", currentWord.TabWord[i]);
//         }
//         printf("\n");
//         ADVWORD();
//     }
//     return 0;
// }