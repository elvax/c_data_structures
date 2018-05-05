/*
 * Autor: Sebastian Pabich
 */
//
// Created by sebastian on 29.04.18.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
     void* (*function)(void*, void*, functions*);
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

void* insert(void *ds, void *data, functions* functions_struct){
    functions *fun_pointers = functions_struct;
    int status = fun_pointers->insert(ds, (char*) data);
}

char* validate_input(char* data){
    char* dest = malloc(strlen(data) + 1);
    char *src = data;
    while (*src) {
        if(isalpha(*src))
            break;
        *src++;
    }
    // after loop src points to first alpha character

    strcpy(dest, src); //copy that part of string
    int i;
    for ( i = strlen(dest)-1; i >= 0; i--) {
        if(isalpha(dest[i]))
            break;
    }
    // after loop dest[i] is last alpha character in string
    dest[i+1] = '\0'; // we replace next on with '\0' (end of string)

    return dest;
}