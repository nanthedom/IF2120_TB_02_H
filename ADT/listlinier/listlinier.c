#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

// /* Definisi Node : */
// typedef int ElType;
// typedef struct node* Address;
// typedef struct node {
//     ElType info;
//     Address next;
// } Node;

// #define INFO(p) (p)->info
// #define NEXT(p) (p)->next

Address newNode(ElType val){
    Address N = (Address) malloc(sizeof(Node));
    if(N != NULL){
        INFO(N) = val;
        NEXT(N) = NULL;
    }
    return N;
}

// /* Definisi List : */
// /* List kosong : FIRST(l) = NULL */
// /* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
// /* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

// typedef Address List;

// #define IDX_UNDEF (-1)
// #define FIRST(l) (l)

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return FIRST(l) == NULL;
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
    if(!isEmpty(l)){
        int i = 0; Address curAdr; curAdr = FIRST(l);
        while(i < idx){
            curAdr = NEXT(curAdr);
            i++;
        }
        return INFO(curAdr);
    }else{
        return IDX_UNDEF;
    }
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val){
    if(!isEmpty(*l)){
        int i = 0; Address curAdr; curAdr = FIRST(*l);
        while(i < idx){
            curAdr = NEXT(curAdr);
            i++;
        }
        INFO(curAdr) = val;
    }
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val){
    if(!isEmpty(l)){
        int i = 0; int idx = IDX_UNDEF; Address curAdr = FIRST(l); boolean found = false;
        while(curAdr != NULL && !found){
            if(INFO(curAdr) == val){
                found = true;
                idx = i;
            }
            i++; curAdr = NEXT(curAdr);
        }
        return idx;
    }
    return IDX_UNDEF;
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address p;
    p = newNode(val);
    if(p != NULL){
        NEXT(p) = *l;
        FIRST(*l) = p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val){
    Address p,curAdr; curAdr = *l;
    p = newNode(val);
    if(p != NULL){
        if(isEmpty(*l)){
            insertFirst(l,val);
        }else{
            while (NEXT(curAdr) != NULL){
                curAdr = NEXT(curAdr);
            }
            NEXT(curAdr) = p;
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx){
    Address p, curAdr = *l;
    p = newNode(val);
    if(p != NULL){
        int i = 0;
        if(idx == 0){
            insertFirst(l,val);
        } else{
            while(i < idx-1){
                curAdr = NEXT(curAdr); i++;
            }
            NEXT(p) = NEXT(curAdr);
            NEXT(curAdr) = p;
        }
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
    *val = INFO(*l);
    *l = NEXT(*l);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val){
    Address curAdr = *l; Address beforeAdr = NULL;
    while(NEXT(curAdr) != NULL){
        beforeAdr =  curAdr;
        curAdr = NEXT(curAdr);
    }
    *val = INFO(curAdr);
    if(beforeAdr == NULL){
        *l = NULL;
    } else{
        NEXT(beforeAdr) = NULL;
    }
    free(curAdr);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val){
    Address curAdr = *l; int i = 0;
    if(idx == 0){
        deleteFirst(l, val);
    } else{
        while(i < idx-1){
            i++; curAdr = NEXT(curAdr);
        }
        Address idxAdr = NEXT(curAdr);
        *val = INFO(idxAdr);
        NEXT(curAdr) = NEXT(idxAdr);
        free(idxAdr);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    printf("[");
    if(!isEmpty(l)){
        Address p = FIRST(l);
        while(p != NULL){
            printf("%d", INFO(p));
            if(NEXT(p) != NULL){
                printf(",");
            }
            p = NEXT(p);
        }
    }
    printf("]");
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l){
    int count = 0; Address curAdr = l;
    while(curAdr != NULL){
        count++;
        curAdr = NEXT(curAdr);
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
    List l;  
    CreateList(&l);
    Address curAdr = l1;
    while((curAdr) != NULL){
        insertLast(&l, INFO(curAdr));
        curAdr = NEXT(curAdr);
    }
    curAdr = l2;
    while((curAdr) != NULL){
        insertLast(&l, INFO(curAdr));
        curAdr = NEXT(curAdr);
    }
    return l;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
