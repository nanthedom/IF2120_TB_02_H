#include "inisialisasi.h"
#include "pengguna.h"

void init(){
    isLogin = false;
    isClosed = false;
}

void prosesCmd(Word w){
    Word daftar, masuk, keluar, tutup_program;
    strToWord("DAFTAR", &daftar);
    strToWord("MASUK", &masuk);
    strToWord("KELUAR", &keluar);
    strToWord("TUTUP_PROGRAM", &tutup_program);
    if(isKataEqual(w,daftar)){
        Daftar();
    } else if(isKataEqual(w,masuk)){
        Masuk();
    } else if(isKataEqual(w,keluar)){
        Keluar();
    } else if (isKataEqual(w,tutup_program)){
        TutupProgram();
    }
}