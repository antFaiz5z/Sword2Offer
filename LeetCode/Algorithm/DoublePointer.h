//
// Created by Faiz on 2019/1/9 0009.
//

#ifndef JIANZHIOFFER_DOUBLE_POINTER_H
#define JIANZHIOFFER_DOUBLE_POINTER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DoublePointer {

public:

    //167
    static vector<int> twoSum(vector<int> &numbers, int target);
    //633
    static bool judgeSquareSum(int c);
    //524
    static string findLongestWord(string s, vector<string>& d);

    //125
    bool isPalindrome(string s);

    //131
    vector<vector<string>> partition(string s);
    void bt(string &s, vector<vector<string>> &ret, vector<string> &sub, int index);

    //139
    bool wordBreak(string s, vector<string>& wordDict);

private:

};


#endif //JIANZHIOFFER_DOUBLE_POINTER_H
