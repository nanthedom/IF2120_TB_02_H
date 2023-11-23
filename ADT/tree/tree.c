#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode *createNode(ElType val)
/* Fungsi untuk membuat node baru dengan data tertentu */
/* Alokasi sebuah treenode p, bernilai tidak NULL jika berhasil */
/* Mengirimkan treenode hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka treenode tidak NULL, dan misalnya
   menghasilkan p, maka p↑.info=val, p↑.child=NULL, p↑.nextchild=NULL
   Jika alokasi gagal, mengirimkan NULL */
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode != NULL)
    {
        newNode->data = val;
        newNode->firstChild = NULL;
        newNode->nextSibling = NULL;
    }
    return newNode;
}

boolean isTreeEmpty(TreeNode *p)
/* Fungsi untuk mengecek apakah pohon kosong
   Mengirimkan true jika p adalah pohon yang kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    return (p == NULL);
}

boolean isOneElmt(TreeNode *p)
{
    /* Fungsi untuk mengecek apakah pohon hanya terdiri dari satu elemen
        Pohon tidak kosong dan tidak memiliki anak dan saudara berikutnya */
    return (p != NULL && child(p) == NULL && nextchild(p) == NULL);
}

void addChild(TreeNode *parent, TreeNode *cc)
/* I.S. p terdefinisi
   F.S. child menjadi cabang atau daun baru dari parent
    proses: menambahkan anak ke sebuah node */
{
    if (parent->firstChild == NULL)
    {
        parent->firstChild = cc;
    }
    else
    {
        TreeNode *sibling = parent->firstChild;
        while (sibling->nextSibling != NULL)
        {
            sibling = sibling->nextSibling;
        }
        sibling->nextSibling = cc;
    }
}

void delete(TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    // Hapus anak-anak terlebih dahulu (rekursif)
    delete(node->firstChild);
    delete(node->nextSibling);

    // Setelah semua anak dihapus, dealokasi memori untuk node ini
    free(node);
}

void deleteTree(TreeNode *node, ElType val)
/* I.S. p terdefinisi
   F.S. p dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address p,
   Menghapus tree akan dilakukan secara cascade,
   dimana peranakannya ikut terhapus */

{
    if (node == NULL)
    {
        return;
    }
    TreeNode *foundNode = searchTree(node, val);
    delete(foundNode);
}

/* ****** Display Tree ***** */
void printTree(TreeNode *node, int depth)
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
{
    if (node == NULL)
    {
        return;
    }

    for (int i = 0; i < depth; i++)
    {
        printf("  ");
    }
    printf("%d\n", node->data);

    printTree(node->firstChild, depth + 1); // Cetak anak pertama
    printTree(node->nextSibling, depth);    // Cetak saudara berikutnya
}

TreeNode *searchTree(TreeNode *node, int val)
/* Fungsi untuk mencari val pada tree
   Mengembalikan TreeNode ditemukannya val */
{
    if (node == NULL)
    {
        return NULL; // Basis: node tidak ditemukan
    }

    if (node->data == val)
    {
        return node; // Basis: node ditemukan
    }

    // Cari di anak pertama dan saudara berikutnya
    TreeNode *found = searchTree(node->firstChild, val);
    if (found == NULL)
    {
        found = searchTree(node->nextSibling, val);
    }

    return found;
}





















































