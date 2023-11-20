#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "simpan.h"

// User
extern ListPengguna ListUser;
// Kicauan
extern ListKicauan ListTweet;
// Balasan
extern ListBalasan ListReply;

void Simpan()
/* Melakukan prosedur simpan sesuai dengan spesifikasi */
{
    Word parentPath;
    strToWord("data/", &parentPath);
    printf("Masukkan nama folder penyimpanan: ");
    ReadWord();
    Word relativePath = currentWord;
    Word completePath = concatWord(parentPath, relativePath);
    char *path;
    // printWord(completePath);
    wordToString(completePath, &path);
    struct stat st = {0};
    if (stat(path, &st) == -1)
    {
        printf("Belum terdapat ");
        printWord(relativePath);
        printf(". Akan dilakukan pembuatan ");
        printWord(relativePath);
        printf(" terlebih dahulu.\n");
        if (mkdir(path, 0777) == 0)
        {
            printf("Directory created: %s\n", path);
            printf("Mohon tunggu... \n");
            printf("1...\n");
            printf("2...\n");
            printf("3...\n");
            printWord(relativePath);
            printf(" telah berhasil dibuat\n");
        }
        else
        {
            perror("mkdir");
        }
    }
    SimpanPengguna(completePath);
}

void printWordToFile(Word w, FILE *filename)
/* Menulis w ke dalam file diakhiri dengan \n */
{
    int i;
    for (i = 0; i < w.Length; i++)
    {
        fprintf(filename, "%c", w.TabWord[i]);
    }
    fprintf(filename, "\n");
}

void SimpanPengguna(Word path)
/* Menyimpan data pengguna ke file pengguna.config sesuai dengan spesifikasi*/
{
    int n, i;
    Word w;
    FILE *userconfig;
    char *confPath;
    Word penggunaConfig;
    strToWord("/pengguna.config", &penggunaConfig);
    Word configPath = concatWord(path, penggunaConfig);
    wordToString(configPath, &confPath);
    // printWord(configPath);
    userconfig = fopen(confPath, "w");
    n = length(ListUser);
    fprintf(userconfig, "%d\n", n);
    for (i = 0; i < length(ListUser); i++)
    {
        printWordToFile(Nama(ELMT(ListUser, i)), userconfig);
        printWordToFile(Password(ELMT(ListUser, i)), userconfig);
        printWordToFile(Bio(Profil(ELMT(ListUser, i))), userconfig);
        printWordToFile(NoHP(Profil(ELMT(ListUser, i))), userconfig);
        printWordToFile(Weton(Profil(ELMT(ListUser, i))), userconfig);
        if (isPublic(Profil(ELMT(ListUser, i))))
        {
            fprintf(userconfig, "Publik\n");
        }
        else
        {
            fprintf(userconfig, "Privat\n");
        }
        int a, b;
        for (a = 0; a < 5; a++)
        {
            for (b = 0; b < 5; b++)
            {
                fprintf(userconfig, "%c ", Warna(PIXEL(Profpic(Profil(ELMT(ListUser, i))), a, b)));
                fprintf(userconfig, "%c", Karakter(PIXEL(Profpic(Profil(ELMT(ListUser, i))), a, b)));
                if (b < 4)
                {
                    fprintf(userconfig, " ");
                }
            }
            fprintf(userconfig, "\n");
        }
    }

    // SIMPAN MATRIKS PERTEMANAN DAN PERMINTAAN PERTEMANAN
}

void simpanKicauan(Word path)
/* Menyimpan data kicauan ke file kicauan.config sesuai dengan spesifikasi*/
{
    Word kicauanConfig, configPath;
    char *fconfPath;
    FILE *fconfKicauan;
    strToWord("/kicauan.config", &kicauanConfig);
    configPath = concatWord(path, kicauanConfig);
    wordToString(configPath, &fconfPath);
    fconfKicauan = fopen(fconfPath, "w");

    int count;
    count = countKicauan(ListTweet);
    fprintf(fconfKicauan, "%d\n", count);

    int i;
    for (i = 0; i < count; i++)
    {
        printWordToFile(idKicau(ELMTKicau(ListTweet, i)), fconfKicauan);
        printWordToFile(textKicau(ELMTKicau(ListTweet, i)), fconfKicauan);
        printWordToFile(likeKicau(ELMTKicau(ListTweet, i)), fconfKicauan);
        printWordToFile(authorKicau(ELMTKicau(ListTweet, i)), fconfKicauan);
        printWordToFile(datetimeKicau(ELMTKicau(ListTweet, i)), fconfKicauan);
    }

    fclose(fconfKicauan);
}
