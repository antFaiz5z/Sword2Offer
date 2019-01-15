//
// Created by Faiz on 2019/1/11 0011.
//

#ifndef JIANZHIOFFER_SORT_H
#define JIANZHIOFFER_SORT_H

#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Sort {

    //215
    //排序 ：时间复杂度 O(NlogN)，空间复杂度 O(1)
    static int findKthLargest_stl(vector<int> &nums, int k);

    //堆排序 ：时间复杂度 O(NlogK)，空间复杂度 O(K)
    static int findKthLargest_heap(vector<int> &nums, int k);

    //快速选择 ：时间复杂度 O(N)，空间复杂度 O(1)   //LeetCode运行时间却最长
    static int findKthLargest_quick(vector<int> &nums, int k);

    static int partition(vector<int> &nums, int l, int h);

    static void swap(vector<int> &nums, int i, int j);

    //347
    vector<int> topKFrequent(vector<int> &nums, int k);
};


#endif //JIANZHIOFFER_SORT_H
