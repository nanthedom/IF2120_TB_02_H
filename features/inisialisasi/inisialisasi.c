#include "inisialisasi.h"
#include "../pengguna/pengguna.h"
#include "../profil/profil.h"
#include "../kicau/kicau.h"
#include "../teman/teman.h"
#include "../draf/draf.h"
#include <stdlib.h>
#include <stdio.h>

void init()
{
    isLogin = false;
    isClosed = false;
}

void parseMultiCmd(Word w, Word *cmd, Word **param)
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
    (*param) = (Word *)malloc(2 * sizeof(Word));
    CreateWord(param[0]);
    CreateWord(param[1]);
    while (i < w.Length && w.TabWord[i] != BLANK)
    {
        (*param)[j].TabWord[k] = w.TabWord[i];
        i++;
        k++;
    }
    (*param)[j].Length = k;
    if (i < w.Length)
    {
        i++;
        j++;
        k = 0;
        while (i < w.Length && w.TabWord[i] != BLANK)
        {
            (*param)[j].TabWord[k] = w.TabWord[i];
            i++;
            k++;
        }
        (*param)[j].Length = k;
    }
}

void prosesCmd(Word w)
{
    Word daftar, masuk, keluar, tutup_program, ganti_profil, lihat_profil, atur_jenis_akun, ubah_foto_profil, kicau, kicauan, suka_kicauan, ubah_kicauan, daftar_teman, hapus_teman, buat_draf, lihat_draf;
    strToWord("DAFTAR", &daftar);
    strToWord("MASUK", &masuk);
    strToWord("KELUAR", &keluar);
    strToWord("TUTUP_PROGRAM", &tutup_program);
    strToWord("GANTI_PROFIL", &ganti_profil);
    strToWord("LIHAT_PROFIL", &lihat_profil);
    strToWord("ATUR_JENIS_AKUN", &atur_jenis_akun);
    strToWord("UBAH_FOTO_PROFIL", &ubah_foto_profil);
    strToWord("KICAU", &kicau);
    strToWord("KICAUAN", &kicauan);
    strToWord("SUKA_KICAUAN", &suka_kicauan);
    strToWord("UBAH_KICAUAN", &ubah_kicauan);
    strToWord("DAFTAR_TEMAN", &daftar_teman);
    strToWord("HAPUS_TEMAN", &hapus_teman);
    strToWord("BUAT_DRAF", &buat_draf);
    strToWord("LIHAT_DRAF", &lihat_draf);
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
    else if (containBlanks(w))
    {
        Word newCmd;
        Word *param;
        parseMultiCmd(w, &newCmd, &param);
        if (isKataEqual(newCmd, lihat_profil))
        {
            if (isLogin)
            {
                LihatProfil((param)[0]);
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
                int id = wordToInteger(param[0]);
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
                int id = wordToInteger(param[0]);
                ubahKicauan(id);
            }
            else
            {
                printf("Anda belum login! masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
    }
}