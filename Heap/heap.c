/**
 * @file heap.c
 * @author tjl
 * @brief 
 * @version 0.1
 * @date 2022-03-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h>

#include "heap.h"


#define HEAP_CAPACITY_DFT           (1 << 4)

static int heap_cap_resize(long *cap)
{
    *cap <<= 1;
    if (*cap > HEAP_CAPACITY_MAX) {
        *cap = HEAP_CAPACITY_MAX;
        return HEAP_ERR_CAPACITY_FULL;
    }
    return HEAP_ERR_SUCCESS;
}



#ifdef DATA_STORAGE_MODE_TREE
    typedef struct binary_tree_s {
        void *data;
        struct binary_tree_s *left;
        struct binary_tree_s *right;
    } binary_tree_t;
#endif

/**
 * @brief 堆句柄
 * 
 */
struct heap_s {

    long size;

#ifdef DATA_STORAGE_MODE_ARRAY
    void **data;
#else
    binary_tree_t *data;
#endif

    long capacity;
    cmp_func cmp_f;
};


heap_t *heap_create(cmp_func cmp)
{
    heap_t *hp = malloc(sizeof(heap_t));
    if (!hp) {
        return NULL;
    }

    void **data = malloc(sizeof(void *) * HEAP_CAPACITY_DFT);

    if (cmp) {
        hp->cmp_f = cmp;
    }
    else {
        hp->cmp_f = heap_cmp_func_dft;
    }

    hp->size = 0;
    hp->capacity = HEAP_CAPACITY_DFT;


    hp->data = NULL;

    return hp;
}