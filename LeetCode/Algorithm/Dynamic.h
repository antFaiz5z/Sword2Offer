//
// Created by Faiz on 2019/7/9 0009.
//

#ifndef SWORD2OFFER_DYNAMIC_H
#define SWORD2OFFER_DYNAMIC_H

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Dynamic {
public:

    //62
    int uniquePaths(int m, int n);
    int uniquePathsII(int m, int n);
    int uniquePathsIII(int m, int n);

    //63
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
    int uniquePathsWithObstaclesII(vector<vector<int>>& obstacleGrid);

    //139
    bool wordBreak(string s, vector<string>& wordDict);
    //140
    vector<string> wordBreak2(string s, vector<string>& wordDict);
    //超时用例：
    //"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    //["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
    vector<string> wordBreak2II(string s, vector<string>& wordDict);//记忆化回溯
    vector<string> wordBreak2II_bt(string s, unordered_set<string> &t, unordered_map<int, vector<string>> &m, int index);

};


#endif //SWORD2OFFER_DYNAMIC_H
