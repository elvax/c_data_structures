/*
 * Autor: Sebastian Pabich
 */
//
// Created by sebastian on 05.05.18.
//

#ifndef CLIONLISTA4_EXTERNAL_H
#define CLIONLISTA4_EXTERNAL_H

typedef struct functions{
    int (*insert)(void *, char *);

    void (*print_all_data)(void *);

    int (*find)(void *, char *);

    void (*delete)(void *, char *);

    int (*count_elements)(void *);

    char* (*min)(void*);

    char* (*max)(void*);

    char *(*successor)(void *, char *);

    int (*get_no_elements)(void *);

    void (*increment_no_elements)(void *);

    void (*decrement_no_elements)(void *);

}functions;

extern functions functions_list;

extern functions functions_bst;

extern functions functions_rbt;

extern functions functions_hmap;

#endif //CLIONLISTA4_EXTERNAL_H
