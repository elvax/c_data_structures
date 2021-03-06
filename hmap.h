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

typedef struct hmap hmap;

typedef struct node_hmap node_hmap;

unsigned long hash(unsigned char *str);

hmap* new_hash_map(int size);

node_hmap* create_hash_table(int size);

int get_size_node_hmap(hmap* hmap1, int index);

void print_alldata_node_hmap(hmap* hmap1, int index);

void printTest();

rb_tree* convert_to_rbt(hmap *hmap1, long hash_index);

void* get_data_structure_hmap(hmap *hmap1, long hash_index);

void increment_no_elements_hmap(void *ds);

void decrement_no_elements_hmap(void *ds);


int insert_hmap(void* hmap, char* data);

int delete_hmap(void *ds, char* data);
//void load_hmap(struct hmap* hmap)


int get_no_elements_hmap(void *ds);

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
 * @return      ""
 */
char* min_hmap(void* ds);

/**
 * In hash map we can't find max value,
 * blank character is returned then.
 * @param ds    pointer to hash map
 * @return      ""
 */
char* max_hmap(void* ds);

/**
 * In hash map we can't find successor of value,
 * blank character is returned then.
 * @param ds    pointer to hash map
 * @return      ""
 */
char* successor_hmap(void* ds, char*);
//void insert(void* data_structure, char* data);

int count_elements_hmap(void* ds);

#endif //CLIONLISTA4_HMAP_H
