/*
 * Autor: Sebastian Pabich
 */
//
// Created by sebastian on 28.04.18.
//

#ifndef CLIONLISTA4_HMAP_H
#define CLIONLISTA4_HMAP_H

#include "alg_rbt.h"

#define MOD 10

extern int test;

//typedef struct functions Functions;

//typedef struct collection_functions collection_functions;

//extern struct collection_functions *list_functions;
//extern struct collection_functions *rbt_functions;



//typedef struct hmap{
//    int size;
//    struct node_hmap *arr;
//}hmap;
//
//typedef struct node_hmap{
//    int size;
//    void* data_structure;
//    struct functions* functions;
//}node_hmap;

typedef struct hmap hmap;

typedef struct node_hmap node_hmap;

unsigned long hash(unsigned char *str);

hmap* new_hash_map(int size);

node_hmap* create_hash_table(int size);

int get_size_node_hmap(hmap* hmap1, int index);

void print_alldata_node_hmap(hmap* hmap1, int index);

void printTest();

node_rbt* convert_to_rbt(hmap *hmap1, int hash_index);

void* get_data_structure_hmap(hmap *hmap1, int hash_index);

void increment_elements_hmap(hmap *hmap1);


int insert_hmap(void* hmap, char* data);
void delete_hmap(struct hmap* hmap, char* data);
//void load_hmap(struct hmap* hmap)


int get_no_elements_hmap(hmap *hmap1);

/**
 * Function searches data structure for given data
 * @param hmap  pointer to hash map
 * @param data  value to look for
 * @return      1 if value exists in hash map
 *              0 otherwise
 */
int find_hmap(void* hmap, char* data);

/**
 * Prints all values in given hash map
 * @param hmap1
 */
void print_all_data_hmap(void* hmap1);

/**
 * In hash map we can't find min value,
 * blank character is returned then.
 * @param ds    pointer to hash map
 * @return      "" - nothing
 */
char* min_hmap(void* ds);
//void insert(void* data_structure, char* data);

#endif //CLIONLISTA4_HMAP_H
