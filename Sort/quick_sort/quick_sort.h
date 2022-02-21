/**
 * @file quick_sort.h
 * @author tjl (you@domain.com)
 * @brief 快排
 * @version 0.1
 * @date 2022-02-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __QUICK_SORT_H
#define __QUICK_SORT_H


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 快排接口
 * 
 * @param arr 待排序数组
 * @param len 长度
 * @return int 0：成功 -1：失败
 */
int quick_sort(int arr[], int len);

/**
 * @brief 打印数组
 * 
 * @param arr 待打印数组
 * @param len 长度
 */
void print(int arr[], int len);


#ifdef __cplusplus
}
#endif


#endif
