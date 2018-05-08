/*
 * Autor: Sebastian Pabich
 */
//
// Created by sebastian on 28.04.18.
//

#ifndef CLIONLISTA4_ALG_LINKED_LIST_H
#define CLIONLISTA4_ALG_LINKED_LIST_H

typedef struct linked_list linked_list;

typedef struct node_list node_list;

linked_list *new_linked_list();

int insert_list(void* ds, char* data);

void print_all_data_list(void*);

/**
 * Function searches for given value in list
 * @param ds    pointer to list
 * @param arg   pointer to value to search for
 * @return      1 if found with success
 *              0 otherwise
 */
int find_list(void*, char*);

/**
 * Function prints min value in list
 * @param ds    pointer to list
 * @return      data from minimum node
 *              "" if list is empty
 */
char* min_list(void* ds);

/**
 * Function prints max value in list. Since list
 * is self sorted and has pointer to last node this
 * operation in const in time.
 * @param ds    pointer to list
 * @return      data from minimum node
 *              "" if list is empty
 */
char* max_list(void* ds);

/**
 * Function prints successor of given data in list
 * @param ds    pinter to list
 * @param data  input data
 * @return      data from successor node
 *              "" if no successor of invalid input data
 */
char* successor_list(void* ds, char* data);

/**
 * Prints data from list lexicographically
 * @param ds    pointer to list
 */
void print_inorder_list(void* ds);

int get_no_elements_list(void* ds);

void increment_no_elements_list(void* ds);

void decrement_no_elements_list(void* ds);

node_list *get_head_list(linked_list *list);

node_list* new_node_list(char *data, node_list *next);

node_list* get_next( node_list*);

node_list *_insert_list(node_list *data_structure, char *data);
int _find_list(void* head, char* data);
void* _delete_list(void* head, char* data);
int _count_elements_list(void*);
char* get_data_list( node_list*);
void _print_all_data_list(node_list*);
char* retrieve_first(void* data_structure);
char *__get_prev_data(void *ds);



#endif //CLIONLISTA4_ALG_LINKED_LIST_H
