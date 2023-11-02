#include "kicau.h"
#include "../pengguna/pengguna.h"
#include <stdlib.h>
#include <stdio.h>

extern int currentIdTweet;
extern ListKicauan ListTweet;
// extern Pengguna currentUser;

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

void kicau()
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
        printf("| ID = %d", currentIdTweet);
        printf("\n| ");
        printWord(author(tweet));
        printf("\n| ");
        TulisDATETIME(datetime(tweet));
        printf("\n| ");
        printWord(text(tweet));
        printf("\n| Disukai: %d", like(tweet));
    }
}

void kicauan()
{
    int i;
    for (i = 0; i < NEFF(ListTweet); i++)
    {
        printf("| ID = %d", id(ELMT(ListTweet, i)));
        printf("\n| ");
        printWord(author(ELMT(ListTweet, i)));
        printf("\n| ");
        TulisDATETIME(datetime(ELMT(ListTweet, i)));
        printf("\n| ");
        printWord(text(ELMT(ListTweet, i)));
        printf("\n| Disukai: %d", like(ELMT(ListTweet, i)));
        printf("\n");
    }
}

void sukaKicau(int id)
{
    
}

void ubahKicauan(int id)
{

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