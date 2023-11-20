/* File: wordmachine.c */
/* Definisi Mesin Word: Model Akuisisi Versi I */
#include <stdio.h>
#include "../boolean/boolean.h"
#include "../charmachine/charmachine.h"
#include "wordmachine.h"
#include <stdlib.h>

Word currentWord;
boolean EndWord;

void IgnoreEnter()
{
    while (currentChar == ENTER)
    {
        ADV();
    }
}
void IgnoreCarriage()
{
    while (currentChar == CARRIAGE)
    {
        ADV();
    }
}
void IgnoreCarriageEnter()
{
    while ((currentChar == ENTER) | (currentChar == CARRIAGE))
    {
        ADV();
    }
}

void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void CreateWord(Word *w)
{
    w->TabWord = (char *)malloc(NMax * sizeof(char));
    w->Length = 0;
}

boolean containBlanks(Word w)
{
    int i = 0;
    boolean found = false;
    while (i < w.Length && !found)
    {
        if (w.TabWord[i] == BLANK)
        {
            found = true;
        }
        i++;
    }
    return found;
}

void ReadFromFile(char *str)
{
    startFile(str);
    IgnoreCarriageEnter();
    currentWord.TabWord = (char *)malloc(NMax * sizeof(char));
    if (currentChar == EOF)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordFile(1);
    }
}

void ReadWord()
{
    START();
    IgnoreCarriageEnter();
    currentWord.TabWord = (char *)malloc(NMax * sizeof(char));
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
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ReadLine(int n)
{
    Word EMPTY;
    CreateWord(&EMPTY);
    currentWord = EMPTY;
    if (currentChar != EOF)
    {
        EndWord = false;
        CopyWordFile(n);
    }
}

void ReadLineWithEnter(int n)
{
    Word EMPTY;
    CreateWord(&EMPTY);
    currentWord = EMPTY;
    if (currentChar != EOF)
    {
        EndWord = false;
        CopyWordFileWithEnter(n);
    }
}
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

void CopyWord()
{
    int i = 0, N = NMax;
    while (currentChar != MARK)
    {
        if (i < N)
        {
            currentWord.TabWord[i] = currentChar;
        }
        else
        {
            currentWord.TabWord = (char *)realloc(currentWord.TabWord, 2 * N * sizeof(char));
            N *= 2;
            currentWord.TabWord[i] = currentChar;
        }
        i++;
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
void CopyWordFile(int row)
{
    int i = 0, N = NMax, count = 0;
    while (count < row && currentChar != EOF)
    {
        if (i >= N)
        {
            currentWord.TabWord = (char *)realloc(currentWord.TabWord, 2 * N * sizeof(char));
            N *= 2;
        }
        if (currentChar != ENTER && currentChar != CARRIAGE)
        {
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        else if (currentChar == ENTER)
        {
            count++;
        }
        ADVFile();
    }
    currentWord.Length = i;
}

void CopyWordFileWithEnter(int row)
{
    int i = 0, N = NMax, count = 0;
    while (count < row && currentChar != EOF)
    {
        if (i >= N)
        {
            currentWord.TabWord = (char *)realloc(currentWord.TabWord, 2 * N * sizeof(char));
            N *= 2;
        }
        if (currentChar != CARRIAGE)
        {
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        if (currentChar == ENTER)
        {
            count++;
        }
        ADVFile();
    }
    currentWord.Length = i;
}

void printWord(Word word)
{
    int i;
    for (i = 0; i < word.Length; i++)
    {
        printf("%c", word.TabWord[i]);
    }
}

Word CopySubset(Word w, int n)
{
    Word result;
    CreateWord(&result);

    for (int i = 0; i < n; i++)
    {
        result.TabWord[i] = w.TabWord[i];
    }
    result.Length = n;
    return result;
}

void copy(Word w1, Word *w2)
{
    int i;
    for (i = 0; i < w1.Length; i++)
    {
        w2->TabWord[i] = w1.TabWord[i];
    }
    w2->Length = w1.Length;
}

boolean isKataEqual(Word w1, Word w2)
{
    if (w1.Length == w2.Length)
    {
        boolean eq = true;
        int i = 0;
        while (i < w1.Length && eq)
        {
            if (w1.TabWord[i] != w2.TabWord[i])
            {
                eq = false;
            }
            i++;
        }
        return eq;
    }
    return false;
}

void strToWord(char *s, Word *w)
{
    int i = 0, N = NMax;
    (*w).TabWord = (char *)malloc(NMax * sizeof(char));
    while (s[i] != '\0')
    {
        if (i < N)
        {
            w->TabWord[i] = s[i];
        }
        else
        {
            (*w).TabWord = (char *)realloc((*w).TabWord, 2 * N * sizeof(char));
            N *= 2;
            w->TabWord[i] = s[i];
        }
        i++;
    }
    w->Length = i;
}

boolean isNumerical(char c)
{
    int ic = (int)c;
    return (ic >= 48 && ic <= 57);
}

boolean isNumber(Word w)
{
    if (w.Length > 0)
    {
        boolean isNum = true;
        int i = 0;
        while (isNum && i < w.Length)
        {
            if (!isNumerical(w.TabWord[i]))
            {
                isNum = false;
            }
            i++;
        }
        return isNum;
    }
    return false;
}

int wordToInteger(Word w)
{
    int i;
    int n = 0;
    int j = 0;
    if (w.TabWord[j] == '-')
    {
        j++;
        for (i = j; i < w.Length; i++)
        {
            n = n * 10 + (w.TabWord[i] - '0');
        }
        n = n * (-1);
    }
    else
    {
        for (i = 0; i < w.Length; i++)
        {
            n = n * 10 + (w.TabWord[i] - '0');
        }
    }

    return n;
}

void wordToString(Word w, char **str)
{
    *str = (char *)malloc((w.Length + 1) * sizeof(char));
    int i;
    for (i = 0; i < w.Length; i++)
    {
        (*str)[i] = w.TabWord[i];
    }
    (*str)[i] = '\0';
}

Word concatWord(Word w1, Word w2)
{
    Word w;
    CreateWord(&w);
    w.Length = w1.Length + w2.Length;
    int i;
    for (i = 0; i < w1.Length; i++)
    {
        w.TabWord[i] = w1.TabWord[i];
        // printf("char : %c", w.TabWord[i]);
    }
    for (i = 0; i < w2.Length; i++)
    {
        w.TabWord[i + w1.Length] = w2.TabWord[i];
        // printf("char : %c", w.TabWord[i+w1.Length]);
    }
    return w;
}