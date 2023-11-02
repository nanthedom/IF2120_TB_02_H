#include <stdio.h>
#include "ADT/pengguna/pengguna.h"
#include "ADT/inisialisasi/inisialisasi.h"
#include "ADT/wordmachine/wordmachine.h"
#include "ADT/profil/profil.h"
#include "ADT/kicau/kicau.h"
#include "ADT/draf/draf.h"

/* USER*/
boolean isLogin;
boolean isClosed;
Pengguna *currentUser;
ListPengguna ListUser;

/* Kicauan */
int currentIdTweet;
ListKicauan ListTweet;

/* Draf */
StackDraf SDraf;
Draf draf;

int main()
{
  CreateListKicauan(&ListTweet);
  CreateList(&ListUser);
  CreateEmptyDraft(&SDraf);
  init();
  Word cmd;
  while (!isClosed)
  {
    printf(">> ");
    ReadWord();
    cmd = currentWord;
    prosesCmd(cmd);
  }
}