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

struct rb_tree{
    int no_elements;
    node_rbt* root;
};

enum color{RED, BLACK};

struct node_rbt{
    char* data;
    struct node_rbt *left_child,
      *right_child,
      *parent;
    enum color color;
} NIL = {"jestem nil", NULL, NULL, NULL, BLACK};


rb_tree *new_rb_tree(){
    rb_tree *new = (rb_tree *) malloc(sizeof(rb_tree));
    new->no_elements = 0;
    new->root = NULL;
    return new;
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

void fix_rbt(rb_tree* tree, node_rbt *root){
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
                rotate_left(tree, current);
            } else {
                current->parent->color = BLACK;
                current->parent->parent->color = RED;
                rotate_right(tree, current->parent->parent);
            }
        } else {
            node_rbt *y = current->parent->parent->left_child;
            if (y->color == RED) {
                current->parent->color = BLACK;
                y->color = BLACK;
                current->parent->parent->color = RED;
                current = current->parent->parent;
            } else if (current == current->parent->left_child) {
                current = current->parent;
                rotate_right(tree, current);
            } else {
                current->parent->color = BLACK;
                current->parent->parent->color = RED;
                rotate_left(tree, current->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
}

int insert_rbt(void *ds, char *data){
    rb_tree *rbTree = ds;

    if (rbTree == NULL) {
        printf("error null pointer\n");
        exit(-1);
    }
        if (rbTree->root != NULL){
            node_rbt *new_node = new_leaf_rbt(&NIL, data);
            node_rbt *parent = &NIL;
            node_rbt *current = rbTree->root;
            while (current != &NIL) {
                parent = current;
                if (strcmp(new_node->data, current->data) < 0){
                    current = current->left_child;
                } else {
                    current = current->right_child;
                }
            }
            new_node->parent = parent;
            if (strcmp(new_node->data, parent->data) < 0){
                parent->left_child = new_node;
            } else {
                parent->right_child = new_node;
            }

            rbTree->no_elements++;
            fix_rbt(rbTree, new_node);
    } else {
        rbTree->root = new_leaf_rbt(&NIL, data);
        rbTree->root->color = BLACK;
        rbTree->no_elements++;
    }
}

void rotate_left(rb_tree* tree, node_rbt* x) {
    node_rbt *y = x->right_child;
    x->right_child = y->left_child;
    if (y->left_child != &NIL) {
        y->left_child->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == &NIL) {
        x->parent = y;
        tree->root = y;
    } else if (x == x->parent->left_child) {
        x->parent->left_child = y;
    } else {
        x->parent->right_child = y;
    }
    y->left_child = x;
    x->parent = y;
}

void rotate_right(rb_tree* tree, node_rbt* y) {
    node_rbt *x = y->left_child;
    y->left_child = x->right_child;
    if (x->right_child != &NIL) {
        x->right_child->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == &NIL) {
        y->parent = x;
        tree->root = x;
    } else if (y == y->parent->right_child) {
        y->parent->right_child = x;
    } else{
        y->parent->left_child = x;
    }
    x->right_child = y;
    y->parent = x;

}

void print_inorder_rbt(void *ds){
    rb_tree *rbTree = ds;
    if (rbTree == NULL) {
        printf("error null pointer\n");
        exit(-1);
    }
    if (rbTree->root == NULL || rbTree->no_elements == 0) {
        printf("\n");
    } else {
        _print_inorder_rbt(rbTree->root);
    }
}

void _print_inorder_rbt(node_rbt *root){
    node_rbt *current = root;
    if (root != NULL && root != &NIL) {
        _print_inorder_rbt(current->left_child);
        printf("rbt: %s %d \n", current->data, current->color);
        _print_inorder_rbt(current->right_child);
    }
}

void print_root(node_rbt *root){
    printf("root: %s\n", root->data);
}

int is_leaf(node_rbt *node){
    return (node->left_child->data == "" && node->right_child->data == "") ? 1 : 0;
}

int find_rb_tree(void* ds, char* data){
    rb_tree *rbTree = ds;
    if (rbTree == NULL) {
        printf("error null pointer\n");
        exit(-1);
    }
    return (rbTree->root == NULL || rbTree->no_elements == 0) ? 0 : _find_rbt(rbTree->root, data);
}

int _find_rbt( node_rbt* root, char *data){
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

char* min_rb_tree(void* ds){
    rb_tree *rbTree = ds;
    if (rbTree == NULL) {
        printf("error null pointer\n");
        exit(-1);
    }
    return (rbTree->root == NULL || rbTree->no_elements == 0) ? 0 : _min_rbt(rbTree->root);
}

char* _min_rbt(node_rbt *root){
    if (root == NULL)
        return "";

    node_rbt *current = root;
    while (current->left_child != &NIL)
        current = current->left_child;
    return current->data;
}

char* max_rb_tree(void* ds){
    rb_tree *rbTree = ds;
    if (rbTree == NULL) {
        printf("error null pointer\n");
        exit(-1);
    }
    return (rbTree->root == NULL || rbTree->no_elements == 0) ? 0 : _max_rbt(rbTree->root);
}

char* _max_rbt(node_rbt *root){
    node_rbt *current = root;
    while (current->right_child != &NIL)
    current = current->right_child;
    return current->data;
}

void *delete_rbt(void *data_strucutre, char *data){

}

int count_elements_rbt(void* data_strucutre){

}

char* successor_rb_tree(void* ds, char* data) {
    rb_tree *rbTree = ds;
    if (rbTree == NULL) {
        printf("error null pointer\n");
        exit(-1);
    }
    return (rbTree->root == NULL || rbTree->no_elements == 0) ? "" : _successor_rbt(rbTree->root, data);
}

char *_successor_rbt( node_rbt *data_strucuture, char *key) {
    node_rbt *node = get_node_of_val_rbt(data_strucuture, key);
    if (node->right_child != &NIL)
        return _min_rbt(node->right_child);

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
