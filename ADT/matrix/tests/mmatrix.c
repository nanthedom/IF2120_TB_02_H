#include "../matrix.h"
#include <stdio.h>

int main(){
    int type; Matrix mat1, mat2, mat3, mat3t;
    scanf("%d", &type);
    

    switch (type){
        case 1: 
            createMatrix(3, 3, &mat1);
            displayMatrix(mat1);
            break;
        case 2:
            createMatrix(3, 2, &mat2);
            ELMTMAT(mat2, 0, 0) = 1;
            ELMTMAT(mat2, 0, 1) = 2;
            ELMTMAT(mat2, 1, 0) = 3;
            ELMTMAT(mat2, 1, 1) = 4;
            displayMatrix(mat2);
            break;
        case 3:
            createMatrix(2, 2, &mat3);
            ELMTMAT(mat3, 0, 0) = 1;
            ELMTMAT(mat3, 0, 1) = 2;
            ELMTMAT(mat3, 1, 0) = 3;
            ELMTMAT(mat3, 1, 1) = 4;
            mat3t = transpose(mat3);
            displayMatrix(mat3t);
            break;
    }
    return 0;
}