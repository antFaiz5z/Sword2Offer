//
// Created by Faiz on 2019/4/23 0023.
//

#ifndef JIANZHIOFFER_OTHERS_H
#define JIANZHIOFFER_OTHERS_H

#include <iostream>
#include <list>
#include <cstdint>

using namespace std;

struct TimeSegment {
    uint64_t btime;
    uint64_t etime;

    TimeSegment() : btime(0), etime(0) {}

    TimeSegment(uint64_t btime_, uint64_t etime_) : btime(btime_), etime(etime_) {}
};

class Others {

    //给出若干左闭右开（也许相反）区间，保留begin至end之间部分
    void MergeTimeSegment(uint64_t nBeginTime, uint64_t nEndTime, std::list<TimeSegment> &lstTimeSegment);

    //将代码中注释部分删去，包括//与/**/，考虑转义符
    void removeAnnotation();

    //计算字符串中数字部分之和
    void string2digitalComputation();

};


#endif //JIANZHIOFFER_OTHERS_H
