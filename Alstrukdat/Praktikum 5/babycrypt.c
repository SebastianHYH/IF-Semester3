#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "boolean.h"

static char *s[52] = {"a", "b", "c", "d", "e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","a", "b", "c", "d", "e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
static char *c[52] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

Word lowercase;
Word uppercase;

int wordToNum(Word word)
{
    int num = 0;
    for (int i = 0; i < word.Length; i++) {
        num = num * 10 + (word.TabWord[i] - '0');
    }
    return num % 26;
}

int main ()
{
    int i, shift, j;
    char wordAfterShift;
    STARTWORD();
    // Check jika angka 26 atau 0 sehingga tidak ada shift
    shift = wordToNum(currentWord);
    if (shift == 0)
    {
        ADVWORD();
        for (i = 0; i < currentWord.Length; i++)
        {
            printf("%c", currentWord.TabWord[i]);
        }
        ADVWORD();
        while (!EndWord)
        {
            printf(" ");
            for (i = 0; i < currentWord.Length; i++)
            {
                printf("%c", currentWord.TabWord[i]);
            }
            ADVWORD();
        }
    }
    // Jika angka selain 26 :(
    else
    {
        ADVWORD();
        for (i = 0; i < currentWord.Length; i++)
        {
            if (currentWord.TabWord[i] >= 'A' && currentWord.TabWord[i] <= 'Z') {
                wordAfterShift = (currentWord.TabWord[i] - 'A' - shift + 26) % 26 + 'A';
            } else if (currentWord.TabWord[i] >= 'a' && currentWord.TabWord[i] <= 'z') {
                wordAfterShift = (currentWord.TabWord[i] - 'a' - shift + 26) % 26 + 'a';
            } else {
                wordAfterShift = currentWord.TabWord[i];
            }
            printf("%c", wordAfterShift);
        }
        ADVWORD();
        while (!EndWord)
        {
            printf(" ");
            for (i = 0; i < currentWord.Length; i++)
            {
                if (currentWord.TabWord[i] >= 'A' && currentWord.TabWord[i] <= 'Z') {
                    wordAfterShift = (currentWord.TabWord[i] - 'A' - shift + 26) % 26 + 'A';
                } else if (currentWord.TabWord[i] >= 'a' && currentWord.TabWord[i] <= 'z') {
                    wordAfterShift = (currentWord.TabWord[i] - 'a' - shift + 26) % 26 + 'a';
                } else {
                    wordAfterShift = currentWord.TabWord[i];
                }
                printf("%c", wordAfterShift);
            }
            ADVWORD();
        }
    }
    printf("\n");
    return 0;
}