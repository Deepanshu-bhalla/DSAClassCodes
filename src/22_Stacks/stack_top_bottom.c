#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    int *arr;
};


int isFull(struct stack *ptr){
    if(ptr -> top == ptr -> size -1){
       return 1;
    }
    return 0;
}

int isEmpty(struct stack *ptr){
    if(ptr -> top == -1){
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow\n");
    }
    else{
        ptr -> top++;
        ptr -> arr[ptr -> top] = val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        int val =ptr -> arr[ptr -> top];
        ptr -> top--;
        return val;
    }
}

int stackTop(struct stack *ptr){
    int val =  ptr -> arr[ptr -> top];
    return val;
}

int stackBottom(struct stack *ptr){
    int val = ptr -> arr[0];
    return val;
} 

int main(){

    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));

    sp -> top = -1;
    sp -> size = 10;
    sp -> arr = (int *)malloc(sp -> size * sizeof(int));

    push(sp, 11);
    push(sp, 6);
    push(sp, 7);
    push(sp, 8);
    push(sp, 9);
    push(sp, 20);

   
    printf("The top of the stack is %d\n", stackTop(sp));
    printf("The bottom of the stack is %d\n", stackBottom(sp));
    
    return 0;
}
