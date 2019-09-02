//
// Created by Faiz on 2019/9/2 0002.
//

#ifndef SWORD2OFFER_QUICKSORTK_H
#define SWORD2OFFER_QUICKSORTK_H

/* 使用部分快排，查找第k小的数，或者第k大的数*/

#include <cstdio>
#include <cstdlib>

int partition(int data[], size_t left, size_t right) {
    int i = left;
    int j = right;
    int p = (left + right) / 2;
    int pivot = data[p];
    while (i < j) {
        for (; i < p && data[i] <= pivot; ++i);
        if (i < p) {
            data[p] = data[i];
            p = i;
        }
        for (; j > p && data[j] >= pivot; --j);
        if (j > p) {
            data[p] = data[j];
            p = j;
        }
    }
    data[p] = pivot;
    return p;

}

void quick_sort(int data[], size_t left, size_t right) {
    if (left < right) {
        int index = partition(data, left, right);
        if (index - left > 1)
            quick_sort(data, left, index - 1);
        if (right - index > 1)
            quick_sort(data, index + 1, right);
    }
}

void findK(int data[], size_t left, size_t right, size_t k) {
    if (left < right) {
        int mid = partition(data, left, right);
        if (mid - left + 1 >= k)
            findK(data, left, mid, k);
        else
            findK(data, mid + 1, right, k - (mid - left + 1));
    }
}



#endif //SWORD2OFFER_QUICKSORTK_H
