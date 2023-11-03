#include "../pengguna/pengguna.h"
#include "../teman/teman.h"
#include "balasan.h"
#include <stdio.h>
#include <stdlib.h>

extern int currentIdReply;
extern ListPengguna ListUser;
extern Pengguna *currentUser;

void CreateBalasan(Balasan *reply)
{
    idBalas(*reply) = currentIdReply;
    textBalas(*reply) = currentWord;
    authorBalas(*reply) = Nama(*currentUser);
    DATETIME dt;
    BacaDATETIME(&dt);
    datetimeBalas(*reply) = dt;
}

TreeNode *createNode(Balasan reply)
/* Fungsi untuk membuat node baru dengan data tertentu */
{
    TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
    if (p != NULL)
    {
        ROOT(p) = reply;
        firstChild(p) = NULL;
        nextSibling(p) = NULL;
    }
    return p;
}

void addChild(TreeNode *parent, TreeNode *child)
/* Fungsi untuk menambahkan anak ke sebuah node */
{
    if (firstChild(parent) == NULL)
    {
        firstChild(parent) = child;
    }
    else
    {
        TreeNode *sibling = parent->firstChild;
        while (nextSibling(sibling) != NULL)
        {
            sibling = nextSibling(sibling);
        }
        nextSibling(sibling) = child;
    }
}

void printTree(TreeNode *node, int depth)
/* Fungsi untuk mencetak pohon dengan banyak cabang secara rekursif */
{   
    if (node == NULL)
    {
        return;
    }

    for (int i = 0; i < depth; i++)
    {
        printf("   ");
    }
    Balasan reply = ROOT(node);
    int idx = indexOf(ListUser, authorBalas(reply));
    if (isPublic(Profil(ELMT(ListUser, idx))) || isFriendsWith(authorBalas(reply)))
    {
        printf("| ID = %d", idBalas(reply));
        printf("\n| ");
        printWord(authorBalas(reply));
        printf("\n| ");
        TulisDATETIME(datetimeBalas(reply));
        printf("\n| ");
        printWord(textBalas(reply));
        printf("\n");
    }
    else
    {
        printf("| ID = %d\n", idBalas(reply));
        printf("| PRIVAT");
        printf("| PRIVAT");
        printf("| PRIVAT");
    }
    printf("\n");
    printTree(firstChild(node), depth + 1); // Cetak anak pertama
    printTree(nextSibling(node), depth);    // Cetak saudara berikutnya
}

int main()
{
    Balasan a;
    CreateBalasan(&a);
    TreeNode *root = createNode(a);
    TreeNode *child1 = createNode(a);
    TreeNode *child2 = createNode(a);
    TreeNode *child3 = createNode(a);
    TreeNode *child4 = createNode(a);
    TreeNode *child5 = createNode(a);
    TreeNode *child6 = createNode(a);
    TreeNode *child7 = createNode(a);
    TreeNode *child8 = createNode(a);

    addChild(root, child1);
    addChild(root, child2);
    addChild(child2, child3);
    addChild(root, child4);
    addChild(root, child5);
    addChild(root, child6);
    addChild(root, child7);
    addChild(root, child8);
    // addChild(root, child4);

    printf("Pohon dengan banyak cabang:\n");
    printTree(root, 0);

    return 0;
}
