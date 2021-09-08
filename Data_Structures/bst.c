#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bst.h"



bst init_bst(){
    bst BST = NULL;
    return BST;
}

void swap(node** a,node** b){
    node* tmp = *a;
    *a = *b;
    *b = tmp;
}



node* make_node(int key,char* name,char* email){
    node* Node = (node*)malloc(sizeof(node));
    Node->key = key;
    strcpy(Node->name,name);
    strcpy(Node->email,email);
    Node->left_child = NULL;
    Node->right_child = NULL;
    return Node;
}




 node* search_node(bst BST,int key){
     if(BST == NULL){
         return NULL;
     }
     if(key == BST->key){
         return BST;
     }
     if(key > BST->key){
        return search_node(BST->right_child,key);
     }else{
         return search_node(BST->left_child,key);
     }
 }


bst insert_node(bst BST,int key,char* name,char* email){
    if(BST == NULL){
        BST = make_node(key,name,email);
        return BST;
    }
    if(key > BST->key){
        BST->right_child = insert_node(BST->right_child,key,name,email);
    }else{
        BST->left_child = insert_node(BST->left_child,key,name,email);
    }
    return BST;
}


node* find_min(node* Node){
    while(Node->left_child != NULL){
        Node = Node->left_child;
    }
    return Node;
}

node* find_max(node* Node){
    while(Node->right_child != NULL){
        Node = Node->right_child;
    }
    return Node;
}

bst delete_node(bst BST,int key){
    if(BST ==  NULL){
        return BST;
    }
    if(key > BST->key){
        BST->right_child = delete_node(BST->right_child,key);
    }else if(key < BST->key){
        BST->right_child = delete_node(BST->left_child,key);
    }else{
    if(BST->left_child ==NULL && BST->right_child == NULL){
        free(BST);
        return NULL;
    }else if(BST->left_child == NULL){
        node* Node = BST;
        BST = BST->right_child;
        free(Node);
        return BST;
    }else if(BST->right_child == NULL){
        node* Node = BST;
        BST = BST->left_child;
        free(Node);
        return BST;
    }else{
        node* Node = find_max(BST->left_child);
        BST->key = Node->key;
        strcpy(BST->name,Node->name);
        strcpy(BST->email,Node->email);
        BST->left_child = delete_node(BST->left_child,Node->key);
    }
    }
    return BST;
}

bst make_bst(node* a ,int size){
    int i;
    bst BST = init_bst();
    for(i =0 ;i<size;i++){
        BST = insert_node(BST,strlen(a[i].name),a[i].name,a[i].email);
    }
    return BST;
}

void in_order_traverse(bst BST, void (*f)(bst BST)){
    if(BST != NULL){
        in_order_traverse(BST->left_child,f);
        f(BST);
        in_order_traverse(BST->right_child,f);
    }
}

void post_order_traverse(bst BST, void (*f)(bst BST)){
    if(BST != NULL){
        in_order_traverse(BST->left_child,f);
        in_order_traverse(BST->right_child,f);
        f(BST);
    }
}

void print_node(node* Node){
    printf("%s %s \n",Node->name,Node->email);
}

void print_bst(bst BST){
    printf("\n");
    in_order_traverse(BST,print_node);
}

void free_node(node* Node){
    free(Node);
}

void free_bst(bst BST){
    post_order_traverse(BST,free_node);
}

