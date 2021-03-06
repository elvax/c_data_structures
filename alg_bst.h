/*
 * Autor: Sebastian Pabich
 */
//
// Created by sebastian on 27.04.18.
//

#ifndef CLIONLISTA4_ALG_BST_H
#define CLIONLISTA4_ALG_BST_H

typedef struct bs_tree bs_tree;

typedef struct node_bst node_bst;

int get_no_elements_bst(void* ds);

bs_tree *new_bs_tree();

node_bst* new_node_bst(char* data, node_bst* parent);

node_bst *_insert_node_bst(node_bst *head, char *data);

int insert_bs_tree(void* ds, char* data);

void print_inorder_bs_tree(void* ds);

int find_bs_tree(void* ds, char* data);

char* min_bs_tree(void* ds);

char* max_bs_tree(void* ds);

char* successor_bs_tree(void* ds, char* data);

char* _successor_bs_tree(node_bst* n, char* data);

node_bst* get_node_of_val_bst(node_bst* root, char* data);

void _print_inorder_bst(node_bst *root);

void* get_function(char* string);

int _find_bst(node_bst *root, char* data);

node_bst* _min_node_bst(node_bst *node);

node_bst* _max_node_bst(node_bst *node);

int delete_bst(void *ds, char* data);

void _delete_bst(bs_tree *tree, char* data);

void transplant_bst(bs_tree* tree, node_bst *u, node_bst *v);


/*
 * Returns minimum data in this tree
 */
char* min_bst(node_bst *root);

typedef struct funs_bst funs_bst;

void increment_no_elements_bst(void* ds);

void decrement_no_elements_bst(void* ds);

#endif //CLIONLISTA4_ALG_BST_H
