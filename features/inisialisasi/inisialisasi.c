#include "inisialisasi.h"
#include "../pengguna/pengguna.h"
#include "../profil/profil.h"
#include "../kicau/kicau.h"
#include "../teman/teman.h"
#include "../permintaan/permintaan.h"
#include "../balasan/balasan.h"
#include "../draf/draf.h"
#include "../muat/muat.h"
#include <stdlib.h>
#include <stdio.h>

void init()
{
    printf(".______    __    __  .______      .______    __  .______      \n"
           "|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\     \n"
           "|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |    \n"
           "|   _  <  |  |  |  | |      /     |   _  <  |  | |      /     \n"
           "|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n"
           "|______/   \\______/  | _| `._____||______/  |__| | _| `._____|\n\n"
           "Selamat datang di BurBir. \n"
           "Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");
    isLogin = false;
    isClosed = false;
}

void parseMultiCmd(Word w, Word *cmd, Word *param0, Word *param1)
{
    int i = 0;
    CreateWord(cmd);
    while (w.TabWord[i] != BLANK)
    {
        (*cmd).TabWord[i] = w.TabWord[i];
        i++;
    }
    (*cmd).Length = i;
    i++;
    int j = 0, k = 0;
    CreateWord(param0);
    CreateWord(param1);
    while (i < w.Length && w.TabWord[i] != BLANK)
    {
        (*param0).TabWord[k] = w.TabWord[i];
        i++;
        k++;
    }
    (*param0).Length = k;
    if (i < w.Length)
    {
        i++;
        j++;
        k = 0;
        while (i < w.Length && w.TabWord[i] != BLANK)
        {
            (*param1).TabWord[k] = w.TabWord[i];
            i++;
            k++;
        }
        (*param1).Length = k;
    }
}

void prosesCmd(Word w)
{
    Word daftar, muat, masuk, keluar, tutup_program, ganti_profil, lihat_profil, atur_jenis_akun, ubah_foto_profil, kicau, kicauan, suka_kicauan, ubah_kicauan, balas, balasan, hapus_balasan, daftar_teman, hapus_teman, buat_draf, lihat_draf, tambah_teman, setujui_pertemanan, daftar_permintaan_pertemanan;
    strToWord("DAFTAR", &daftar);
    strToWord("MASUK", &masuk);
    strToWord("KELUAR", &keluar);
    strToWord("MUAT", &muat);
    strToWord("TUTUP_PROGRAM", &tutup_program);
    strToWord("GANTI_PROFIL", &ganti_profil);
    strToWord("LIHAT_PROFIL", &lihat_profil);
    strToWord("ATUR_JENIS_AKUN", &atur_jenis_akun);
    strToWord("UBAH_FOTO_PROFIL", &ubah_foto_profil);
    strToWord("KICAU", &kicau);
    strToWord("KICAUAN", &kicauan);
    strToWord("SUKA_KICAUAN", &suka_kicauan);
    strToWord("UBAH_KICAUAN", &ubah_kicauan);
    strToWord("BALAS", &balas);
    strToWord("BALASAN", &balasan);
    strToWord("HAPUS_BALASAN", &hapus_balasan);
    strToWord("DAFTAR_TEMAN", &daftar_teman);
    strToWord("HAPUS_TEMAN", &hapus_teman);
    strToWord("BUAT_DRAF", &buat_draf);
    strToWord("LIHAT_DRAF", &lihat_draf);
    strToWord("TAMBAH_TEMAN", &tambah_teman);
    strToWord("SETUJUI_PERTEMANAN", &setujui_pertemanan);
    strToWord("DAFTAR_PERMINTAAN_PERTEMANAN", &daftar_permintaan_pertemanan);
    if (isKataEqual(w, daftar))
    {
        Daftar();
    }
    else if (isKataEqual(w, masuk))
    {
        Masuk();
    }
    else if (isKataEqual(w, keluar))
    {
        Keluar();
    }
    else if (isKataEqual(w, tutup_program))
    {
        TutupProgram();
    }
    else if (isKataEqual(w, muat))
    {
        if (isLogin)
        {
            printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.\n");
        }
        else
        {
            Muat();
        }
    }
    else if (isKataEqual(w, ganti_profil))
    {
        if (isLogin)
        {
            GantiProfil();
        }
        else
        {
            printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        }
    }
    else if (isKataEqual(w, atur_jenis_akun))
    {
        if (isLogin)
        {
            AturJenisAkun();
        }
        else
        {
            printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        }
    }
    else if (isKataEqual(w, ubah_foto_profil))
    {
        if (isLogin)
        {
            UbahFotoProfil();
        }
        else
        {
            printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        }
    }
    else if (isKataEqual(w, kicau))
    {
        if (isLogin)
        {
            Kicau();
            inisialisasiBalasan();
        }
        else
        {
            printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        }
    }
    else if (isKataEqual(w, kicauan))
    {
        if (isLogin)
        {
            printKicauan();
        }
        else
        {
            printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        }
    }
    else if (isKataEqual(w, daftar_teman))
    {
        if (isLogin)
        {
            daftarTeman();
        }
        else
        {
            printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        }
    }
    else if (isKataEqual(w, hapus_teman))
    {
        if (isLogin)
        {
            hapusTeman();
        }
        else
        {
            printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        }
    }
    else if (isKataEqual(w, buat_draf))
    {
        if (isLogin)
        {
            BuatDraf();
        }
        else
        {
            printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        }
    }
    else if (isKataEqual(w, lihat_draf))
    {
        if (isLogin)
        {
            LihatDraf();
        }
        else
        {
            printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        }
    }
    else if (isKataEqual(w, tambah_teman))
    {
        if (isLogin)
        {
            TambahTeman();
        }
        else
        {
            printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        }
    }
    else if (isKataEqual(w, daftar_permintaan_pertemanan))
    {
        if (isLogin)
        {
            DaftarPermintaanPertemanan();
        }
        else
        {
            printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        }
    }
    else if (isKataEqual(w, setujui_pertemanan))
    {
        if (isLogin)
        {
            SetujuiPertemanan();
        }
        else
        {
            printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        }
    }
    else if (containBlanks(w))
    {
        Word newCmd, param0, param1;
        parseMultiCmd(w, &newCmd, &param0, &param1);
        if (isKataEqual(newCmd, lihat_profil))
        {
            if (isLogin)
            {
                LihatProfil(param0);
            }
            else
            {
                printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
        else if (isKataEqual(newCmd, suka_kicauan))
        {
            if (isLogin)
            {
                int id = wordToInteger(param0);
                sukaKicau(id);
            }
            else
            {
                printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
        else if (isKataEqual(newCmd, ubah_kicauan))
        {
            if (isLogin)
            {
                int id = wordToInteger(param0);
                ubahKicauan(id);
            }
            else
            {
                printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
        else if (isKataEqual(newCmd, balas))
        {
            if (isLogin)
            {
                int idKicau = wordToInteger(param0);
                int idBalas = wordToInteger(param1);
                buatBalasan(idKicau, idBalas);
            }
            else
            {
                printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
        else if (isKataEqual(newCmd, balasan))
        {
            if (isLogin)
            {
                int idKicau = wordToInteger(param0);
                printBalasan(idKicau);
            }
            else
            {
                printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
        else if (isKataEqual(newCmd, hapus_balasan))
        {
            if (isLogin)
            {
                int idKicau = wordToInteger(param0);
                int idBalas = wordToInteger(param1);
                hapusBalasan(idKicau, idBalas);
            }
            else
            {
                printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
    }
}