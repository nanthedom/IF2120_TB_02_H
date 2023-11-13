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
            printf("%d", wordToInteger(word));
            break;
        case 3:
            ReadWord();
            word = currentWord;
            ReadWord();
            printf("%d", isKataEqual(word,currentWord));
            break;
        case 4:
            ReadWord();
            copy(currentWord, &word);
            printf("%d", word.Length);
            break;
    }
    return 0;
}
