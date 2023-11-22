#include "pengguna.h"
#include "../profil/profil.h"
#include "../inisialisasi/inisialisasi.h"
#include "../permintaan/permintaan.h"
#include <stdio.h>

extern ListPengguna ListUser;
extern boolean isLogin;
extern boolean isClosed;
extern Pengguna *currentUser;

void CreatePengguna(Pengguna *p, Word Nama, Word Password)
{
    Nama(*p) = Nama;
    Password(*p) = Password;
    CreateProfil(&Profil(*p));
}

void CreatePenggunaFile(Pengguna *p, Word Nama, Word Password, Word bio, Word noHP, Word weton, boolean isPub, MatrixFoto M)
{
    Nama(*p) = Nama;
    Password(*p) = Password;
    CreateProfilFile(&Profil(*p), bio, noHP, weton, isPub, M);
}

void CreateList(ListPengguna *l)
{
    length(*l) = 0;
}

boolean isEmpty(ListPengguna l)
{
    return length(l) == 0;
}

boolean isFull(ListPengguna l)
{
    return length(l) == USERMAX;
}

void printList(ListPengguna l)
{
    int i;
    for (i = 0; i < length(l); i++)
    {
        printf("Nama: ");
        printWord(Nama(ELMT(l, i)));
        printf("\n");
    }
}

int indexOf(ListPengguna l, Word Nama)
{
    if (!isEmpty(l))
    {
        int i = 0;
        boolean found = false;
        int idx = IDX_UNDEF;
        while (i < length(l) && !found)
        {
            if (isKataEqual(Nama(ELMT(l, i)), Nama))
            {
                found = true;
                idx = i;
            }
            i++;
        }
        return idx;
    }
    return IDX_UNDEF;
}

void insertLast(ListPengguna *l, Pengguna p)
{
    if (length(*l) < USERMAX)
    {
        ELMT(*l, length(*l)) = p;
        length(*l)++;
    }
}

boolean isNamaValid(Word Nama)
{
    return (Nama.Length <= 20 && Nama.Length > 0) && (indexOf(ListUser, Nama) == IDX_UNDEF);
}

boolean isPasswordValid(Word Password)
{
    return (Password.Length <= 20 && Password.Length > 0);
}

void Daftar()
{
    if (!isLogin)
    {
        Word Nama, Password;
        printf("\nMasukkan nama:\n");
        ReadWord();
        Nama = currentWord;
        while (!isNamaValid(Nama))
        {
            if (indexOf(ListUser, Nama) != IDX_UNDEF)
            {
                printf("\nWah, sayang sekali nama tersebut telah diambil.\n");
            }
            else
            {
                printf("\nNama tidak boleh melebihi 20 karakter atau berupa string kosong.\n");
            }
            printf("\nMasukkan nama:\n");
            ReadWord();
            Nama = currentWord;
        }
        printf("\nMasukkan kata sandi:\n");
        ReadWord();
        Password = currentWord;
        while (!isPasswordValid(Password))
        {
            printf("\nPassword tidak boleh melebihi 20 karakter atau berupa string kosong.\n");
            printf("\nMasukkan kata sandi:\n");
            ReadWord();
            Password = currentWord;
        }
        Pengguna p;
        CreatePengguna(&p, Nama, Password);
        if (length(ListUser) < USERMAX)
        {
            insertLast(&ListUser, p);
        }
        else
        {
            printf("\nSayang sekali jumlah pengguna tidak dapat melebihi 20 orang.\n\n");
        }
        printf("\nPengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n\n");
    }
    else
    {
        printf("\nAnda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n\n");
    }
}

void Masuk()
{
    if (!isEmpty(ListUser))
    {
        if (!isLogin)
        {
            Word Nama, Password;
            printf("\nMasukkan nama:\n");
            ReadWord();
            Nama = currentWord;
            while (indexOf(ListUser, Nama) == IDX_UNDEF)
            {
                printf("\nWah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
                printf("\nMasukkan nama:\n");
                ReadWord();
                Nama = currentWord;
            }
            printf("\nMasukkan kata sandi:\n");
            ReadWord();
            Password = currentWord;
            while (!isKataEqual(Password(ELMT(ListUser, indexOf(ListUser, Nama))), Password))
            {
                printf("\nWah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
                printf("\nMasukkan kata sandi:\n");
                ReadWord();
                Password = currentWord;
            }
            currentUser = &ELMT(ListUser, indexOf(ListUser, Nama));
            printf("\nAnda telah berhasil masuk dengan nama pengguna ");
            printWord(Nama(*currentUser));
            isLogin = true;
            LoadDaftarPermintaan();
            printf(". Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n\n");
        }
        else
        {
            printf("\nWah Anda sudah masuk. Keluar dulu yuk!\n\n");
        }
    }
    else
    {
        printf("Belum terdapat pengguna yang terdaftar. Daftar dulu yuk!\n\n");
    }
}

void Keluar()
{
    if (isLogin)
    {
        isLogin = false;
        ClearDaftarPermintaan();
        printf("\nAnda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n\n");
    }
    else
    {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
    }
}

void TutupProgram()
{
    isClosed = true;
    printf("\nAnda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n\n");
}