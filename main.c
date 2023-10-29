#include <stdio.h>
#include "ADT/pengguna.h"
#include "ADT/inisialisasi.h"
#include "ADT/wordmachine.h"
#include "ADT/profil.h"

ListPengguna ListUser;
int main(){
    CreateList(&ListUser);
    init(); Word cmd;
    while(!isClosed){
        printf(">> ");
        ReadWord();
        cmd = currentWord;
        prosesCmd(cmd);
    }
}