#include <stdio.h>
#include "features/pengguna/pengguna.h"
#include "features/inisialisasi/inisialisasi.h"
#include "ADT/wordmachine/wordmachine.h"
#include "features/profil/profil.h"
#include "features/kicau/kicau.h"
#include "features/teman/teman.h"
#include "features/draf/draf.h"
#include "features/balasan/balasan.h"

/* USER*/
boolean isLogin;
boolean isClosed;
Pengguna *currentUser;
ListPengguna ListUser;

/* Kicauan */
int currentIdTweet;
ListKicauan ListTweet;

/* Balasan */
int currentIdReply;
ListBalasan ListReply;

/* Teman */
AdjMatrix matrixPertemanan;

/* Draf */
StackDraf SDraf;
Draf draf;

int main()
{
  CreateListKicauan(&ListTweet);
  createListBalasan(&ListReply);
  CreateList(&ListUser);
  CreateEmptyDraft(&SDraf);
  CreateAdjMatrix(20, &matrixPertemanan);
  ELMTMAT(matrixPertemanan, 0, 0) = 1;
  ELMTMAT(matrixPertemanan, 0, 1) = 1;
  ELMTMAT(matrixPertemanan, 1, 0) = 1;
  ELMTMAT(matrixPertemanan, 1, 1) = 1;
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