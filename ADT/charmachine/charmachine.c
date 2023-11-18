/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "charmachine.h"
#include <stdio.h>
#include <stdlib.h>
#include "../boolean/boolean.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void startFile(char *str){
       pita = fopen(str, "r");
       if(pita == NULL){
              printf("File tidak ditemukan. Exiting....\n");
              exit(0);
       }
       ADVFile();
}

void ADVFile(){
       retval = fscanf(pita, "%c", &currentChar);
       EOP = currentChar == EOF;
}


void ADVinFile(){
       retval = fscanf(pita, "%c", &currentChar);
       EOP = currentChar == '\n';
}

void START()
{
       /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
                 Jika currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       pita = stdin;
       ADV();
}

void ADV()
{
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentChar, currentChar != MARK
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
                 currentChar mungkin = MARK.
                       Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       retval = fscanf(pita, "%c", &currentChar);
       EOP = (currentChar == MARK);
       // if (EOP)
       // {
       //        pita = NULL;
       // }
}
