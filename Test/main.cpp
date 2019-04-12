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

struct TimeSegment {
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


}


int main() {

    std::list<TimeSegment> lst;
    lst.emplace_back(10,20);
    lst.emplace_back(40,50);
    lst.emplace_back(60,70);
    lst.emplace_back(80,90);
    lst.emplace_back(100,110);

    show(lst);

    MergeTimeSegment(20, 40, lst);

    show(lst);

    /*int n, begin, end;
    int max = 0, min = numeric_limits<int32_t>::max();
    vector<vector<int>> num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &begin, &end);
        num.push_back(vector<int>{begin,end});
    }
    for (auto &i : num) {
        cout << i[0] << ":" <<i[1] <<endl;
        if (i[0] < min) min = i[0];
        if (i[1] > max) max = i[1];
    }
    int *sum = new int[max - min]();
    for (auto &i : num) {
        for (int j = i[0]; j < i[1]; ++j) {
            sum[j - min] += 1;
        }
    }
    int ret = 0;
    for (int k = 0; k < max - min; ++k) {
        if (sum[k] > ret) ret = sum[k];
    }
    cout << ret;*/

    /*string str;
    vector<string> vs;
    while (cin >> str){
        vs.push_back(str);
    }
    sort(vs.begin(), vs.end(), [](string str1, string str2){return strcmp(str1.c_str(), str2.c_str());});
    string ret = "";
    for (auto &i : vs){
        ret += i;
    }
    cout << ret << endl;*/





}

