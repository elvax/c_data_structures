/*
 * Autor: Sebastian Pabich
 */
//
// Created by sebastian on 29.04.18.
//

#ifndef CLIONLISTA4_ALG_UTILITY_H
#define CLIONLISTA4_ALG_UTILITY_H

//typedef struct functions functions;
//
//extern functions functions_list;
//
//extern functions functions_bst;
//
//extern functions functions_rbt;
//
//extern functions functions_hmap;

#include "external.h"

typedef enum data_structure_type{bst, rbt, hash_map} DATA_STRUCTURE_TYPE;

typedef struct conversion_data_structures conversion_data_structures;

typedef struct conversion_str_fun_ptr conversion_str_fun_ptr;


DATA_STRUCTURE_TYPE str2enum_ds_type(const char* str);

void *str2fun_ptr(const char* str);

void usage();

void* insertion(void* ds, char* data, void*(*insert_fun)(void*,char*));

void *insert(void *ds, void *data, functions *fun);

/**
 * This method removes all non-alpha characters
 * from the beginning and ending of given string, yet
 * preserves non-alpha characters between alpha characters
 * int the middle of given string.
 * @param data      input string
 * @return char*    new string that satisfies above
 *                  mentioned conditions
 */
char* validate_input(char* data);

/**
 * Function reads strings from file splitted by whitespaces
 * @param ds    pointer to data structure to insert into
 * @param arg   name of the file
 * @return
 */
void* load(void *ds, void *arg, functions*);


/**
 * Function searches for given value in data structure
 * @param ds    pointer to data structure
 * @param arg   pointer to value to search for
 * @return      1 if found with success
 *              0 otherwise
 */
void* find(void *ds, void *arg, functions*);

#endif //CLIONLISTA4_ALG_UTILITY_H
