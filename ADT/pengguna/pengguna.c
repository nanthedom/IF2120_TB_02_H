#include "pengguna.h"
#include "../profil/profil.h"
#include "../inisialisasi/inisialisasi.h"
#include <stdio.h>

extern ListPengguna ListUser;
boolean isLogin;
boolean isClosed;
Pengguna* currentUser;

void CreatePengguna(Pengguna* p, Word Nama, Word Password){
    Nama(*p) = Nama;
    Password(*p) = Password;
    CreateProfil(&Profil(*p));
}

void CreateList(ListPengguna* l){
    length(*l) = 0;
}

boolean isEmpty(ListPengguna l){
    return length(l) == 0;
}
boolean isFull(ListPengguna l){
    return length(l) == USERMAX;
}
void printList(ListPengguna l){
    int i;
    for(i = 0; i < length(l); i++){
        printf("Nama: ");
        printWord(Nama(ELMT(l,i)));
        printf("\n");
    }
}

int indexOf(ListPengguna l, Word Nama){
    if(!isEmpty(l)){
        int i = 0; boolean found = false; int idx = IDX_UNDEF;
        while(i < length(l) && !found){
            if(isKataEqual(Nama(ELMT(l,i)), Nama)){
                found = true;
                idx = i;
            }
            i++;
        }
        return idx;
    }
    return IDX_UNDEF;
}

void insertLast(ListPengguna *l, Pengguna p){
    if (length(*l) < USERMAX){
        ELMT(*l,length(*l)) = p;
        length(*l)++;
    }
}

boolean isNamaValid(Word Nama){
    return (Nama.Length <= 20 && Nama.Length > 0)  && (indexOf(ListUser, Nama) == IDX_UNDEF);
}

boolean isPasswordValid(Word Password){
    return (Password.Length <= 20 && Password.Length > 0);
}
void Daftar(){
    if(!isLogin){
        Word Nama,Password;
        printf("Masukkan nama:\n");
        ReadWord();
        Nama = currentWord;
        while(!isNamaValid(Nama)){
            if(indexOf(ListUser, Nama) != IDX_UNDEF){
                printf("Wah, sayang sekali nama tersebut telah diambil.\n");
            } else{
                printf("Nama tidak boleh melebihi 20 karakter atau berupa string kosong.\n");
            }
            printf("Masukkan nama:\n");
            ReadWord();
            Nama = currentWord;
        }
        printf("Masukkan kata sandi:\n");
        ReadWord();
        Password = currentWord;
        while(!isPasswordValid){
            printf("Password tidak boleh melebihi 20 karakter atau berupa string kosong.\n");
            printf("Masukkan kata sandi:\n");
            ReadWord();
            Password = currentWord;
        }
        Pengguna p;
        CreatePengguna(&p, Nama, Password);
        if(length(ListUser) < USERMAX){
            insertLast(&ListUser,p);
        } else{
            printf("Sayang sekali jumlah pengguna tidak dapat melebihi 20 orang.\n");
        }
        printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
    } else{
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
    }
}

void Masuk(){
    if(!isLogin){
        Word Nama,Password;
        printf("Masukkan nama:\n");
        ReadWord();
        Nama = currentWord;
        while(indexOf(ListUser, Nama) == IDX_UNDEF){
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
            printf("Masukkan nama:\n");
            ReadWord();
            Nama = currentWord;           
        }
        printf("Masukkan kata sandi:\n");
        ReadWord();
        Password = currentWord;
        while(!isKataEqual(Password(ELMT(ListUser,indexOf(ListUser, Nama))), Password)){
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            printf("Masukkan kata sandi:\n");
            ReadWord();
            Password = currentWord;
        }
        currentUser = &ELMT(ListUser, indexOf(ListUser,Nama));
        printf("Anda telah berhasil masuk dengan nama pengguna ");
        printWord(Nama(*currentUser));
        isLogin = true;
        printf(". Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n");
    } else{
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
    }
}

void Keluar(){
    if(isLogin){
        isLogin = false;
        printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
    } else{
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

void TutupProgram(){
    isClosed = true;
    printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
}