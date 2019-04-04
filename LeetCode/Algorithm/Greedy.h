//
// Created by Faiz on 2019/1/9 0009.
//

#ifndef JIANZHIOFFER_GREEDY_H
#define JIANZHIOFFER_GREEDY_H

#include <vector>
#include <string>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Greedy {

    //455
    int getContentChildren(vector<int> &g, vector<int> &s);

    //435
    int eraseOverlapIntervals(vector<Interval> &intervals);

    //452
    int findMinArrowShots(vector<pair<int, int>> &points);

    //406
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people);

    //763
    vector<int> partitionLabels(string S);

    //605
    bool canPlaceFlowers(vector<int> &flowerbed, int n);

    //392
    bool isSubsequence(string s, string t);

    //665
    bool checkPossibility(vector<int> &nums);

    bool checkPossibilityII(vector<int> &nums);

    //122
    int maxProfit(vector<int> &prices);

    int maxProfitII(vector<int> &prices);

    //53
    int maxSubArray(vector<int> &nums);

    int maxSubArrayII(vector<int> &nums);

    //55
    bool canJump(vector<int> &nums);

    //45
    int jump(vector<int> &nums);


};

#endif //JIANZHIOFFER_GREEDY_H
