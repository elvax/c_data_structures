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
        linkedList->head = _insert_list(linkedList->head, data);
        linkedList->no_elements++;
    }
}

void print_all_data_list(void* ds){
    linked_list *linkedList = ds;
    _print_all_data_list(linkedList->head);
}

int find_list(void *ds, char *data) {
    linked_list *linkedList = ds;
    return _find_list(linkedList->head, data);
}

char* min_list(void* ds){
    return "";
}

char* max_list(void* ds){
    return "";
}

char* successor_list(void* ds, char* data){
    linked_list *linkedList = ds;
    node_list* current = linkedList->head;
    while (current != NULL){
        if (!strcmp(data, current->data)) {
            return (current->next != NULL) ? current->next->data : "";
        } else {
            current = current->next;
        }
    }
    return "";
}

void print_inorder_list(void* ds){
    linked_list *linkedList = ds;
    if (linkedList == NULL || linkedList->no_elements == 0) {
        printf("\n");
    } else {
        node_list *current = linkedList->head;
        while (current != NULL) {
            printf("%s\n", current->data);
            current = current->next;
        }
    }
}

node_list *get_head_list(linked_list *list){
    return  list->head;
}

node_list* get_next( node_list* node){
    return node->next;
}

char* get_data_list( node_list* node){
    return node->data;
}

node_list* new_node_list(char *data, node_list *next){
    node_list *new = (node_list *) malloc(sizeof(node_list));
    new->data = data;
    new->next = next;
    return new;
}

node_list *_insert_list(node_list *head, char* data){
    node_list *headList = head;
//    node_list* previous = NULL;
//    node_list* current=head;
//    while(current != NULL) {
//        if (strcmp(data, current->data) < 0) {
//            if (previous != NULL) {
//                node_list *newNode = new_node_list(data, previous, current);
//                previous->next = newNode;
//                current->prev = newNode;
//                return head;
//            } else {
//                node_list *newNode = new_node_list(data, head->prev, current);
//                return newNode;
//            }
//        } else if (strcmp(data, current->data) == 0) {
//            node_list *newNode = new_node_list(data, current, current->next);
//            current->next = newNode;
//            if (newNode->next == NULL) {
//                head->prev = newNode;
//            }
//            return head;
//        } else {
//            previous = current;
//            current = current->next;
//        }
//    }
//    node_list *newNode = new_node_list(data, previous, NULL);
//    previous->next = newNode;
//    head->prev = newNode;
//    return head;
    node_list *newNode = new_node_list(data, headList);
    return newNode;

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

void _print_all_data_list(node_list* data_structure){
    node_list* head = data_structure;

    node_list* crawler=head;
    while(crawler != NULL) {
        printf("lista: %s\n", get_data_list(crawler));
        crawler = crawler->next;
    }
}

char* retrieve_first(void* data_structure){
    node_list *head = data_structure;
}

//char *__get_prev_data(void *ds){
//    linked_list *list = ds;
//    printf("prev: %s\n", list->head->prev->data);
//}