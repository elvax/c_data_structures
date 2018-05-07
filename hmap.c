/*
 * Autor: Sebastian Pabich
 */
#include <stdio.h>
#include <stdlib.h>
#include "hmap.h"
#include "alg_linked_list.h"
#include "alg_utility.h"
#include "external.h"

int test = 10;

struct hmap{
    int size,
        no_elements;
    struct node_hmap *arr;
};

struct node_hmap{
    int size;
    void* data_structure;
    functions *functions;
};


void print_alldata_node_hmap(hmap* hmap1, int index){
    hmap1->arr[index].functions->print_all_data(hmap1->arr[index].data_structure);
}

int get_size_node_hmap(hmap* hmap1, int index){
    return hmap1->arr[index].size;
}

hmap *new_hash_map(int size){
    hmap *new = (hmap *) malloc(sizeof(hmap));
    new->size = size;
    new->no_elements = 0;
    new->arr = create_hash_table(size);
}

node_hmap* create_hash_table(int size){
    node_hmap* table = (node_hmap *) malloc(sizeof(node_hmap) * size);

    for (int i = 0; i < size; i++) {
        table[i].size = 0;
        table[i].data_structure = NULL;
        table[i].functions = NULL;
    }
    return table;
}

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % MOD;
}

//poprawic inkrementacje size
int insert_hmap(void* data_structure, char* data){
    hmap *hmap = data_structure;
    long hash_index = hash(data);

    //if sprawdzający size i zmieniający strukture

    if(hmap->arr[hash_index].data_structure == NULL){
//        hmap->arr[hash_index].data_structure = new_node_list(data, NULL, NULL);
        hmap->arr[hash_index].data_structure = new_linked_list();
        hmap->arr[hash_index].functions = &functions_list;
        hmap->arr[hash_index].functions->insert(hmap->arr[hash_index].data_structure, data);
        hmap->arr[hash_index].size++;
        increment_elements_hmap(hmap);
    } else if (hmap->arr[hash_index].size > 1) {
        if ( hmap->arr[hash_index].functions->insert(hmap->arr[hash_index].data_structure, data)){
            hmap->arr[hash_index].data_structure = convert_to_rbt(hmap, hash_index);
            hmap->arr[hash_index].functions = &functions_rbt;
            hmap->arr[hash_index].size++;
            increment_elements_hmap(hmap);
        }
    } else {
        if (hmap->arr[hash_index].functions->insert(hmap->arr[hash_index].data_structure, data)){
            hmap->arr[hash_index].size++;
            increment_elements_hmap(hmap);
        }
    }
    return 1;

}

rb_tree* convert_to_rbt(hmap *hmap1, long hash_index){
    linked_list *list = get_data_structure_hmap(hmap1, hash_index);
    rb_tree *new_data_structure = new_rb_tree();
//            create_bst(get_data_list(head_list));

    node_list *current = get_head_list(list);
    while (current != NULL){
        insert_rbt(new_data_structure, get_data_list(current));
        current = get_next(current);
    }
    // TODO delete list
    return new_data_structure;
}

void* get_data_structure_hmap(hmap *hmap1, int hash_index){
    return hmap1->arr[hash_index].data_structure;
}

void delete_hmap(struct hmap* hmap, char* data){
    long hash_index = hash(data);

    hmap->arr[hash_index].data_structure =
            hmap->arr[hash_index].functions->delete(hmap->arr[hash_index].data_structure, data);

    hmap->arr[hash_index].size = hmap->arr[hash_index].functions->count_elements(hmap->arr[hash_index].data_structure);
}


void printTest(){
    printf("test = %d\n", test);
}

void increment_elements_hmap(hmap *hmap1){
    hmap1->no_elements++;
}

int get_no_elements_hmap(hmap *hmap1){
    return hmap1->no_elements;
}

int find_hmap(void* hmap1, char* data){
    hmap* hash_map = hmap1;
    long hash_index = hash(data);

    //size 0 of node in hash table indicates no elements in that node
    if(hash_map->arr[hash_index].size == 0)
        return 0;
    //otherwise find element
    return hash_map->arr[hash_index].functions->find(hash_map->arr[hash_index].data_structure, data);
}

void print_all_data_hmap(void* hmap1){
    hmap *hash_map = hmap1;
    int size = hash_map->size;
    int i;
    for (i = 0; i < size; i++) {
        if(hash_map->arr[i].size > 0)
            print_alldata_node_hmap(hash_map, i);
    }
}

char* min_hmap(void* ds){
    return "";
}

char *max_hmap(void *ds){
    return "";
}