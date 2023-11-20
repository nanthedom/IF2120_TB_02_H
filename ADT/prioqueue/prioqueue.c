#include "prioqueue.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueue Q){
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueue Q){
    return ((Tail(Q) + 1) % MaxElPQ(Q) == Head(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElPQ */
int NBElmtPQ (PrioQueue Q){
    if(IsEmpty(Q)){
        return 0;
    } else{
        int count;
        count = Tail(Q) - Head(Q) + 1;
        return ((count <= 0)? count + MaxElPQ(Q): count);
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueue * Q, int Max){
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    Q -> T = (ElmPermintaan*) malloc((Max)*sizeof(ElmPermintaan));
    if(Q->T != NULL){
        MaxElPQ(*Q) = Max;
    } else{
        MaxElPQ(*Q) = 0;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElPQ=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueue * Q){
    MaxElPQ(*Q) = 0;
    free(Q->T);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElPQ(Q) diset 0 */

void Enqueue(PrioQueue *Q, ElmPermintaan X)
{
    int i, j; ElmPermintaan temp;

    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    }
    else {
        Tail(*Q) = Tail(*Q) == MaxElPQ(*Q) - 1 ? 0 : Tail(*Q) + 1;
        InfoTail(*Q) = X;
        i = Tail(*Q);
        j = i == 0 ? MaxElPQ(*Q) - 1 : i - 1;
        while (i != Head(*Q) && Prio(ElmtPQ(*Q, i)) > (Prio(ElmtPQ(*Q, j)))) {
            temp = ElmtPQ(*Q, i);
            ElmtPQ(*Q, i) = ElmtPQ(*Q, j);
            ElmtPQ(*Q, j) = temp;
            i = j;
            j = i == 0 ? MaxElPQ(*Q) - 1 : i - 1;
        }
    }
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueue * Q, ElmPermintaan * X){
    *X = InfoHead(*Q);
    if(NBElmtPQ(*Q) == 1){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else{
        Head(*Q) = (Head(*Q) + 1) % MaxElPQ(*Q);
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueue (PrioQueue Q){
    if(!IsEmpty(Q)){
        int i = Head(Q);
        while(i != Tail(Q)){
            printf("%d %c\n", Prio(ElmtPQ(Q,i)), Info(ElmtPQ(Q,i)));
            i = (i + 1) % MaxElPQ(Q);
        }
        printf("%d %c\n", Prio(ElmtPQ(Q,i)), Info(ElmtPQ(Q,i)));
    }
    printf("#\n");
}
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/