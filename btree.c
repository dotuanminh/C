#include<stdio.h>
#include<stdlib.h>
#include"btree.h"

node* make_node(int id){
    node* Node = (node*)malloc(sizeof(node));
    Node->id = id;
    Node->left_child = NULL;
    Node->right_child = NULL;
    Node->parent = NULL;
    return Node;
}


tree make_root(int id){
    tree Tree = make_node(id);
    return Tree;
}


node* add_left_child(node* Node , int id){
    if(Node->left_child != NULL){
        return Node;
    }
    node* tmp = make_node(id);
    tmp->parent = Node;
    Node->left_child = tmp;
    return Node;
}

node* add_right_child(node* Node , int id){
    if(Node->right_child != NULL){
        return Node;
    }
    node* tmp = make_node(id);
    tmp->parent = Node;
    Node->right_child = tmp;
    return Node;
}


node* find(tree Tree,int id){
    if(Tree == NULL){
        return NULL;
    }
    if(Tree->id == id){
        return Tree;
    }
    node* Node = find(Tree->left_child,id);
    if(Node != NULL){
        return Node;
    }else{
        return find(Tree->right_child,id);
    }
}


int height(node* Node){
    int maxHeight = 0;
    if(Node == NULL){
        return 0;
    }
    int hl = height(Node->left_child);
    maxHeight = hl  > maxHeight ? hl : maxHeight;
    int hr = height(Node->right_child);
    maxHeight = hr  > maxHeight ? hr : maxHeight;
    return maxHeight + 1;
}


int size(tree Tree){
    if(Tree == NULL){
        return 0;
    }
    return 1 + size(Tree->left_child) + size(Tree->right_child);
}


void traverse(tree Tree , void (*f)(tree Tree)){
    if(Tree == NULL){
        return ;
    }
    f(Tree);
    traverse(Tree->left_child,f);
    traverse(Tree->right_child,f);
}

void print_leaf(node* Node){
    if(Node->right_child != NULL || Node->left_child != NULL){
        return ;
    }
    printf("%d ",Node->id);
}

void find_leaves(tree Tree){
    printf("\n");
    traverse(Tree,print_leaf);
}


void print_node(node* Node){
    if(Node->left_child == NULL && Node->right_child == NULL){
        return ; 
    }
    printf("\n%d ",Node->id);
    if(Node->left_child != NULL){
        printf("%d ",Node->left_child->id);
    }else{
        printf("%d ",-1);
    }
    if(Node->right_child != NULL){
        printf("%d ",Node->right_child->id);
    }else{
        printf("%d ",-1);
    }
}


void print(tree Tree){
    if(Tree->left_child == NULL && Tree->right_child == NULL){
        printf("\n%d ",Tree->id);
        return ;
    }
    traverse(Tree,print_node);
}


void free_node(node* Node){
    free(Node);
}


void free_tree(tree Tree){
    traverse(Tree,free_node);
}

node* right_child(node* Node){
    return Node->right_child ;
}

node* left_child(node* Node){
    return Node->left_child;
}