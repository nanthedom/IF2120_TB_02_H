#include "../wordmachine/wordmachine.h"
#include "../profil/profil.h"
#include "../boolean/boolean.h"

#ifndef PENGGUNA_H
#define PENGGUNA_H

#define USERMAX 20
#define IDX_UNDEF -1


// Tipe Pengguna
typedef struct {
    Word Nama;
    Word Password;
    Profil profil;
} Pengguna;

extern Pengguna* currentUser;

#define Nama(P) (P).Nama
#define Password(P) (P).Password
#define Profil(P) ((P).profil)

/**List Statik dengan implementasi eksplisit rata kiri*/
typedef struct {
    Pengguna buffer[USERMAX];
    int length;
} ListPengguna;


#define ELMT(l,i) (l).buffer[i]
#define length(l) (l).length

void CreatePengguna(Pengguna* p, Word Nama, Word Password);
void CreateList(ListPengguna*l);
boolean isEmpty(ListPengguna l);
boolean isFull(ListPengguna l);
void printList(ListPengguna l);
int indexOf(ListPengguna l, Word Nama);
void insertLast(ListPengguna* l, Pengguna p);

void Daftar();
void Masuk();
void Keluar();
void TutupProgram();
#endif