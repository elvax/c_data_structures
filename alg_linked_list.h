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

node_list* new_node_list(char *data, node_list *next);
node_list* get_next( void*);
int _insert_list(void* data_structure, char* data);
int _find_list(void* head, char* data);
void* _delete_list(void* head, char* data);
int _count_elements_list(void*);
char* get_data_list( void*);
void _print_all_data_list(void*);
char* retrieve_first(void* data_structure);



#endif //CLIONLISTA4_ALG_LINKED_LIST_H
