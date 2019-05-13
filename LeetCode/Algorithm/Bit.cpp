//
// Created by Faiz on 2019/5/13 0013.
//

#include "Bit.h"

#include <algorithm>

vector<vector<int>> Bit::subsets(vector<int> &nums) {

    vector<vector<int>> results;
    vector<int> subsets;

    sort(nums.begin(), nums.end());
    helper(results, subsets, nums, 0);
    return results;
}

void Bit::helper(vector<vector<int>> &results, vector<int> &subsets, vector<int> &nums, int start) {

    results.push_back(subsets);
    for (int i = start; i < nums.size(); ++i) {
        subsets.push_back(nums[i]);
        helper(results, subsets, nums, i +1);
        subsets.pop_back();
    }
}
