#ifndef KICAU_H
#define KICAU_H

#define MAX_CHAR 280

#include "../boolean/boolean.h"
#include "../wordmachine/wordmachine.h"
#include "../datetime/datetime.h"

// Tipe Kicauan
typedef struct
{
    int id;
    Word text;
    int like;
    Word author;
    DATETIME datetime;
} Kicauan;

// SELEKTOR
#define id(p) (p).id
#define text(p) (p).text
#define like(p) (p).like
#define author(p) (p).author
#define datetime(p) (p).datetime

/* List dinamis dengan implementasi rata kiri*/
/* Definisi elemen dan koleksi objek */
typedef Kicauan ElType; /* type elemen list */
typedef int IdxType;
typedef struct
{
    ElType *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListKicauan;

/* VALIDATOR */
boolean kicauanValid(Word text);
/* Mengirim True jika jumlah karakter kicauan tidak lebih dari MAX_CHAR */

boolean kicauanEmpty(Word text);
/* Mengirim True jika karakter kicauan kosong */

/* SELEKTOR */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

void CreateListKicauan(ListKicauan *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListKicauan *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

int countKicauan(ListKicauan l);
/* Mengirimkan banyaknya kicauan, yaitu neff */
/* Mengirimkan nol jika list l kosong */

void kicau(ListKicauan *l);

void sukaKicau(ListKicauan *l, int id);

void kicauan(ListKicauan l);

void ubahKicauan(ListKicauan *l, int id);

#endif