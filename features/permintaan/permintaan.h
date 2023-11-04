#ifndef PERMINTAAN_H
#define PERMINTAAN_H

#include "../../ADT/boolean/boolean.h"
#include "../../ADT/wordmachine/wordmachine.h"
#include "../../ADT/prioqueue/prioqueue.h"
#include "../../ADT/matrix/matrix.h"
#include "../teman/teman.h"
#include "../pengguna/pengguna.h"

extern Matrix matrixPermintaan;
extern PrioQueue daftarPermintaan;

void LoadDaftarPermintaan();

boolean sudahKirimPermintaan(int userIdx, int targetIdx);

void tambahkanPermintaan(int userIdx, int targetIdx);

void TambahTeman();

void printElmtPQ(int idx);

void DaftarPermintaanPertemanan();

void SetujuiPertemanan();

void ClearDaftarPermintaan();

#endif