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

// Kicauan
int currentIdTweet;
ListKicauan ListTweet;

int main(){
<<<<<<< HEAD
    Word x;
    CreateWord(&x);
    ReadWord();
    x = currentWord;
    // printWord(x);
    // printf("\n%s", x.TabWord);
    load(x);
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

=======
    loadPengguna("data/save1/pengguna.config");
    printList(ListUser);
    PrintFoto((Profil(ListUser.buffer[0])));
<<<<<<< HEAD
    PrintFoto((Profil(ListUser.buffer[2])));
=======
    currentUser = &ListUser.buffer[2]; isLogin= true;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", ELMTADJMAT(matrixPertemanan,i,j));
        }
        printf("\n");
    }
    printDaftarTeman();
>>>>>>> e620ed31f9cfca4024701151c9d51472c13587f7
>>>>>>> main
}