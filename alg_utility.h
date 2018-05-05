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

#endif //CLIONLISTA4_ALG_UTILITY_H
