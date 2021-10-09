#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1){
    return 1;
    }
    return 0;
 }

int isFull(struct stack  *ptr)
{
    if (ptr->top == ptr->size - 1){
        return 1;
    }
    return 0;
}


int main()
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));
    
    //pushing manually into the stack
    s -> arr[0] = 7;
    s -> top++;
    
    s -> arr[1] = 8;
    s -> top++;

    s -> arr[2] = 12;
    s -> top++;
    
    s -> arr[3] = 5;
    s -> top++;

    s -> arr[4] = 4;
    s -> top++;
    
    s -> arr[5] = 1;
    s -> top++;


    if (isEmpty(s))
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is not empty\n");
    }
    return 0;
}
