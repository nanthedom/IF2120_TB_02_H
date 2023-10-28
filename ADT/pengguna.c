#include "pengguna.h"
#include <stdio.h>

void CreateList(ListPengguna*l){
    length(*l) = 0;
}

boolean isEmpty(ListPengguna l){
    return length(l) == 0;
}
boolean isFull(ListPengguna l){
    return length(l) == USERMAX;
}
void printList(ListPengguna l){
    int i;
    for(i = 0; i < length(l); i++){
        printf("Nama: ");
        printWord(Nama(ELMT(l,i)));
        printf("\n");
    }
}

int indexof(ListPengguna l, Word Nama){
    if(!isEmpty(l)){
        int i = 0; boolean found = false; int idx = IDX_UNDEF;
        while(i < length(l) && !found){
            if(isKataEqual(Nama(ELMT(l,i)), Nama)){
                found = true;
                idx = i;
            }
        }
        return idx;
    }
}

