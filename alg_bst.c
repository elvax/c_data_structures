/*
 * Autor: Sebastian Pabich
 */
//
// Created by sebastian on 27.04.18.
//

#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "alg_bst.h"
#include <stdio.h>

node_bst* new_node_bst(char* data, node_bst* parent){
    node_bst* new = (node_bst*) malloc(sizeof(node_bst));
    new->data = data;
    new->parent = parent;
    new->left_child = new->right_child = NULL;

    return new;
}
// node_bst* insert(node_bst* root, char* data){
//
//   if (root == NULL)
//     return new_node_bst(data, NULL);
//
//   if (strcmp(data, root->data)){
//     root->left_child = insert(node->left_child,
//   }
// }

node_bst* insert_bst(node_bst *head, char *data){
    if (head == NULL)
        return new_node_bst(data, NULL);

    if (strcmp(data, head->data) < 0) {
        node_bst *new_node = insert_bst(head->left_child, data);    //returns newly created node
        head->left_child = new_node;
        new_node->parent = head;                                    //sets parent for new node
    } else if (strcmp(data, head->data) > 0) {
        node_bst *new_node = insert_bst(head->right_child, data);
        head->right_child = new_node;
        new_node->parent = head;
    }

    // returns unchanged structure when "data" is already in tree
    return head;
}

void print_inorder_bst(node_bst *root){
    if (root != NULL) {
        print_inorder_bst(root->left_child);
        printf("%s \n", root->data);
        print_inorder_bst(root->right_child);
    }
}

int find_bst(node_bst *root, char* data){
    if(root == NULL) return 0;

    node_bst *current = root;

    while (current != NULL) {
        if (strcmp(data, current->data) < 0) {
            current = current->left_child;
        } else if(strcmp(data, current->data) > 0) {
            current = current->right_child;
        } else{
            return 1;
        }
    }
    return 0;
}

node_bst* min_node_bst(node_bst *node) {
    if (node == NULL)
        return NULL;

    node_bst *current = node;

    /* loop down to find the leftmost leaf */
    while (current->left_child != NULL)
        current = current->left_child;

    return current;
}

node_bst *delete_bst(node_bst *root, char* data){
    if(root == NULL)
        return NULL;

    if (strcmp(data, root->data) < 0) {
        return root->left_child = delete_bst(root->left_child, data);
    } else if (strcmp(data, root->data) > 0) {
        return root->right_child = delete_bst(root->right_child, data);
    } else {
        if (root->left_child == NULL) {
            node_bst *tmp = root->right_child;
            free(root);
            return tmp;
        } else if(root->right_child == NULL){
            node_bst *tmp = root->left_child;
            free(root);
            return tmp;
        }
        node_bst *tmp = min_node_bst(root->right_child);
        root->data = tmp->data;
        root->right_child = delete_bst(root->right_child, tmp->data);
    }
    return root;
}

char *min_bst(node_bst *root) {
    if (root == NULL)
        return "";

    return min_node_bst(root)->data;
}

struct funs_bst{
    char* str;
    void* ptr;
} funs_bst_array[] = {
        { "insert", &insert_bst },
        { "print",  &print_inorder_bst }
};

void* get_function(char* str){
    int j;
    for (j = 0; j < sizeof(funs_bst_array) / sizeof(funs_bst_array[0]); ++j)
        if ( !strcmp (str, funs_bst_array[j].str) )
            return funs_bst_array[j].ptr;

}



