#include "../pengguna/pengguna.h"
#include "../teman/teman.h"
#include "../kicau/kicau.h"
#include "balasan.h"
#include <stdio.h>
#include <stdlib.h>

extern int currentIdReply;
extern int currentIdTweet;
extern ListBalasan ListReply;
extern ListKicauan ListTweet;
extern ListPengguna ListUser;
extern Pengguna *currentUser;

void CreateBalasan(Balasan *reply, int idprnt)
{
    idBalas(*reply) = currentIdReply;
    idparent(*reply) = idprnt;
    textBalas(*reply) = currentWord;
    authorBalas(*reply) = Nama(*currentUser);
    DATETIME dt;
    BacaDATETIME(&dt);
    datetimeBalas(*reply) = dt;
}

void CreateBalasanFile()
{
}

void createEmptyBalasan(Balasan *reply)
{
    Word tweet;
    strToWord("root-kicau", &tweet);
    idBalas(*reply) = -1;
    idParent(*reply) = -1;
    textBalas(*reply) = tweet;
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
        ROOT(*p) = reply;
        firstChild(p) = NULL;
        nextSibling(p) = NULL;
    }
    return p;
}

void createBuffer(ElTypeReply *elmt, TreeNode reply)
{
    content(*elmt) = reply;
    count(*elmt) = 0;
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

void printDepth(int depth)
{
    for (int i = 1; i < depth; i++)
    {
        printf("   ");
    }
}

void printTree(TreeNode *node, int depth)
/* Fungsi untuk mencetak pohon dengan banyak cabang secara rekursif */
{
    if (node == NULL)
    {
        return;
    }
    if (depth != 0)
    {
        Balasan reply = ROOT(*node);
        int idx = indexOf(ListUser, authorBalas(reply));
        if (isPublic(Profil(ELMT(ListUser, idx))) || isFriendsWith(authorBalas(reply)) || isKataEqual(Nama(*currentUser), authorBalas(reply)))
        {
            printDepth(depth);
            printf("| ID = %d", idBalas(reply));
            printf("\n");
            printDepth(depth);
            printf("| ");
            printWord(authorBalas(reply));
            printf("\n");
            printDepth(depth);
            printf("| ");
            TulisDATETIME(datetimeBalas(reply));
            printf("\n");
            printDepth(depth);
            printf("| ");
            printWord(textBalas(reply));
            printf("\n");
        }
        else
        {
            printDepth(depth);
            printf("| ID = %d\n", idBalas(reply));
            printDepth(depth);
            printf("| PRIVAT\n");
            printDepth(depth);
            printf("| PRIVAT\n");
            printDepth(depth);
            printf("| PRIVAT\n");
        }
    }
    printf("\n");
    printTree(firstChild(node), depth + 1); // print firstchildnya
    printTree(nextSibling(node), depth);    // print nextnya
}

TreeNode *searchTree(TreeNode *node, int id)
/* Fungsi untuk mencari id pada tree balasan */
{
    if (node == NULL)
    {
        return NULL; // basis node tidak ditemukan
    }

    if (idBalas(ROOT(*node)) == id)
    {
        return node; // basis node ditemukan
    }

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

int countKicauBalasan(ListBalasan l)
/* Mengembalikan jumlah kicauan yang memiliki balasan */
{
    int cnt = 0;
    int i;
    for (i = 0; i < NEFFBalas(l); i++)
    {
        if (count(ELMT(l, i)) > 0)
        {
            cnt++;
        }
    }

    return cnt;
}

void createListBalasan(ListBalasan *l)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    int capacity = 64;
    BUFFERBalas(*l) = (ElTypeReply *)malloc(capacity * sizeof(ElTypeReply));
    NEFFBalas(*l) = 0;
    CAPACITYBalas(*l) = capacity;
}

void expandListBalasan(ListBalasan *l, int num)
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    BUFFERBalas(*l) = (ElTypeReply *)realloc(BUFFERBalas(*l), (CAPACITYBalas(*l) + num) * sizeof(ElTypeReply));
    CAPACITYBalas(*l) += num;
}

void insertLastBalasan(ElTypeReply Reply)
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

void inisialisasiBalasan()
{
    Balasan Reply;
    createEmptyBalasan(&Reply);
    TreeNode *root = createNode(Reply);
    ElTypeReply elmt;
    createBuffer(&elmt, *root);
    insertLastBalasan(elmt);
}

void buatBalasan(int idKicau, int idBalas)
{
    if (idKicauValid(idKicau))
    {
        int idxtweet = searchByIdKicau(idKicau);
        int idxuser = indexOf(ListUser, authorKicau(ELMTKicau(ListTweet, idxtweet)));
        if (isPublic(Profil(ELMT(ListUser, idxuser))) || isFriendsWith(authorKicau(ELMTKicau(ListTweet, idxtweet))) || idBalas != -1 || isKataEqual(Nama(*currentUser), authorKicau(ELMTKicau(ListTweet, idxtweet))))
        {
            if (idbalasValid(idBalas) || idBalas == -1)
            {
                TreeNode *foundNode = searchTree(&content(ELMTBalas(ListReply, idKicau - 1)), idBalas);
                idxuser = indexOf(ListUser, authorBalas(ROOT(*foundNode)));
                if (isPublic(Profil(ELMT(ListUser, idxuser))) || isFriendsWith(authorBalas(ROOT(*foundNode))) || isKataEqual(Nama(*currentUser), authorBalas(ROOT(*foundNode))))
                {
                    printf("\nMasukkan balasan:\n");
                    ReadWord();
                    printf("\n");
                    if (balasanBlanks())
                    {
                        printf("Balasan tidak boleh hanya berisi spasi!\n");
                        printf("\n");
                    }
                    else
                    {
                        Balasan reply;
                        currentIdReply++;
                        if (balasanValid())
                        {
                            CreateBalasan(&reply, idBalas);
                        }
                        else
                        {
                            currentWord.Length = 280;
                            CreateBalasan(&reply, idBalas);
                        }
                        // update TreeNode balasan
                        count(ELMTBalas(ListReply, idKicau - 1))++;
                        TreeNode *child = createNode(reply);
                        addChild(foundNode, child);

                        // output
                        printf("Selamat! balasan telah diterbitkan!\n");
                        printf("Detil balasan:\n");
                        printf("| ID = %d", idBalas(ROOT(*child)));
                        printf("\n| ");
                        printWord(authorBalas(ROOT(*child)));
                        printf("\n| ");
                        TulisDATETIME(datetimeBalas(ROOT(*child)));
                        printf("\n| ");
                        printWord(textBalas(ROOT(*child)));
                        printf("\n\n");
                    }
                }
                else
                {
                    printf("\n");
                    printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman dengan akun tersebut!\n");
                    printf("\n");
                }
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
            printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman dengan akun tersebut!\n");
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
    if (idKicauValid(idKicau))
    {
        int idxtweet = searchByIdKicau(idKicau);
        int idxuser = indexOf(ListUser, authorKicau(ELMTKicau(ListTweet, idxtweet)));
        if (isPublic(Profil(ELMT(ListUser, idxuser))) || isFriendsWith(authorKicau(ELMTKicau(ListTweet, idxtweet))) || isKataEqual(Nama(*currentUser), authorKicau(ELMTKicau(ListTweet, idxtweet))))
        {
            if (count(ELMTBalas(ListReply, idKicau - 1)) == 0)
            {
                printf("\n");
                printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
                printf("\n");
            }
            else
            {
                TreeNode node = content(ELMTBalas(ListReply, idKicau - 1));
                printTree(&node, 0);
            }
        }
        else
        {
            printf("\n");
            printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
            printf("\n");
        }
    }
    else
    {
        printf("\n");
        printf("Tidak terdapat kicauan dengan id tersebut!\n");
        printf("\n");
    }
}

void deleteTree(TreeNode *reply, int id)
{
    if (reply == NULL)
    {
        return;
    }

    /* Hapus child dulu */
    TreeNode *child = firstChild(reply);
    TreeNode *prevChild = NULL;
    while (child != NULL)
    {
        TreeNode *nextChild = nextSibling(child);
        if (idBalas(ROOT(*child)) == id)
        {
            child = NULL;
            // hapus nextchild/nextsiblingnya
            if (prevChild == NULL)
            {
                firstChild(reply) = nextChild;
            }
            else
            {
                nextSibling(prevChild) = nextChild;
            }
            free(child);
        }
        else
        {
            deleteTree(child, id);
        }
        prevChild = child;
        child = nextChild;
    }
}

void hapusBalasan(int idKicau, int idBalas)
{
    if (idKicauValid(idKicau))
    {
        if (idBalas != -1)
        {
            int idxtweet = searchByIdKicau(idKicau);
            TreeNode *found = searchTree(&content(ELMTBalas(ListReply, idxtweet)), idBalas);
            if (found != NULL)
            {
                if (isKataEqual(Nama(*currentUser), authorBalas(ROOT(*found))))
                {
                    deleteTree(&content(ELMTBalas(ListReply, idxtweet)), idBalas);
                    count(ELMTBalas(ListReply, idxtweet))--;
                    printf("\n");
                    printf("Balasan berhasil dihapus\n");
                    printf("\n");
                }
                else
                {
                    printf("\n");
                    printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
                    printf("\n");
                }
            }
            else
            {
                printf("\n");
                printf("Balasan tidak ditemukan\n");
                printf("\n");
            }
        }
        else
        {
            printf("\n");
            printf("Anda tidak bisa menghapus kicauan utama\n");
            printf("\n");
        }
    }
    else
    {
        printf("\n");
        printf("Tidak ditemukan kicauan dengan ID = %d!\n", idKicau);
        printf("\n");
    }
}