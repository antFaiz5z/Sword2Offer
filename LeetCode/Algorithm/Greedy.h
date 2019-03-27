//
// Created by Faiz on 2019/1/9 0009.
//

#ifndef JIANZHIOFFER_GREEDY_H
#define JIANZHIOFFER_GREEDY_H

#include <vector>

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
    int eraseOverlapIntervals(vector<Interval>& intervals);
    //452
    int findMinArrowShots(vector<pair<int, int>>& points);

};


#endif //JIANZHIOFFER_GREEDY_H
