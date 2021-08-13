#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack{
    int* data;
    int top;
    int nrOfElements;
    int capacity;
};
typedef struct stack Stack;

Stack createStack(int capacity){
    Stack s;
    s.top = -1;
    s.capacity = capacity;
    s.nrOfElements = 0;
    s.data = (int*)malloc(s.capacity * sizeof(int));
    return s;
}

void push(Stack *s, int element);
int pop(Stack *s);
int peek(Stack s);
bool isEmpty(Stack s);
bool isFull(Stack s);
void reallocate(Stack *s);

int main(void){
    Stack s = createStack(10);
    for(int i = 0; i < 10; i++){
        push(&s, (i+1));
    }
    printf("peek: %d\n", peek(s));
    printf("--------\n");
    while(!isEmpty(s)){
        printf("pop:%d\n", pop(&s));
    }
    printf("--------\n");
    printf("peek: %d\n", peek(s));
    return 0;
}

void push(Stack *s, int element){
    if(isFull(*s)){
        printf("Your stack is full\n");
    }else{
        s->top++;
        s->data[s->top] = element;
        s->nrOfElements++;
    }
}

int pop(Stack *s){
    if(isEmpty(*s)){
        printf("Nothing to pop\n");
        return -1;
    }else{
        int value = s->data[s->top];
        s->top--;
        s->nrOfElements--;
        return value;
    }
}

int peek(Stack s){
    if(isEmpty(s)){
        printf("Nothing to peek\n");
        return -1;
    }else{
        return s.data[s.top];
    }
}

bool isEmpty(Stack s){
    return s.top == -1;
}

bool isFull(Stack s){
    return s.nrOfElements == s.capacity;
}