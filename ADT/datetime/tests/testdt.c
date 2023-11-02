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
        // Test BacaDatetime
        BacaDATETIME(&date);
        TulisDATETIME(date);
        break;

    
    }

    return 0;
}