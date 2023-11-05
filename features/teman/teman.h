#ifndef TEMAN_H
#define TEMAN_H

#include "../../ADT/boolean/boolean.h"
#include "../../ADT/wordmachine/wordmachine.h"

#define SIZE_CAP 20
#define IDX_UNDEF -1

typedef struct
{
   int mem[SIZE_CAP][SIZE_CAP];
   int nEff;
} AdjMatrix;

#define NEFFM(M) (M).nEff
#define ELMTADJMAT(M, i, j) (M).mem[(i)][(j)]

extern AdjMatrix matrixPertemanan;

void CreateAdjMatrix(int nEff, AdjMatrix *m);

void printDaftarTeman();

int jumlahTeman();

void daftarTeman();

boolean isFriendsWith(Word nama);

void removeTeman(AdjMatrix *m, Word nama);

void hapusTeman();

#endif