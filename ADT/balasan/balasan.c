#include "../pengguna/pengguna.h"
#include "balasan.h"
#include <stdio.h>
#include <stdlib.h>

extern int currentIdReply;
extern Pengguna *currentUser;

void CreateBalasan(Balasan *reply)
{
    id(*reply) = currentIdReply;
    text(*reply) = currentWord;
    author(*reply) = currentUser;
    DATETIME dt;
    BacaDATETIME(&dt);
    datetime(*reply) = dt;
}

Tree NewTree(ElType root)
{
    /* KAMUS */
    Tree p;

    /* ALGORITMA */
    p = (Address)malloc(sizeof(TreeNode));
    if (p != NULL)
    {
        root(p) = root;
        child(p) = (Address)malloc(sizeof(TreeNode));
    }
    return p;
}

void CreateTree(ElType root, Tree left_tree, Tree right_tree, Tree *p)
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p */
{
    /* KAMUS */

    /* ALGORITMA */
    *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val)
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL
   Jika alokasi gagal, mengirimkan NULL */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = (Address)malloc(sizeof(TreeNode));
    if (p != NULL)
    {
        ROOT(p) = val;
    }
}

void deallocTreeNode(Address p)
/* I.S. p terdefinisi
   F.S. p dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address p */
{
    /* KAMUS */

    /* ALGORITMA */
    free(p);
}

boolean isTreeEmpty(Tree p)
/* Mengirimkan true jika p adalah pohon biner yang kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    return (p == NULL);
}

boolean isOneElmt(Tree p)
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */
{
    /* KAMUS */

    /* ALGORITMA */
    return (!isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) == NULL);
}

boolean isUnerLeft(Tree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft:
   hanya mempunyai subpohon kiri */
{
    /* KAMUS */

    /* ALGORITMA */
    return (!isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) == NULL);
}

boolean isUnerRight(Tree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright:
   hanya mempunyai subpohon kanan */
{
    /* KAMUS */

    /* ALGORITMA */
    return (!isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) != NULL);
}

boolean isBinary(Tree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner:
  mempunyai subpohon kiri dan subpohon kanan */
{
    /* KAMUS */

    /* ALGORITMA */
    return (!isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) != NULL);
}

/* ****** Display Tree ***** */
void printTreeLevel(Tree p, int h, int l)
{
    /* KAMUS */
    int N;

    /* ALGORITMA */
    if (!isTreeEmpty(p))
    {
        N = h * l;

        while (N > 0)
        {
            printf(" ");
            N--;
        }

        printf("%d\n", ROOT(p));

        printTreeLevel(LEFT(p), h, l + 1);
        printTreeLevel(RIGHT(p), h, l + 1);
    }
}

void printTree(Tree p, int h)
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/
{
    /* KAMUS */

    /* ALGORITMA */
    printTreeLevel(p, h, 0);
}
