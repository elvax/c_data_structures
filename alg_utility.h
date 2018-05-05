/*
 * Autor: Sebastian Pabich
 */
//
// Created by sebastian on 29.04.18.
//

#ifndef CLIONLISTA4_ALG_UTILITY_H
#define CLIONLISTA4_ALG_UTILITY_H

typedef enum data_structure_type{bst, rbt, hash_map} DATA_STRUCTURE_TYPE;

typedef struct conversion_data_structures conversion_data_structures;

typedef struct conversion_str_fun_ptr conversion_str_fun_ptr;


DATA_STRUCTURE_TYPE str2enum_ds_type(const char* str);

void *str2fun_ptr(const char* str);

void usage();

void* insertion(void* ds, char* data, void*(*insert_fun)(void*,char*));

void *insert(void *ds, void *data, void *functions);

#endif //CLIONLISTA4_ALG_UTILITY_H
