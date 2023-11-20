#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../../ADT/wordmachine/wordmachine.h"
#include "../pengguna/pengguna.h"
#include "../inisialisasi/inisialisasi.h"
#include "../profil/profil.h"
#include "../kicau/kicau.h"
#include "../teman/teman.h"
#include "../draf/draf.h"
#include "../balasan/balasan.h"
#include "../permintaan/permintaan.h"

// Log
extern boolean isLogin;
extern boolean isClosed;

// Word
extern Word currentWord;

// User
extern ListPengguna ListUser;

// Pertemanan
extern AdjMatrix matrixPertemanan;
extern Matrix matrixPermintaan;

// Kicau
extern int currentIdTweet;
extern ListKicauan ListTweet;
extern StackDraf SDraf;

// Balasan
extern ListBalasan ListReply;

void StoreDataPengguna(int n)
{
    Word nama, password, bio, no, weton, isPub, pic, publik;
    boolean pub;
    Pengguna P;
    MatrixFoto M;
    strToWord("Publik", &publik);
    int i;
    for (i = 0; i < n; i++)
    {
        // nama
        ReadLine(1);
        nama = currentWord;
        // password
        ReadLine(1);
        password = currentWord;
        // bio
        ReadLine(1);
        bio = currentWord;
        // No.HP
        ReadLine(1);
        no = currentWord;
        // Weton
        ReadLine(1);
        weton = currentWord;
        // isPublic
        ReadLine(1);
        isPub = currentWord;
        if (isKataEqual(isPub, publik))
        {
            pub = true;
        }
        else
        {
            pub = false;
        }
        // ProfPic
        ReadLineWithEnter(5);
        pic = currentWord;
        M = ReadFotoFile(pic);
        CreatePenggunaFile(&P, nama, password, bio, no, weton, pub, M);
        insertLast(&ListUser, P);
    }
}

void loadPengguna(char *path)
{
    int n, NPermintaan;
    Word permintaan;

    ReadFromFile(path);
    n = wordToInteger(currentWord);
    StoreDataPengguna(n);

    // Pertemanan
    ReadLineWithEnter(n);
    CreateAdjMatrixFile(&matrixPertemanan, currentWord, n);
    // Permintaan
    ReadLine(1);
    NPermintaan = wordToInteger(currentWord);
    ReadLineWithEnter(NPermintaan);
    permintaan = currentWord;
    MatrixPermintaanFile(permintaan, NPermintaan);
}

void StoreDataKicau(int n)
{
    Kicauan tweet;
    int i, id, like;
    Word text, author;
    DATETIME dt;

    for (i = 0; i < n; i++)
    {
        ReadLine(1);
        id = wordToInteger(currentWord);
        ReadLine(1);
        text = currentWord;
        ReadLine(1);
        like = wordToInteger(currentWord);
        ReadLine(1);
        author = currentWord;
        ReadLine(1);
        dt = WordToDT(currentWord);
        CreateKicauFile(&tweet, id, text, like, author, dt);
        insertLastKicauan(tweet);
        inisialisasiBalasan();
    }
}

void loadKicauan(char *path)
{
    int nKicau;
    ReadFromFile(path);
    nKicau = wordToInteger(currentWord);
    StoreDataKicau(nKicau);
}

void parseID(Word *idparent, Word *idbalas)
{
    int idx = 0, j = 0;
    while (idx < currentWord.Length && currentWord.TabWord[idx] != BLANK)
    {
        (*idparent).TabWord[j] = currentWord.TabWord[idx];
        idx++;
        j++;
    }
    (*idparent).Length = j;
    idx++;
    j = 0;
    while (idx < currentWord.Length && currentWord.TabWord[idx] != BLANK)
    {
        (*idbalas).TabWord[j] = currentWord.TabWord[idx];
        idx++;
        j++;
    }
    (*idbalas).Length = j;
}

void StoreDataBalasan(int idKicau, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        Balasan reply;

        ReadLine(1);
        Word idparent;
        Word idbalas;
        CreateWord(&idparent);
        CreateWord(&idbalas);
        parseID(&idparent, &idbalas);
        int idparentInt = wordToInteger(idparent);
        int idbalasInt = wordToInteger(idbalas);
        idParentBalas(reply) = idparentInt;
        idBalas(reply) = idbalasInt;
        ReadLine(1);
        textBalas(reply) = currentWord;
        ReadLine(1);
        authorBalas(reply) = Nama(*currentUser);
        ReadLine(1);
        DATETIME dt;
        dt = WordToDT(currentWord);
        datetimeBalas(reply) = dt;

        // muat ke tree
        TreeNode *foundNode = searchTree(&content(ELMTBalas(ListReply, idKicau - 1)), idparentInt);
        TreeNode *child = createNode(reply);
        addChild(foundNode, child);
    }
}

void loadBalasan(char *path)
{
    ReadFromFile(path);
    int nElmt;
    nElmt = wordToInteger(currentWord);
    int i;
    for (i = 0; i < nElmt; i++)
    {
        int idKicau;
        ReadLine(1);
        idKicau = wordToInteger(currentWord);
        int countReply;
        ReadLine(1);
        countReply = wordToInteger(currentWord);
        count(ELMT(ListReply, idKicau - 1)) = countReply;
        StoreDataBalasan(idKicau, countReply);
    }
}

void load(Word dir)
{
    Word filepengguna = {"/pengguna.config", 16};
    Word filekicauan = {"/kicauan.config", 15};
    Word filebalasan = {"/balasan.config", 15};
    // Word filedraf = {"/draf.config", 12};
    // Word fileutas = {"/utas.config", 12};

    Word data = {"data/", 5};
    Word path = concatWord(data, dir);
    Word penggunacfg = concatWord(path, filepengguna);
    Word kicauancfg = concatWord(path, filekicauan);
    Word balasancfg = concatWord(path, filebalasan);
    // Word drafcfg = concatWord(path, filedraf);
    // Word utascfg = concatWord(path, fileutas);

    loadPengguna(penggunacfg.TabWord);
    loadKicauan(kicauancfg.TabWord);
    loadBalasan(balasancfg.TabWord);
    loadDraf(drafcfg.TabWord);
    loadUtas(utascfg.TabWord);

}

boolean isDirectoryExists(char *path)
{
    struct stat fileStat;

    if (stat(path, &fileStat) == 0)
    {
        if (S_ISDIR(fileStat.st_mode))
        {
            return true; // Direktori ada
        }
    }

    return false; // Direktori tidak ada
}

void loadfirst()
{
    Word directory;
    boolean succes = false;
    while (!succes)
    {
        printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
        ReadWord();
        directory = currentWord;
        if (isDirectoryExists(directory.TabWord))
        { // udah ada
            load(directory);
            succes = true;
        }
        else
        {
            printf("Tidak ada folder yang dimaksud!");
        }
    }
}

void Muat()
{
    Word directory;
    printf("Masukkan nama folder yang hendak dimuat.");
    ReadWord();
    directory = currentWord;
    if (isDirectoryExists(directory.TabWord))
    { // udah ada
        load(directory);
    }
    else
    {
        printf("Tidak ada folder yang dimaksud!");
    }
}

// int main(){
//     Word x;
//     CreateWord(&x);
//     ReadWord();
//     x = currentWord;
//     // printWord(x);
//     // printf("\n%s", x.TabWord);
//     load(x);
// }
