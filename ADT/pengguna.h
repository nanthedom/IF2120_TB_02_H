#include "wordmachine.h"
#include "boolean.h"

#ifndef PENGGUNA_H
#define PENGGUNA_H

#define USERMAX 20
#define IDX_UNDEF -1

typedef struct{
    char X;
    char Y;
} Foto;

#define Warna(F) (F).X
#define Karakter(F) (F).Y

#define ROW_CAP 5
#define COL_CAP 5

typedef struct
{
   Foto mem[ROW_CAP][COL_CAP];
} MatrixFoto;

#define PIXEL(M,i,j) (M).mem[(i)][(j)]


typedef struct {
    Word bio;
    Word noHP;
    Word weton;
    boolean isPublic;
    MatrixFoto M;
} Profil;

typedef struct {
    Word Nama;
    Word Password;
    Profil profil;
} Pengguna;

extern Pengguna currentUser;

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