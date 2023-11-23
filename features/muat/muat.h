#include "../../ADT/wordmachine/wordmachine.h"
#include "..//pengguna/pengguna.h"
#include "..//inisialisasi/inisialisasi.h"
#include "..//profil/profil.h"
#include "..//kicau/kicau.h"
#include "..//teman/teman.h"
#include "..//draf/draf.h"
#include "..//balasan/balasan.h"

void StoreDataPengguna(Word data);
void StoreDataPertemanan(int n);
void StoreDataPermintaan(int n);
void loadPengguna(char *path);

void StoreDataKicau(int n);
void loadKicauan(char *path);

void parseID(Word *idparent, Word *idbalas);
void StoreDataBalasan(int idKicau, int n);
void loadBalasan(char *path);

void StoreDataDraf();
void loadDraf(char *path);

void StoreDataUtas(int idKicau, int n, int idtweet, List *LUtas);
void loadUtas(char *path);

void loadfirst();
void load(Word dir);

void Muat();
