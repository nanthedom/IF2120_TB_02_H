#include "kicau.h"
#include "../pengguna/pengguna.h"
#include "../teman/teman.h"
#include <stdlib.h>
#include <stdio.h>

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
/* *** Test list penuh *** */
{
    return (NEFF(l) == 0);
}
boolean isFullKicauan(ListKicauan l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    return (NEFF(l) == CAPACITY(l));
}

void CreateListKicauan()
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    int capacity = 64;
    BUFFER(ListTweet) = (Kicauan *)malloc(capacity * sizeof(Kicauan));
    NEFF(ListTweet) = 0;
    CAPACITY(ListTweet) = capacity;
}

void dealocateList()
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(BUFFER(ListTweet));
    CAPACITY(ListTweet) = 0;
    NEFF(ListTweet) = 0;
}

int countKicauan()
/* Mengirimkan banyaknya kicauan, yaitu neff */
/* Mengirimkan nol jika list l kosong */
{
    return NEFF(ListTweet);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListKicauan l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
    return IDX_MIN;
}

IdxType getLastIdx(ListKicauan l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return NEFF(l) - 1;
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

void insertLastKicauan(ListKicauan *l, Kicauan kicau)
{
    if (isFullKicauan(ListTweet))
    {
        expandList(&*l, 2 * CAPACITY(*l));
        ELMT(*l, getLastIdx(*l) + 1) = kicau;
    }
    else
    {
        ELMT(*l, getLastIdx(*l) + 1) = kicau;
    }
    NEFF(*l)++;
}

void insertByTime(Kicauan kicau)
{
    if (isFullKicauan(ListTweet))
    {
        expandList(&ListTweet, 2 * CAPACITY(ListTweet));
    }
    if (isEmptyKicauan(ListTweet))
    {
        ELMT(ListTweet, 0) = kicau;
        NEFF(ListTweet)++;
    }
    else
    {
        int idx = getLastIdx(ListTweet);
        while (idx > 0 && DLT(datetimeKicau(kicau), datetimeKicau(ELMT(ListTweet, idx))))
        {
            ELMT(ListTweet, idx + 1) = ELMT(ListTweet, idx);
            idx--;
        }
        if (DGT(datetimeKicau(kicau), datetimeKicau(ELMT(ListTweet, idx))))
        {
            ELMT(ListTweet, idx + 1) = kicau;
        }
        else
        {
            ELMT(ListTweet, idx + 1) = ELMT(ListTweet, idx);
            ELMT(ListTweet, idx) = kicau;
        }
        NEFF(ListTweet)++;
    }
}

void Kicau()
{
    printf("Masukkan kicauan:\n");
    ReadWord();
    if (kicauanBlanks())
    {
        printf("Kicauan tidak boleh hanya berisi spasi!\n");
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
        insertLastKicauan(&ListTweet, tweet);
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
    }
}

void printKicauan()
{
    printf("\n");
    int i;
    for (i = NEFF(ListTweet) - 1; i >= 0; i--)
    {
        int idx = indexOf(ListUser, authorKicau(ELMT(ListTweet, i)));
        if (isPublic(Profil(ELMT(ListUser, idx))) || isFriendsWith(authorKicau(ELMT(ListTweet, i))))
        {
            printf("| ID = %d", idKicau(ELMT(ListTweet, i)));
            printf("\n| ");
            printWord(authorKicau(ELMT(ListTweet, i)));
            printf("\n| ");
            TulisDATETIME(datetimeKicau(ELMT(ListTweet, i)));
            printf("\n| ");
            printWord(textKicau(ELMT(ListTweet, i)));
            printf("\n| Disukai: %d\n", likeKicau(ELMT(ListTweet, i)));
            printf("\n");
        }
    }
}

boolean idValid(int id)
{
    return id - 1 >= 0 && id - 1 < NEFF(ListTweet);
}

void sukaKicau(int id)
{
    if (idValid(id))
    {
        int idx = indexOf(ListUser, authorKicau(ELMT(ListTweet, id - 1)));
        if (isPublic(Profil(ELMT(ListUser, idx))) || isFriendsWith(authorKicau(ELMT(ListTweet, id - 1))))
        {
            likeKicau(ELMT(ListTweet, id - 1))++;
            printf("Selamat! kicauan telah disukai!\n");
            printf("Detil kicauan:\n");
            printf("| ID = %d", idKicau(ELMT(ListTweet, id - 1)));
            printf("\n| ");
            printWord(authorKicau(ELMT(ListTweet, id - 1)));
            printf("\n| ");
            TulisDATETIME(datetimeKicau(ELMT(ListTweet, id - 1)));
            printf("\n| ");
            printWord(textKicau(ELMT(ListTweet, id - 1)));
            printf("\n| Disukai: %d\n", likeKicau(ELMT(ListTweet, id - 1)));
        }
        else
        {
            printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
        }
    }
    else
    {
        printf("Tidak ditemukan kicauan dengan ID = %d!\n", id);
    }
}

void ubahKicauan(int id)
{
    if (idValid(id))
    {
        if (isKataEqual(Nama(*currentUser), authorKicau(ELMT(ListTweet, id - 1))))
        {
            printf("Masukkan kicauan baru:\n");
            ReadWord();
            if (kicauanBlanks())
            {
                printf("Kicauan tidak boleh hanya berisi spasi!\n");
            }
            else
            {
                if (kicauanValid())
                {
                    textKicau(ELMT(ListTweet, id - 1)) = currentWord;
                }
                else
                {
                    currentWord.Length = 280;
                    textKicau(ELMT(ListTweet, id - 1)) = currentWord;
                }
                printf("| ID = %d", idKicau(ELMT(ListTweet, id - 1)));
                printf("\n| ");
                printWord(authorKicau(ELMT(ListTweet, id - 1)));
                printf("\n| ");
                TulisDATETIME(datetimeKicau(ELMT(ListTweet, id - 1)));
                printf("\n| ");
                printWord(textKicau(ELMT(ListTweet, id - 1)));
                printf("\n| Disukai: %d\n", likeKicau(ELMT(ListTweet, id - 1)));
            }
        }
        else
        {
            printf("Kicauan dengan ID = %d bukan milikmu!\n", id);
        }
    }
    else
    {
        printf("Tidak ditemukan kicauan dengan ID = %d!\n", id);
    }
}

void expandList(ListKicauan *l, int num)
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    BUFFER(*l) = (Kicauan *)realloc(BUFFER(*l), (CAPACITY(*l) + num) * sizeof(Kicauan));
    CAPACITY(*l) += num;
}

void shrinkList(ListKicauan *l, int num)
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    BUFFER(*l) = (Kicauan *)realloc(BUFFER(*l), (CAPACITY(*l) - num) * sizeof(Kicauan));
    CAPACITY(*l) -= num;
}

void compressList(ListKicauan *l)
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */
{
    BUFFER(*l) = (Kicauan *)realloc(BUFFER(*l), NEFF(*l) * sizeof(Kicauan));
    CAPACITY(*l) = NEFF(*l);
}