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
    TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
    if (*p != NULL)
    {
        root(*p) = val;
        child(*p) = NULL;
        nextchild(*p) = NULL;
    }
    return *p;
}

boolean isTreeEmpty(TreeNode *p)
/* Fungsi untuk mengecek apakah pohon kosong
   Mengirimkan true jika p adalah pohon yang kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    return (*p == NULL);
}

boolean isOneElmt(TreeNode *p)
{
    /* Fungsi untuk mengecek apakah pohon hanya terdiri dari satu elemen
        Pohon tidak kosong dan tidak memiliki anak dan saudara berikutnya */
    return (*p != NULL && child(*p) == NULL && nextchild(*p) == NULL);
}

void addChild(TreeNode *parent, TreeNode *child)
/* I.S. p terdefinisi
   F.S. child menjadi cabang atau daun baru dari parent
/* proses: menambahkan anak ke sebuah node */
{
    if (child(parent) == NULL)
    {
        child(parent) = child;
    }
    else
    {
        TreeNode *sibling = child(parent);
        while (nextchild(sibling) != NULL)
        {
            sibling = nextchild(sibling);
        }
        nextchild(sibling) = child;
    }
}

void deleteTree(TreeNode *tree, ElType val)
/* I.S. p terdefinisi
   F.S. p dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address p,
   Menghapus tree akan dilakukan secara cascade,
   dimana peranakannya ikut terhapus */
{
    if (tree == NULL)
    {
        return;
    }

    /* Hapus child dulu */
    TreeNode *loc = child(tree);
    TreeNode *prevChild = NULL;
    while (loc != NULL)
    {
        TreeNode *next = nextchild(loc);
        if (root(loc) == val)
        {
            loc = NULL;
            // hapus nextchildnya
            if (prevChild == NULL)
            {
                child(tree) = next;
            }
            else
            {
                nextchild(prevChild) = next;
            }
            free(loc);
        }
        else
        {
            deleteTree(loc, val);
        }
        prevChild = loc;
        loc = next;
    }
}

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

    printTree(node->child, depth + 1); // Cetak anak pertama
    printTree(node->nextchild, depth); // Cetak saudara berikutnya
}

TreeNode *searchTree(TreeNode *node, int val)
/* Fungsi untuk mencari val pada tree
   Mengembalikan TreeNode ditemukannya val */
{
    if (node == NULL)
    {
        return NULL; // basis node tidak ditemukan
    }

    if (root(*node) == id)
    {
        return node; // basis node ditemukan
    }

    TreeNode *found = searchTree(child(*node), id);
    if (found == NULL)
    {
        found = searchTree(nextchild(*node), id);
    }

    return found;
}





















































