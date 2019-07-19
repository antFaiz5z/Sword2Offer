//
// Created by Faiz on 2019/5/13 0013.
//

#ifndef SWORD2OFFER_BIT_H
#define SWORD2OFFER_BIT_H

#include <vector>
#include <cstdint>

using namespace std;

/*
 * 1.如果 n 以 1 结尾：
 * xxxxx1
 * 则 n - 1 的二进制表示为：
 * xxxxx0
 * 此时：n and n - 1 = xxxxx0
 *
 * 2.如果 n 以 0 结尾：
 * xxx10..0
 * 则 n - 1 的二进制表示为：
 * xxx01..1
 * 此时：n and n - 1 = xxx00..0
 *
 * 两种情况都去掉了最后一个 1
 *
 * 3.相同的数字异或后为 0。
 * 4.任何数异或 0 都等于其本身。
 *
 */
class Bit {
public:

    //78
    vector<vector<int>> subsets(vector<int> &nums);
    void helper(vector<vector<int>> &results, vector<int> &subsets, vector<int> &nums, int start);

    //191
    int hammingWeight(uint32_t n);
    int hammingWeightII(int32_t n);

    bool isPowerOf(int n, int base);
    //231
    bool isPowerOfTwo(int n);
    bool isPowerOfTwoII(int n);
    bool isPowerOfTwoIII(int n);

    //326
    bool isPowerOfThree(int n);
    bool isPowerOfThreeII(int n);
    //342
    bool isPowerOfFour(int n);
    bool isPowerOfFourII(int n);

    //136
    int singleNumber(vector<int>& nums);
    int singleNumberII(vector<int>& nums);

    //137
    int singleNumber2(vector<int>& nums);



};


#endif //SWORD2OFFER_BIT_H
