#include <stdio.h>
#include "features/pengguna/pengguna.h"
#include "features/inisialisasi/inisialisasi.h"
#include "ADT/wordmachine/wordmachine.h"
#include "ADT/matrix/matrix.h"
#include "ADT/graf/graf.h"
#include "ADT/prioqueue/prioqueue.h"
#include "features/profil/profil.h"
#include "features/kicau/kicau.h"
#include "features/teman/teman.h"
#include "features/draf/draf.h"
#include "features/balasan/balasan.h"
#include "features/muat/muat.h"
#include "features/simpan/simpan.h"

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

/* Permintaan Pertemanan */
Matrix matrixPermintaan;
PrioQueue daftarPermintaan;

/* Draf */
StackDraf SDraf;
Draf draf;

/* Utas */
int currentIdUtas;

int main()
{
  CreateListKicauan(&ListTweet);
  createListBalasan(&ListReply);
  CreateList(&ListUser);
  CreateEmptyDraft(&SDraf);
  CreateAdjMatrix(20, &matrixPertemanan);
  createMatrix(0, 3, &matrixPermintaan);

  init();
  loadfirst();

  Word cmd;
  while (!isClosed)
  {
    printf(">> ");
    ReadWord();
    cmd = currentWord;
    prosesCmd(cmd);
  }
}