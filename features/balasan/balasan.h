#ifndef POHONBINER_H
#define POHONBINER_H

#include "../../ADT/boolean/boolean.h"
#include "../../ADT/wordmachine/wordmachine.h"
#include "../../ADT/datetime/datetime.h"

// Tipe Balasan
typedef struct
{
    int idbalas;
    int idparentBalas;
    Word text;
    Word author;
    DATETIME datetime;
} Balasan;

/* Selektor */
#define idBalas(p) (p).idbalas
#define idParentBalas(p) (p).idparentBalas
#define textBalas(p) (p).text
#define authorBalas(p) (p).author
#define datetimeBalas(p) (p).datetime

/* Tipe tree Balasan */
typedef struct TreeNode
{
    Balasan info;
    struct TreeNode *firstChild;  // Pointer ke anak pertama
    struct TreeNode *nextSibling; // Pointer ke saudara berikutnya
} TreeNode;

/* Selektor */
#define ROOT(p) (p).info
#define firstChild(p) (p)->firstChild
#define nextSibling(p) (p)->nextSibling

typedef struct ElTypeReply
{
    TreeNode content;
    int count;
} ElTypeReply;

/* Selektor */
#define content(l) (l).content
#define count(l) (l).count

/* List dinamis dengan implementasi rata kiri */
typedef int IdxType;
typedef struct
{
    ElTypeReply *buffer;
    int nEff;
    int capacity;
} ListBalasan;

/* Selektor */
#define NEFFBalas(l) (l).nEff
#define BUFFERBalas(l) (l).buffer
#define ELMTBalas(l, i) (l).buffer[i]
#define CAPACITYBalas(l) (l).capacity

void createBalasan(Balasan *reply, int idprnt);
/* Terbentuk balasan dengan id, text, author, dan waktu yang valid */

void createEmptyBalasan(Balasan *reply);

TreeNode *createNode(Balasan reply);
/* Fungsi untuk membuat node baru dengan data tertentu */

void createBuffer(ElTypeReply *elmt, TreeNode reply);

void addChild(TreeNode *parent, TreeNode *child);
/* Fungsi untuk menambahkan anak ke sebuah node */

void printTree(TreeNode *node, int depth);
/* Fungsi untuk mencetak pohon dengan banyak cabang secara rekursif */

TreeNode *searchTree(TreeNode *node, int id);
/* Fungsi untuk mencari id pada tree balasan */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyBalasan(ListBalasan l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullBalasan(ListBalasan l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* *** Selektor INDEKS *** */
IdxType getFirstIdxBalasan(ListBalasan l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */

IdxType getLastIdxBalasan(ListBalasan l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

int countKicauBalasan(ListBalasan l);
/* Mengembalikan jumlah kicauan yang memiliki balasan */

void createListBalasan(ListBalasan *l);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void expandListBalasan(ListBalasan *l, int num);
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void insertLastBalasan(ElTypeReply Reply);

void createEmptyBalasan(Balasan *reply);

void createEmptyBalasanFile(Kicauan tweet, Balasan *reply);

boolean idKicauValid(int idKicau);
/* Mengirim True jika idKicau valid */

boolean idbalasValid(int idBalas);
/* Mengirim True jika idBalas valid */

boolean balasanValid();
/* Mengirim True jika jumlah karakter balasan tidak lebih dari 280 */

boolean balasanBlanks();
/* Mengirim True jika karakter balasan kosong */

void inisialisasiBalasan();

void buatBalasan(int idKicau, int idBalas);

void printBalasan(int idKicau);

void deleteTree(TreeNode *reply, int id, int idxtweet);

void hapusBalasan(int idKicau, int idBalas);

void dealocateListBalasan();

#endif