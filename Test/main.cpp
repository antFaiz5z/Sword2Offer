//
// Created by Faiz on 2019/3/18 0018.
//
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <cstring>
#include <list>

using namespace std;

/*struct TimeSegment {
    uint64_t btime;
    uint64_t etime;

    TimeSegment() : btime(0), etime(0) {
    }

    TimeSegment(uint64_t btime_, uint64_t etime_) : btime(btime_), etime(etime_) {
    }
};


void show(std::list<TimeSegment> &lst){

    cout << "---------------" <<endl;
    for (auto &i : lst){
        cout << i.btime << ", " << i.etime << endl;
    }
}

inline void MergeTimeSegment(uint64_t nBeginTime, uint64_t nEndTime, std::list<TimeSegment> &lstTimeSegment) {

    for (auto it = lstTimeSegment.begin(); it != lstTimeSegment.end(); it++) {

        if (nBeginTime > it->etime) {
            continue;
        }
        if (nEndTime < it->btime) {
            lstTimeSegment.insert(it, TimeSegment(nBeginTime, nEndTime));
            return;
        }
        if (nBeginTime >= it->btime && nEndTime <= it->etime) {
            return;
        }
        if (nBeginTime < it->btime) {
            it->btime = nBeginTime;
            if (nEndTime >= it->btime && nEndTime <= it->etime) {
                return;
            }
        }

        auto it3 = it;
        auto it2 = ++it3;
        for (; it2 != lstTimeSegment.end();) {
            show(lstTimeSegment);
            if (nEndTime >= it2->etime) {
                it->etime = nEndTime;
                it2 = lstTimeSegment.erase(it2);
            } else if (nEndTime >= it2->btime && nEndTime < it2->etime) {
                it->etime = it2->etime;
                lstTimeSegment.erase(it2);
                return;
            } else {
                it->etime = nEndTime;
                return;
            }
        }
    }


}*/

/*    std::list<TimeSegment> lst;
    lst.emplace_back(10,20);
    lst.emplace_back(40,50);
    lst.emplace_back(60,70);
    lst.emplace_back(80,90);
    lst.emplace_back(100,110);

    show(lst);

    MergeTimeSegment(20, 40, lst);

    show(lst);*/


int main() {


/*    string tmp;
    cin >> tmp;
    int ret = 0;
    int ch, now = 0;
    bool first = true;
    bool negative = false;

    for (int i = 0; i < tmp.size(); ++i) {

        if (tmp[i] < '0' || tmp[i] > '9'){
            if (tmp[i] == '-' && first){
                negative = true;
            }
            if (!first){
                ret = negative ? ret - now : ret + now;
                now = 0;
                first = true;
                negative = tmp[i] == '-';
            }
            continue;
        }
        ch = tmp[i] - '0';
        if (ch == 0 && first){
            continue;
        }
        now = now* 10 +ch;
        first = false;

    }
    ret = negative ? ret - now : ret + now;
    cout << ret << endl;
    return ret;*/

    char *s = (char*)malloc(50);
    bool multi = false;


    while (scanf("%s\n", s)){
        string tmp = s;
        for (int i = 0; i < tmp.size(); ++i) {
            if (tmp[i] == '/' && tmp[i +1] == '/'){
                if (i > 0 && tmp[i -1] == '\\'){
                    continue;
                }
                break;
            }
            if (tmp[i] == '/' && tmp[i+ 1] == '*'){
                if (i > 0 && tmp[i -1] == '\\'){
                    continue;
                }
                multi = true;
            }
            if (multi){
                if (tmp[i] == '*' && tmp[i +1] == '/'){
                    multi = false;
                }
            }else{
                cout << tmp[i];
            }
        }
    }
}












