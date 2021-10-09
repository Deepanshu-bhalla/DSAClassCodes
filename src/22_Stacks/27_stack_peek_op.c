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
        //printf("Stack Overflow, %d cannot be pushed into the stack\n",val);
    }
    else{
        ptr -> top++;
        ptr -> arr[ptr -> top] = val;
        
        //printf("%d is pushed into the stack\n",val);
    }
    
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow, No element to pop up\n");
    }
    else{
        int  val = ptr -> arr[ptr -> top];
        ptr-> top--;
        return val;
    }
}

int peek(struct stack *ptr, int i){
    if(ptr -> arr[ptr -> top - i + 1] < 0){
        printf("Invalid position to peek\n");
        return -1;
    }
    else{
        return ptr -> arr[ptr -> top-i+1];
    }
}

int main(){

    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp -> top = -1;
    sp -> size = 10;
    sp -> arr = (int *)malloc(sp -> size * sizeof(int));
    
 
    push(sp, 5);     // pos 8    index 0                      
    push(sp, 6);     // pos 7    index 1
    push(sp, 7);     // pos 6    index 2     
    push(sp, 8);     // pos 5    index 3      // Last In First Out
    push(sp, 9);     // pos 4    index 4                                            
    push(sp, 10);    // pos 3    index 5 
    push(sp, 11);    // pos 2    index 6           
    push(sp, 12);    // pos 1    index 7      // Last In First Out

    pop(sp);         // This will pop 12 out
    pop(sp);         // This will pop 11 out

    for(int i=1; i <= sp -> top + 1; i++){
         printf("The value at position %d is %d\n",i,peek(sp, i));
    }
       
       
       //printf("%d ",peek(sp, 1));  // This will give the element in the stack at position 1  // 12.
    
    
    return 0;
}
