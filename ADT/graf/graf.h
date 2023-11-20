#ifndef GRAF_H
#define GRAF_H

#include "../boolean/boolean.h"

#define SIZE_CAP 20
#define IDX_UNDEF -1

typedef struct
{
   int mem[SIZE_CAP][SIZE_CAP];
   int nEff;
} AdjMatrix;

#define NEFFM(M) (M).nEff
#define ELMTADJMAT(M, i, j) (M).mem[(i)][(j)]

void CreateAdjMatrix(int nEff, AdjMatrix *m);

void InsertEdge(AdjMatrix *m, int i, int j);

void DeleteEdge(AdjMatrix *m, int i, int j);

void DisplayAdjMatrix(AdjMatrix m);

#endif