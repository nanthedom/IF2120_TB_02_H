#include "../time.h"
#include <stdio.h>

int main(){
    int type; TIME T1, T2;
    scanf("%d", &type);
    

    switch (type){
        case 1: 
            CreateTime(&T1, 23, 59, 59);
            TulisTIME(T1);
            printf("\n");
            break;
        case 2:
            CreateTime(&T1, 18, 20, 00);
            CreateTime(&T2, 20, 10, 00);
            printf("%ld\n", Durasi(T1, T2));
            break;
        case 3:
            CreateTime(&T1, 18, 20, 00);
            printf("%ld\n", TIMEToDetik(T1));
            break;
    }
    return 0;
}