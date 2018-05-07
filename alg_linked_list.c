/*
 * Autor: Sebastian Pabich
 */
//
// Created by sebastian on 28.04.18.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "alg_linked_list.h"

struct linked_list{
    int no_elements;
    struct node_list *head;
};

struct node_list{
    struct node_list *next;
    char *data;
};

linked_list *new_linked_list(){
    linked_list *new = (linked_list *) malloc(sizeof(linked_list));
    new->no_elements = 0;
    new->head = NULL;
    return new;
}

int insert_list(void* ds, char* data){
    linked_list *linkedList = ds;
    if (linkedList->head == NULL){
        linkedList->head = new_node_list(data, NULL);
        linkedList->no_elements++;
        return 1;
    } else {
        //TODO inkrementacja no_elements
        return _insert_list(linkedList->head, data);
    }
}

void print_all_data_list(void* ds){
    linked_list *linkedList = ds;
    _print_all_data_list(linkedList->head);
}

node_list* get_next( void* data_strucutre){
    node_list *head = data_strucutre;
    return head->next;
}

char* get_data_list( void* data_structure){
    node_list *head = data_structure;
    return head->data;
}

node_list* new_node_list(char *data, node_list *next){
    node_list *new = (node_list *) malloc(sizeof(node_list));
    new->data = data;
    new->next = next;

    return new;
}

int _insert_list(void* data_structure, char* data){
    node_list *list_head = data_structure;
    if (list_head == NULL){
        printf("ERROR w insert_list");
        return 0;
    }

    //find zwróci 1 (true) jak już jest - nie będzie duplikatow
    if (_find_list(data_structure, data))
        return 0;


    node_list* crawler=list_head;
    while(crawler->next != NULL)
        crawler=crawler->next;
    //po wyjsciu w while crawler wskazuje na ostatni element

    crawler->next=new_node_list(data, NULL); //dotychczasowy ostatni element wskazuje na nowoutworzony
    return 1;
}

int _find_list(void* head, char* data){
    node_list* crawler = head;
    if (head == NULL) {
        return 0;
    }

    while (crawler != NULL) {
        if (strcmp(crawler->data, data) == 0) {
            return 1;
        }
        crawler = crawler->next;
    }
    return 0;
}

void *_delete_list(void *head, char *data) {

    if (head == NULL)
        return NULL;

    // jak nie ma el. "data" w liście to wejdzie w ifa
    if (!_find_list(head, data)) {
        return head;
    }

    node_list *current = head;
    node_list* prev=NULL;
    while (current != NULL) {
        if (!strcmp(current->data, data)) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
                free(current);
            }
        }
        prev = current;
        current = current->next;
    }
    return head;

}

int _count_elements_list(void *data_structure) {
    node_list *crawler = data_structure;
    int counter = 0;

    while (crawler != NULL) {
        counter++;
        crawler = crawler->next;
    }

    return counter;
}

void _print_all_data_list(void* data_structure){
    node_list* head = data_structure;

    node_list* crawler=head;
    while(crawler != NULL) {
        printf("data: %s\n", get_data_list(crawler));
        crawler = get_next(crawler);
    }
}

char* retrieve_first(void* data_structure){
    node_list *head = data_structure;

}