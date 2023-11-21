#include <stdio.h>
#include "draf.h"
#include "../../ADT/datetime/datetime.h"

extern StackDraf SDraf;
extern Draf draf;
extern ListKicauan ListTweet;
extern int currentIdTweet;
extern Pengguna *currentUser;

void CreateDraf(Draf *D)
{
  DATETIME dt;
  BacaDATETIME(&dt);
  datetimeDraf(*D) = dt;
  textDraf(*D) = currentWord;
  authorDraf(*D) = Nama(*currentUser);
}

void CreateDrafFile(Draf *D, Word nama, Word text, DATETIME dt)
{
  datetimeDraf(*D) = dt;
  textDraf(*D) = text;
  authorDraf(*D) = nama;
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
  TulisDATETIME(datetimeDraf(InfoTop(*S)));
  printf("\n| ");
  printWord(textDraf(InfoTop(*S)));
  printf("\n");
}

void HapusDraf()
{
  Draf topDraf;
  PopDraft(&SDraf, &topDraf);
}

void SimpanDraf(Word teks)
{
  CreateDraf(&draf);
  textDraf(draf) = teks;
  PushDraft(&SDraf, draf);
}

void TerbitDraf()
{
  Kicauan Kicau;
  currentIdTweet++;
  DrafToKicau(InfoTop(SDraf), &Kicau);
  insertByTime(Kicau);
  printf("Selamat! Draf kicauan telah berhasil diterbitkan!\n");
  printf("| ID = %d", idKicau(Kicau));
  printf("\n| ");
  printWord(authorKicau(Kicau));
  printf("\n| ");
  TulisDATETIME(datetimeKicau(Kicau));
  printf("\n| ");
  printWord(textKicau(Kicau));
  printf("\n| Disukai: %d\n", likeKicau(Kicau));
  printf("\n");
}

void DrafToKicau(Draf D, Kicauan *Kicau)
{
  idKicau(*Kicau) = currentIdTweet;
  textKicau(*Kicau) = textDraf(D);
  datetimeKicau(*Kicau) = datetimeDraf(D);
  authorKicau(*Kicau) = authorDraf(D);
  likeKicau(*Kicau) = 0;
  CreateListUtas(&utasUtama(*Kicau));
}

void BuatDraf()
{
  Word currentText, hapus, simpan, terbit;
  strToWord("HAPUS", &hapus);
  strToWord("SIMPAN", &simpan);
  strToWord("TERBIT", &terbit);

  printf("Masukkan draf:\n");
  ReadWord();
  currentText = currentWord;
  printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n>> ");
  ReadWord();
  if (isKataEqual(currentWord, hapus))
  {
    printf("\nDraf telah berhasil dihapus!\n");
  }
  else if (isKataEqual(currentWord, simpan))
  {
    SimpanDraf(currentText);
    printf("\nDraf telah berhasil disimpan!\n");
  }
  else if (isKataEqual(currentWord, terbit))
  {
    SimpanDraf(currentText);
    TerbitDraf();
    Draf tempDraf;
    PopDraft(&SDraf, &tempDraf);
  }
}

void LihatDraf()
{
  if (IsDraftEmpty(SDraf))
  {
    printf("\nYah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
  }
  else
  {
    Word hapus, simpan, terbit, kembali, ubah;
    strToWord("HAPUS", &hapus);
    strToWord("SIMPAN", &simpan);
    strToWord("TERBIT", &terbit);
    strToWord("KEMBALI", &kembali);
    strToWord("UBAH", &ubah);

    printf("\nIni draf terakhir anda:");
    printf("\n| ");
    TulisDATETIME(datetimeDraf(InfoTop(SDraf)));
    printf("\n| ");
    printWord(textDraf(InfoTop(SDraf)));
    printf("\n");

    printf("\nApakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
    ReadWord();

    if (!isKataEqual(currentWord, kembali))
    {
      if (isKataEqual(currentWord, hapus))
      {
        HapusDraf();
        printf("\nDraf telah berhasil dihapus!\n");
      }
      else if (isKataEqual(currentWord, ubah))
      {
        Word currentText;

        printf("\nMasukkan draf yang baru:\n");
        ReadWord();
        currentText = currentWord;
        printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n>> ");
        ReadWord();
        if (isKataEqual(currentWord, hapus))
        {
          HapusDraf();
          printf("\nDraf telah berhasil dihapus!\n");
        }
        else if (isKataEqual(currentWord, simpan))
        {
          // Draf topDraf;
          // PopDraft(&SDraf, &topDraf);
          // textDraf(topDraf) = currentText;
          // PushDraft(&SDraf, topDraf);
          SimpanDraf(currentText);
          printf("\nDraf telah berhasil disimpan!\n");
        }
        else if (isKataEqual(currentWord, terbit))
        {
          // Draf topDraf, tempDraf;
          // PopDraft(&SDraf, &topDraf);
          // textDraf(topDraf) = currentText;
          // PushDraft(&SDraf, topDraf);
          SimpanDraf(currentText);
          TerbitDraf();
          Draf tempDraf;
          PopDraft(&SDraf, &tempDraf);
        }
      }
      else if (isKataEqual(currentWord, terbit))
      {
        TerbitDraf();
        Draf tempDraf;
        PopDraft(&SDraf, &tempDraf);
      }
    }
  }
}

int CountDraftUser(StackDraf SDraf, Word nama)
{
  int countDraf = 0;
  Draf top;
  StackDraf temp;
  CreateEmptyDraft(&temp);
  while (!IsDraftEmpty(SDraf))
  {
    PopDraft(&SDraf, &top);
    if (isKataEqual(authorDraf(top), nama))
    {
      countDraf++;
    }
    PushDraft(&temp, top);
  }
  while (!IsDraftEmpty(temp))
  {
    PopDraft(&temp, &top);
    PushDraft(&SDraf, top);
  }
  return countDraf;
}