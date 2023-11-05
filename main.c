#include <stdio.h>
#include "features/pengguna/pengguna.h"
#include "features/inisialisasi/inisialisasi.h"
#include "ADT/wordmachine/wordmachine.h"
#include "ADT/matrix/matrix.h"
#include "ADT/prioqueue/prioqueue.h"
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

/* Permintaan Pertemanan */
Matrix matrixPermintaan;
PrioQueue daftarPermintaan;

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
  createMatrix(0, 3, &matrixPermintaan);
  // ELMTMAT(matrixPertemanan, 0, 0) = 1;
  // ELMTMAT(matrixPertemanan, 0, 1) = 1;
  // ELMTMAT(matrixPertemanan, 1, 0) = 1;
  // ELMTMAT(matrixPertemanan, 1, 1) = 1;
  init();
//   loadfirst(); nanti mau dibuat di muat
  Word cmd;
  while (!isClosed)
  {
    printf(">> ");
    ReadWord();
    cmd = currentWord;
    prosesCmd(cmd);
  }
}