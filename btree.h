#ifndef __BTREE_H__
#define __BTREE_H__


typedef struct node{
    int id;
    struct node* parent;
    struct node* left_child;
    struct node* right_child;
}node;

typedef struct node* tree;

node* make_node(int);
tree make_root(int);
node* add_left_child(node*,int);
node* add_right_child(node*,int);
node* find(tree,int);
void find_leaves(tree);
int height(node*);
int size(tree);
void traverse(tree , void (*f)(tree));
void print_node(node*);
void print_leaf(node*);
void print(tree);
void free_node(node*);
void free_tree(tree);
node* left_child(node*);
node* right_child(node*);


#endif
