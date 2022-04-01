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


/**
 * @brief 调整堆容量
 * 
 * @param cap [in out] 调整后的堆容量
 * @return int 
 */
static int heap_cap_resize(long *cap)
{
    if (*cap >= HEAP_CAPACITY_MAX) {
        return HEAP_ERR_CAPACITY_FULL;
    }

    *cap <<= 1;
    if (*cap > HEAP_CAPACITY_MAX) {
        *cap = HEAP_CAPACITY_MAX;
    }
    return HEAP_ERR_SUCCESS;
}

#define HEAP_DATA_SWAP(__a, __b) \
do { \
    void *tmp = __a; \
    __a = __b; \
    __b = tmp; \
} while(0)


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
    heap_cmp_func cmp_f;
};


/**
 * @brief 创建堆
 * 
 * @param cmp 堆元素比较函数
 * @return heap_t* 
 */
heap_t *heap_create(heap_cmp_func cmp)
{
    heap_t *hp = malloc(sizeof(heap_t));
    if (!hp) {
        return NULL;
    }

    void **data = malloc(sizeof(void *) * HEAP_CAPACITY_DFT);
    if (!data) {
        free(hp);
        return NULL;
    }

    if (cmp) {
        hp->cmp_f = cmp;
    }
    else {
        hp->cmp_f = heap_cmp_func_dft;
    }

    hp->size = 0;
    hp->capacity = HEAP_CAPACITY_DFT;
    hp->data = data;

    return hp;
}


/**
 * @brief 获取堆元素个数
 * 
 * @param hp 
 * @return long 
 */
long heap_size(heap_t *hp)
{
    if (!hp) {
        return HEAP_ERR_PARAMETER_INVALID;
    }
    return hp->size;
}


/**
 * @brief 获取堆容量大小
 * 
 * @param hp 
 * @return long 
 */
long heap_capacity(heap_t *hp)
{
    if (!hp) {
        return HEAP_ERR_PARAMETER_INVALID;
    }
    return hp->capacity;
}


/**
 * @brief 释放堆
 * 
 * @param hp 
 */
void heap_destroy(heap_t *hp)
{
    if (!hp) {
        return ;
    }

    if (hp->data) {
        free(hp->data);
    }
    free(hp);

    return ;
}


/**
 * @brief 向堆中添加元素
 * 
 * @param hp 
 * @param data 
 * @return int 
 */
int heap_push(heap_t *hp, void *data)
{
    if (!hp || !hp->cmp_f || !data) {
        return HEAP_ERR_PARAMETER_INVALID;
    }

    if (hp->size >= hp->capacity) {
        long cap = hp->capacity;
        int ret = heap_cap_resize(&cap);
        if (ret != HEAP_ERR_SUCCESS) {
            return ret;
        }

        void **re_data = (void**)realloc(hp->data, sizeof(void *) * cap);
        if (!re_data) {
            return HEAP_ERR_MEMORY_ERROR;
        }
        hp->data = re_data;
        hp->capacity = cap;
    }

    int cur_idx = hp->size;
    hp->data[cur_idx] = data;
    hp->size++;
    
    // 调整堆
    while(cur_idx != 0) {
        int par_idx = (cur_idx - 1) >> 1;
        if (hp->cmp_f(hp->data[cur_idx], hp->data[par_idx]) >= 0) {
            break;
        }
        HEAP_DATA_SWAP(hp->data[cur_idx], hp->data[par_idx]);
        cur_idx = par_idx;
    }

    return HEAP_ERR_SUCCESS;
}


/**
 * @brief 从堆中取数据
 * 
 * @param tp 
 * @param data [out] 堆顶元素
 * @return int 
 */
int heap_pop(heap_t *tp, void **data)
{
    if (!tp || !tp->cmp_f || !data) {
        return HEAP_ERR_PARAMETER_INVALID;
    }

    if (tp->size == 0) {
        return HEAP_ERR_DATA_EMPTY;
    }

    *data = tp->data[0];
    tp->size--;
    tp->data[0] = tp->data[tp->size];

    long cur_idx = 0;
    // 调整堆
    while (cur_idx <= tp->size) {

    }

    return HEAP_ERR_SUCCESS;
}


/**
 * @brief 获取堆顶元素
 * 
 * @param tp 
 * @param data [out] 堆顶元素
 * @return int 
 */
int heap_top(heap_t *tp, void **data)
{
    if (!tp || !tp->cmp_f || !data) {
        return HEAP_ERR_PARAMETER_INVALID;
    }

    if (tp->size == 0) {
        return HEAP_ERR_DATA_EMPTY;
    }

    *data = tp->data[0];

    return HEAP_ERR_SUCCESS;
}
