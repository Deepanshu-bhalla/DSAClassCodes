//Program to implement stack using linkedlist
#include<stdio.h>
#include<stdlib.h>
 
struct Node{
    int data;
    struct Node* next;
};

void linkedlistTraversal(struct Node*p ){
    while(p != NULL){
    printf("Element: %d\n", p-> data);
    p = p -> next;
    }
}

int isFull(struct Node *sp){
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    if( p == NULL){
        return 1;
    }
    return 0;
}

int isEmpty(struct Node *sp){
   if(sp  == NULL){
       return 1;
   }
   return 0;
}


int stackTop(struct Node* top){
  return top -> data;
}

int stackBottom(struct Node *top){
    struct Node* p = top;
    while(p -> next != NULL){
        p = p -> next;
    }
    return p -> data;
}

int stackPeek(struct Node* top, int pos){
    struct Node* p = top;
    for(int i = 0; (i < pos-1 && p != NULL); i++){
        p = p -> next;
    }
    if (p == NULL){
        printf("Invalid position to peek\n");
    }
    return p-> data;
}

struct Node* push(struct Node *top, int val){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        n -> data = val;
        n -> next = top;
        top = n;
        return top;
    }
}

int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node *n = *top;
        *top = (*top)-> next;
        int val = n -> data;
        free(n);
        return val;
    }
}

int main(){

    struct Node* top  = NULL;
    
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);
    
    linkedlistTraversal(top);

    int element = pop(&top);                    // This pops out topmost element
    printf("Popped element: %d\n", element);
    
    int topEle = stackTop(top);                  // This will return topmost element
    printf("Top most element is %d\n", topEle);

    int bottomEle = stackBottom(top);            // This will return the bottom most element of the stack
    printf("Bottom most element is %d\n", bottomEle);
    
    int stackpeek = stackPeek(top, 5);           // This peeks at the position and returns the element at that position
    printf("Element is %d\n", stackpeek);

    linkedlistTraversal(top);

    return 0;
}

