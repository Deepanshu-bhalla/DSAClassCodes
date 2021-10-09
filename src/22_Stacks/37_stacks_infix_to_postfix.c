#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr -> top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr){
    if(ptr -> top == ptr -> size -1){
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow\n");
    }else {
        ptr -> top++;
        ptr -> arr[ptr -> top] = val;
        printf("%c is pushed into the stack\n",val);
    }
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow\n");
    }else{
        char val = ptr -> arr[ptr -> top];
        ptr -> top--;
        return val;
    }
}

char stackTop(struct stack *ptr){
    char top = ptr -> arr[ptr -> top];
    return top;
}

int precedence(char val){
    if(val == '*' || val == '/'){
        return 3;
    }
    else if( val == '+' || val == '-'){
        return 2;
    }
    else{
        return 0;
    }
}

int isOperator(char val){
    if(val == '/' || val == '*' || val == '+' || val == '-'){
        return 1;
    }
    else {
        return 0;
    }

}

char *infix_to_postfix(char *infix){
    struct stack *sp = (struct stack*) malloc(sizeof(struct stack));
    sp -> top = -1;
    sp -> size = 100;
    sp -> arr = (char *)malloc(sp -> size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix)+1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
    }
        else{
            if(precedence(infix[i]) > precedence(stackTop(sp))) {
                push(sp, infix[i]);
                i++;
            }

            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';

    return postfix;
    
}
int main(){
    char *infix = "x-y/z*d";
    printf("Postfix : %s", infix_to_postfix(infix));
    return 0;
}

