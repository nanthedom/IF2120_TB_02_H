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

extern boolean isLogin;
extern boolean isClosed;
extern Word currentWord;

void load(Word dir){
    char *directory = dir.TabWord;
    char *file = "text.txt";
    char *path;
    // const char *fileNames[] = {"pengguna.config", "kicauan.config", "balasan.config", "draf.config", "utas.config"};
    snprintf(path,sizeof(path), "%s/%s", directory,file);
    printf("%s",path);
}

// boolean isDirectoryExists(char *path) {
//     struct stat fileStat;

//     if (stat(path, &fileStat) == 0) {
//         if (S_ISDIR(fileStat.st_mode)) {
//             return true; // Direktori ada
//         }
//     }
    
//     return false; // Direktori tidak ada
// }

// void loadfirst(){
//     Word directory;
//     printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
//     ReadWord();
//     directory = currentWord;
//     if(isDirectoryExists(directory.TabWord)){
//         // udah ada
//         load(directory);
//     }else{
//         printf("Tidak ada folder yang dimaksud!");
//     }
// }
// void muat(Word cmd);

int main(){
    Word x;
    ReadWord();
    x=currentWord;
    // load(x);
}


