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

/**
 *           0
 *       1       2
 *     3   4   5   6
 *   7
 * 
 */

static void heap_down(int *data, int begin, int size, cmp_func cmp)
{
    int cur_idx = begin;
    while (cur_idx < size) {
        int lc = (cur_idx << 1) + 1;
        int rc = (cur_idx << 1) + 2;
        int swap_idx;

        // 如果没有子节点
        if (lc >= size) {
            break;
        }

        // 如果只有左节点，则父节点与子节点进行比较
        if (rc >= size) {
            // 父节点小于子节点，退出
            if (cmp(&data[cur_idx], &data[lc]) <= 0) {
                break;
            }
            swap_idx = lc;
        }
        else {
            swap_idx = lc;
            // 比较左右子节点，得到较小者
            if (cmp(&data[rc], &data[lc]) < 0) {
                swap_idx = rc;
            }

            // 比较父节点与较小子节点
            if (cmp(&data[cur_idx], &data[swap_idx]) <= 0) {
                break;
            }
        }

        // 交换父节点与子节点
        int tmp = data[cur_idx];
        data[cur_idx] = data[swap_idx];
        data[swap_idx] = tmp;
        
        cur_idx = swap_idx;
    }
    return ;
}


int heap_sort(int *data, int size, cmp_func cmp)
{
    if (!data || size == 0 || !cmp) {
        return -1;
    }

    /**
     * @brief 构造堆
     * 
     *  步骤：
     *      1. 从最后一个不是叶子节点的节点开始
     *      2. 将它与它的子节点进行比较、交换
     *      3. 如果发生交换、继续往下比较
     *      4. 重复以上步骤，直到根节点
     * 
     */
    int last_par = (size >> 1) - 1;
    for (int i = last_par; i >= 0; i--) {
        heap_down(data, i, size, cmp);
    }


    /**
     * @brief 排序
     * 
     *  步骤：
     *      1. 将堆顶元素与末尾元素进行交换
     *      2. 调整堆，重新构成一个堆
     *      3. 重复以上步骤，每次将堆顶元素排在末尾
     */
    for (int i = size - 1; i > 0; i--) {
        // 交换第一个与最后一个
        int tmp = data[0];
        data[0] = data[i];
        data[i] = tmp;

        // 调整堆
        heap_down(data, 0, i + 1, cmp);
    }

    return 0;
}
