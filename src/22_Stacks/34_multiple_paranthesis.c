#include<stdio.h>
#include<stdlib.h>

struct stack{
    char top;
    int size;
    char *arr;
};

int isFull(struct stack *sp){
    if(sp -> top == sp -> size -1){
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *sp){
    if(sp -> top == -1){
        return 1;
    }
    return 0;
}

char pop(struct stack *sp){
    if(isEmpty(sp)){
        printf("Stack Underflow\n");
    }
    else{
        char val = sp -> arr[sp -> top];
        sp -> top--;
        return val;
    }
}

void push(struct stack *sp, char val){
    if(isFull(sp)){
        printf("Stack Overflow\n");
    }
    else{
        sp -> top++;
        sp -> arr[sp -> top] = val;
    }
}
int stackTop(struct stack *sp){
    char top = sp -> arr[sp -> top];
    return top;
}

int match(char a, char b){
    if(a == '{' && b == '}'){
        return 1;
    }
    if(a == '[' && b == ']'){
        return 1;
    }
    if(a == '(' && b == ')'){
        return 1;
    }
    return 0;

}

int parenthesis(char *exp){
    struct stack *ptr;
    ptr -> top = -1;
    ptr -> size = 100;
    ptr -> arr = (char*)malloc(ptr -> size * sizeof(char));
    char popped_ch;
    for(int i = 0; exp[i] !='\0'; i++){
        char pushed_ch = exp[i];
        if(pushed_ch == '{' || pushed_ch == '[' || pushed_ch == '('){
        
            push(ptr, pushed_ch);
        }
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
           
            if(isEmpty(ptr)){
                return 0;
        }
        popped_ch = pop(ptr);
        if(!match(popped_ch,exp[i])){
            return 0;
            }
        }
        
    }
    if(isEmpty(ptr)){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    char *exp = "{8[7-2+6*(4+2+1)+1]3}";
     printf("************\n");
    if(parenthesis(exp)){
        printf("Balanced parenthesis\n");
    }
    else{
        printf("Unbalanced parenthesis\n");
    }
     printf("************\n");
    return 0;
}
