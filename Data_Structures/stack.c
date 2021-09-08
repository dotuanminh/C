#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

stack init(){
    stack Stack = NULL;
    return Stack;
}

int is_empty(stack Stack){
    if(Stack == NULL){
        return 1;
    }
    return 0;
}

stack pop(stack Stack){
    if(is_empty(Stack)){
        exit(0);
    }
    node* tmp = Stack;
    Stack = Stack->next;
    free(tmp);
    return Stack;
}

stack push(stack Stack,int data){
    node* Node = make_node(data);
    Node->next = Stack;
    Stack = Node;
    return Stack;
}


int top(stack Stack){
    return Stack->data;
}

node* make_node(int data){
    node* Node = (node*)malloc(sizeof(node));
    Node->next = NULL;
    Node->data = data;
    return Node;
}

void del_stack(stack Stack){
    node* tmp = NULL;
    while(Stack != NULL){
        tmp = Stack;
        Stack = Stack->next;
        free(tmp);
    }
}