/*
 * Autor: Sebastian Pabich
 */
//
// Created by sebastian on 29.04.18.
//

#ifndef CLIONLISTA4_ALG_RBT_H
#define CLIONLISTA4_ALG_RBT_H

typedef struct rb_tree rb_tree;

typedef struct node_rbt node_rbt;

typedef enum color COLOR;

rb_tree *new_rb_tree();

node_rbt *create_bst(char*);

node_rbt* new_node_rbt(node_rbt*, char*);

node_rbt* new_leaf_rbt(node_rbt*, char*);

void print_color_sizeof();

void print_node_rb_size();
void print_rb_tree_size();

int insert_rbt(void *root, char *data);

void fix_rbt(rb_tree* tree, node_rbt *root);

void rotate_left(rb_tree* tree, node_rbt* n);

void rotate_right(rb_tree* tree, node_rbt* n);

void print_inorder_rbt(void *ds);

void _print_inorder_rbt(node_rbt *root);

void print_root(node_rbt *);

int is_leaf(node_rbt *node);

int find_rb_tree(void *root, char *data);

int _find_rbt(node_rbt *root, char *data);

char *min_rb_tree(void *root);

char *_min_rbt(node_rbt *root);

char *max_rb_tree(void *root);

char *_max_rbt(node_rbt *root);

void *delete_rbt(void *, char *);

void _delete_rbt(rb_tree *tree, char* data);

void _delete_fixup_rbt(rb_tree *tree, node_rbt *node);

void transplant_rbt(rb_tree *tree, node_rbt* u, node_rbt *v);

node_rbt* _min_node_rbt(node_rbt *node);

int count_elements_rbt(void*);

char* successor_rb_tree(void*, char*);

char* _successor_rbt(node_rbt*, char*);

node_rbt* get_node_of_val_rbt(node_rbt* root, char* data);

int get_no_elements_rbt(void* ds);

void increment_no_elements_rbt(void* ds);

void decrement_no_elements_rbt(void* ds);

#endif //CLIONLISTA4_ALG_RBT_H
