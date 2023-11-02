#include "../wordmachine.h"
#include <stdio.h>

int main(){
    int type; Word word;
    scanf("%d", &type);

    switch (type){
        case 1:
            ReadWord();
            CreateWord(&word);
            copy(currentWord,&word);
            printWord(word);
            break;
        case 2:
            ReadWord();
            CreateWord(&word);
            copy(currentWord, &word);
            printf("%d", word2Int(word));
            break;
        case 3:
            ReadWord();
            word = currentWord;
            ReadWord();
           printf("%d", isKataEqual(word,currentWord));
    }
    return 0;
}
