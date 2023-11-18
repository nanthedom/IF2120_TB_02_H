#include "../pcolor.h"
#include <stdio.h>

int main(){
    int type;
    scanf("%d", &type);
    

    switch (type){
        case 1: 
            print_red('R');
            print_green('G');
            print_blue('B');
    }
    return 0;
}