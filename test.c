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
    // PrintFoto((Profil(ListUser.buffer[0])));
    // currentUser = &ListUser.buffer[2]; isLogin= true;
    Simpan();
    // Word x;
    // // createMatrix(0, 3, &matrixPermintaan);
    // CreateWord(&x);
    // CreateListKicauan(&ListTweet);
    // CreateEmptyDraft(&SDraf);
    // ReadWord();
    // x = currentWord;
    // printWord(x)
    // int v = wordToInteger(x);
    // printf("%d", v);
    // load(x);
    // Word nama = authorDraf(InfoTop(SDraf));
    // int count = CountDraftUser(SDraf, nama);
    // printf("%d",count);
    // printWord(nama);




    // printf("%d",NEFFKicau(ListTweet));
    // Kicauan K = ELMTKicau(ListTweet,0);
    // printWord(K.textKicau);
    // printKicauan();
    // displayMatrix(matrixPermintaan);
    // loadPengguna("data/save1/pengguna.config");
    // test matrix pertemanan
    // printf("%d", matrixPertemanan.mem[0][0]);
    // printf("%d", matrixPertemanan.mem[0][1]);
    // printf("%d\n", matrixPertemanan.mem[0][2]);
    // printf("%d", matrixPertemanan.mem[1][0]);
    // printf("%d", matrixPertemanan.mem[1][1]);
    // printf("%d\n", matrixPertemanan.mem[1][2]);
    // printf("%d", matrixPertemanan.mem[2][0]);
    // printf("%d", matrixPertemanan.mem[2][1]);
    // printf("%d", matrixPertemanan.mem[2][2]);

    // test pengguna
    // *currentUser = ListUser.buffer[0];
    // daftarTeman();
    // printList(ListUser);
    // PrintFoto((Profil(ListUser.buffer[0])));
    // PrintFoto((Profil(ListUser.buffer[2])));


    // test matrixpermintaan
    // printf("%d", matrixPermintaan.mem[0][0]);
    // printf("%d", matrixPermintaan.mem[0][1]);
    // printf("%d\n", matrixPermintaan.mem[0][2]);
    // printf("%d", matrixPermintaan.mem[1][0]);
    // printf("%d", matrixPermintaan.mem[1][1]);
    // printf("%d\n", matrixPermintaan.mem[1][2]);
    // printf("%d", matrixPermintaan.mem[2][0]);
    // printf("%d", matrixPermintaan.mem[2][1]);
    // printf("%d", matrixPermintaan.mem[2][2]);


    // loadPengguna("data/save1/pengguna.config")
    // printList(ListUser);
    // PrintFoto((Profil(ListUser.buffer[0])));

    // PrintFoto((Profil(ListUser.buffer[2])));
    // currentUser = &ListUser.buffer[2]; isLogin= true;
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         printf("%d ", ELMTADJMAT(matrixPertemanan,i,j));
    //     }
    //     printf("\n");
    // }
    // printDaftarTeman();

}