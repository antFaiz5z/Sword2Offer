//
// Created by Faiz on 2019/5/13 0013.
//

#ifndef SWORD2OFFER_BIT_H
#define SWORD2OFFER_BIT_H

#include <vector>

using namespace std;

class Bit {
public:

    //78
    vector<vector<int>> subsets(vector<int>& nums);
    void helper(vector<vector<int>> &results, vector<int> &subsets, vector<int> &nums, int start);
};


#endif //SWORD2OFFER_BIT_H
