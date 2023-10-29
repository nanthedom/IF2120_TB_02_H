#include "inisialisasi.h"
#include "pengguna.h"
#include "profil.h"
#include <stdio.h>

void init(){
    isLogin = false;
    isClosed = false;
}

void prosesCmd(Word w){
    Word daftar, masuk, keluar, tutup_program, ganti_profil, lihat_profil, atur_jenis_akun, ubah_foto_profil;
    strToWord("DAFTAR", &daftar);
    strToWord("MASUK", &masuk);
    strToWord("KELUAR", &keluar);
    strToWord("TUTUP_PROGRAM", &tutup_program);
    strToWord("GANTI_PROFIL", &ganti_profil);
    strToWord("ATUR_JENIS_AKUN", &atur_jenis_akun);
    strToWord("UBAH_FOTO_PROFIL", &ubah_foto_profil);
    if(isKataEqual(w,daftar)){
        Daftar();
    } else if(isKataEqual(w,masuk)){
        Masuk();
    } else if(isKataEqual(w,keluar)){
        Keluar();
    } else if (isKataEqual(w,tutup_program)){
        TutupProgram();
    } else if(isKataEqual(w, ganti_profil)){
        if(isLogin){
            GantiProfil();
        } else{
            printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        }
    } else if(isKataEqual(w, atur_jenis_akun)){
        if(isLogin){
            AturJenisAkun();
        } else{
            printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        }
    } else if (isKataEqual(w, ubah_foto_profil)){
        if(isLogin){
            UbahFotoProfil();
        } else{
            printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        }
    }
}