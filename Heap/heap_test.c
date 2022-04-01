/**
 * @file heap_test.c
 * @author 堆测试
 * @brief 
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

static long cmp_func(void *a, void *b) {
    return (long)(*(int*)a - *(int*)b);
}


int main() {

    srand(time(NULL));

    printf("----------heap_test--------------\n");

    heap_t *hp = heap_create(cmp_func);

    printf("\nheap create:\n");
    printf("heap_size: %ld\nheap_capacity: %ld\n",heap_size(hp), heap_capacity(hp));

    // 添加元素
    printf("\npush int number:\n");
    for(int i = 0; i < 10; i++) {
        int rand_num = rand() % 100;
        printf("idx: %d, num: %d\n", i, rand_num);
        int ret = heap_push(hp, (void *)&rand_num);
        if (ret != HEAP_ERR_SUCCESS) {
            printf("[error]: %d\n", ret);
            break;
        }
    }

    heap_destroy(hp);

    return 0;
}
