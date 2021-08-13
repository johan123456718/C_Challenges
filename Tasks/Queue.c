#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct queue{
    int *data;
    int rear, front;
    int maxSize;
    int nrOfElements;
};
typedef struct queue Queue;

bool offer(Queue *q, int element);
bool isEmpty(Queue q);
int peek(Queue q);
int poll(Queue *q);

Queue createQueue(int maxSize){
    Queue q;
    q.maxSize = maxSize;
    q.data = (int*)malloc(q.maxSize * sizeof(int));
    q.rear = 0;
    q.front = (maxSize - 1);
    q.nrOfElements = 0;
    return q;
}
int main(void){
    Queue q = createQueue(10);
    int tmp = 0;
    printf("peek: %d\n", peek(q));
    printf("---------\n");
    for(int i = 0; i < 10; i++){
        scanf("%d", &tmp);
        offer(&q, tmp);
    }
    printf("---------\n");
    printf("peek: %d\n", peek(q));

    while(!isEmpty(q)){
        printf("poll = %d\n", poll(&q));
    }
    printf("peek: %d\n", peek(q));
    return 0;
}

bool offer(Queue *q, int element){
    if(q->nrOfElements == q->maxSize){
        return false;
    }
    if(isEmpty(*q)){
        q->data[q->front] = element;
        q->nrOfElements++; 
        return true;
    }else{
        q->data[q->rear] = element;
        q->rear = (q->rear + 1) % q->maxSize;
        q->nrOfElements++; 
        return true;
    }
}

int peek(Queue q){
    if(isEmpty(q)){
        printf("\nNothing to peek\n");
        return -1;
    }
    
    return q.data[q.front];
}

int poll(Queue *q){
    if(isEmpty(*q)){
        printf("\nNothing to peek\n");
        return -1;
    }
    int value = q->data[q->rear];
    q->rear = (q->rear + 1) % q->maxSize;
    q->nrOfElements--;
    return value;
}

bool isEmpty(Queue q){
    return q.nrOfElements == 0;
}


