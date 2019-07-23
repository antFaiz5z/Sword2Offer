//
// Created by Faiz on 2019/6/30 0030.
//

#include "Unsorted.h"

#include <map>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

vector<int> Unsorted::pathInZigZagTree(int label) {
    vector<int> ret;
    vector<vector<int>> seqs;
    int floor = 0;
    int direction = 0;
    int count = 0;
    int begin = 1, end = 1;
    int index = 0;
    while (count < label) {
        ++floor;
        vector<int> seq;
        begin = end;
        //end = 2 ^ floor;
        end = pow(2, floor);
        for (int i = begin; i < end; ++i) {
            seq.push_back(i);
            ++count;
        }
        if (direction) {
            ::reverse(seq.begin(), seq.end());
        }
        seqs.push_back(seq);
        direction = 1 - direction;
    }
    //vector<int> seq = seqs[floor -1];
    for (int i = 0; i < seqs[floor - 1].size(); ++i) {
        if (label == seqs[floor - 1][i]) {
            index = i;
            break;
        }
    }
    while (floor) {
        ret.push_back(seqs[--floor][index]);
        index /= 2;
    }
    ::reverse(ret.begin(), ret.end());
    return ret;

}

int Unsorted::reverse(int x) {

    int ret = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        //32位环境下，max=2147483647，min=-2147483648
        if (ret > numeric_limits<int>::max() / 10 || (ret == numeric_limits<int>::max() / 10 && pop > 7)) return 0;
        if (ret < numeric_limits<int>::min() / 10 || (ret == numeric_limits<int>::min() / 10 && pop < -8)) return 0;
        ret = ret * 10 + pop;
    }
    return ret;
}

bool Unsorted::add_overflow(int x, int y) {

    //cout << x  << "+" << y << "=" << x+y <<endl;
    return (x >= 0 && y >= 0 && x + y < 0) || (x < 0 && y < 0 && x + y >= 0);
}

int Unsorted::reverseII(int x) {

    int ret = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (ret > numeric_limits<int>::max() / 10 || ret < numeric_limits<int>::min() / 10 ||
            add_overflow(ret * 10, pop))
            return 0;
        ret = ret * 10 + pop;
    }
    return ret;
}

int Unsorted::myAtoi(string str) {

    int index = 0, ret = 0;
    bool flag = true;
    int n = str.size();
    while (index < n && str[index] == ' ') ++index;
    if (index < n && str[index] == '+') {
        ++index;
    } else if (index < n && str[index] == '-') {
        flag = false;
        ++index;
    }
    for (int i = index; i < n; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            int pop = str[i] - '0';
            if (flag &&
                (ret > numeric_limits<int>::max() / 10 || (ret == numeric_limits<int>::max() / 10 && pop > 7))) {
                return numeric_limits<int>::max();
            }
            if (!flag &&
                (-ret < numeric_limits<int>::min() / 10 || (-ret == numeric_limits<int>::min() / 10 && pop >= 8))) {//!!!
                return numeric_limits<int>::min();
            }
            ret = ret * 10 + pop;
            //cout << ret << " " << pop << endl
        } else {
            break;
        }
    }

    return flag ? ret : -ret;
}

bool Unsorted::isAnagram(string s, string t) {

    if (s.size() != t.size()){
        return false;
    }
    multiset<char> set;
    for (auto &i : s){
        set.insert(i);
    }
    for (auto &i : t){
        if (set.find(i) != set.end()){
            set.erase(set.find(i));
        }else{
            return false;
        }
    }
    return true;
}


