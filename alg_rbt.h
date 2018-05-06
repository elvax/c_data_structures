/*
 * Autor: Sebastian Pabich
 */
//
// Created by sebastian on 29.04.18.
//

#ifndef CLIONLISTA4_ALG_RBT_H
#define CLIONLISTA4_ALG_RBT_H

typedef struct node_rbt node_rbt;

typedef enum color COLOR;



node_rbt *create_bst(char*);

node_rbt* new_node_rbt(node_rbt*, char*);

node_rbt* new_leaf_rbt(node_rbt*, char*);

int _insert_rbt(node_rbt *root, node_rbt *new_node);

int insert_rbt(void *root, char *data);

void fix_rbt(node_rbt *root);

void insert_repair_tree(node_rbt* n);

void insert_case1(node_rbt* n);

void insert_case2(node_rbt* n);

void insert_case3(node_rbt* n);

void insert_case4(node_rbt* n);

void insert_case4step2(node_rbt* n);

struct node_rbt* parent(node_rbt* n);

struct node_rbt* grandparent(node_rbt* n);

struct node_rbt* sibling(node_rbt* n);

struct node_rbt* uncle(node_rbt* n);

void rotate_left(node_rbt* n);

void rotate_right(node_rbt* n);

void print_inorder_rbt(void *root);

void print_root(node_rbt *);

int is_leaf(node_rbt *node);

int find_rbt(void *root, char *data);

char *min_rbt(node_rbt *root);

char *max_rbt(node_rbt *root);

void *delete_rbt(void *, char *);

int count_elements_rbt(void*);

char* successor_rbt(void*, char*);

node_rbt* get_node_of_val_rbt(void* ds, char* data);

#endif //CLIONLISTA4_ALG_RBT_H
