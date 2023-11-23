#include <stdio.h>
#include "draf.h"
#include "../../ADT/datetime/datetime.h"

extern ListDraf ListStackDraf;
extern StackDraf SDraf;
extern Draf draf;
extern ListKicauan ListTweet;
extern int currentIdTweet;
extern Pengguna *currentUser;
extern ListPengguna ListUser;

void CreateListDraf(ListDraf *l)
{
  int i;
  for (i = 0; i < CAPACITY; i++)
  {
    StackDraf S;
    CreateEmptyDraft(&S);
    ELMTDraf(*l, i) = S;
  }
}

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

void DisplayDraf(StackDraf S)
{
  printf("\nIni draf terakhir anda:");
  printf("\n| ");
  TulisDATETIME(datetimeDraf(InfoTop(S)));
  printf("\n| ");
  printWord(textDraf(InfoTop(S)));
  printf("\n");
}

void HapusDraf(StackDraf *S)
{
  Draf topDraf;
  PopDraft(S, &topDraf);
}

void SimpanDraf(StackDraf *S, Word teks)
{
  CreateDraf(&draf);
  textDraf(draf) = teks;
  PushDraft(S, draf);
}

void TerbitDraf(StackDraf *S)
{
  Kicauan Kicau;
  currentIdTweet++;
  DrafToKicau(InfoTop(*S), &Kicau);
  insertByTime(Kicau);
  printf("\nSelamat! Draf kicauan telah berhasil diterbitkan!\n");
  printf("| ID = %d", idKicau(Kicau));
  printf("\n| ");
  printWord(authorKicau(Kicau));
  printf("\n| ");
  TulisDATETIME(datetimeKicau(Kicau));
  printf("\n| ");
  printWord(textKicau(Kicau));
  printf("\n| Disukai: %d\n", likeKicau(Kicau));
  printf("\n\n");
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

  int index = searchIdxStackPengguna(Nama(*currentUser));
  StackDraf S = ELMTDraf(ListStackDraf, index);

  printf("\nMasukkan draf:\n");
  ReadWord();
  currentText = currentWord;
  printf("\nApakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
  ReadWord();

  if (isKataEqual(currentWord, hapus))
  {
    printf("\nDraf telah berhasil dihapus!\n");
  }
  else if (isKataEqual(currentWord, simpan))
  {
    SimpanDraf(&S, currentText);
    printf("\nDraf telah berhasil disimpan!\n");
  }
  else if (isKataEqual(currentWord, terbit))
  {
    SimpanDraf(&S, currentText);
    TerbitDraf(&S);
    Draf tempDraf;
    PopDraft(&S, &tempDraf);
  }
}

void LihatDraf()
{
  // swapToTop(&SDraf);
  int index = searchIdxStackPengguna(Nama(*currentUser));
  StackDraf S = ELMTDraf(ListStackDraf, index);

  if (IsDraftEmpty(S) || !isKataEqual(authorDraf(InfoTop(S)), Nama(*currentUser)))
  {
    printf("\nYah, anda belum memiliki draf apapun! Buat dulu ya :D\n\n");
  }
  else
  {
    Word hapus, simpan, terbit, kembali, ubah;
    strToWord("HAPUS", &hapus);
    strToWord("SIMPAN", &simpan);
    strToWord("TERBIT", &terbit);
    strToWord("KEMBALI", &kembali);
    strToWord("UBAH", &ubah);

    DisplayDraf(S);

    printf("\nApakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
    ReadWord();

    if (!isKataEqual(currentWord, kembali))
    {
      if (isKataEqual(currentWord, hapus))
      {
        HapusDraf(&S);
        printf("\nDraf telah berhasil dihapus!\n\n");
      }
      else if (isKataEqual(currentWord, ubah))
      {
        Word currentText;

        printf("\nMasukkan draf yang baru:\n");
        ReadWord();
        currentText = currentWord;
        printf("\nApakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
        ReadWord();
        if (isKataEqual(currentWord, hapus))
        {
          HapusDraf(&S);
          printf("\nDraf telah berhasil dihapus!\n\n");
        }
        else if (isKataEqual(currentWord, simpan))
        {
          Draf draf;
          PopDraft(&S, &draf);
          textDraf(draf) = currentText;
          PushDraft(&S, draf);
          printf("\nDraf telah berhasil disimpan!\n\n");
        }
        else if (isKataEqual(currentWord, terbit))
        {
          SimpanDraf(&S, currentText);
          TerbitDraf(&S);
          Draf tempDraf;
          PopDraft(&S, &tempDraf);
        }
      }
      else if (isKataEqual(currentWord, terbit))
      {
        TerbitDraf(&S);
        Draf tempDraf;
        PopDraft(&S, &tempDraf);
      }
    }
  }
}

int CountDraftUser(Word nama)
{
  int index = searchIdxStackPengguna(nama);
  StackDraf S = ELMTDraf(ListStackDraf, index);
  int countDraf = 0;
  StackDraf temp;
  Draf draf;
  CreateEmptyDraft(&temp);
  while (!IsDraftEmpty(S))
  {
    PopDraft(&S, &draf);
    countDraf++;
    PushDraft(&temp, draf);
  }

  while (!IsDraftEmpty(temp))
  {
    PopDraft(&temp, &draf);
    PushDraft(&S, draf);
  }
  return countDraf;
}

void PushLoad(StackDraf *SDraf, Draf draf)
{
  StackDraf temp;
  CreateEmptyDraft(&temp);
  Draf tempDraf;

  while (!IsDraftEmpty(*SDraf))
  {
    PopDraft(SDraf, &tempDraf);
    PushDraft(&temp, tempDraf);
  }
  PushDraft(SDraf, draf);
  while (!IsDraftEmpty(temp))
  {
    PopDraft(&temp, &tempDraf);
    PushDraft(SDraf, tempDraf);
  }
}

void swapToTop(StackDraf *S)
{
  StackDraf temp;
  Draf draf;
  boolean found = false;
  while (!IsDraftEmpty(*S) && !found)
  {
    PopDraft(S, &draf);
    if (isKataEqual(authorDraf(draf), Nama(*currentUser)))
    {
      found = true;
    }
    else
    {
      PushDraft(&temp, draf);
    }
  }

  Draf tempDraf;
  while (!IsDraftEmpty(temp))
  {
    PopDraft(&temp, &tempDraf);
    PushDraft(S, tempDraf);
  }

  PushDraft(S, draf);
}

int searchIdxStackPengguna(Word nama)
{
  boolean found = false;
  int idx = 0;
  while (idx < length(ListUser) && !found)
  {
    if (isKataEqual(Nama(ELMT(ListUser, idx)), nama))
    {
      found = true;
    }
    else
    {
      idx++;
    }
  }

  return idx;
}