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
                             &print_all_data_list,
                             &find_list,
                             &_delete_list,
                             &_count_elements_list,
                             &min_list,
                             &max_list,
                             &successor_list
};

//poprawić
functions functions_bst = { &insert_bs_tree,
                            &print_inorder_bs_tree,
                            &find_bs_tree,
                            &delete_rbt,
                            &count_elements_rbt,
                            &min_bs_tree,
                            &max_bs_tree,
                            &successor_bs_tree
};

functions functions_rbt = { &insert_rbt,
                            &print_inorder_rbt,
                            &find_rb_tree,
                            &delete_rbt,
                            &count_elements_rbt,
                            &min_rb_tree,
                            &max_rb_tree,
                            &successor_rb_tree
};

functions functions_hmap = { &insert_hmap,
                             &print_all_data_hmap,
                             &find_hmap,
                             &delete_hmap,
                             &count_elements_hmap,
                             &min_hmap,
                             &max_hmap,
                             &successor_hmap
};
