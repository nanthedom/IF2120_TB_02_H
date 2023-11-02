#include "../stack.h"
#include <stdio.h>

int main(){
    int type;
    Stack s;
    scanf("%d", &type);
    

    switch (type){
        case 1: 
            // Test isEmpty
            CreateEmpty(&s);
            if(IsEmpty(s)){
                printf("1");
            }else{
                printf("0");
            }
            break;
        case 2:
            // Test isFull
            CreateEmpty(&s);
            while(Top(s)<MaxEl-1){
                Push(&s,2);
            }
            if(IsFull(s)){
                printf("1");
            }else{
                printf("0");

            }
            break;
        case 3:
            // Test Push, Pop, isFull
            int val;
            CreateEmpty(&s);
            Push(&s,0);
            Pop(&s,&val);
            printf("%d",val);
            break;
    }
    return 0;
}
