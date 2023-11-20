#ifndef DRAF_H
#define DRAF_H

#include "../../ADT/boolean/boolean.h"
#include "../../ADT/wordmachine/wordmachine.h"
#include "../../ADT/datetime/datetime.h"
#include "../kicau/kicau.h"

#define Nil -1
#define MaxEl 1000
/* Nil adalah stack dengan elemen kosong . */

// Tipe Draf
typedef struct
{
  DATETIME datetimeDraf;
  Word textDraf;
  Word authorDraf;
} Draf;

/* Definisi akses dengan Selektor : Set dan Get */
#define datetimeDraf(d) (d).datetimeDraf
#define textDraf(d) (d).textDraf
#define authorDraf(d) (d).authorDraf

/* Stack Draf */
typedef Draf infotype;
typedef int address; /* indeks tabel */

/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
  infotype T[MaxEl]; /* tabel penyimpan elemen */
  address TOP;       /* alamat TOP: elemen puncak */
} StackDraf;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateDraf(Draf *D);
/* I.S. Sembarang */
/* F.S. Membuat sebuah draf D */

void CreateDrafFile(Draf *D, Word nama, Word text, DATETIME dt);
/* I.S. Sembarang */
/* F.S. Membuat sebuah draf D dari file*/

void CreateEmptyDraft(StackDraf *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsDraftEmpty(StackDraf S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsDraftFull(StackDraf S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushDraft(StackDraf *S, infotype D);
/* Menambahkan D sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopDraft(StackDraf *S, infotype *D);
/* Menghapus D dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

/* ************ Menampilkan sebuah elemen Stack ************ */
void DisplayDraf(StackDraf *S);
/* Menampilkan draf terakhir */
/* I.S. S terdefinisi */
/* F.S. Menampilkan InfoTop dari Stack Draf / draf terakhir */

/* ************ Skema Pemrosesan Draf ********************** */
void HapusDraf();

void SimpanDraf();

void TerbitDraf();

void DrafToKicau(Draf D, Kicauan *Kicau);

void BuatDraf();

void LihatDraf();

int CountDraftUser(StackDraf SDraf, Word nama);

#endif