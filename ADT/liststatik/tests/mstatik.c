#include "../liststatik.h"
#include <stdio.h>

int main(){
    int type;
    ListStatik L;
    CreateListStatik(&L);
    scanf("%d", &type);
    

    switch (type){
        case 1: 
            // Test INSERT
            insertFirst(&L, 2);
            insertLast(&L, 7);
            insertAt(&L, 6, 1);
            printList(L);
            break;
        case 2:
            int val;
            // Test DELETE
            insertFirst(&L, 2);
            insertLast(&L, 7);
            insertAt(&L, 6, 1);
            deleteFirst(&L, &val);
            deleteLast(&L, &val);
            deleteAt(&L, &val,0);
            printList(L);
            break;
        case 3:
            // Test READ
            readList(&L);
            printList(L);
            break;
    }
    return 0;
}