#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct node{
    int row;
    int column;
    struct node* parent;
    struct node* next;
}node;

typedef struct queue{
    struct node* front;
    struct node* rear;
}queue;

queue init();
int is_empty(queue);
queue enqueue(queue , node*);
queue dequeue(queue);
node* front(queue);
void del_queue(queue);

#endif