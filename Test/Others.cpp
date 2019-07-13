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



void Others::bytedance_one() {


    vector<int> a{1,2,10},b{1,2,3};
    int n = a.size();
    int x= 0;
    int y =0;
    int greater = 0;
    int same = 0;

/*    cin >> n;
    for (int i = 0; i < n; ++i) {
        int j;
        cin >> j;
        a.push_back(j);
    }
    for (int i = 0; i < n; ++i) {
        int j;
        cin >> j;
        b.push_back(j);
    }*/
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    while (x < n){
        if (a[x] > b[y] || y >= n){
            ++greater;
        }else if (a[x] == b[y]){
            ++same;
        }else if (a[x] < b[y]){
            ++x;
            continue;
        }
        ++x;
        ++y;

    }

    cout << greater *2 + same - n << endl;
}

void Others::bytedance_two() {


    vector<int> score{2,7,9,4,3};
    int n = score.size();
    vector<int> divide;
    int *max_score = (int *)malloc(sizeof (int));
    //int *now_score = (int *)malloc(sizeof (int));
    //int *direction = (int *)malloc(sizeof (int));
    *max_score = 0;
    //*now_score = 0;
    //*direction = 1;

    /*cin >> n;
    for (int i = 0; i < n; ++i) {
        int j;
        cin >> j;
        score.push_back(j);
    }*/

    bytedance_bt(score, divide, n, max_score, 0, 1, 0);
    cout << *max_score << endl;

}

void Others::bytedance_bt(vector<int> &score, vector<int> &divide, int n, int *max_score, int now_score, int direction, int index){

    if (index >= n){
        *max_score = max(*max_score, now_score);
        return;
    }
    int begin = 1, end;
    if (index == 0){
        end = min (2, n);
    } else{
        end = min (divide[divide.size() -1] * 2, n - index);
    }
    for (int i = begin; i <= end; ++i) {
        divide.push_back(i);
        //index += i;
        int sum = 0;
        if (direction) {
            for (int j = 0; j < i; ++j) {
                sum += score[index + j];
            }
            //*now_score += sum;
        }
        //direction = 1 - direction;
        bytedance_bt(score, divide, n, max_score, now_score + sum, 1- direction, index + i);
        //*now_score -= sum;
        divide.pop_back();
    }
}