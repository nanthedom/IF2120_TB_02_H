#include <stdio.h>
#include "permintaan.h"

extern Pengguna* currentUser;
extern boolean isLogin;
extern ListPengguna ListUser;

void LoadDaftarPermintaan() {
    int i, userIdx; ElmPermintaan e;

    userIdx = indexOf(ListUser, Nama(*currentUser));

    MakeEmpty(&daftarPermintaan, 20);
    for (i = 0; i < ROW_EFF(matrixPermintaan); i++) {
        if (ELMTMAT(matrixPermintaan, i, 1) == userIdx) {
            Info(e) = ELMTMAT(matrixPermintaan, i, 0);
            Prio(e) = ELMTMAT(matrixPermintaan, i, 2);
            Enqueue(&daftarPermintaan, e);
        }
    }
}

void MatrixPermintaanFile(Word w, Matrix *m, int row){
    int k=0,val;

    createMatrix(row,3,&m);
    for(int i=0; i<row; ++i){
        for(int j=0; j<3; ++j){
            while(w.TabWord[k] != ENTER && w.TabWord[k] != MARK){
                while (w.TabWord[k] == BLANK){
                    k++;
                }
                val = w.TabWord[k] - '0';
                ELMTADJMAT(*m,i,j) = val;
                k++;
            }
            if(w.TabWord[k]==ENTER){
                k++;
            }
            
        }
    }

}

boolean sudahKirimPermintaan(int userIdx, int targetIdx) {
    int i;

    for (i = 0; i < ROW_EFF(matrixPermintaan); i++) {
        if (ELMTMAT(matrixPermintaan, i, 0) == userIdx && ELMTMAT(matrixPermintaan, i, 1) == targetIdx) {
            return true;
        }
    }
    return false;
}

void tambahkanPermintaan(int userIdx, int targetIdx) {
    ELMTMAT(matrixPermintaan, ROW_EFF(matrixPermintaan), 0) = userIdx;
    ELMTMAT(matrixPermintaan, ROW_EFF(matrixPermintaan), 1) = targetIdx;
    ELMTMAT(matrixPermintaan, ROW_EFF(matrixPermintaan), 2) = jumlahTeman(userIdx);
    ROW_EFF(matrixPermintaan)++;
}

void TambahTeman() {
    Word nama; int targetIdx, userIdx;

    if (!IsEmpty(daftarPermintaan)) {
        printf("\nTerdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n\n");
    } else {
        printf("\nMasukkan nama pengguna:\n");
        ReadWord();
        nama = currentWord;

        targetIdx = indexOf(ListUser, nama);
        userIdx = indexOf(ListUser, Nama(*currentUser));

        if (targetIdx == IDX_UNDEF) {
            printf("\nPengguna bernama ");
            printWord(nama);
            printf(" tidak ditemukan\n\n");
        } else if (sudahKirimPermintaan(userIdx, targetIdx)) {
            printf("\nAnda sudah mengirimkan permintaan pertemanan kepada");
            printWord(nama);
            printf(". Silakan tunggu hingga permintaan Anda disetujui.\n\n");
        } else if (isFriendsWith(nama)) {
            printf("\nAnda sudah berteman dengan ");
            printWord(nama);
            printf(".\n\n");
        } else {
            tambahkanPermintaan(userIdx, targetIdx);
            printf("Permintaan pertemanan kepada ");
            printWord(nama);
            printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n\n");
        }
    }
}

void printElmtPQ(int idx) {
    ElmPermintaan e; Word nama;
    e = ElmtPQ(daftarPermintaan, idx);
    nama = Nama(ELMT(ListUser, Info(e)));
    printf("| ");
    printWord(nama);
    printf("\n");
    printf("| Jumlah teman: %d\n", Prio(e));
}

void DaftarPermintaanPertemanan() {
    int i, jmlPermintaan;

    if (!IsEmpty(daftarPermintaan)) {
        jmlPermintaan = NBElmtPQ(daftarPermintaan);
        printf("\nTerdapat %d permintaan pertemanan untuk Anda.\n\n", jmlPermintaan);

        for(i = 0; i < NBElmtPQ(daftarPermintaan); i++) {
            printElmtPQ(i);
            printf("\n");
        }
    } else {
        printf("\nTidak ada permintaan pertemanan untuk Anda.\n\n");
    }
}

void SetujuiPertemanan() {
    Word nama, answer, ya; ElmPermintaan e, val; int userIdx, targetIdx;

    if (!IsEmpty(daftarPermintaan)) {
        strToWord("YA", &ya);

        e = ElmtPQ(daftarPermintaan, 0);
        nama = Nama(ELMT(ListUser, Info(e)));
        userIdx = indexOf(ListUser, Nama(*currentUser));
        targetIdx = indexOf(ListUser, nama);
        printf("Permintaan pertemanan teratas dari ");
        printWord(nama);
        printf("\n\n");
        printElmtPQ(0);

        printf("\nApakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
        ReadWord();
        answer = currentWord;

        if (isKataEqual(answer, ya)) {
            ELMTADJMAT(matrixPertemanan, targetIdx, userIdx) = 1;
            ELMTADJMAT(matrixPertemanan, userIdx, targetIdx) = 1;
            printf("\nPermintaan pertemanan dari ");
            printWord(nama);
            printf(" telah disetujui. Selamat! Anda telah berteman dengan ");
            printWord(nama);
            printf(".\n\n");
        } else {
            printf("\nPermintaan pertemanan dari ");
            printWord(nama);
            printf(" telah ditolak.\n\n");
        }
        Dequeue(&daftarPermintaan, &val);
    } else {
        printf("\nTidak ada permintaan pertemanan untuk Anda.\n\n");
    }
}
 
void ClearDaftarPermintaan() {
    DeAlokasi(&daftarPermintaan);
}