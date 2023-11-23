#ifndef KICAU_H
#define KICAU_H

#define MAX_CHAR 280
#define IDX_MIN 0

#include "../../ADT/boolean/boolean.h"
#include "../../ADT/wordmachine/wordmachine.h"
#include "../../ADT/datetime/datetime.h"
#include "../../features/utas/utas.h"

typedef struct node *Address;
// Tipe Kicauan
typedef struct
{
    int idKicau;
    Word textKicau;
    int likeKicau;
    Word authorKicau;
    DATETIME datetimeKicau;
    Address utasUtama;
    int idUtasKicau;
} Kicauan;

// SELEKTOR
#define idKicau(p) (p).idKicau
#define textKicau(p) (p).textKicau
#define likeKicau(p) (p).likeKicau
#define authorKicau(p) (p).authorKicau
#define datetimeKicau(p) (p).datetimeKicau
#define utasUtama(p) (p).utasUtama
#define idUtasKicau(p) (p).idUtasKicau

/* List dinamis dengan implementasi rata kiri*/
/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct
{
    Kicauan *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;        /* >=0, banyaknya elemen efektif */
    int capacity;    /* ukuran elemen */
} ListKicauan;

/* SELEKTOR */
#define NEFFKicau(l) (l).nEff
#define BUFFERKicau(l) (l).buffer
#define ELMTKicau(l, i) (l).buffer[i]
#define CAPACITYKicau(l) (l).capacity

/* VALIDATOR */
boolean kicauanValid();
/* Mengirim True jika jumlah karakter kicauan tidak lebih dari MAX_CHAR */

boolean kicauanBlanks();
/* Mengirim True jika karakter kicauan kosong */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyKicauan(ListKicauan l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */

/* *** Test list penuh *** */
boolean isFullKicauan(ListKicauan l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

void CreateListKicauan(ListKicauan *l);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateListKicau();
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

int countKicauan();
/* Mengirimkan banyaknya kicauan, yaitu neff */
/* Mengirimkan nol jika list l kosong */

/* *** Selektor INDEKS *** */
IdxType getFirstIdxKicauan(ListKicauan l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdxKicauan(ListKicauan l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

void CreateKicau(Kicauan *kicau);
/* I.S. Kicau sembarang */
/* F.S. Terbentuk kicauan dengan komponennya berasal dari masukan user */

void CreateKicauFile(Kicauan *kicau, int id, Word text, int like, Word author, DATETIME dt);
/* I.S. Kicau sembarang */
/* F.S. Terbentuk kicauan dengan komponennya berasal dari file yang telah dibaca */

void insertLastKicauan(Kicauan kicau);
/* I.S. Terdefinisi ListKicauan ListTweet */
/* F.S. Kicau menjadi elemen terakhir ListKicauan ListTweet */

void insertByTime(Kicauan kicau);
/* I.S. Terdefinisi ListKicauan ListTweet */
/* F.S. Kicau menjadi elemen ListKicauan ListTweet terurut berdasarkan DATETIME */

void Kicau();
/* Melakukan kicau sesuai dengan spesifikasi */

void printKicauan();
/* Menampilkan kicauan sesuai dengan spesifikasi */

boolean idValid(int id);
/* Mengrimkan True jika id valid untuk id kicau */

IdxType searchByIdKicau(int idKicau);
/* Mengirim indeks ditemukannya kicauan berdasarkan idKicau dari ListKicauan ListTweet */

Kicauan searchKicau(int idKicau);
/* Mengirim Kicauan berdasarkan idKicau dari ListKicauan ListTweet */

Kicauan searchByIdUtasKicau(int idUtas);
/* Mengirim Kicauan berdasarkan idKicau dari ListKicauan ListTweet */

void sukaKicau(int id);
/* Melakukan suka kicauan sesuai dengan spesifikasi */

void ubahKicauan(int id);
/* Melakukan ubah kicauan sesuai dengan spesifikasi */

void expandListKicau(ListKicauan *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkListKicau(ListKicauan *l, int num);
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressListKicau(ListKicauan *l);
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */

#endif