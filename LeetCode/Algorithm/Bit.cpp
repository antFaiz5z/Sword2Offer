//
// Created by Faiz on 2019/5/13 0013.
//

#include "Bit.h"

#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_set>

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
        helper(results, subsets, nums, i + 1);
        subsets.pop_back();
    }
}

int Bit::hammingWeight(uint32_t n) {

    int ret = 0;
    while (n) {
        n = n & n - 1;
        ++ret;
    }
    return ret;
}

int Bit::hammingWeightII(int32_t n) {

    int ret = 0;
    while (n) {
        if (n == INT_MIN) {//INT_MIN-1溢出
            ++ret;
            break;
        }
        n = n & n - 1;
        ++ret;
    }
    return ret;
}

bool Bit::isPowerOf(int n, int base) {//base可正可负

    if (n == 0 || (base > 0 && n < 0))
        return false;
    while (n != 1) {
        if (n % base)
            return false;
        n /= base;
    }
    return true;
}

bool Bit::isPowerOfTwo(int n) {

    return isPowerOf(n, 2);
}

bool Bit::isPowerOfTwoII(int n) {

    return n > 0 && !(n & n - 1);
}

bool Bit::isPowerOfTwoIII(int n) {

    return n > 0 && (int)pow(2, 30) % n == 0;
    //pow(2,30)为不超过INT_MAX的2的最大次幂
    // 因为 2 是质数，所以 2^30的除数只有 2^1,2^2,…,2 ^30
}

bool Bit::isPowerOfThree(int n) {

    return isPowerOf(n, 3);
}

bool Bit::isPowerOfThreeII(int n) {

    return n > 0 && (int) pow(3, 19) % n == 0;
    //pow(3,19)为不超过INT_MAX的3的最大次幂
    // 因为 3 是质数，所以 3^19的除数只有 3^1,3^2,…,3 ^19
}

bool Bit::isPowerOfFour(int n) {

    return isPowerOf(n, 4);
}

bool Bit::isPowerOfFourII(int n) {

    //若是4的幂次，奇数位1的个数为1，反之为0
    if (n < 0 || n & n -1) return false;
    return n & 0x55555555;//...010101 或者//return n % 3 == 1;
    return n > 0 && !(n & n -1) && n & 0x55555555;
    return n > 0 && !(n & n -1) && !(n & 0xAAAAAAAA);
}

int Bit::singleNumber(vector<int> &nums) {//位运算，空间复杂度O(1)

    //异或运算的另一个含义是“二进制下不考虑进位的加法”：0+0 = 0， 1+1=0……
    int ret = 0;
    for (auto & i : nums){
        ret ^= i;
    }
    return ret;
}

int Bit::singleNumberII(vector<int> &nums) {//哈希表，空间复杂度O(n)

    unordered_set<int> set;
    for (auto &i : nums){
        if (set.find(i) != set.end()){
            set.erase(i);
        }else{
            set.insert(i);
        }
    }
    return *(set.begin());
}

int Bit::singleNumber2(vector<int> &nums) {

    //创建“三进制下不考虑进位的加法”
    int ones = 0, twos = 0, threes = 0;
    for (auto &i : nums){
        twos |= ones & i;       // ones & num 提取两个数都为1的位，与twos作或操作保留出现2次的位
        ones ^= i;              // 当 ones 和 num 同时为 1 or 0 时，ones = 0，因为同时为1已经加到twos里了，这里不做count
        threes = ones & twos;   // 当ones和twos对应位都为1时，说明此位出现了3次
        ones &= ~threes;        // three为1的位，将one和two对应位归零
        twos &= ~threes;
    }
    return ones;
}


