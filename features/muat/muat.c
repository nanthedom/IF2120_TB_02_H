#include <stdio.h>
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

extern boolean isLogin;
extern boolean isClosed;
extern Word currentWord;
extern ListPengguna ListUser;
extern AdjMatrix matrixPertemanan;
extern Matrix matrixPermintaan;
extern int currentIdTweet;
extern ListKicauan ListTweet;

void StoreDataPengguna(int n){
    Word nama,password,bio,no,weton,isPub,pic,publik;
    boolean pub;
    Pengguna P;
    MatrixFoto M;
    strToWord("Publik", &publik);
    int i;
    for(i = 0; i < n; i++){
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
        if(isKataEqual(isPub,publik)){
            pub = true;
        }else{
            pub = false;
        }
        // ProfPic
        ReadLineWithEnter(5);
        pic = currentWord;
        M = ReadFotoFile(pic);
        CreatePenggunaFile(&P,nama,password,bio,no,weton,pub,M);
        insertLast(&ListUser,P);
    }
}

void loadPengguna(char *path){
    int n,NPermintaan;
    Word dataPengguna,pertemanan,permintaan;

    ReadFromFile(path);
    // printWord(currentWord);
    n = wordToInteger(currentWord);
    StoreDataPengguna(n);

    // Pertemanan
    ReadLineWithEnter(n);
    CreateAdjMatrixFile(&matrixPertemanan,currentWord,n);
    // Permintaan
    ReadLine(1);
    NPermintaan = wordToInteger(currentWord);
    ReadLineWithEnter(NPermintaan);
    permintaan =currentWord;
    // printWord(currentWord);
    MatrixPermintaanFile(permintaan, NPermintaan);//sudah aman
    // printList(ListUser);

}
//pengguna dah aman

void StoreDataKicau(int n){
    Kicauan tweet;
    int i, id,like;
    Word text,author;
    DATETIME dt;

    for(i = 0; i < n; i++){
        ReadLine(1);
        id = wordToInteger(currentWord);
        ReadLine(1);
        text = currentWord;
        ReadLine(1);
        like = wordToInteger(currentWord);
        ReadLine(1);
        author = currentWord;
        ReadLine(1);
        dt = WordToDT(currentWord); //sudah aman
        // TulisDATETIME(dt);
        CreateKicauFile(&tweet,id,text,like,author,dt);//dah bosa masuk
        // printWord(tweet.textKicau);
        insertLastKicauan(tweet);//dah aman
    }

}

void loadKicauan(char *path){
    int nKicau;
    
    ReadFromFile(path);
    nKicau = wordToInteger(currentWord);
    StoreDataKicau(nKicau);


}
void loadBalasan(char *path){
    // printf("%s",path);
    ReadFromFile(path);
    printWord(currentWord);
    // AdvNewLine(1);
    // printf("%s",currentWord.TabWord);
    // printWord(currentWord);

}
void loadDraf(char *path){
    printf("%s",path);
    // ReadFromFile(path);
    // printWord(currentWord);
}
void loadUtas(char *path){
    printf("%s",path);
    // ReadFromFile(path);
    // printWord(currentWord);
}

Word concatWord(Word w1, Word w2){
    Word ans;
    CreateWord(&ans);
    ans.Length = w1.Length + w2.Length;
    int i;
    for(i = 0; i < w1.Length; i++){
        ans.TabWord[i] = w1.TabWord[i];
    }
    for(i = 0; i < w2.Length;i++){
        ans.TabWord[i+w1.Length] = w2.TabWord[i];
    }
    return ans;
}

void load(Word dir){
    Word filepengguna = {"/pengguna.config",16};
    Word filekicauan = {"/kicauan.config",15};
    Word filebalasan = {"/balasan.config",15};
    Word filedraf = {"/draf.config",12};
    Word fileutas = {"/utas.config",12};

    Word data = {"data/", 5};
    Word path = concatWord(data,dir);
    Word penggunacfg = concatWord(path,filepengguna);
    Word kicauancfg = concatWord(path,filekicauan);
    Word balasancfg = concatWord(path,filebalasan);
    Word drafcfg = concatWord(path,filedraf);
    Word utascfg = concatWord(path,fileutas);

    loadPengguna(penggunacfg.TabWord);
    loadKicauan(kicauancfg.TabWord);
    loadBalasan(balasancfg.TabWord);
    // loadDraf(drafcfg.TabWord);
    // loadUtas(utascfg.TabWord);

}

boolean isDirectoryExists(char *path) {
    struct stat fileStat;

    if (stat(path, &fileStat) == 0) {
        if (S_ISDIR(fileStat.st_mode)) {
            return true; // Direktori ada
        }
    }
    
    return false; // Direktori tidak ada
}

void loadfirst(){
    Word directory;
    boolean succes=false;
    while(!succes){
        printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
        ReadWord();
        directory = currentWord;
        if(isDirectoryExists(directory.TabWord)){// udah ada
            load(directory);
            succes = true;
        }else{
            printf("Tidak ada folder yang dimaksud!");
        }
    }
}
void Muat(){
    Word directory;
    printf("Masukkan nama folder yang hendak dimuat.");
    ReadWord();
    directory = currentWord;
    if(isDirectoryExists(directory.TabWord)){// udah ada
        load(directory);
    }else{
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


