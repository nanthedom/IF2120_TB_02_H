#include "graf.h"
#include <stdio.h>

void CreateAdjMatrix(int nEff, AdjMatrix *m) {
    int i, j;

    NEFFM(*m) = nEff;
    for (i = 0; i < SIZE_CAP; i++) {
        for (j = 0; j < SIZE_CAP; j++) {
            if (i != j) {
                ELMTADJMAT(*m, i, j) = 0;
            } else {
                ELMTADJMAT(*m, i, j) = 1;
            }
        }
    }
}

void InsertEdge(AdjMatrix *m, int i, int j) {
    ELMTADJMAT(*m, i, j) = 1;
    ELMTADJMAT(*m, j, i) = 1;
}

void DeleteEdge(AdjMatrix *m, int i, int j) {
    ELMTADJMAT(*m, i, j) = 0;
    ELMTADJMAT(*m, j, i) = 0;
}

void DisplayAdjMatrix(AdjMatrix m) {
    int i, j;
    for(i = 0; i < NEFFM(m); i++){
        for(j = 0; j < NEFFM(m); j++){
            printf("%d", ELMTADJMAT(m,i,j));
            if(j < NEFFM(m) - 1){
                printf(" ");
            }
        }
        printf("\n");
    }
}