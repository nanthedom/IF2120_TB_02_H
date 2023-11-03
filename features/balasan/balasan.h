#ifndef POHONBINER_H
#define POHONBINER_H

#include "../../ADT/boolean/boolean.h"
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
#define idBalas(p) (p).id
#define textBalas(p) (p).text
#define authorBalas(p) (p).author
#define datetimeBalas(p) (p).datetime

/* Tipe tree Balasan */
typedef struct TreeNode {
    Balasan info;
    struct TreeNode *firstChild;  // Pointer ke anak pertama
    struct TreeNode *nextSibling; // Pointer ke saudara berikutnya
} TreeNode;

/* Selektor */
#define ROOT(p) (p)->info
#define firstChild(p) (p)->firstChild
#define nextSibling(p) (p)->nextSibling

/* List dinamis dengan implementasi rata kiri */
typedef int IdxType;
typedef struct 
{
    TreeNode *buffer;
    int nEff;
    int capacity;
} ListBalasan;

/* Selektor */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

void CreateBalasan(Balasan *reply);

TreeNode *createNode(Balasan reply);
/* Fungsi untuk membuat node baru dengan data tertentu */

void addChild(TreeNode *parent, TreeNode *child);
/* Fungsi untuk menambahkan anak ke sebuah node */

void printTree(TreeNode *node, int depth);
/* Fungsi untuk mencetak pohon dengan banyak cabang secara rekursif */

#endif