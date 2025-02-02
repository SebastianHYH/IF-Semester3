/* Sebastian Hung Yansen */
/* 13523070 */
/* Praktikum 5 putar.c */
/* 22 Oktober 2024 */

#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "boolean.h"

int main()
{
    int wordPos = 1;
    int i;
    STARTWORD();
    for (int i = currentWord.Length - 1; i >= 0; i--)
    {
        printf("%c", currentWord.TabWord[i]);
    }
    ADVWORD();
    while (!EndWord)
    {
        printf(" ");
        if (wordPos % 2 == 0)
        {
            for (i = currentWord.Length - 1; i >= 0; i--)
            {
                printf("%c", currentWord.TabWord[i]);
            }
            ADVWORD();
        }
        else //wordPos % 2 != 0
        {
            for (i = 0; i < currentWord.Length; i++)
            {
                printf("%c", currentWord.TabWord[i]);
            }
            ADVWORD();
        }
        wordPos += 1;
    }
    printf("\n");
    return 0;
}