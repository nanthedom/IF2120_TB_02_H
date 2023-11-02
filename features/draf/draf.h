#ifndef DRAF_H
#define DRAF_H

#include "../datetime/datetime.h"
#include "../wordmachine/wordmachine.h"

// Tipe Draf
typedef struct
{
  DATETIME datetime;
  Word text;
} Draf;

// SELEKTOR
#define datetime(p) (p).datetime
#define text(p) (p).text

#endif