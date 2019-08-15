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
    int max_gain(TreeNode* root, int &max_sum);

    //128
    int longestConsecutive(vector<int>& nums);

    //5
    string longestPalindrome(string s);
    int longestPalindrome_search(string &s, int left, int right);



    //393
    bool validUtf8(vector<int>& data);
    bool validUtf8II(vector<int>& data);

    //93
    vector<string> restoreIpAddresses(string s);
    void restoreIpAddresses_bt(vector<string> &ret, string &s, vector<int> &nums, int index, int count);

    //468
    string validIPAddress(string IP);
    string validIPAddressII(string IP);
    void split(const string& s, vector<string> &vs, char delim = ' ');
    bool isValidIPv4(const string& IP);
    bool isValidIPv6(const string& IP);
};


#endif //SWORD2OFFER_UNSORTED_H
