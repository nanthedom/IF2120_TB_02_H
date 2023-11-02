#include <stdio.h>
#include "../pengguna/pengguna.h"
#include "teman.h"

extern Pengguna* currentUser;
extern boolean isLogin;
extern ListPengguna ListUser;

void CreateAdjMatrix(int nEff, AdjMatrix *m) {
    int i, j;

    NEFFM(*m) = nEff;
    for (i = 0; i < SIZE_CAP; i++) {
        for (j = 0; j < SIZE_CAP; j++) {
            ELMTMAT(matrixPertemanan, i, j) = 0;
        }
    }
}

void printDaftarTeman() {
    int userIdx, i, j;

    printf("Daftar teman ");
    printWord(Nama(*currentUser));
    printf("\n");

    userIdx = indexOf(ListUser, Nama(*currentUser));
    for (i = 0; i < NEFFM(matrixPertemanan); i++) {
        if (ELMTMAT(matrixPertemanan, i, userIdx) == 1 && i != userIdx) {
            printf("| ");
            printWord(Nama(ELMT(ListUser, i)));
            printf("\n");
        }
    }
}

void daftarTeman() {
    int userIdx, i, j, count;

    count = 0;
    userIdx = indexOf(ListUser, Nama(*currentUser));
    for (i = 0; i < NEFFM(matrixPertemanan); i++) {
        if (ELMTMAT(matrixPertemanan, i, userIdx) == 1 && i != userIdx) {
            count++;
        }
    }

    printf("\n");
    if (count > 0) {
        printWord(Nama(*currentUser));
        printf(" memiliki %d teman\n", count);
        printDaftarTeman();
    } else {
        printWord(Nama(*currentUser));
        printf(" belum mempunyai teman\n\n");
    }
}

boolean isFriendsWith(Word nama) {
    int i, friendIdx, userIdx;

    userIdx = indexOf(ListUser, Nama(*currentUser));
    friendIdx = indexOf(ListUser, nama);

    if (friendIdx == IDX_UNDEF) {
        return false;
    } else {
        return (ELMTMAT(matrixPertemanan, userIdx, friendIdx) == 1);
    }
}

void removeTeman(AdjMatrix *m, Word nama) {
    int friendIdx, userIdx;

    userIdx = indexOf(ListUser, Nama(*currentUser));
    friendIdx = indexOf(ListUser, nama);

    ELMTMAT(*m, friendIdx, userIdx) = 0;
    ELMTMAT(*m, userIdx, friendIdx) = 0;
}

void hapusTeman() {
    Word nama, pil, yes; int idx;

    printf("\nMasukkan nama pengguna: \n");
    ReadWord();
    nama = currentWord;

    if (isFriendsWith(nama)) {
        printf("Apakah anda yakin ingin menghapus ");
        printWord(nama);
        printf(" dari daftar teman anda?(YA/TIDAK) ");
        ReadWord();
        pil = currentWord;
        strToWord("YA", &yes);

        if (isKataEqual(pil ,yes)) {
            removeTeman(&matrixPertemanan, nama);
            printWord(nama);
            printf(" berhasil dihapus dari daftar teman Anda.\n\n");
        } else {
            printf("Penghapusan teman dibatalkan.\n\n");
        }
    } else {
        printWord(nama);
        printf(" bukan teman Anda.\n\n");
    }
}