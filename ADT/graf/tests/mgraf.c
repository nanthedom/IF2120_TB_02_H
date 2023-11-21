#include "../graf.h"
#include <stdio.h>

int main(){
    int type; AdjMatrix g1, g2, g3;
    scanf("%d", &type);
    

    switch (type){
        case 1: 
            CreateAdjMatrix(3, &g1);
            DisplayAdjMatrix(g1);
            break;
        case 2:
            CreateAdjMatrix(3, &g2);
            InsertEdge(&g2, 1, 2);
            DisplayAdjMatrix(g2);
            break;
        case 3:
            CreateAdjMatrix(3, &g3);
            InsertEdge(&g3, 1, 2);
            DeleteEdge(&g3, 1, 2);
            DisplayAdjMatrix(g3);
            break;
    }
    return 0;
}