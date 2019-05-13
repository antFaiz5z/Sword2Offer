//
// Created by Faiz on 2019/1/9 0009.
//

#ifndef JIANZHIOFFER_HASH_TABLE_H
#define JIANZHIOFFER_HASH_TABLE_H

#include <vector>

using namespace std;

class HashTable {

public:

    //1
    vector<int> twoSum(vector<int>& nums, int target);          //O(n2) O(1)
    vector<int> twoSum_hashI(vector<int>& nums, int target);    //O(n)  O(n)
    vector<int> twoSum_hashII(vector<int>& nums, int target);   //O(n)  O(n)

};


#endif //JIANZHIOFFER_HASH_TABLE_H
