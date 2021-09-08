#include<stdlib.h>
#include"queue.h"

queue init(){
    queue Queue;
    Queue.front = NULL;
    Queue.rear = NULL;
    return Queue;
}

int is_empty(queue Queue){
    if(Queue.front == NULL){
        return 1;
    }
    return 0;   
}

queue enqueue(queue Queue,node* Node){
    if(is_empty(Queue)){
        Queue.front = Node;
        Queue.rear = Node;
    }else{
        (Queue.rear)->next = Node;
        Queue.rear = Node;
    }
    return Queue;
}

queue dequeue(queue Queue){
    Queue.front = Queue.front->next;
    if(is_Empty(Queue)){
        Queue.rear = NULL;
    }
    return Queue;
}

void del_queue(queue Queue){
    while(!is_empty(Queue)){
        node* tmp;
        tmp = Queue.front;
        Queue.front = (Queue.front)->next;
        free(tmp);
    }
}

node* front(queue Queue){
    if(is_empty(Queue)){
        exit(0);
    }
    return (Queue.front);
}