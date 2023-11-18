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

void StoreDataPengguna(Word data){
    Word nama,password,bio,no,weton,isPub,pic,publik;
    boolean pub;
    Pengguna P;
    MatrixFoto M;
    strToWord("Publik", &publik);

    // nama
    AdvNewLine(1);
    // nama = currentWord;
    // // password
    // AdvNewLine(1);
    // password = currentWord;
    // // bio
    // AdvNewLine(1);
    // bio = currentWord;
    // // No.HP
    // AdvNewLine(1);
    // no = currentWord;
    // // Weton
    // AdvNewLine(1);
    // weton = currentWord;
    // // isPublic
    // AdvNewLine(1);
    // isPub = currentWord;
    // if(isKataEqual(isPub,publik)){
    //     pub = true;
    // }else{
    //     pub = false;
    // }
    // // ProfPic
    // AdvNewLine(5);
    // pic = currentWord;
    // M = ReadFotoFile(pic);
    // CreatePenggunaFile(&P,nama,password,bio,no,weton,pub,M);
    // insertLast(&ListUser,P);
    
}

void 
// jadinya bikin slicingenter, sama slicingblank.
void loadPengguna(char *path){
    int n,pre,NPermintaan;
    Word dataPengguna,pertemanan,permintaan;

    printf("%s",path);
    ReadFromFile(path);
    printWord(currentWord);
    sliceWordEnter(word,)
    AdvNewLine(1);
    printWord(currentWord);
    // currentChar = currentWord.TabWord[0];
    // ADVFile();
    // printf("s");
    // AdvNewLine(2);
    // printWord(currentWord);
    // n = wordToInteger(currentWord);
    // printf("%d",n);
    // for (int i=0;i<n;++i){
    //     AdvNewLine(11);
    //     dataPengguna = currentWord;
    //     StoreDataPengguna(dataPengguna);
    // }
    // // Pertemanan
    // AdvNewLine(n);
    // pertemanan = currentWord;
    // CreateAdjMatrixFile(&matrixPertemanan,pertemanan,n);
    // AdvNewLine(1);
    // // Permintaan
    // NPermintaan = wordToInteger(currentWord);
    // AdvNewLine(NPermintaan);
    // permintaan =currentWord;
    // MatrixPermintaanFile(permintaan, &matrixPermintaan, NPermintaan);
    // printList(ListUser);

}

void StoreDataKicau(Word w){
    // Kicauan tweet;
    // int id,like;
    // Word text,author;
    // DATETIME dt;

    // AdvNewLine(1);
    // id = wordToInteger(currentWord);
    // AdvNewLine(1);
    // text = currentWord;
    // AdvNewLine(1);
    // like = wordToInteger(currentWord);
    // AdvNewLine(1);
    // author = currentWord;
    // AdvNewLine(1);
    // dt = WordToDT(currentWord);

    // CreateKicauFile(&tweet,id,text,like,author,dt);
    // insertLastKicauan(tweet);
}

void loadKicauan(char *path){
    printf("%s",path);
    // int nKicau;
    
    // ReadFromFile(path);
    // AdvNewLine(1);
    // nKicau = wordToInteger(currentWord);
    // for(int i=0; i<nKicau; ++i){
    //     AdvNewLine(5);
    //     StoreDataKicau(currentWord);
    // }

}
void loadBalasan(char *path){
    printf("%s",path);
    // ReadFromFile(path);
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
    // const char *fileNames[] = {"pengguna.config", "kicauan.config", "balasan.config", "draf.config", "utas.config"};
    // const char *directory= dir.TabWord;
    // char *newPath;
    // char path[256];
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
    // loadKicauan(kicauancfg.TabWord);
    // loadBalasan(balasancfg.TabWord);
    // loadDraf(drafcfg.TabWord);
    // loadUtas(utascfg.TabWord);


    //     snprintf(path,sizeof(path), "%s/%s/%s", "data", directory,fileNames[i]);
        
    //     switch (i){
    //         case 0:
    //             newPath = path;
    //             loadPengguna(newPath);
    //             break;
    //         case 1:
    //             // newPath = path;
    //             // loadKicauan(newPath);
    //             break;
    //         case 2:
    //             // newPath = path;
    //             // loadBalasan(newPath);
    //             break;
    //         case 3:
    //             // newPath = path;
    //             // loadDraf(newPath);
    //             break;
    //         case 4:
    //             // newPath = path;
    //             // loadUtas(newPath);
    //             break;
    //     }
    // }
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


int main(){
    Word x;
    CreateWord(&x);
    ReadWord();
    x = currentWord;
    // printWord(x);
    // printf("\n%s", x.TabWord);
    load(x);
}


