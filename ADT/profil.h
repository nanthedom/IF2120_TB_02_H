#include "pengguna.h"
#include "wordmachine.h"
#include "pcolor.h"

#ifndef PROFIL_H
#define PROFIL_H

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