//
// Created by Faiz on 2019/1/9 0009.
//

#include "Greedy.h"

#include <algorithm>

int Greedy::getContentChildren(vector<int> &g, vector<int> &s) {

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i, j;
    for (i = 0, j = 0; i < g.size() && j < s.size(); ++j) {
        if (g[i] <= s[j]) ++i;
    }
    return i;
}

int Greedy::eraseOverlapIntervals(vector<Interval> &intervals) {

    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.end < b.end; });
    int count = 1, end = 0;
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i].start < intervals[end].end) continue;
        ++count;
        end = i;
    }
    return static_cast<int>(intervals.size()) - count;
}

int Greedy::findMinArrowShots(vector<pair<int, int>> &points) {

    if (points.empty()) return 0;
    sort(points.begin(), points.end(), [](pair<int, int> a, pair<int, int> b){return a.second < b.second;});
    int count = 1, end = 0;
    for (int i = 1; i < points.size(); ++i) {
        if (points[i].first <= points[end].second) continue;
        ++count;
        end = i;
    }
    return count;
}
