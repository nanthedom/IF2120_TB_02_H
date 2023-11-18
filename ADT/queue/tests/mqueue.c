#include "../queue.h"
#include <stdio.h>

int main(){
    int type;
    Queue q;
    scanf("%d", &type);
    

    switch (type){
        case 1: 
            // Test Enqueue
            CreateQueue(&q);
            enqueue(&q,1);
            enqueue(&q,2);
            displayQueue(q);
            break;
        case 2:
            // Test Dequeue
            int val;
            CreateQueue(&q);
            enqueue(&q,1);
            dequeue(&q,&val);
            displayQueue(q);
            break;
        case 3:
            // Test isEmpty
            CreateQueue(&q);
            printf("%d",isEmpty(q));
            break;
    }
    return 0;
}