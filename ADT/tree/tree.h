/* File : bintree.h */
/* ADT pohon biner */
/* Representasi Address dengan pointer */
/* ElType adalah integer */

#ifndef TREE_H
#define TREE_H

#include "../boolean/boolean.h"

typedef int ElType;
/* Tipe tree */
typedef struct TreeNode
{
   ElType info;
   struct TreeNode *child;     // Pointer ke anak pertama
   struct TreeNode *nextchild; // Pointer ke saudara berikutnya
} TreeNode;

/* Selektor */
#define root(p) (p).info
#define child(p) (p).child
#define nextchild(p) (p).nextchild

TreeNode *createNode(ElType val);
/* Fungsi untuk membuat node baru dengan data tertentu */
/* Alokasi sebuah treenode p, bernilai tidak NULL jika berhasil */
/* Mengirimkan treenode hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka treenode tidak NULL, dan misalnya
   menghasilkan p, maka p↑.info=val, p↑.child=NULL, p↑.nextchild=NULL
   Jika alokasi gagal, mengirimkan NULL */

boolean isTreeEmpty(TreeNode p);
/* Fungsi untuk mengecek apakah pohon kosong
   Mengirimkan true jika p adalah pohon biner yang kosong */

boolean isOneElmt(TreeNode *p);
/* Fungsi untuk mengecek apakah pohon hanya terdiri dari satu elemen
    Pohon tidak kosong dan tidak memiliki anak dan saudara berikutnya */

void addChild(TreeNode *parent, TreeNode *child);
/* I.S. p terdefinisi
   F.S. child menjadi cabang atau daun baru dari parent
/* proses: menambahkan anak ke sebuah node */

void deleteTree(TreeNode *tree, ElType val);
/* I.S. p terdefinisi
   F.S. p dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address p,
   Menghapus tree akan dilakukan secara cascade,
   dimana peranakannya ikut terhapus */

/* ****** Display Tree ***** */
void printTree(TreeNode *node, int depth);
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh,
A
  B
    D
  C
    E
*/

TreeNode *searchTree(TreeNode *node, int val);
/* Fungsi untuk mencari val pada tree
   Mengembalikan TreeNode ditemukannya val */




#endif
