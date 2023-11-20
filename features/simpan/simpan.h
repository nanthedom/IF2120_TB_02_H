#include "../../ADT/wordmachine/wordmachine.h"
#include "../pengguna/pengguna.h"
#include "../kicau/kicau.h"

void Simpan();
/* Melakukan prosedur simpan sesuai dengan spesifikasi */

void printWordToFile(Word w, FILE* filename); 
/* Menulis w ke dalam file diakhiri dengan \n */

void SimpanPengguna(Word path);
/* Menyimpan data pengguna ke file pengguna.config sesuai dengan spesifikasi*/

void simpanKicauan(Word path);
/* Menyimpan data kicauan ke file kicauan.config sesuai dengan spesifikasi*/

void simpanBalasan(Word path);
/* Menyimpan data kicauan ke file balasan.config sesuai dengan spesifikasi*/

void simpanDraf(Word path);
/* Menyimpan data Draf ke file draf.config sesuai dengan spesifikasi*/

void simpanUtas(Word path);
/* Menyimpan data Utas ke file utas.config sesuai dengan spesifikasi*/

#endif