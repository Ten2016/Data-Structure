/**
 * @file quick_sort.c
 * @author tjl (you@domain.com)
 * @brief 快排
 * @version 0.1
 * @date 2022-02-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

#include "quick_sort.h"



static void quick_sort_(int arr[], int left, int right) {
    if (left < right) {
        int p = arr[left];
        int l = left;
        int r = right;

        while (l < r) {
            while (l < r && arr[r] >= p) r--;   // 从右往左找到第一个小于p的值
            arr[l] = arr[r];                    // 交换到左边
            while (l < r && arr[l] <= p) l++;   // 从左往右找到第一个大于p的值
            arr[r] = arr[l];                    // 交换到右边
        }

        arr[l] = p;
        quick_sort_(arr, left, l - 1);
        quick_sort_(arr, l + 1, right);
    }
}


/**
 * @brief 快排接口
 * 
 * @param arr 待排序数组
 * @param len 长度
 * @return int 0：成功 -1：失败
 */
int quick_sort(int arr[], int len) {

    quick_sort_(arr, 0, len - 1);

    return 0;
}