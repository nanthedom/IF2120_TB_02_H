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

void CreateListKicauan()
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    int capacity = 64;
    BUFFER(ListTweet) = (ElType *)malloc(capacity * sizeof(ElType));
    NEFF(ListTweet) = 0;
    CAPACITY(ListTweet) = capacity;
}

void dealocateList()
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(ListTweet.buffer);
    ListTweet.capacity = 0;
    ListTweet.nEff = 0;
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
    id(*kicau) = currentIdTweet;
    text(*kicau) = currentWord;
    like(*kicau) = 0;
    author(*kicau) = Nama(*currentUser);
    DATETIME dt;
    BacaDATETIME(&dt);
    datetime(*kicau) = dt;
}

void insertLastKicauan(ListKicauan *l, Kicauan kicau)
{
    if (NEFF(*l) < CAPACITY(*l))
    {
        ELMT(*l, getLastIdx(*l) + 1) = kicau;
    }
    else
    {
        expandList(&*l, 2 * CAPACITY(*l));
        ELMT(*l, getLastIdx(*l) + 1) = kicau;
    }
    NEFF(*l)
    ++;
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
        printf("| ID = %d", currentIdTweet);
        printf("\n| ");
        printWord(author(tweet));
        printf("\n| ");
        TulisDATETIME(datetime(tweet));
        printf("\n| ");
        printWord(text(tweet));
        printf("\n| Disukai: %d\n", like(tweet));
    }
}

void printKicauan()
{
    printf("\n");
    int i;
    for (i = NEFF(ListTweet) - 1; i >= 0; i--)
    {
        int idx = indexOf(ListUser, author(ELMT(ListTweet, i)));
        if (isPublic(Profil(ELMT(ListUser, idx))) || isFriendsWith(author(ELMT(ListTweet, i))))
        {
            printf("| ID = %d", id(ELMT(ListTweet, i)));
            printf("\n| ");
            printWord(author(ELMT(ListTweet, i)));
            printf("\n| ");
            TulisDATETIME(datetime(ELMT(ListTweet, i)));
            printf("\n| ");
            printWord(text(ELMT(ListTweet, i)));
            printf("\n| Disukai: %d\n", like(ELMT(ListTweet, i)));
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
        int idx = indexOf(ListUser, author(ELMT(ListTweet, id - 1)));
        if (isPublic(Profil(ELMT(ListUser, idx))) || isFriendsWith(author(ELMT(ListTweet, id - 1))))
        {
            like(ELMT(ListTweet, id - 1))++;
            printf("Selamat! kicauan telah disukai!\n");
            printf("Detil kicauan:\n");
            printf("| ID = %d", id(ELMT(ListTweet, id - 1)));
            printf("\n| ");
            printWord(author(ELMT(ListTweet, id - 1)));
            printf("\n| ");
            TulisDATETIME(datetime(ELMT(ListTweet, id - 1)));
            printf("\n| ");
            printWord(text(ELMT(ListTweet, id - 1)));
            printf("\n| Disukai: %d\n", like(ELMT(ListTweet, id - 1)));
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
        if (isKataEqual(Nama(*currentUser), author(ELMT(ListTweet, id - 1))))
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
                    text(ELMT(ListTweet, id - 1)) = currentWord;
                }
                else
                {
                    currentWord.Length = 280;
                    text(ELMT(ListTweet, id - 1)) = currentWord;
                }
                printf("| ID = %d", id(ELMT(ListTweet, id - 1)));
                printf("\n| ");
                printWord(author(ELMT(ListTweet, id - 1)));
                printf("\n| ");
                TulisDATETIME(datetime(ELMT(ListTweet, id - 1)));
                printf("\n| ");
                printWord(text(ELMT(ListTweet, id - 1)));
                printf("\n| Disukai: %d\n", like(ELMT(ListTweet, id - 1)));
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
    BUFFER(*l) = (ElType *)realloc(BUFFER(*l), (CAPACITY(*l) + num) * sizeof(ElType));
    CAPACITY(*l) += num;
}

void shrinkList(ListKicauan *l, int num)
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    BUFFER(*l) = (ElType *)realloc(BUFFER(*l), (CAPACITY(*l) - num) * sizeof(ElType));
    CAPACITY(*l) -= num;
}

void compressList(ListKicauan *l)
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */
{
    BUFFER(*l) = (ElType *)realloc(BUFFER(*l), NEFF(*l) * sizeof(ElType));
    CAPACITY(*l) = NEFF(*l);
}