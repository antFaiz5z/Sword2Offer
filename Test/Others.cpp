//
// Created by Faiz on 2019/4/23 0023.
//

#include "Others.h"

void Others::MergeTimeSegment(uint64_t nBeginTime, uint64_t nEndTime, std::list<TimeSegment> &lstTimeSegment) {

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
            //show(lstTimeSegment);
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
}

void Others::removeAnnotation() {//error

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

void Others::string2digitalComputation() {

    string tmp;
    cin >> tmp;
    int ret = 0;
    int ch, now = 0;
    bool first = true;
    bool negative = false;

    for (char i : tmp) {

        if (i < '0' || i > '9'){
            if (i == '-' && first){
                negative = true;
            }
            if (!first){
                ret = negative ? ret - now : ret + now;
                now = 0;
                first = true;
                negative = i == '-';
            }
            continue;
        }
        ch = i - '0';
        if (ch == 0 && first){
            continue;
        }
        now = now* 10 +ch;
        first = false;

    }
    ret = negative ? ret - now : ret + now;
    cout << ret;
}
