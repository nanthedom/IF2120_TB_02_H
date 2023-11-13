#ifndef UTAS_H
#define UTAS_H

#include "../../ADT/boolean/boolean.h"
#include "../../ADT/wordmachine/wordmachine.h"
#include "../../ADT/datetime/datetime.h"
#include "../kicau/kicau.h"
#include "../pengguna/pengguna.h"
#include "../teman/teman.h"

/* Tipe Utas */
typedef struct
{
  int idParent;
  int idUtas;
  int indexUtas;
  Word textUtas;
  Word authorUtas;
  DATETIME datetimeUtas;
} Utas;

#define idParent(u) (u).idParent
#define idUtas(u) (u).idUtas
#define indexUtas(u) (u).indexUtas
#define textUtas(u) (u).textUtas
#define authorUtas(u) (u).authorUtas
#define datetimeUtas(u) (u).datetimeUtas

/* Definisi Node : */
typedef Utas ElTypeUtas;
typedef struct node *Address;
typedef struct node
{
  ElTypeUtas info;
  Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNodeUtas(ElTypeUtas val);

typedef Address List;

// #define IDX_UNDEF NULL
#define FIRST(l) (l)

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListUtas(List *l);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

void CreateUtas(Utas *utas, Word word, int idKicau);

/****************** TEST LIST KOSONG ******************/
boolean isEmptyUtas(List l);
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElTypeUtas getElmtUtas(List l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmtUtas(List *l, int idx, ElTypeUtas val);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOfUtas(List l, ElTypeUtas val);
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstUtas(List *l, ElTypeUtas val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastUtas(List *l, ElTypeUtas val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtUtas(List *l, ElTypeUtas val, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstUtas(List *l, ElTypeUtas *val);
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLastUtas(List *l, ElTypeUtas *val);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAtUtas(List *l, int idx, ElTypeUtas *val);
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

int lengthUtas(List l);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

void utas(int id);

void sambungUtas(int id, int index);

void displayUtas(int id);

#endif