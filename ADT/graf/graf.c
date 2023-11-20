#include "graf.h"

void CreateAdjMatrix(int nEff, AdjMatrix *m) {
    int i, j;

    NEFFM(*m) = nEff;
    for (i = 0; i < SIZE_CAP; i++) {
        for (j = 0; j < SIZE_CAP; j++) {
            ELMTADJMAT(*m, i, j) = 0;
        }
    }
}

void InsertEdge(AdjMatrix *m, int i, int j) {

}

void DeleteEdge(AdjMatrix *m, int i, int j) {

}

void DisplayAdjMatrix(AdjMatrix m) {

}