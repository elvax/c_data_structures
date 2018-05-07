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

struct bs_tree{
    int no_elements;
    node_bst *root;
};

struct node_bst{
    char* data;
    struct node_bst *left_child;
    struct node_bst *right_child;
    struct node_bst *parent;
};

bs_tree *new_bs_tree(){
    bs_tree *new = (bs_tree *) malloc(sizeof(bs_tree));
    new->no_elements = 0;
    new->root = NULL;
    return new;
}

node_bst* new_node_bst(char* data, node_bst* parent){
    node_bst* new = (node_bst*) malloc(sizeof(node_bst));
    new->data = data;
    new->parent = parent;
    new->left_child = new->right_child = NULL;
    return new;
}

node_bst* _insert_node_bst(node_bst *head, char *data){
    if (head == NULL)
        return new_node_bst(data, NULL);

    if (strcmp(data, head->data) < 0) {
        node_bst *new_node = _insert_node_bst(head->left_child, data);    //returns newly created node
        head->left_child = new_node;
        new_node->parent = head;                                    //sets parent for new node
    } else if (strcmp(data, head->data) > 0) {
        node_bst *new_node = _insert_node_bst(head->right_child, data);
        head->right_child = new_node;
        new_node->parent = head;
    }
    // returns unchanged structure when "data" is already in tree
    return head;
}

int insert_bs_tree(void* ds, char* data){
    bs_tree *bsTree = ds;

    if (bsTree == NULL) {
        printf("error NULL pointer\n");
        exit(-1);
    }
    bsTree->root = _insert_node_bst(bsTree->root, data);
    bsTree->no_elements++;
}

void print_inorder_bs_tree(void* ds){
    bs_tree * bsTree = ds;
    if (bsTree == NULL || bsTree->no_elements == 0){
        printf("\n");
        return;
    }
    _print_inorder_bst(bsTree->root);
}

void _print_inorder_bst(node_bst *root){
    if (root != NULL) {
        _print_inorder_bst(root->left_child);
        printf("%s \n", root->data);
        _print_inorder_bst(root->right_child);
    }
}

int find_bs_tree(void* ds, char* data){
    bs_tree *bsTree = ds;
    if (bsTree == NULL || bsTree->no_elements == 0)
        return 0;

    return _find_bst(bsTree->root, data);
}

int _find_bst(node_bst *root, char* data){
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

char* min_bs_tree(void* ds){
    bs_tree *bsTree = ds;
    return (bsTree == NULL || bsTree->no_elements == 0) ? "" : _min_node_bst(bsTree->root)->data;
}

char* max_bs_tree(void* ds){
    bs_tree *bsTree = ds;
    return (bsTree == NULL || bsTree->no_elements == 0) ? "" : _max_node_bst(bsTree->root)->data;
}

char* successor_bs_tree(void* ds, char* data){
    bs_tree *bsTree = ds;
    return (bsTree == NULL || bsTree->no_elements == 0) ? "" : _successor_bs_tree(bsTree->root, data);
}

char* _successor_bs_tree(node_bst* ds, char* data){
    node_bst *node = get_node_of_val_bst(ds, data);
    if (node->right_child != NULL)
        return min_bst(node->right_child);

    node_bst *parent = node->parent;
    while (parent != NULL && node == parent->right_child) {
        node = parent;
        parent = parent->parent;
    }
    return parent->data;

}

node_bst* get_node_of_val_bst(void* ds, char* data){
    node_bst *current = ds;
    while (current != NULL) {
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

node_bst* _min_node_bst(node_bst *node) {
    node_bst *current = node;

    /* loop down to find the leftmost leaf */
    while (current->left_child != NULL)
        current = current->left_child;

    return current;
}

node_bst* _max_node_bst(node_bst *node) {
    node_bst *current = node;

    /* loop down to find the leftmost leaf */
    while (current->right_child != NULL)
        current = current->right_child;

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
        node_bst *tmp = _min_node_bst(root->right_child);
        root->data = tmp->data;
        root->right_child = delete_bst(root->right_child, tmp->data);
    }
    return root;
}

char *min_bst(node_bst *root) {
    if (root == NULL)
        return "";

    return _min_node_bst(root)->data;
}

//struct funs_bst{
//    char* str;
//    void* ptr;
//} funs_bst_array[] = {
//        { "insert", &insert_bst },
//        { "print",  &print_inorder_bst }
//};
//
//void* get_function(char* str){
//    int j;
//    for (j = 0; j < sizeof(funs_bst_array) / sizeof(funs_bst_array[0]); ++j)
//        if ( !strcmp (str, funs_bst_array[j].str) )
//            return funs_bst_array[j].ptr;
//
//}



