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
    vector<int> twoSum(vector<int> &nums, int target);          //暴力      O(n2) O(1)
    vector<int> twoSum_hashI(vector<int> &nums, int target);    //哈希 两遍 O(n)  O(n)
    vector<int> twoSum_hashII(vector<int> &nums, int target);   //哈希 一遍 O(n)  O(n)

    //3
    int lengthOfLongestSubstring(string s);

    int lengthOfLongestSubstringII(string s);

    //18
    vector<vector<int>> fourSum(vector<int> &nums, int target);

    //15
    vector<vector<int>> threeSum(vector<int> &nums, int target);

    //
    vector<vector<int>> kSum(vector<int> &nums, int target, int k, int start);

    //454
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D);

    //30
    vector<int> findSubstring(string s, vector<string> &words);

    vector<int> findSubstringII(string s, vector<string> &words);

    //76
    string minWindow(string s, string t);
    string minWindowII(string s, string t);

};


#endif //JIANZHIOFFER_HASH_TABLE_H
