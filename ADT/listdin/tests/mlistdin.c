#include "../listdin.h"
#include <stdio.h>

int main(){
    int type, val; ListDin l;
    scanf("%d", &type);
    

    switch (type){
        case 1: 
            CreateListDin(&l, 100);
            l.buffer[0] = 2;
            l.buffer[1] = 4;
            l.buffer[2] = 6;
            l.nEff = 3;
            printList(l);
            break;
        case 2:
            CreateListDin(&l, 100);
            printList(l);
            break;
        case 3:
            CreateListDin(&l, 100);
            insertLast(&l, 10);
            insertLast(&l, 20);
            deleteLast(&l, &val);
            printList(l);
            break;
    }
    return 0;
}