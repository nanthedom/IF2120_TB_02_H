#include "kicau.h"
#include "../pengguna/pengguna.h"
#include "../teman/teman.h"
#include <stdlib.h>
#include <stdio.h>
#include "../../ADT/datetime/datetime.h"

extern int currentIdTweet;
extern ListKicauan ListTweet;
extern ListPengguna ListUser;
extern Pengguna *currentUser;

/* VALIDATOR */
boolean kicauanValid()
/* Mengirim True jika jumlah karakter kicauan tidak lebih dari MAX_CHAR */
{
    return currentWord.Length > 0 && currentWord.Length <= 280;
}

boolean kicauanBlanks()
/* Mengirim True jika karakter kicauan kosong */
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

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyKicauan(ListKicauan l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
    return (NEFFKicau(l) == 0);
}
/* *** Test list penuh *** */
boolean isFullKicauan(ListKicauan l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    return (NEFFKicau(l) == CAPACITYKicau(l));
}

void CreateListKicauan(ListKicauan *l)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    int capacity = 64;
    BUFFERKicau(*l) = (Kicauan *)malloc(capacity * sizeof(Kicauan));
    NEFFKicau(*l) = 0;
    CAPACITYKicau(*l) = capacity;
}

void dealocateList()
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFFKicau(l)=0 */
{
    free(BUFFERKicau(ListTweet));
    CAPACITYKicau(ListTweet) = 0;
    NEFFKicau(ListTweet) = 0;
}

int countKicauan()
/* Mengirimkan banyaknya kicauan, yaitu NEFFKicau */
/* Mengirimkan nol jika list l kosong */
{
    return NEFFKicau(ListTweet);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdxKicauan(ListKicauan l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
    return IDX_MIN;
}

IdxType getLastIdxKicauan(ListKicauan l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return NEFFKicau(l) - 1;
}

void CreateKicau(Kicauan *kicau)
{
    idKicau(*kicau) = currentIdTweet;
    textKicau(*kicau) = currentWord;
    likeKicau(*kicau) = 0;
    authorKicau(*kicau) = Nama(*currentUser);
    DATETIME dt;
    BacaDATETIME(&dt);
    datetimeKicau(*kicau) = dt;
}

void insertLastKicauan(Kicauan kicau)
{
    if (isFullKicauan(ListTweet))
    {
        expandListKicau(&ListTweet, 2 * CAPACITYKicau(ListTweet));
        ELMTKicau(ListTweet, getLastIdxKicauan(ListTweet) + 1) = kicau;
    }
    else
    {
        ELMTKicau(ListTweet, getLastIdxKicauan(ListTweet) + 1) = kicau;
    }
    NEFFKicau(ListTweet)++;
}

void insertByTime(Kicauan kicau)
{
    if (isFullKicauan(ListTweet))
    {
        expandListKicau(&ListTweet, 2 * CAPACITYKicau(ListTweet));
    }
    if (isEmptyKicauan(ListTweet))
    {
        ELMTKicau(ListTweet, 0) = kicau;
        NEFFKicau(ListTweet)++;
    }
    else
    {
        int idx = getLastIdxKicauan(ListTweet);
        while (idx > 0 && DLT(datetimeKicau(kicau), datetimeKicau(ELMTKicau(ListTweet, idx))))
        {
            ELMTKicau(ListTweet, idx + 1) = ELMTKicau(ListTweet, idx);
            idx--;
        }
        if (DGT(datetimeKicau(kicau), datetimeKicau(ELMTKicau(ListTweet, idx))))
        {
            ELMTKicau(ListTweet, idx + 1) = kicau;
        }
        else
        {
            ELMTKicau(ListTweet, idx + 1) = ELMTKicau(ListTweet, idx);
            ELMTKicau(ListTweet, idx) = kicau;
        }
        NEFFKicau(ListTweet)++;
    }
}

void createEmptyBalasan(Balasan *reply)
{
    Word tweet;
    strToWord("root-kicau", &tweet);
    idBalas(*reply) = 0;
    textBalas(*reply) = tweet;
    authorBalas(*reply) = Nama(*currentUser);
    DATETIME dt;
    BacaDATETIME(&dt);
    datetimeBalas(*reply) = dt;
}

void Kicau()
{
    printf("\n");
    printf("Masukkan kicauan:\n");
    ReadWord();
    printf("\n");
    if (kicauanBlanks())
    {
        printf("Kicauan tidak boleh hanya berisi spasi!\n");
        printf("\n");
    }
    else
    {
        Kicauan tweet;
        currentIdTweet++;
        if (kicauanValid())
        {
            CreateKicau(&tweet);
        }
        else
        {
            currentWord.Length = 280;
            CreateKicau(&tweet);
        }
        // update ListTweet
        insertLastKicauan(tweet);
        printf("Selamat! kicauan telah diterbitkan!\n");
        printf("Detil kicauan:\n");
        printf("| ID = %d", idKicau(tweet));
        printf("\n| ");
        printWord(authorKicau(tweet));
        printf("\n| ");
        TulisDATETIME(datetimeKicau(tweet));
        printf("\n| ");
        printWord(textKicau(tweet));
        printf("\n| Disukai: %d\n", likeKicau(tweet));
        printf("\n");
        
        // update inisialisasi ListReply
        Balasan Reply;
        createEmptyBalasan(&Reply);
        TreeNode *root = createNode(Reply);
        ElTypeReply elmt;
        createBuffer(&elmt, *root);
        insertLastBalasan(elmt);
    }
}

void printKicauan()
{
    printf("\n");
    int i;
    for (i = NEFFKicau(ListTweet) - 1; i >= 0; i--)
    {
        int idx = indexOf(ListUser, authorKicau(ELMTKicau(ListTweet, i)));
        if (isPublic(Profil(ELMT(ListUser, idx))) || isFriendsWith(authorKicau(ELMTKicau(ListTweet, i))))
        {
            printf("| ID = %d", idKicau(ELMTKicau(ListTweet, i)));
            printf("\n| ");
            printWord(authorKicau(ELMTKicau(ListTweet, i)));
            printf("\n| ");
            TulisDATETIME(datetimeKicau(ELMTKicau(ListTweet, i)));
            printf("\n| ");
            printWord(textKicau(ELMTKicau(ListTweet, i)));
            printf("\n| Disukai: %d\n", likeKicau(ELMTKicau(ListTweet, i)));
            printf("\n");
        }
    }
}

boolean idValid(int id)
{
    return id - 1 >= 0 && id - 1 < NEFFKicau(ListTweet);
}

void sukaKicau(int id)
{
    if (idValid(id))
    {
        int idx = indexOf(ListUser, authorKicau(ELMTKicau(ListTweet, id - 1)));
        if (isPublic(Profil(ELMT(ListUser, idx))) || isFriendsWith(authorKicau(ELMTKicau(ListTweet, id - 1))))
        {
            likeKicau(ELMTKicau(ListTweet, id - 1))++;
            printf("\n");
            printf("Selamat! kicauan telah disukai!\n");
            printf("Detil kicauan:\n");
            printf("| ID = %d", idKicau(ELMTKicau(ListTweet, id - 1)));
            printf("\n| ");
            printWord(authorKicau(ELMTKicau(ListTweet, id - 1)));
            printf("\n| ");
            TulisDATETIME(datetimeKicau(ELMTKicau(ListTweet, id - 1)));
            printf("\n| ");
            printWord(textKicau(ELMTKicau(ListTweet, id - 1)));
            printf("\n| Disukai: %d\n", likeKicau(ELMTKicau(ListTweet, id - 1)));
            printf("\n");
        }
        else
        {
            printf("\n");
            printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
            printf("\n");
        }
    }
    else
    {
        printf("\n");
        printf("Tidak ditemukan kicauan dengan ID = %d!\n", id);
        printf("\n");
    }
}

void ubahKicauan(int id)
{
    if (idValid(id))
    {
        if (isKataEqual(Nama(*currentUser), authorKicau(ELMTKicau(ListTweet, id - 1))))
        {
            printf("\n");
            printf("Masukkan kicauan baru:\n");
            ReadWord();
            printf("\n");
            if (kicauanBlanks())
            {
                printf("Kicauan tidak boleh hanya berisi spasi!\n");
                printf("\n");
            }
            else
            {
                if (kicauanValid())
                {
                    textKicau(ELMTKicau(ListTweet, id - 1)) = currentWord;
                }
                else
                {
                    currentWord.Length = 280;
                    textKicau(ELMTKicau(ListTweet, id - 1)) = currentWord;
                }
                printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
                printf("| ID = %d", idKicau(ELMTKicau(ListTweet, id - 1)));
                printf("\n| ");
                printWord(authorKicau(ELMTKicau(ListTweet, id - 1)));
                printf("\n| ");
                TulisDATETIME(datetimeKicau(ELMTKicau(ListTweet, id - 1)));
                printf("\n| ");
                printWord(textKicau(ELMTKicau(ListTweet, id - 1)));
                printf("\n| Disukai: %d\n", likeKicau(ELMTKicau(ListTweet, id - 1)));
                printf("\n");
            }
        }
        else
        {
            printf("\n");
            printf("Kicauan dengan ID = %d bukan milikmu!\n", id);
            printf("\n");
        }
    }
    else
    {
        printf("\n");
        printf("Tidak ditemukan kicauan dengan ID = %d!\n", id);
        printf("\n");
    }
}

void expandListKicau(ListKicauan *l, int num)
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    BUFFERKicau(*l) = (Kicauan *)realloc(BUFFERKicau(*l), (CAPACITYKicau(*l) + num) * sizeof(Kicauan));
    CAPACITYKicau(*l) += num;
}

void shrinkListKicau(ListKicauan *l, int num)
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan NEFFKicau < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    BUFFERKicau(*l) = (Kicauan *)realloc(BUFFERKicau(*l), (CAPACITYKicau(*l) - num) * sizeof(Kicauan));
    CAPACITYKicau(*l) -= num;
}

void compressListKicau(ListKicauan *l)
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = NEFFKicau */
{
    BUFFERKicau(*l) = (Kicauan *)realloc(BUFFERKicau(*l), NEFFKicau(*l) * sizeof(Kicauan));
    CAPACITYKicau(*l) = NEFFKicau(*l);
}