//
// Created by Faiz on 2019/6/30 0030.
//

#include "Unsorted.h"

#include <map>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> Unsorted::pathInZigZagTree(int label) {
    vector<int> ret;
    vector<vector<int>> seqs;
    int floor = 0;
    int direction = 0;
    int count = 0;
    int begin = 1, end = 1;
    int index = 0;
    while (count < label){
        ++floor;
        vector<int> seq;
        begin = end;
        //end = 2 ^ floor;
        end = pow(2, floor);
        for (int i = begin; i < end; ++i){
            seq.push_back(i);
            ++count;
        }
        if (direction){
            reverse(seq.begin(), seq.end());
        }
        seqs.push_back(seq);
        direction = 1 - direction;
    }
    //vector<int> seq = seqs[floor -1];
    for (int i = 0; i < seqs[floor -1].size(); ++i){
        if (label == seqs[floor -1][i]){
            index = i;
            break;
        }
    }
    while(floor){
        ret.push_back(seqs[--floor][index]);
        index /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;

}

void Unsorted::bytedance_one() {


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

void Unsorted::bytedance_two() {


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

void Unsorted::bytedance_bt(vector<int> &score, vector<int> &divide, int n, int *max_score, int now_score, int direction, int index){

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

