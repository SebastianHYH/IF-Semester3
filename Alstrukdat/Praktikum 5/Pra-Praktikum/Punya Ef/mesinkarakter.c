#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean eop;

static FILE *pita;
static int retval;

void START(){
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

    pita = fopen("pitakar.txt", "r");
    ADV();
}

void ADV(){
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
   retval = fscanf(pita, "%c", &currentChar);
   eop = (currentChar == MARK);
   if (eop) {
      fclose(pita);
   }
    
}
