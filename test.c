#include <stdio.h>
#include "features/pengguna/pengguna.h"
#include "features/profil/profil.h"
#include "features/muat/muat.h"
#include "features/teman/teman.h"
#include "features/permintaan/permintaan.h"
#include "ADT/wordmachine/wordmachine.h"
#include "ADT/charmachine/charmachine.h"
#include "ADT/prioqueue/prioqueue.h"
#include "ADT/matrix/matrix.h"
#include "ADT/pcolor/pcolor.h"
/* USER*/
boolean isLogin;
boolean isClosed;
Pengguna *currentUser;
ListPengguna ListUser;

/* Teman */
AdjMatrix matrixPertemanan;

/* Permintaan Pertemanan */
Matrix matrixPermintaan;
PrioQueue daftarPermintaan;

int main(){
    loadPengguna("data/save1/pengguna.config");
    printList(ListUser);
    PrintFoto((Profil(ListUser.buffer[0])));
    PrintFoto((Profil(ListUser.buffer[2])));
}