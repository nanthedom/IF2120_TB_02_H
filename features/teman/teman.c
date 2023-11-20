#include <stdio.h>
#include "../pengguna/pengguna.h"
#include "teman.h"

extern Pengguna* currentUser;
extern boolean isLogin;
extern ListPengguna ListUser;

void CreateAdjMatrixFile(AdjMatrix *m, Word w, int Neff){
    Word format;
    format = w;
    int i = 0, j = 0, k = 0;

    NEFFM(*m)=Neff;
    while (i < NEFFM(*m)){
        while (j < NEFFM(*m)){
            while (format.TabWord[k] == BLANK || format.TabWord[k] == ENTER){
                k++;
            }
            ELMTADJMAT(*m,i,j) = format.TabWord[k] - '0';
            k++;
            j++;
        }
        i++; j = 0;
    }    
}

void printDaftarTeman() {
    int userIdx, i;

    printf("Daftar teman ");
    printWord(Nama(*currentUser));
    printf("\n");

    userIdx = indexOf(ListUser, Nama(*currentUser));
    for (i = 0; i < NEFFM(matrixPertemanan); i++) {
        if (ELMTADJMAT(matrixPertemanan, i, userIdx) == 1 && i != userIdx) {
            printf("| ");
            printWord(Nama(ELMT(ListUser, i)));
            printf("\n");
        }
    }
}

int jumlahTeman(int userIdx) {
    int i, count;

    count = 0;
    for (i = 0; i < NEFFM(matrixPertemanan); i++) {
        if (ELMTADJMAT(matrixPertemanan, i, userIdx) == 1 && i != userIdx) {
            count++;
        }
    }

    return count;
}

void daftarTeman() {
    int userIdx, count;

    userIdx = indexOf(ListUser, Nama(*currentUser));
    count = jumlahTeman(userIdx);

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
    int friendIdx, userIdx;

    userIdx = indexOf(ListUser, Nama(*currentUser));
    friendIdx = indexOf(ListUser, nama);

    if (friendIdx == IDX_UNDEF) {
        return false;
    } else {
        return (ELMTADJMAT(matrixPertemanan, userIdx, friendIdx) == 1);
    }
}

void removeTeman(AdjMatrix *m, Word nama) {
    int friendIdx, userIdx;

    userIdx = indexOf(ListUser, Nama(*currentUser));
    friendIdx = indexOf(ListUser, nama);

    ELMTADJMAT(*m, friendIdx, userIdx) = 0;
    ELMTADJMAT(*m, userIdx, friendIdx) = 0;
}

void hapusTeman() {
    Word nama, pil, yes;

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