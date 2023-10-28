#include <stdio.h>
#include "ADT/pengguna.h"
#include "ADT/inisialisasi.h"
#include "ADT/wordmachine.h"

int main(){
    extern ListPengguna ListUser;
    CreateList(&ListUser);
    init();
    Daftar();
    Masuk();
    Masuk();
    Keluar();
}