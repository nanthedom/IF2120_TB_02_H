#include <stdio.h>
#include "../datetime.h"

int main()
{
    int type, D,M,Y,h,m,s;
    DATETIME date;

    scanf("%d", &type);

    switch (type)
    {
    case 1:
        // Test GetMaxDay
        scanf("%d", &M);
        scanf("%d", &Y);

        printf("%d", GetMaxDay(M,Y));
        break;

    case 2:
        // Test Validitas
        scanf("%d", &D);
        scanf("%d", &M);
        scanf("%d", &Y);
        scanf("%d", &h);
        scanf("%d", &m);
        scanf("%d", &s);

        if(IsDATETIMEValid(D,M,Y,h,m,s)){
            printf("1");
        }else{
            printf("0");
        }
        break;

    case 3:
        // Test CreateDatetime dan TulisDatetume
        scanf("%d", &D);
        scanf("%d", &M);
        scanf("%d", &Y);
        scanf("%d", &h);
        scanf("%d", &m);
        scanf("%d", &s);
        CreateDATETIME(&date, D,M,Y,h,m,s);
        TulisDATETIME(date);
        break;


    case 4:
        // Test DEQ
        DATETIME D1,D2;
        CreateDATETIME(&D1,2,2,2000,2,2,2);
        CreateDATETIME(&D2,2,2,2000,2,2,2);
        if(DEQ(D1,D2)){
            printf("1");
        }else{
            printf("0");
        }
        break;
    
    case 5:
        // Test DNEQ
        CreateDATETIME(&D1,2,2,2000,2,2,2);
        CreateDATETIME(&D2,2,2,2000,2,2,2);
        if(DNEQ(D1,D2)){
            printf("1");
        }else{
            printf("0");
        }
        break;

    case 6:
        // Test DLT
        CreateDATETIME(&D1,2,2,2000,2,2,2);
        CreateDATETIME(&D2,2,2,2001,2,2,2);
        if(DLT(D1,D2)){
            printf("1");
        }else{
            printf("0");
        }
        break;
    case 7:
        // Test DGT
        CreateDATETIME(&D1,2,2,2000,2,2,2);
        CreateDATETIME(&D2,2,2,2001,2,2,2);
        if(DGT(D1,D2)){
            printf("1");
        }else{
            printf("0");
        }
        break;

    case 8:
        // Test DATETIMENextNDetik
        CreateDATETIME(&D1,2,2,2000,2,2,2);
        D2 = DATETIMENextNDetik(D1,1);
        TulisDATETIME(D2);
        break;

    case 9:
        // Test DATETIMEPrevNDetik
        CreateDATETIME(&D1,2,2,2000,2,2,2);
        D2 = DATETIMEPrevNDetik(D1,1);
        TulisDATETIME(D2);
        break;


    case 10:
        // Test durasi
        CreateDATETIME(&D1,2,2,2000,2,2,2);
        CreateDATETIME(&D2,2,2,2000,2,2,5);
        long durasi = DATETIMEDurasi(D1,D2);
        printf("%ld",durasi);
        break;

    }
    
    return 0;
}