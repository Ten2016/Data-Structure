/**
 * @file heap_sort.h
 * @author tjl
 * @brief 
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/**
 * @brief 元素比较函数
 * 
 */
typedef long (*cmp_func)(void *a, void *b);


/**
 * @brief 堆排序
 * 
 * @param data 待排序数据
 * @param size 元素个数
 * @param cmp  比较函数
 * @return int 
 */
int heap_sort(int *data, int size, cmp_func cmp);