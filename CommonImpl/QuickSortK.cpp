//
// Created by Faiz on 2019/9/2 0002.
//

#include "QuickSortK.h"

int main() {
    int data[] = {12, 2, 1, 0, 4, 11, -1, 9, 6};
    int len = sizeof(data) / sizeof(data[0]);
    //  quick_sort(data,0,len - 1);
    int i = 0;
    /* 打印原始序列 */
    for (i = 0; i < len; ++i) {
        printf(" %d ", data[i]);
    }
    printf("\n");
    findK(data, 0, len - 1, 5);
    printf(" x = %d\n", data[5 -1]);
    /* 找到第k个大的数后的序列*/
    for (i = 0; i < len; ++i) {
        printf(" %d ", data[i]);
    }
    printf("\n");
    /* 快排之后的序列*/
    quick_sort(data, 0, len - 1);
    for (i = 0; i < len; ++i) {
        printf(" %d ", data[i]);
    }
    printf("\n");

}