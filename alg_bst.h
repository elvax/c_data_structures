/*
 * Autor: Sebastian Pabich
 */
//
// Created by sebastian on 27.04.18.
//

#ifndef CLIONLISTA4_ALG_BST_H
#define CLIONLISTA4_ALG_BST_H



typedef struct node_bst{
    char* data;
    struct node_bst *left_child;
    struct node_bst *right_child;
    struct node_bst *parent;
} node_bst;

node_bst* new_node_bst(char* data, node_bst* parent);
node_bst* insert(node_bst* root, char* data);

node_bst *insert_bst(node_bst *head, char *data);

void print_inorder_bst(node_bst *root);

void* get_function(char* string);

int find_bst(node_bst *root, char* data);

node_bst* min_node_bst(node_bst *node);

node_bst *delete_bst(node_bst *root, char* data);

/*
 * Returns minimum data in this tree
 */
char* min_bst(node_bst *root);

typedef struct funs_bst funs_bst;



#endif //CLIONLISTA4_ALG_BST_H
