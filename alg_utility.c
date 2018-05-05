/*
 * Autor: Sebastian Pabich
 */
//
// Created by sebastian on 29.04.18.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "alg_utility.h"

struct conversion_data_structures {
    DATA_STRUCTURE_TYPE type;
    const char *string;
} conversion_ds_type[] = {
        { bst,  "bst" },
        { rbt,  "rbt" },
        { hash_map, "hmap" }
};

 struct conversion_str_fun_ptr {
     const char* string;
     void* (*function)(void*, void*, void*);
 } conversion_fun_ptr[] = {
         "insert",
         &insert
 };


DATA_STRUCTURE_TYPE str2enum_ds_type(const char* str){
    int j;
    for (j = 0; j < sizeof(conversion_ds_type) / sizeof(conversion_ds_type[0]); ++j)
        if ( !strcmp (str, conversion_ds_type[j].string) )
            return conversion_ds_type[j].type;
    fprintf(stderr, "wybrano default\n");
}

void *str2fun_ptr(const char* str){
    int j;
    for (j = 0; j < sizeof(conversion_fun_ptr) / sizeof(conversion_fun_ptr[0]); ++j)
        if ( !strcmp (str, conversion_fun_ptr[j].string) )
            return conversion_fun_ptr[j].function;
    fprintf(stderr, "wybrano default\n");
}

void usage(){
    printf("podaj --type bst|rbt|hmap\n");
    exit(-1);
}

void* insertion(void* ds, char* data, void*(*insert_fun)(void*,char*)){
    return insert_fun(ds, data);
}

void* insert(void *ds, void *data, void* functions){
    printf("wstawia do struktury danych %s\n", (char*)data);
}
