/* File: wordmachine.c */
/* Definisi Mesin Word: Model Akuisisi Versi I */
#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

Word currentWord;
boolean EndWord;

void IgnoreBlanks(){
    while(currentChar == BLANK){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(){
    START();
    IgnoreBlanks();
    if(currentChar == MARK){
        EndWord = true;
    } else{
        EndWord = false;
        CopyWord();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

// void ADVWORD(){
//     IgnoreBlanks();
//     if(currentChar == MARK){
//         EndWord = true;
//     } else{
//         CopyWord();
//     }
//     // IgnoreBlanks();
// }
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord(){
    int i = 0;
    while (currentChar != MARK){
        if(i < NMax){
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        ADV();
    }
    currentWord.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
   printf("\n");
}

void copy(Word w1, Word *w2){
    int i;
    for(i = 0; i < w1.Length; i++){
        w2->TabWord[i] = w1.TabWord[i];
    }
    w2->Length = w1.Length;
}