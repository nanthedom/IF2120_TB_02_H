#include "../charmachine.h"
#include <stdio.h>

int main(){
    int type;    
    scanf("%d", &type);
    

    switch (type){
        case 1: 
            START();
            while(currentChar != MARK){
                printf("%c", currentChar);
                ADV();
            }
            break;
    }
    return 0;
}