#ifndef POHONBINER_H
#define POHONBINER_H

#include "../boolean/boolean.h"
#include "../../ADT/wordmachine/wordmachine.h"
#include "../../ADT/datetime/datetime.h"

// Tipe Balasan
typedef struct
{
    int id;
    Word text;
    Word author;
    DATETIME datetime;
} Balasan;

/* Selektor */
#define id(p) (p)->id
#define text(p) (p)->text
#define author(p) (p)->author
#define datetime(p) (p)->datetime

/* Tipe tree Balasan */
typedef struct treeNode* Address;
typedef struct treeNode { 
     Balasan info;
     Address *child;
} TreeNode;

/* Selektor */
#define root(p) (p)->info
#define child(p) (p)->child

typedef Address Tree;

/* List dinamis dengan implementasi rata kiri */
typedef Tree ElType;
typedef int IdxType;
typedef struct 
{
    ElType *buffer;
    int nEff;
    int capacity;
} ListBalasan;

void CreateBalasan(Balasan *reply);

// Tree NewTree (ElType root, Tree left_tree, Tree right_tree); 
// /* Menghasilkan sebuah tree jika alokasi berhasil 
//    Menghasilkan pohon kosong (NULL) jika alokasi gagal */

// void CreateTree (ElType root, Tree left_tree, Tree right_tree, Tree *p);
// /* I.S. Sembarang
//    F.S. Menghasilkan sebuah pohon p

// Address newTreeNode(ElType val);
// /* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
// /* Mengirimkan address hasil alokasi sebuah elemen bernilai val
//    Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
//    menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
//    Jika alokasi gagal, mengirimkan NULL */

// void deallocTreeNode (Address p);
// /* I.S. p terdefinisi 
//    F.S. p dikembalikan ke sistem 
//    Melakukan dealokasi/pengembalian address p */

// boolean isTreeEmpty (Tree p);
// /* Mengirimkan true jika p adalah pohon biner yang kosong */

// boolean isOneElmt (Tree p);
// /* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

// boolean isUnerLeft (Tree p);
// /* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
//    hanya mempunyai subpohon kiri */

// boolean isUnerRight (Tree p);
// /* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
//    hanya mempunyai subpohon kanan */

// boolean isBinary (Tree p);
// /* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
//   mempunyai subpohon kiri dan subpohon kanan */

// /* ****** Display Tree ***** */
// void printPreorder(Tree p);
// /* I.S. p terdefinisi */
// /* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
//    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
//    Pohon kosong ditandai dengan ().
//    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
// /* Contoh: 
//    (A()()) adalah pohon dengan 1 elemen dengan akar A
//    (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */

// void printInorder(Tree p);
// /* I.S. p terdefinisi */
// /* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
//    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
//    Pohon kosong ditandai dengan ().
//    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
// /* Contoh: 
//    (()A()) adalah pohon dengan 1 elemen dengan akar A
//    ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */

// void printPostorder(Tree p);
// /* I.S. p terdefinisi */
// /* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
//    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
//    Pohon kosong ditandai dengan ().
//    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
// /* Contoh: 
//    (()()A) adalah pohon dengan 1 elemen dengan akar A
//    ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */

// void printTree(Tree p, int h);
// /* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
// /* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
// /* Penulisan akar selalu pada baris baru (diakhiri newline) */
// /* Contoh, jika h = 2: 
// 1) Pohon preorder: (A()()) akan ditulis sbb:
// A
// 2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
// A
//   B
//   C
// 3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
// A
//   B
//     D
//   C
//     E
// Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
// */
#endif