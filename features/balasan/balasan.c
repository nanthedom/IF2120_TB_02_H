#include "../pengguna/pengguna.h"
#include "../teman/teman.h"
#include "balasan.h"
#include <stdio.h>
#include <stdlib.h>

extern int currentIdReply;
extern int currentIdTweet;
extern ListBalasan ListReply;
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
        TreeNode *sibling = firstChild(parent);
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

TreeNode *searchTree(TreeNode *node, int id)
/* Fungsi untuk mencari id pada tree balasan */
{
    if (node == NULL)
    {
        return NULL; // Basis: node tidak ditemukan
    }

    if (idBalas(ROOT(node)) == id)
    {
        return node; // Basis: node ditemukan
    }

    // Cari di anak pertama dan saudara berikutnya
    TreeNode *found = searchTree(firstChild(node), id);
    if (found == NULL)
    {
        found = searchTree(nextSibling(node), id);
    }

    return found;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyBalasan(ListBalasan l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
    return (NEFFBalas(l) == 0);
}
/* *** Test list penuh *** */
boolean isFullBalasan(ListBalasan l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    return (NEFFBalas(l) == CAPACITYBalas(l));
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdxBalasan(ListBalasan l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
    return 0;
}

IdxType getLastIdxBalasan(ListBalasan l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return NEFFBalas(l) - 1;
}

void createListBalasan(ListBalasan *l)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    int capacity = 64;
    BUFFERBalas(*l) = (TreeNode *)malloc(capacity * sizeof(TreeNode));
    NEFFBalas(*l) = 0;
    CAPACITYBalas(*l) = capacity;
}

void expandListBalasan(ListBalasan *l, int num)
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    BUFFERBalas(*l) = (TreeNode *)realloc(BUFFERBalas(*l), (CAPACITYBalas(*l) + num) * sizeof(TreeNode));
    CAPACITYBalas(*l) += num;
}

void insertLastBalasan(TreeNode Reply)
{
    if (isFullBalasan(ListReply))
    {
        expandListBalasan(&ListReply, 2 * CAPACITYBalas(ListReply));
        ELMTBalas(ListReply, getLastIdxBalasan(ListReply) + 1) = Reply;
    }
    else
    {
        ELMTBalas(ListReply, getLastIdxBalasan(ListReply) + 1) = Reply;
    }
    NEFFBalas(ListReply)++;
}

void createEmptyBalasan(Balasan *reply)
{
    Word tweet;
    strToWord("root-kicau", &tweet);
    idBalas(*reply) = -1;
    textBalas(*reply) = tweet;
    authorBalas(*reply) = tweet;
    DATETIME dt;
    BacaDATETIME(&dt);
    datetimeBalas(*reply) = dt;
}

boolean idKicauValid(int idKicau)
/* Mengirim True jika idKicau valid */
{
    return idKicau > 0 && idKicau <= currentIdTweet;
}

boolean idbalasValid(int idBalas)
/* Mengirim True jika idBalas valid */
{
    return idBalas > 0 && idBalas <= currentIdReply;
}

boolean balasanValid()
/* Mengirim True jika jumlah karakter balasan tidak lebih dari MAX_CHAR */
{
    return currentWord.Length > 0 && currentWord.Length <= 280;
}

boolean balasanBlanks()
/* Mengirim True jika karakter balasan kosong */
{
    int i = 0;
    boolean found = true;
    while (i < currentWord.Length && found)
    {
        if (currentWord.TabWord[i] == BLANK || currentWord.TabWord[i] == MARK)
        {
            i++;
        }
        else
        {
            found = false;
        }
    }
    return found;
}

void buatBalasan(int idKicau, int idBalas)
{
    if (idKicauValid(idKicau))
    {
        if (idbalasValid(idBalas) || idBalas == -1)
        {
            printf("\nMasukkan balasan:\n");
            ReadWord();
            Balasan reply;
            CreateBalasan(&reply);
            TreeNode *child = createNode(reply);
            TreeNode *foundNode = searchTree(&ELMTBalas(ListReply, idKicau - 1), idBalas);
            addChild(foundNode, child);
        }
        else
        {
            printf("\n");
            printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
            printf("\n");
        }
    }
    else
    {
        printf("\n");
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
        printf("\n");
    }
}

void printBalasan(int idKicau)
{
    TreeNode node = ELMTBalas(ListReply, idKicau - 1);
    printTree(&node, 1);
}