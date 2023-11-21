#include "utas.h"
#include <stdio.h>
#include <stdlib.h>

extern int currentIdUtas;
extern Pengguna *currentUser;
extern ListPengguna ListUser;
extern ListKicauan ListTweet;

Address newNodeUtas(ElTypeUtas val)
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

void CreateUtas(Utas *utas, Word word, int idKicau, int idx)
{
  idParent(*utas) = idKicau;
  idUtas(*utas) = currentIdUtas;
  indexUtas(*utas) = idx;
  textUtas(*utas) = word;
  DATETIME dt;
  BacaDATETIME(&dt);
  datetimeUtas(*utas) = dt;
  authorUtas(*utas) = Nama(*currentUser);
}

boolean isEmptyUtas(List l)
{
  return FIRST(l) == NULL;
}

boolean idUtasValid(int idUtas)
{
  return idUtas > 0 && idUtas <= currentIdUtas;
}

boolean isIdxUtasValid(List l, int index)
{
  Address p = FIRST(l);
  int idx = 0;
  while (p != NULL)
  {
    idx++;
  }
  if (idx <= index)
  {
    return true;
  }
  else
  {
    return false;
  }
}

ElTypeUtas getElmtUtas(List l, int idx)
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

int indexOfUtas(List l, ElTypeUtas val)
{
  if (!isEmptyUtas(l))
  {
    int i = 0;
    int idx = IDX_UNDEF;
    Address curAdr = FIRST(l);
    boolean found = false;
    while (curAdr != NULL && !found)
    {
      if (indexUtas(INFO(curAdr)) == indexUtas(val))
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
  p = newNodeUtas(val);
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
  p = newNodeUtas(val);
  if (p != NULL)
  {
    if (isEmptyUtas(*l))
    {
      insertFirstUtas(l, val);
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
  p = newNodeUtas(val);
  if (p != NULL)
  {
    int i = 0;
    if (idx == 0)
    {
      insertFirstUtas(l, val);
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
    deleteFirstUtas(l, val);
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

int lengthUtas(List l)
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
    int idxtweet = searchByIdKicau(id);
    if (isKataEqual(Nama(*currentUser), authorKicau(ELMTKicau(ListTweet, idxtweet))))
    {
      Word lanjutUtas;
      strToWord("TIDAK", &lanjutUtas);
      Word currentText;
      Utas utas;
      int index = 0;
      currentIdUtas++;
      idUtasKicau(ELMTKicau(ListTweet, idxtweet)) = currentIdUtas;
      printf("\nUtas berhasil dibuat!\n");
      printf("\nMasukkan kicauan:\n");
      ReadWord();
      currentText = currentWord;
      CreateUtas(&utas, currentText, id, index + 1);
      Address P = newNodeUtas(utas);
      FIRST(utasUtama(ELMTKicau(ListTweet, idxtweet))) = P;
      Address L = FIRST(utasUtama(ELMTKicau(ListTweet, idxtweet)));
      printf("\nApakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
      ReadWord();
      while (!isKataEqual(currentWord, lanjutUtas))
      {
        printf("\nMasukkan kicauan:\n");
        ReadWord();
        currentText = currentWord;
        CreateUtas(&utas, currentText, id, indexUtas(INFO(L)) + 1);
        Address Q = newNodeUtas(utas);
        NEXT(L) = Q;
        printf("\nApakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
        ReadWord();
        L = NEXT(L);
      }
      printf("\nUtas selesai!\n");
    }
    else
    {
      printf("\nUtas ini bukan milik anda!\n");
    }
  }
  else
  {
    printf("\nKicauan tidak ditemukan\n");
  }
  printf("\n");
}

void sambungUtas(int id, int index)
{
  if (idUtasValid(id))
  {
    int idxtweet = searchByIdUtas(id);
    if (isKataEqual(Nama(*currentUser), authorKicau(ELMTKicau(ListTweet, idxtweet))))
    {
      Address p = FIRST(utasUtama(ELMTKicau(ListTweet, idxtweet)));
      while (indexUtas(INFO(p)) != index)
      {
        p = NEXT(p);
      }
      Word currentText;
      Utas utas;
      if (indexUtas(INFO(p)) <= index)
      {
        printf("\nMasukkan kicauan:\n");
        ReadWord();
        currentText = currentWord;
        CreateUtas(&utas, currentText, id, indexUtas(INFO(p)) + 1);
        insertAtUtas(&p, utas, index);
        printf("\n");
        // while (NEXT(p) != NULL)
        // {
        //   indexUtas(INFO(p)) += 1;
        //   p = NEXT(p);
        // }
      }
      else
      {
        printf("\nIndex terlalu tinggi!\n");
      }
    }
    else
    {
      printf("\nAnda tidak bisa menyambung utas ini!\n");
    }
  }
  else
  {
    printf("\nUtas tidak ditemukan!\n");
  }
  printf("\n");
}

void hapusUtas(int id, int index)
{
  int idxtweet = searchByIdUtas(id);
  Address p = FIRST(utasUtama(ELMTKicau(ListTweet, idxtweet)));
  if (index != 0)
  {
    if (isKataEqual(Nama(*currentUser), authorKicau(ELMTKicau(ListTweet, idxtweet))))
    {
      if (idUtasValid(id))
      {
        if (indexUtas(INFO(p)) <= index)
        {
          ElTypeUtas utas;
          deleteAtUtas(&utasUtama(ELMTKicau(ListTweet, idxtweet)), index - 1, &utas);
          printf("\nKicauan sambungan berhasil dihapus!\n");
          while (NEXT(p) != NULL)
          {
            if (indexUtas(INFO(p)) > index)
            {
              indexUtas(INFO(p)) -= 1;
            }
            p = NEXT(p);
          }
          indexUtas(INFO(p)) -= 1;
        }
        else
        {
          printf("\nKicauan sambungan dengan index %d tidak ditemukan pada utas!\n", index);
        }
      }
      else
      {
        printf("\nUtas tidak ditemukan!\n");
      }
    }
    else
    {
      printf("\nAnda tidak bisa menghapus kicauan dalam utas ini!\n");
    }
  }
  else
  {
    printf("\nAnda tidak bisa menghapus kicauan utama!\n");
  }
  printf("\n");
}

void displayUtas(int id)
{
  Kicauan kicau = searchByIdUtasKicau(id);
  int idxtweet = searchByIdKicau(idKicau(kicau));
  int idxuser = indexOf(ListUser, authorKicau(ELMTKicau(ListTweet, idxtweet)));
  if (idUtasValid(id))
  {
    if (isPublic(Profil(ELMT(ListUser, idxuser))) || isFriendsWith(authorKicau(ELMTKicau(ListTweet, idxtweet))) || isKataEqual(Nama(*currentUser), authorKicau(ELMTKicau(ListTweet, idxtweet))))
    {
      Address p = utasUtama(kicau);
      printf("\n| ID = %d", idKicau(kicau));
      printf("\n| ");
      printWord(authorKicau(kicau));
      printf("\n| ");
      TulisDATETIME(datetimeKicau(kicau));
      printf("\n| ");
      printWord(textKicau(kicau));
      printf("\n");
      while (p != NULL)
      {
        printf("\n   | INDEX = %d", indexUtas(INFO(p)));
        printf("\n   | ");
        printWord(authorUtas(INFO(p)));
        printf("\n   | ");
        TulisDATETIME(datetimeUtas(INFO(p)));
        printf("\n   | ");
        printWord(textUtas(INFO(p)));
        printf("\n");
        p = NEXT(p);
      }
      printf("\n");
    }
    else
    {
      printf("\nAkun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
    }
  }
  else
  {
    printf("\nUtas tidak ditemukan!\n");
  }
  printf("\n");
}

int searchByIdUtas(int id)
{
  int i = 0;
  boolean found = false;
  while (i < NEFFKicau(ListTweet) && !found)
  {
    if (idUtasKicau(ELMTKicau(ListTweet, i)) == id)
    {
      found = true;
    }
    else
    {
      i++;
    }
  }
  return i;
}