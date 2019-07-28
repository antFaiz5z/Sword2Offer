//
// Created by Faiz on 2019/4/23 0023.
//

#ifndef JIANZHIOFFER_OTHERS_H
#define JIANZHIOFFER_OTHERS_H

#include <cstdint>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct TimeSegment {
    uint64_t btime;
    uint64_t etime;

    TimeSegment() : btime(0), etime(0) {}

    TimeSegment(uint64_t btime_, uint64_t etime_) : btime(btime_), etime(etime_) {}
};

class Others {
public:

    //牛客
    //给出若干左闭右开（也许相反）区间，保留begin至end之间部分
    void MergeTimeSegment(uint64_t nBeginTime, uint64_t nEndTime, std::list<TimeSegment> &lstTimeSegment);

    //将代码中注释部分删去，包括//与/**/，考虑转义符
    void removeAnnotation();

    //计算字符串中数字部分之和
    void string2digitalComputation();

    //bytedance
    void bytedance_one();//error 30%
    void bytedance_two();//error
    void bytedance_bt(vector<int> &score, vector<int> &divide, int n, int *max_score, int now_score, int direction,
                      int index);

    //牛客
    //'?'可为'A'或'B'，使丑陋数（叠词）最小
    void ugly();

    //0~n-1中选k个数之和为n的倍数
    void combination();//error 10%
    void find(int &ret, int n, int k, int start, int now, int rest);

    //连续走n步（每次都可前进或后退），覆盖距离的期望
    void expectation();//error 50%,运行超时
    void insert(float &sum, float &count, int n, int now, int sum_now, int ma, int mi);

    //pdd
    //用数组B中尽量大的一个数替换数组A中的一个数使其严格递增
    void pdd_one();

    //判断各字符串是否可以头尾相接形成环（相接即字符相同）
    bool pdd_two();

    bool search(vector<pair<char, char >> &v2, unordered_multimap<char, char> &s, int index);


};


#endif //JIANZHIOFFER_OTHERS_H
