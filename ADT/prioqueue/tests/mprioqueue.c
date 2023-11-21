#include "../prioqueue.h"
#include <stdio.h>

int main(){
    int type; PrioQueue pq1, pq2, pq3; ElmPermintaan e1, e2, e3, val;
    scanf("%d", &type);
    

    switch (type){
        case 1: 
            MakeEmpty(&pq1, 20);
            PrintPrioQueue(pq1);
            break;
        case 2:
            Info(e1) = 100;
            Prio(e1) = 3;
            Info(e2) = 200;
            Prio(e2) = 4;
            Info(e3) = 210;
            Prio(e3) = 2;
            MakeEmpty(&pq2, 20);
            Enqueue(&pq2, e1);
            Enqueue(&pq2, e2);
            Enqueue(&pq2, e3);
            PrintPrioQueue(pq2);
            break;
        case 3:
            Info(e1) = 100;
            Prio(e1) = 3;
            Info(e2) = 200;
            Prio(e2) = 4;
            Info(e3) = 210;
            Prio(e3) = 2;
            MakeEmpty(&pq3, 20);
            Enqueue(&pq3, e1);
            Enqueue(&pq3, e2);
            Enqueue(&pq3, e3);
            Dequeue(&pq3, &val);
            PrintPrioQueue(pq3);
            break;
    }
    return 0;
}