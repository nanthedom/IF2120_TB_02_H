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
#include "../utas/utas.h"

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

// Draf
extern ListDraf ListStackDraf;

// Balasan
extern int currentIdReply;
extern ListBalasan ListReply;

// Utas
extern int currentIdUtas;

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

void StoreDataPertemanan(int n)
{
    Word tempPertemanan, temp;
    int i, j, k;

    CreateWord(&temp);
    temp.Length = 1;
    ReadLineWithEnter(n);
    tempPertemanan = currentWord;

    i = 0;
    j = 0;
    for (k = 0; k < tempPertemanan.Length; k++)
    {
        if (tempPertemanan.TabWord[k] == '0' || tempPertemanan.TabWord[k] == '1')
        {
            temp.TabWord[0] = tempPertemanan.TabWord[k];
            ELMTADJMAT(matrixPertemanan, i, j) = wordToInteger(temp);
            i++;
            if (i == n)
            {
                i = 0;
                j++;
            }
        }
    }
}

void StoreDataPermintaan(int n)
{
    Word tempPermintaan, temp;
    int i, j, k;

    CreateWord(&temp);
    ReadLineWithEnter(n);
    tempPermintaan = currentWord;

    i = 0;
    j = 0;
    for (k = 0; k < tempPermintaan.Length; k++)
    {
        temp.Length = 0;
        if (tempPermintaan.TabWord[k] != BLANK && tempPermintaan.TabWord[k] != ENTER)
        {
            while (tempPermintaan.TabWord[k] != BLANK && tempPermintaan.TabWord[k] != ENTER)
            {
                temp.TabWord[temp.Length] = tempPermintaan.TabWord[k];
                temp.Length++;
                k++;
            }
            ELMTMAT(matrixPermintaan, i, j) = wordToInteger(temp);
            j++;
            if (j == 3)
            {
                j = 0;
                i++;
                ROW_EFF(matrixPermintaan)
                ++;
            }
        }
    }
}

void loadPengguna(char *path)
{
    int n;
    ReadFromFile(path);
    n = wordToInteger(currentWord);
    StoreDataPengguna(n);
    StoreDataPertemanan(n);
    ReadLine(1);
    n = wordToInteger(currentWord);
    StoreDataPermintaan(n);
}

void StoreDataKicau(int n)
{
    Kicauan tweet;
    int i, id, like;
    Word text, author;
    DATETIME dt;

    for (i = 0; i < n; i++)
    {
        currentIdTweet++;
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

        // inisialisasi ListBalasan
        Balasan Reply;
        createEmptyBalasanFile(tweet, &Reply);
        TreeNode *root = createNode(Reply);
        ElTypeReply elmt;
        createBuffer(&elmt, *root);
        insertLastBalasan(elmt);
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
        authorBalas(reply) = currentWord;
        ReadLine(1);
        DATETIME dt;
        dt = WordToDT(currentWord);
        datetimeBalas(reply) = dt;

        // muat ke tree
        TreeNode *foundNode = searchTree(&content(ELMTBalas(ListReply, idKicau - 1)), idparentInt);
        TreeNode *child = createNode(reply);
        addChild(foundNode, child);

        // load currentIdReply
        if (currentIdReply < idbalasInt)
        {
            currentIdReply = idbalasInt;
        }
        currentIdReply++;
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

void StoreDataDraf()
{
    int i = 0, nDraft, nBlank = 0;
    Word nama;
    CreateWord(&nama);

    ReadLine(1);
    while (i < currentWord.Length)
    {
        // hitung blank
        if (currentWord.TabWord[i] == BLANK)
        {
            nBlank += 1;
        }
        ++i;
    }
    i = 0;
    while (i < currentWord.Length)
    {
        // masukin nama sama jumlah ndraf
        if (currentWord.TabWord[i] == BLANK)
        {
            nBlank -= 1;
        }
        if (nBlank > 0)
        {
            nama.TabWord[i] = currentWord.TabWord[i];
            nama.Length += 1;
        }
        else
        {
            i++;
            nDraft = currentWord.TabWord[i] - '0';
        }
        i++;
    }

    int index = searchIdxStackPengguna(nama);
    // masukin draft
    while (nDraft > 0)
    {
        Draf D;
        Word text;
        CreateWord(&text);

        ReadLine(1);
        text = currentWord;
        ReadLine(1);
        DATETIME dt;
        dt = WordToDT(currentWord);
        CreateDrafFile(&D, nama, text, dt);
        PushLoad(&ELMTDraf(ListStackDraf, index), D);
        nDraft--;
    }
}

void loadDraf(char *path)
{
    ReadFromFile(path);
    int N = wordToInteger(currentWord);
    for (int i = 0; i < N; i++)
    {
        StoreDataDraf();
    }
}

void StoreDataUtas(int idKicau, int n, int idtweet, List *LUtas)
{
    idUtasKicau(ELMTKicau(ListTweet, idtweet)) = currentIdUtas;
    int i, idx = 1;
    List l;
    Address p;
    p = utasUtama(ELMT(ListTweet, idtweet));
    FIRST(l) = p;
    for (i = 0; i < n; i++)
    {
        Utas utas;

        idUtas(utas) = currentIdUtas;
        idParent(utas) = idKicau;
        ReadLine(1);
        textUtas(utas) = currentWord;
        ReadLine(1);
        authorUtas(utas) = currentWord;
        ReadLine(1);
        DATETIME dt;
        dt = WordToDT(currentWord);
        datetimeUtas(utas) = dt;
        indexUtas(utas) = idx;
        idx++;
        insertLastUtas(&l, utas);
    }
    *LUtas = l;
}

void loadUtas(char *path)
{
    ReadFromFile(path);
    int nElmt = wordToInteger(currentWord);
    for (int i = 0; i < nElmt; i++)
    {
        int idKicau;
        ReadLine(1);
        idKicau = wordToInteger(currentWord);
        int len;
        ReadLine(1);
        len = wordToInteger(currentWord);
        currentIdUtas++;
        int idtweet = searchByIdKicau(idKicau);
        List l;
        StoreDataUtas(idKicau, len, idtweet, &l);
        utasUtama(ELMT(ListTweet, idtweet)) = FIRST(l);
    }
}

void load(Word dir)
{
    Word filepengguna;
    Word filekicauan;
    Word filebalasan;
    Word filedraf;
    Word fileutas;

    strToWord("/pengguna.config", &filepengguna);
    strToWord("/kicauan.config", &filekicauan);
    strToWord("/balasan.config", &filebalasan);
    strToWord("/draf.config", &filedraf);
    strToWord("/utas.config", &fileutas);

    Word WpathPengguna = concatWord(dir, filepengguna);
    Word wpathKicauan = concatWord(dir, filekicauan);
    Word wpathBalasan = concatWord(dir, filebalasan);
    Word wpathDraf = concatWord(dir, filedraf);
    Word wpathUtas = concatWord(dir, fileutas);

    char *pathPengguna;
    char *pathKicauan;
    char *pathBalasan;
    char *pathDraf;
    char *pathUtas;

    wordToString(WpathPengguna, &pathPengguna);
    wordToString(wpathKicauan, &pathKicauan);
    wordToString(wpathBalasan, &pathBalasan);
    wordToString(wpathDraf, &pathDraf);
    wordToString(wpathUtas, &pathUtas);

    loadPengguna(pathPengguna);
    loadKicauan(pathKicauan);
    loadBalasan(pathBalasan);
    loadDraf(pathDraf);
    loadUtas(pathUtas);

    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n\n");
}

void loadfirst()
{
    Word parentPath;
    strToWord("data/", &parentPath);
    boolean succes = false;
    while (!succes)
    {
        printf("\n");
        printf("Silahkan masukkan folder konfigurasi untuk dimuat: ");
        ReadWord();
        printf("\n");

        Word relativePath = currentWord;
        Word completePath = concatWord(parentPath, relativePath);
        char *path;
        wordToString(completePath, &path);
        struct stat st = {0};
        if (stat(path, &st) == -1)
        {
            printf("\n");
            printf("Tidak ada folder yang dimaksud!\n");
            printf("\n");
        }
        else
        {
            load(completePath);
            succes = true;
        }
    }
}

void clearAllKicau()
{
    int i;
    for (i = 0; i < countKicauan(ListTweet); i++)
    {
        // Hapus semua utas pada sebuah kicauan
        deleteListUtas(&utasUtama(ELMTKicau(ListTweet, i)));
    }
    dealocateListKicau();
}

void clearAllBalasan()
{
    int i;
    for (i = 0; i < countKicauBalasan(ListReply); i++)
    {
        // Hapus semua balasan pada setiap kicauan yang memiliki balasan
        deleteTree(&content(ELMTBalas(ListReply, i)), -1, i);
    }
    dealocateListBalasan();
}

void Muat()
{
    clearAllKicau();   // hapus kicau dan utas di dalamnya
    clearAllBalasan(); // hapus balasan seluruhnya

    currentIdTweet = 0;
    currentIdReply = 0;
    currentIdUtas = 0;
    CreateListKicauan(&ListTweet);
    createListBalasan(&ListReply);
    CreateList(&ListUser);
    CreateListDraf(&ListStackDraf);
    CreateAdjMatrix(20, &matrixPertemanan);
    createMatrix(0, 3, &matrixPermintaan);

    printf("Masukkan nama folder yang hendak dimuat.\n");
    ReadWord();
    Word parentPath;
    strToWord("data/", &parentPath);
    Word relativePath = currentWord;
    Word completePath = concatWord(parentPath, relativePath);
    char *path;
    wordToString(completePath, &path);
    struct stat st = {0};
    if (stat(path, &st) == -1)
    {
        printf("\n");
        printf("Tidak ada folder yang dimaksud!\n");
        printf("\n");
    }
    else
    {
        load(completePath);
        printf("Mohon tunggu...\n1...\n2...\n3...\n\nPemuatan selesai!\n\n");
    }
}