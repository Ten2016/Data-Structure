/**
 * @file heap_sort.c
 * @author tjl
 * @brief 
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "heap_sort.h"

int heap_sort(void *data, int size, int type_size, cmp_func cmp)
{
    if (!data || size == 0 || !cmp) {
        return -1;
    }

    // 调整为堆


    // 排序
    for (int i = size; i > 0; i--) {
        // 交换第一个与最后一个
        
    }

    return 0;
}
