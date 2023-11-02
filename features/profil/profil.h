#include "../../ADT/wordmachine/wordmachine.h"
#include "../../ADT/pcolor/pcolor.h"

#ifndef PROFIL_H
#define PROFIL_H
// Tipe Foto (Satuan Foto)
typedef struct
{
    char X;
    char Y;
} Foto;

#define Warna(F) (F).X
#define Karakter(F) (F).Y

#define ROW_CAP 5
#define COL_CAP 5

// Tipe MatriksFoto
typedef struct
{
    Foto mem[ROW_CAP][COL_CAP];
} MatrixFoto;

#define PIXEL(M, i, j) (M).mem[(i)][(j)]

// Tipe Profil
typedef struct
{
    Word bio;
    Word noHP;
    Word weton;
    boolean isPublic;
    MatrixFoto M;
} Profil;

#define Bio(P) (P).bio
#define NoHP(P) (P).noHP
#define Weton(P) (P).weton
#define isPublic(P) (P).isPublic
#define Profpic(P) (P).M

void CreateMatrixFoto(MatrixFoto *M);
void CreateProfil(Profil *P);
void ReadBio(Profil *P);
void ReadNoHP(Profil *P);
boolean isPahing(Word weton);
boolean isKliwon(Word weton);
boolean isLegi(Word weton);
boolean isWage(Word weton);
boolean isPon(Word weton);
boolean isWetonValid(Word weton);
void ReadWeton(Profil *P);
void ReadFoto(Profil *P);
void PrintFoto(Profil P);
void displayProfil();
void GantiProfil();
void LihatProfil(Word Nama);
void AturJenisAkun();
void UbahFotoProfil();

#endif