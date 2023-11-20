#ifndef TEMAN_H
#define TEMAN_H

#include "../../ADT/boolean/boolean.h"
#include "../../ADT/wordmachine/wordmachine.h"
#include "../../ADT/graf/graf.h"

extern AdjMatrix matrixPertemanan;

void CreateAdjMatrixFile(AdjMatrix *m, Word w, int Neff);

void printDaftarTeman();

int jumlahTeman();

void daftarTeman();

boolean isFriendsWith(Word nama);

void removeTeman(AdjMatrix *m, Word nama);

void hapusTeman();

#endif