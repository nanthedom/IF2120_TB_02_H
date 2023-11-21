#include <stdio.h>
#include "features/pengguna/pengguna.h"
#include "features/profil/profil.h"
#include "features/muat/muat.h"
#include "features/teman/teman.h"
#include "features/simpan/simpan.h"
#include "features/permintaan/permintaan.h"
#include "features/draf/draf.h"
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

// Kicauan
int currentIdTweet;
ListKicauan ListTweet;

// Balasan
ListBalasan ListReply;

// draf
StackDraf SDraf;
Draf draf;

int main(){
    loadDraf("data/save1/draf.config");
    loadPengguna("data/save1/pengguna.config");
    printList(ListUser);
    DisplayAdjMatrix(matrixPertemanan);
    displayMatrix(matrixPermintaan);
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         printf("%d ", ELMTADJMAT(matrixPertemanan,i,j));
    //     }
    //     printf("\n");
    // }
    // printDaftarTeman();
<<<<<<<<< Temporary merge branch 1

=========
>>>>>>>>> Temporary merge branch 2
}