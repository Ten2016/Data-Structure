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
#include "heap_sort.h"

static long cmp_lt_func(void *a, void *b) {
    return (long)(*(int*)a - *(int*)b);
}

static long cmp_gt_func(void *a, void *b) {
    return (long)(*(int*)b - *(int*)a);
}

static void print_func(void *e, int flag) {
    printf("%d ", *(int*)e);
    if (flag & HEAP_PRINT_ENDLINE) {
        printf("\n", flag);
    }

    return ;
}


static const int cnt = 50;
static const int mod = 291;


void heap_test(heap_cmp_func cmp_func)
{

    heap_t *hp = heap_create(cmp_func);

    printf("\nheap create:\n");
    printf("heap_size: %ld\theap_capacity: %ld\n",
                heap_get_size(hp), heap_get_capacity(hp));

    // 添加元素
    printf("\npush int number:\n");
    for(int i = 0; i < cnt; i++) {
        int *rand_num = (int *)malloc(sizeof(int));
        *rand_num = rand() % mod;
        
        printf("rand_num: %d\n", *rand_num);
        int ret = heap_push(hp, (void *)rand_num);
        if (ret != HEAP_ERR_SUCCESS) {
            printf("[error]: %d\n", ret);
            break;
        }

        // 获取堆顶元素
        int *elem = NULL;
        ret = heap_top(hp, (void**)&elem);
        if (ret != HEAP_ERR_SUCCESS) {
            printf("[error]: %d\n", ret);
        }

        printf("top: %d\t\theap_size: %ld\theap_capacity: %ld\n",
                    *elem, heap_get_size(hp), heap_get_capacity(hp));
    }

    // 遍历元素
    printf("\nprint:\n");
    heap_walk(hp, print_func);
    printf("\n");

    printf("\nheap_size: %ld\theap_capacity: %ld\n",
                heap_get_size(hp), heap_get_capacity(hp));


    for (int i = 0; i < cnt; i++) {
        int *elem_pop = NULL;
        int *elem_top = NULL;

        int ret = heap_top(hp, (void**)&elem_top);
        if (ret != HEAP_ERR_SUCCESS) {
            printf("[error]: %d\n", ret);
        }
        int ep = *elem_top;

        ret = heap_pop(hp, (void**)&elem_pop);
        if (ret != HEAP_ERR_SUCCESS) {
            printf("[error]: %d\n", ret);
        }
        int et = *elem_pop;

        printf("top: %d, pop: %d\n", et, ep);
        if (et != ep) {
            printf("[error]: top != pop\n");
        }
    }

    printf("\nheap_size: %ld\nheap_capacity: %ld\n",
                heap_get_size(hp), heap_get_capacity(hp));

    heap_destroy(hp);

    return ;
}


void heap_sort_test(heap_cmp_func cmp_func)
{
    if (!cmp_func) {
        return ;
    }

    // 添加元素
    printf("\nheap sort:\n");
    int arr[cnt];
    for(int i = 0; i < cnt; i++) {
        arr[i] = rand() % mod;
        printf("%d ", arr[i]);
    }

    printf("\n");

    // 排序
    heap_sort(arr, cnt, cmp_func);

    // 检查
    for(int i = 0; i < cnt; i++) {
        printf("%d ", arr[i]);
        //  检查排序结果
        if (i) {
            if (cmp_func(&arr[i-1], &arr[i]) > 0) {
                printf("\nerr: %d %d\n", arr[i-1], arr[i]);
                break;
            }
        }
    }
    printf("\n");

    return ;
}


int main() {

    srand(time(NULL));

    printf("----------heap_test--------------\n");

    // 最小堆测试
    heap_test(cmp_lt_func);

    // 最大堆测试
    heap_test(cmp_gt_func);

    // 堆排序测试[小到大]
    heap_sort_test(cmp_lt_func);

    // 堆排序测试[大到小]
    heap_sort_test(cmp_gt_func);

    return 0;
}


