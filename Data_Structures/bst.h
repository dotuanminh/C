#ifndef __BST_H__
#define __BST_H__

typedef struct node{
    char name[20];
    char email[20];
    int key;
    struct node* left_child;
    struct node* right_child;
}node;

typedef struct node* bst;

bst init_bst();
node* make_node(int ,char* ,char* );
node* search_node(bst ,int );
bst insert_node(bst ,int ,char* ,char* );
node* find_min(node* );
node* find_max(node* );
bst delete_node(bst ,int );
bst make_bst(node* ,int );
void post_order_traverse(bst, void (*f)(bst ));
void in_order_traverse(bst, void (*f)(bst ));
void print_node(node* );
void print_bst(bst );
void free_node(node* );
void free_bst(bst BST);

#endif