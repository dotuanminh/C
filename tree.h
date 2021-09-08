#ifndef __TREE_H__
#define __TREE_H__

typedef struct node{
    char* name;
    struct node* parent;
    struct node* left_most_child;
    struct node* right_sibling;
}node;

typedef struct node* tree;

node* make_node(char*);
tree make_root(char*);
node* find(tree,char*);
node* add_child(node*,char*);
int height(node*);
int size(tree);
void traverse(tree, void (*f)(tree));
void print_node(node*);
void print(tree);
void free_node(node*);
void free_tree(tree);

#endif