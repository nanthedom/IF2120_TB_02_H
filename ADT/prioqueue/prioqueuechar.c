#include "prioqueuechar.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q){
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueueChar Q){
    return ((Tail(Q) + 1) % MaxEl(Q) == Head(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (PrioQueueChar Q){
    if(IsEmpty(Q)){
        return 0;
    } else{
        int count;
        count = Tail(Q) - Head(Q) + 1;
        return ((count <= 0)? count + MaxEl(Q): count);
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max){
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    Q -> T = (infotype*) malloc((Max)*sizeof(infotype));
    if(Q->T != NULL){
        MaxEl(*Q) = Max;
    } else{
        MaxEl(*Q) = 0;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q){
    MaxEl(*Q) = 0;
    free(Q->T);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X){
    if(IsEmpty(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        Elmt(*Q,Tail(*Q)) = X;
    } else{
        int i = Head(*Q), idx = i; boolean found = false;
        while ((!found) && (i != Tail(*Q))){
            if(Prio(Elmt(*Q,i)) > Prio(X)){
                found = true;
                idx = i;
            }
            i =  (i + 1)%MaxEl(*Q); 
        }
        if(found){
            int i = Tail(*Q);
            while(i != idx){
                Elmt(*Q,(i+1)%MaxEl(*Q)) = Elmt(*Q,i);
                i--;
                i = (i >= 0)? i: i + MaxEl(*Q);
            }
            Elmt(*Q,i+1) = Elmt(*Q,i);
            Elmt(*Q,idx) = X;
            Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
        } else{
            if(i == Tail(*Q) && !found){
                if(Prio(Elmt(*Q,i)) > Prio(X)){
                    found = true;
                    idx = i;
                }
                if(found){
                    Elmt(*Q,(idx+1) % MaxEl(*Q)) = Elmt(*Q,idx);
                    Elmt(*Q,idx) = X;
                    Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
                } else{
                    Elmt(*Q, (Tail(*Q)+1) % MaxEl(*Q)) = X;
                    Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
                }
            }
        }
    }
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueueChar * Q, infotype * X){
    *X = InfoHead(*Q);
    if(NBElmt(*Q) == 1){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else{
        Head(*Q) = (Head(*Q) + 1) % MaxEl(*Q);
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){
    if(!IsEmpty(Q)){
        int i = Head(Q);
        while(i != Tail(Q)){
            printf("%d %c\n", Prio(Elmt(Q,i)), Info(Elmt(Q,i)));
            i = (i + 1) % MaxEl(Q);
        }
        printf("%d %c\n", Prio(Elmt(Q,i)), Info(Elmt(Q,i)));
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