/*
 * Autor: Sebastian Pabich
 */
//
// Created by sebastian on 29.04.18.
//

#include <stdlib.h>
#include "alg_rbt.h"

enum color{RED, BLACK};

struct node_rbt{
    char* data;
    struct node_rbt *left_child;
    struct node_rbt *right_child;
    struct node_rbt *parent;
    enum color color;
};

node_rbt* new_node_rbt(node_rbt *parent, char* data){
    node_rbt *new = (node_rbt *) malloc( sizeof(struct node_rbt) );
    new->parent = parent;
    new->left_child = new->right_child = NULL;
    new->color = BLACK;
    new->data = data;

    return new;
}
