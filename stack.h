#ifndef __STACK_H__
#define __STACK_H__

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct node* stack;

int is_empty(stack);
stack init();
stack pop(stack);
stack push(stack , int);
int top(stack);
node* make_node(int);
void del_stack(stack);


#endif