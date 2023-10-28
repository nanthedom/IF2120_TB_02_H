#include "wordmachine.h"
#include "boolean.h"

#ifndef PENGGUNA_H
#define PENGGUNA_H

#define USERMAX 20
#define IDX_UNDEF -1

typedef struct {
    Word Nama;
    Word Password;
} Pengguna;

extern Pengguna currentUser;

#define Nama(P) (P).Nama
#define Password(P) (P).Password

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
int indexOfNama(ListPengguna l, Word Nama);
int indexOfPassword(ListPengguna l, Word Password);
void insertLast(ListPengguna* l, Pengguna p);

void Daftar();
void Masuk();
void Keluar();
void TutupProgram();
#endif