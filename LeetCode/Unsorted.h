//
// Created by Faiz on 2019/6/30 0030.
//

#ifndef SWORD2OFFER_UNSORTED_H
#define SWORD2OFFER_UNSORTED_H

#include <vector>

using namespace std;


class Unsorted {

public:
    //1103
    vector<int> pathInZigZagTree(int label);

    void bytedance_one();//error

    void bytedance_two();//error

    void bytedance_bt(vector<int> &score, vector<int> &divide, int n, int *max_score, int now_score, int direction, int index);

};


#endif //SWORD2OFFER_UNSORTED_H
