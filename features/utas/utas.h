#ifndef UTAS_H
#define UTAS_H

#include "../../ADT/boolean/boolean.h"
#include "../../ADT/wordmachine/wordmachine.h"
#include "../../ADT/datetime/datetime.h"

/* Tipe Utas */
typedef struct
{
  int idUtas;
  int index;
  Word textUtas;
  Word authorUtas;
  DATETIME datetimeUtas;
} Utas;

/* Definisi Node : */
typedef Utas ElType;
typedef struct node *Address;
typedef struct node
{
  ElType info;
  Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(ElType val);

typedef Address List;

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

#endif