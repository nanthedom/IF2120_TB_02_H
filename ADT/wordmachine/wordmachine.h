/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __WORDMACHINE_H__
#define __WORDMACHINE_H__

#include "../boolean/boolean.h"
#include "../charmachine/charmachine.h"

#define NMax 64
#define BLANK ' '
#define ENTER '\n'
#define CARRIAGE '\r'

typedef struct
{
   char *TabWord; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;

void IgnoreEnter();
void IgnoreCarriage();
void IgnoreCarriageEnter();
void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void CreateWord(Word *w);

boolean containBlanks(Word w);

void ReadWord();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

// void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void ReadFromFile(char *str);
// membaca file
void ReadLine(int n);
void ReadLineWithEnter(int n);
void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void CopyWordFile();
void CopyWordFileWithEnter();
void printWord(Word word);
Word CopySubset(Word w, int n);
void copy(Word w1, Word *w2);
boolean isKataEqual(Word w1, Word w2);
void strToWord(char *s, Word *w);
boolean isNumerical(char c);
boolean isNumber(Word w);
int wordToInteger(Word w);
<<<<<<< HEAD
#endif
=======
void wordToString(Word w, char** str);
Word concatWord(Word w1, Word w2);
#endif
>>>>>>> c585cc8ada50f50e9e7d46e6d2e370bc34f8c4fa
