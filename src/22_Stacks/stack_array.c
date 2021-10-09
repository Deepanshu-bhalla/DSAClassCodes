#include<stdio.h>
#include<stdlib.h>

struct stack {
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack *ptr){       //Function to check any element present to pop out 
    if(ptr -> top == -1){                         
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){       //Function to check if stack is space to push the values
    if(ptr -> top == ptr -> size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *p, int val){         // PushFunction
    if(isFull(p)){
        printf("Stack Overflow, %d cannot be pushed into the stack\n", val);
    }
    else{
        p -> top++;
        p -> arr[p->top] = val;
        printf("Pushed %d into the stack\n", val);
    }
}

int pop(struct stack *p){                      // Pop Function
    if(isEmpty(p)){
        printf("Stack Underflow, Cannot do pop\n");
        return -1;
    }else {
        int val = p -> arr[p -> top];
        p -> top = p -> top-1;
        return val;
    }
}

int main(){
    
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp -> top = -1;
    sp -> size = 10;
    sp -> arr = (int*)malloc(sp->size * sizeof(int));
    
    //printf("Before Push Empty : %d\n", isEmpty(sp));
    //printf("Before Push Full : %d\n", isFull(sp));
    
    push(sp, 10);
    push(sp, 20);
    push(sp, 30);
    push(sp, 40);
    push(sp, 50);
    push(sp, 60);
    push(sp, 70);
    push(sp, 80);
    push(sp, 90);
    push(sp, 100);
    push(sp, 110);  
     
    //printf("After Push Empty : %d\n", isEmpty(sp));
    //printf("After Push Full : %d\n", isFull(sp));
    
    printf("Popped %d from the stack\n", pop(sp));   // To pop the elements
    printf("Popped %d from the stack\n", pop(sp));   // Elements getting popped in LIFO manner
    printf("Popped %d from the stack\n", pop(sp));
    //pop(sp);
    
    return 0;
}
