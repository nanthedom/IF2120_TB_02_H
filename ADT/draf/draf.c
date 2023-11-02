#include <stdio.h>
#include "draf.h"

extern StackDraf SDraf;

void CreateDraf(Draf *D)
{
  DATETIME dt;
  BacaDATETIME(&dt);
  datetime(*D) = dt;
  text(*D) = currentWord;
}

void CreateEmptyDraft(StackDraf *S)
{
  Top(*S) = Nil;
}

boolean IsDraftEmpty(StackDraf S)
{
  return Top(S) == Nil;
}

boolean IsDraftFull(StackDraf S)
{
  return Top(S) == MaxEl - 1;
}

void PushDraft(StackDraf *S, infotype D)
{
  if (Top(*S) < MaxEl - 1)
  {
    Top(*S)++;
    InfoTop(*S) = D;
  }
}

void PopDraft(StackDraf *S, infotype *D)
{
  if (Top(*S) > Nil)
  {
    *D = InfoTop(*S);
    Top(*S)--;
  }
}

void DisplayDraf(StackDraf *S)
{
  printf("Ini draf terakhir anda:");
  printf("\n| ");
  TulisDATETIME(datetime(InfoTop(*S)));
  printf("\n| ");
  printWord(text(InfoTop(*S)));
  printf("\n");
}

void BuatDraf()
{
  Word currentText, op, hapus, simpan, terbit;
  strToWord("HAPUS", &hapus);
  strToWord("SIMPAN", &simpan);
  strToWord("TERBIT", &terbit);

  printf("Masukkan draf:\n");
  ReadWord();
  currentText = currentWord;
  printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
  ReadWord();
  op = currentWord;
  if (isKataEqual(op, hapus))
  {
    printf("Draf telah berhasil dihapus!\n");
  }
  else if (isKataEqual(op, simpan))
  {
    printf("Draf telah berhasil disimpan!\n");
  }
  else if (isKataEqual(op, terbit))
  {
    printf("Selamat! Draf kicauan telah berhasil diterbitkan!\n");
    printf("| ");
    printWord(currentText);
    printf("\n");
  }
}