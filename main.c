#include <stdio.h>
#include "ADT/pengguna/pengguna.h"
#include "ADT/inisialisasi/inisialisasi.h"
#include "ADT/wordmachine/wordmachine.h"
#include "ADT/profil/profil.h"
#include "ADT/kicau/kicau.h"
#include "ADT/balasan/balasan.h"
#include "ADT/teman/teman.h"

/* USER*/
boolean isLogin;
boolean isClosed;
Pengguna* currentUser;
ListPengguna ListUser;

/* Kicauan */
int currentIdTweet;
ListKicauan ListTweet;

/* Balasan */
int currentIdReply;
ListBalasan ListReply;

/* Teman */
AdjMatrix matrixPertemanan;

int main()
{
    CreateListKicauan(&ListTweet);
    CreateList(&ListUser);
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