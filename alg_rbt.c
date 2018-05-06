/*
 * Autor: Sebastian Pabich
 */
//
// Created by sebastian on 29.04.18.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "alg_rbt.h"

enum color{RED, BLACK};

struct node_rbt{
    char* data;
    struct node_rbt *left_child,
      *right_child,
      *parent;
    enum color color;
} NIL = {"jestem nil", NULL, NULL, NULL, BLACK};


node_rbt *create_bst(char *data){
    node_rbt *new_root = new_leaf_rbt(&NIL, data);
    new_root->color = BLACK;
    return new_root;
}

node_rbt* new_node_rbt(node_rbt *parent, char* data){
    node_rbt *new = (node_rbt *) malloc( sizeof(node_rbt) );
    new->parent = parent;
    new->left_child = new->right_child = NULL;
    new->color = RED;
    new->data = data;

    return new;
}

node_rbt* new_leaf_rbt(node_rbt* parent, char* data){
    node_rbt* leaf = new_node_rbt(parent, data);
    leaf->left_child = &NIL;
    leaf->right_child = &NIL;
    leaf->left_child->color = BLACK;
    leaf->right_child->color = BLACK;
    leaf->color = RED;
    return leaf;
}

int _insert_rbt(node_rbt *root, node_rbt *new_node){
    node_rbt *parent = NULL;
    node_rbt *current = root;
    int isLeft = 0;
    while (current != &NIL) {
        parent = current;
        if (strcmp(new_node->data, current->data) < 0) {
            current = current->left_child;
            isLeft = 1;
        } else if (strcmp(new_node->data, current->data) > 0){
            current = current->right_child;
            isLeft = 0;
        } else {
            return 0;
        }
    }
    if(isLeft){
        new_node->parent = parent;
        parent->left_child = new_node;
    } else {
        new_node->parent = parent;
        parent->right_child = new_node;
    }
    return 1;
}

void fix_rbt(node_rbt *root){
    node_rbt *current = root;
    while (current->parent->color == RED) {
        if (current->parent == current->parent->parent->left_child) {
            node_rbt *y = current->parent->parent->right_child;
            if (y->color == RED) {
                current->parent->color = BLACK;
                y->color = BLACK;
                current->parent->parent->color = RED;
                current = current->parent->parent;
            } else if (current == current->parent->right_child) {
                current = current->parent;
                rotate_left(current);
            }
            current->parent->color = BLACK;
            current->parent->parent->color = RED;
            rotate_right(current->parent->parent);
        } else {
            node_rbt *y = current->parent->parent->left_child;
            if (y->color == RED) {
                current->parent->color = BLACK;
                y->color = BLACK;
                current->parent->parent->color = RED;
                current = current->parent->parent;
            } else if (current == current->parent->left_child) {
                current = current->parent;
                rotate_left(current);
            }
            current->parent->color = BLACK;
            current->parent->parent->color = RED;
            rotate_right(current->parent->parent);
        }
        root->color = BLACK;
    }
}

int insert_rbt(void *root, char *data){
    node_rbt *new_node = new_leaf_rbt(NULL, data);
    int status = _insert_rbt(root, new_node);

    insert_repair_tree(new_node);

    return status;
}

void insert_repair_tree(node_rbt* n) {
    if (parent(n) == NULL) {
        insert_case1(n);
    } else if (parent(n)->color == BLACK) {
        insert_case2(n);
    } else if (uncle(n)->color == RED) {
        insert_case3(n);
    } else {
        insert_case4(n);
    }
}

void insert_case1(node_rbt* n)
{
    if (parent(n) == NULL)
        n->color = BLACK;
}

void insert_case2(node_rbt* n)
{
    return; /* Do nothing since tree is still valid */
}

void insert_case3(node_rbt* n)
{
    parent(n)->color = BLACK;
    uncle(n)->color = BLACK;
    grandparent(n)->color = RED;
    insert_repair_tree(grandparent(n));
}

void insert_case4(node_rbt* n)
{
    node_rbt* p = parent(n);
    node_rbt* g = grandparent(n);

    if (n == g->left_child->right_child) {
        rotate_left(p);
        n = n->left_child;
    } else if (n == g->right_child->left_child) {
        rotate_right(p);
        n = n->right_child;
    }

    insert_case4step2(n);
}

void insert_case4step2(node_rbt* n)
{
    node_rbt* p = parent(n);
    node_rbt* g = grandparent(n);

    if (n == p->left_child)
        rotate_right(g);
    else
        rotate_left(g);
    p->color = BLACK;
    g->color = RED;
}

node_rbt* parent(node_rbt* n) {
    return n->parent;
}

node_rbt* grandparent(node_rbt* n) {
    node_rbt* p = parent(n);
    if (p == NULL)
        return NULL; // No parent means no grandparent
    return parent(p);
}

node_rbt* sibling(node_rbt* n) {
    node_rbt* p = parent(n);
    if (p == NULL)
        return NULL; // No parent means no sibling
    if (n == p->left_child)
        return p->right_child;
    else
        return p->left_child;
}

node_rbt* uncle(node_rbt* n) {
    node_rbt* p = parent(n);
    node_rbt* g = grandparent(n);
    if (g == NULL)
        return NULL; // No grandparent means no uncle
    return sibling(p);
}

void rotate_left(node_rbt* x) {
    node_rbt *y = x->right_child;
    x->right_child = y->left_child;
    if (y->left_child != &NIL) {
        y->left_child->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == &NIL) {
        x->parent = y;
    } else if (x == x->parent->left_child) {
        x->parent->left_child = y;
    } else {
        x->parent->right_child = y;
    }
    x->left_child = x;
    x->parent = y;
}

void rotate_right(node_rbt* y) {
    node_rbt *x = y->left_child;
    y->left_child = x->right_child;
    if (x->right_child != &NIL) {
        x->right_child->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == &NIL) {
        y->parent = x;
    } else if (y == y->parent->right_child) {
        y->parent->right_child = x;
    } else{
        y->parent->left_child = x;
    }
    y->right_child = y;
    y->parent = x;

}

void print_inorder_rbt(void *root){
    node_rbt *current = root;
    if (root != NULL) {
        print_inorder_rbt(current->left_child);
        printf("%s %d \n", current->data, current->color);
        print_inorder_rbt(current->right_child);
    }
}

void print_root(node_rbt *root){
    printf("root: %s\n", root->data);
}

int is_leaf(node_rbt *node){
    return (node->left_child->data == "" && node->right_child->data == "") ? 1 : 0;
}

int find_rbt(void* root, char *data){
    node_rbt *current = root;
    while (current != &NIL) {
        if (strcmp(data, current->data) < 0) {
            current = current->left_child;
        } else if(strcmp(data, current->data) > 0){
            current = current->right_child;
        } else {
            return 1;
        }
    }
    return 0;
}

char* min_rbt(node_rbt *root){
    if (root == NULL)
        return "";

    node_rbt *current = root;
    while (current->left_child != &NIL)
        current = current->left_child;
    return current->data;
}

char* max_rbt(node_rbt *root){
    node_rbt *current = root;
    while (current->right_child != &NIL)
    current = current->right_child;
    return current->data;
}

void *delete_rbt(void *data_strucutre, char *data){

}

int count_elements_rbt(void* data_strucutre){

}

char *successor_rbt(void *data_strucuture, char *key) {
    node_rbt *node = get_node_of_val_rbt(data_strucuture, key);
    if (node->right_child != &NIL)
        return min_rbt(node->right_child);

    node_rbt *parent = node->parent;
    while (parent != &NIL && node == parent->right_child) {
        node = parent;
        parent = parent->parent;
    }
    return parent->data;
}

node_rbt* get_node_of_val_rbt(void* ds, char* data){
    node_rbt *current = ds;
    while (current != &NIL) {
        if (strcmp(data, current->data) < 0) {
            current = current->left_child;
        } else if (strcmp(data, current->data) > 0){
            current = current->right_child;
        } else {
            break;
        }
    }
    return current;
}

























