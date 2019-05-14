//
// Created by Faiz on 2019/1/9 0009.
//

#ifndef JIANZHIOFFER_HASH_TABLE_H
#define JIANZHIOFFER_HASH_TABLE_H

#include <vector>
#include <string>

using namespace std;

class HashTable {

public:

    //1
    vector<int> twoSum(vector<int>& nums, int target);          //暴力      O(n2) O(1)
    vector<int> twoSum_hashI(vector<int>& nums, int target);    //哈希 两遍 O(n)  O(n)
    vector<int> twoSum_hashII(vector<int>& nums, int target);   //哈希 一遍 O(n)  O(n)

    //3
    int lengthOfLongestSubstring(string s);
};


#endif //JIANZHIOFFER_HASH_TABLE_H
