//
// Created by Faiz on 2019/6/30 0030.
//

#ifndef SWORD2OFFER_UNSORTED_H
#define SWORD2OFFER_UNSORTED_H

#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Unsorted {

public:
    //1103
    vector<int> pathInZigZagTree(int label);

    //7
    int reverse(int x);
    //判断x+y是否溢出
    bool add_overflow(int x, int y);
    int reverseII(int x);

    //8
    int myAtoi(string str);

    //242
    bool isAnagram(string s, string t);

    //395
    int longestSubstring(string s, int k);

    //124
    int maxPathSum(TreeNode* root);
    int max_gain(TreeNode* root, int &max_sum)
};


#endif //SWORD2OFFER_UNSORTED_H
