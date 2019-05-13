//
// Created by Faiz on 2019/1/9 0009.
//

#include "HashTable.h"

#include <unordered_map>

vector<int> HashTable::twoSum(vector<int> &nums, int target) {

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i+1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target){
                return vector<int>{i, j};
            }
        }
    }
    return vector<int>();
}

vector<int> HashTable::twoSum_hashI(vector<int> &nums, int target) {

    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        map.insert(pair<int, int>(nums[i], i));
    }
    for (int i = 0; i < nums.size(); ++i) {
        int tmp = target - nums[i];
        if (map.find(tmp) != map.end()){
            return vector<int>{map.at(tmp), i};
        }
    }
    return vector<int>();
}

vector<int> HashTable::twoSum_hashII(vector<int> &nums, int target) {
    return vector<int>();
}
