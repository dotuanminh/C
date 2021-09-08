#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"


tree make_root(char* name){
    tree Tree = make_node(name);
    return Tree;
}


node* make_node(char* name){
    node* Node = (node*)malloc(sizeof(node));
    Node->name = strdup(name);
    Node->parent = NULL;
    Node->left_most_child = NULL;
    Node->right_sibling = NULL;
    return Node;
}

node* find(tree Tree ,char* name){
    node* n;
    if(Tree == NULL){
        return NULL;
    }
    node* Node = Tree;
    if(strcmp(Node->name,name)==0){
        return Node;
    }
    Node = Node->left_most_child;
    while(Node != NULL){
        n = find(Node,name);
        if(n != NULL){
            return n;
        }
        Node = Node->right_sibling;
    }
    return NULL;
}

node* add_child(node* Node,char* name){
    node* p = make_node(name);
    p->parent = Node;
    if(Node->left_most_child == NULL){
        Node->left_most_child = p;
        return Node;
    }
    node* tmp = Node->left_most_child;
    while(tmp->right_sibling != NULL){
        tmp = tmp->right_sibling;
    }
    tmp->right_sibling = p;
    return Node;
}


int height(node* Node){
    int maxHeight = 0;
    Node = Node->left_most_child;
    if(Node == NULL){
        return 0;
    }
    while(Node != NULL){
        int h = height(Node);
        maxHeight = h < maxHeight ? maxHeight : h;
        Node = Node->right_sibling;
    }
    return maxHeight + 1;
}

int size(tree Tree){
    int count  =1 ;
    if(Tree == NULL){
        return 0;
    }
    Tree = Tree->left_most_child;
    while(Tree != NULL){
        count += size(Tree);
        Tree = Tree->right_sibling;
    }
    return count;
}


void traverse(tree Tree , void (*f)(tree Tree)){
    if(Tree == NULL){
        return ;
    }
    f(Tree);
    Tree = Tree->left_most_child;
    while(Tree != NULL){
        traverse(Tree,f);
        Tree = Tree->right_sibling;
    }
    return ;
}


void print_node(node* Node){
    node* tmp;
    if(Node->left_most_child == NULL || Node == NULL){
        return ;
    }
    printf("\n%s ",Node->name);
    tmp = Node->left_most_child;
    while(tmp != NULL){
        printf("%s ",tmp->name);
        tmp = tmp->right_sibling;
    }
    printf("\n");
    return ;
}


void print(tree Tree){
    if(Tree->left_most_child == NULL){
        printf("\n%s",Tree->name);
        return ;
    }
    traverse(Tree,print_node);
}


void free_node(node* Node){
    free(Node->name);
    free(Node);
}

void free_tree(tree Tree){
    traverse(Tree,free_node);
}


