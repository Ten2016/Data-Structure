/**
 * @file quick_sort_test.c
 * @author tjl (you@domain.com)
 * @brief 快排单侧
 * @version 0.1
 * @date 2022-02-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quick_sort.h"

/**
 * @brief 打印数组
 * 
 * @param arr 待打印数组
 * @param len 长度
 */
static void print(int arr[], int len) {
    printf("len: %d\t", len);

    for (int i = 0; i < len; i++) {
        printf("%u ", arr[i]);
    }

    printf("\n");
    return ;
}

static void build(int arr[], int len) {

    int M = len * 10;
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % M;
    }

    // print(arr, len);
}

static void check(int arr1[], int arr2[], int len) {

    // print(arr1, len);
    for (int i = 0; i < len; i++) {
        if (arr1[i] != arr2[i]) {
            printf("diff, len: %d, idx: %d, %u %u\n", len, i, arr1[i], arr2[i]);
            return ;
        }
    }
}


int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main(int argc, char **argv) {

    if (argc < 2) {
        printf("parameter not enough");
        exit(1);
    }

    int run_count = atoi(argv[1]);
    time_t curr_time = time(NULL);

    srand(curr_time);

    printf("curr_time: %u\n", curr_time);

    int *arr_raw = (int*)malloc(run_count * sizeof(int));
    int *arr_qs = (int*)malloc(run_count * sizeof(int));
    if (!arr_raw || !arr_qs) {
        printf("malloc failed, size: %u", run_count);
        exit(1);
    }

    for (int i = 1; i <= run_count; i += 100) {

        build(arr_raw, i);
        memcpy(arr_qs, arr_raw, i * sizeof(int));
        quick_sort(arr_qs, i);

        qsort(arr_raw, i, sizeof(int), cmp);

        check(arr_qs, arr_raw, i);

    }

    printf("run time: %u\n", time(NULL) - curr_time);

    free(arr_raw);
    free(arr_qs);
    return 0;
}