/*
 * Autor: Sebastian Pabich
 */
//
// Created by sebastian on 05.05.18.
//

#include "external.h"
#include "alg_linked_list.h"
#include "alg_rbt.h"
#include "hmap.h"
#include "alg_bst.h"

functions functions_list = { &insert_list,
                             &_print_all_data_list,
                             &_find_list,
                             &_delete_list,
                             &_count_elements_list
};

//poprawić
functions functions_bst = { &insert_bst,
                            &print_inorder_rbt,
                            &find_rbt,
                            &delete_rbt,
                            &count_elements_rbt
};

functions functions_rbt = { &insert_rbt,
                            &print_inorder_rbt,
                            &find_rbt,
                            &delete_rbt,
                            &count_elements_rbt
};

functions functions_hmap = { &insert_hmap,
                             &print_all_data_hmap,
                             &find_hmap};
