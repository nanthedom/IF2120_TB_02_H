#ifndef KICAU_H
#define KICAU_H

#define MAX_CHAR 280
#define IDX_MIN 0

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
boolean kicauanValid();
/* Mengirim True jika jumlah karakter kicauan tidak lebih dari MAX_CHAR */

boolean kicauanBlanks();
/* Mengirim True jika karakter kicauan kosong */

/* SELEKTOR */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

void CreateListKicauan();
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList();
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

int countKicauan();
/* Mengirimkan banyaknya kicauan, yaitu neff */
/* Mengirimkan nol jika list l kosong */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListKicauan l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListKicauan l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

void CreateKicau(Kicauan *kicau);

void insertLastKicauan(ListKicauan *l, Kicauan kicau);

void kicau();

void kicauan();

void sukaKicau(int id);

void ubahKicauan(int id);

void expandList(ListKicauan *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListKicauan *l, int num);
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListKicauan *l);
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */

#endif