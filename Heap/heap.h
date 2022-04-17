/**
 * @file heap.h
 * @author tjl
 * @brief 
 * @version 0.1
 * @date 2022-03-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __HEAP_H
#define __HEAP_H

#ifdef __cplusplus
extern "C" {
#endif

/* 数据内部存储方式  */
#define DATA_STORAGE_MODE_ARRAY
// #define DATA_STORAGE_MODE_TREE

/* 堆最大容量 */
#define HEAP_CAPACITY_MAX           (1 << 20)

typedef struct heap_s heap_t;

/**
 * @brief 错误码
 * 
 */
enum HEAP_ERR_CODE {
    HEAP_ERR_SUCCESS = 0,
    HEAP_ERR_PARAMETER_INVALID,
    HEAP_ERR_MEMORY_ERROR,
    HEAP_ERR_CAPACITY_FULL,
    HEAP_ERR_DATA_EMPTY
};

enum HEAP_PRINT_FLAF {
    HEAP_PRINT_NULL = 0,
    HEAP_PRINT_ENDLINE = 1,
};

/**
 * @brief 堆元素比较函数
 * 
 */
typedef long (*heap_cmp_func)(void *a, void *b);


/**
 * @brief 遍历元素回调函数
 * 
 */
typedef void (*heap_walk_func)(void *e, int flag);

/**
 * @brief 堆元素默认比较函数
 * 
 * @note  比较地址值
 * @param a 堆元素
 * @param b 堆元素
 * @return long 
 */
static long heap_cmp_func_dft(void *a, void *b)
{
    return (long)a - (long)b;
}


heap_t *heap_create(heap_cmp_func cmp);

heap_t *heap_create_from_data(heap_cmp_func cmp, void **data);

int heap_push(heap_t *hp, void *data);

int heap_pop(heap_t *hp, void **data);

int heap_top(heap_t *hp, void **data);

long heap_get_size(heap_t *hp);

long heap_get_capacity(heap_t *hp);

void heap_destroy(heap_t *hp);

void heap_walk(heap_t *hp, heap_walk_func walk);

#ifdef __cplusplus
}
#endif

#endif