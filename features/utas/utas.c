#include "utas.h"
#include <stdio.h>
#include <stdlib.h>

extern int currentIdUtas;

Address newNode(ElTypeUtas val)
{
  Address N = (Address)malloc(sizeof(Node));
  if (N != NULL)
  {
    INFO(N) = val;
    NEXT(N) = NULL;
  }
  return N;
}

void CreateListUtas(List *l)
{
  FIRST(*l) = NULL;
}

void CreateUtas(Utas *utas, Word word, int idKicau)
{
  idParent(*utas) = idKicau;
  idUtas(*utas) = currentIdUtas++;
  indexUtas(*utas) = 1;
  textUtas(*utas) = word;
  DATETIME dt;
  BacaDATETIME(&dt);
  datetimeUtas(*utas) = dt;
}

boolean isEmptyUtas(List l)
{
  return FIRST(l) == NULL;
}

ElTypeUtas getElmtUtas(List l, int idx)
{
  if (!isEmptyLinier(l))
  {
    int i = 0;
    Address curAdr;
    curAdr = FIRST(l);
    while (i < idx)
    {
      curAdr = NEXT(curAdr);
      i++;
    }
    return INFO(curAdr);
  }
  else
  {
    return IDX_UNDEF;
  }
}

ElTypeUtas getUtasById(int idUtas)
{
  Utas utas;
}

int indexOfUtas(List l, ElTypeUtas val)
{
  if (!isEmptyLinier(l))
  {
    int i = 0;
    int idx = IDX_UNDEF;
    Address curAdr = FIRST(l);
    boolean found = false;
    while (curAdr != NULL && !found)
    {
      if (INFO(curAdr) == val)
      {
        found = true;
        idx = i;
      }
      i++;
      curAdr = NEXT(curAdr);
    }
    return idx;
  }
  return IDX_UNDEF;
}

void insertFirstUtas(List *l, ElTypeUtas val)
{
  Address p;
  p = newNode(val);
  if (p != NULL)
  {
    NEXT(p) = *l;
    FIRST(*l) = p;
  }
}

void insertLastUtas(List *l, ElTypeUtas val)
{
  Address p, curAdr;
  curAdr = *l;
  p = newNode(val);
  if (p != NULL)
  {
    if (isEmptyLinier(*l))
    {
      insertFirst(l, val);
    }
    else
    {
      while (NEXT(curAdr) != NULL)
      {
        curAdr = NEXT(curAdr);
      }
      NEXT(curAdr) = p;
    }
  }
}

void insertAtUtas(List *l, ElTypeUtas val, int idx)
{
  Address p, curAdr = *l;
  p = newNode(val);
  if (p != NULL)
  {
    int i = 0;
    if (idx == 0)
    {
      insertFirst(l, val);
    }
    else
    {
      while (i < idx - 1)
      {
        curAdr = NEXT(curAdr);
        i++;
      }
      NEXT(p) = NEXT(curAdr);
      NEXT(curAdr) = p;
    }
  }
}

void deleteFirstUtas(List *l, ElTypeUtas *val)
{
  *val = INFO(*l);
  *l = NEXT(*l);
}

void deleteLastUtas(List *l, ElTypeUtas *val)
{
  Address curAdr = *l;
  Address beforeAdr = NULL;
  while (NEXT(curAdr) != NULL)
  {
    beforeAdr = curAdr;
    curAdr = NEXT(curAdr);
  }
  *val = INFO(curAdr);
  if (beforeAdr == NULL)
  {
    *l = NULL;
  }
  else
  {
    NEXT(beforeAdr) = NULL;
  }
  free(curAdr);
}

void deleteAtUtas(List *l, int idx, ElTypeUtas *val)
{
  Address curAdr = *l;
  int i = 0;
  if (idx == 0)
  {
    deleteFirst(l, val);
  }
  else
  {
    while (i < idx - 1)
    {
      i++;
      curAdr = NEXT(curAdr);
    }
    Address idxAdr = NEXT(curAdr);
    *val = INFO(idxAdr);
    NEXT(curAdr) = NEXT(idxAdr);
    free(idxAdr);
  }
}

int length(List l)
{
  int count = 0;
  Address curAdr = l;
  while (curAdr != NULL)
  {
    count++;
    curAdr = NEXT(curAdr);
  }
  return count;
}

void utas(int id)
{
  if (idValid(id))
  {
    Kicauan kicau = searchKicau(id);
    if (isKataEqual(Nama(currentUser), authorKicau(kicau)))
    {
      Word lanjutUtas;
      strToWord("TIDAK", &lanjutUtas);
      List listUtas;
      Word currentText;
      Utas utas, parent;
      CreateListUtas(&listUtas);
      parent = newNode(parentUtas(searchKicau(id)));
      FIRST(listUtas) = parent;
      printf("\nUtas berhasil dibuat!");
      printf("\nMasukkan kicauan:\n");
      ReadWord();
      currentText = currentWord;
      CreateUtas(&utas, currentText, id);
      Address P = newNode(utas);
      NEXT(listUtas) = P;
      printf("\nApakah Anda ingin melanjutkan utas ini? (YA/TIDAK)");
      ReadWord();
      while (!isKataEqual(currentWord, lanjutUtas))
      {
        printf("\nMasukkan kicauan:\n");
        ReadWord();
        currentText = currentWord;
        CreateUtas(&utas, currentText, id);
        Address P = newNode(utas);
        NEXT(listUtas) = P;
        printf("\nApakah Anda ingin melanjutkan utas ini? (YA/TIDAK)");
        ReadWord();
      }
      printf("\nUtas selesai!");
    }
    else
    {
      printf("\nUtas ini bukan milik anda!\n\n");
    }
  }
  else
  {
    printf("\nKicauan tidak ditemukan\n\n");
  }
}

void sambungUtas(int id, int index)
{
}

void displayUtas(List l)
{
  if (idValid(id))
  {
    int idxtweet = searchByIdKicau(id);
    int idxuser = indexOf(ListUser, authorKicau(ELMTKicau(ListTweet, idxtweet)));
    if (isPublic(Profil(ELMT(ListUser, idxuser))) || isFriendsWith(authorKicau(ELMTKicau(ListTweet, idxtweet))) || isKataEqual(Nama(*currentUser), authorKicau(ELMTKicau(ListTweet, idxtweet))))
    {
      Address p = FIRST(l);
      printf("\n| ID = %d", idUtas(INFO(p)));
      printf("\n| ");
      printWord(authorUtas(INFO(p)));
      printf("\n| ");
      TulisDATETIME(datetimeUtas(INFO(p)));
      printf("\n| ");
      printWord(textUtas(INFO(p)));
      p = NEXT(p);
      while (p != NULL)
      {
        printf("\n| INDEX = %d", indexUtas(INFO(p)));
        printf("\n| ");
        printWord(authorUtas(INFO(p)));
        printf("\n| ");
        TulisDATETIME(datetimeUtas(INFO(p)));
        printf("\n| ");
        printWord(textUtas(INFO(p)));
        p = NEXT(p);
      }
    }
    else
    {
      printf("\nAkun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n\n");
    }
  }
  else
  {
    printf("\nUtas tidak ditemukan!\n\n");
  }
}

Utas parentUtas(Kicauan Kicau)
{
  Utas parent;
  idParent(parent) = idKicau(Kicau);
  idUtas(parent) = currentIdUtas;
  indexUtas(parent) = 0;
  textUtas(parent) = textKicau(Kicau);
  authorUtas(parent) = authorKicau(Kicau);
  datetimeUtas(parent) = datetimeKicau(Kicau);

  return parent;
}