//
// Created by Faiz on 2019/6/30 0030.
//

#ifndef SWORD2OFFER_UNSORTED_H
#define SWORD2OFFER_UNSORTED_H

#include <vector>
#include <string>

using namespace std;


class Unsorted {

public:
    //1103
    vector<int> pathInZigZagTree(int label);

    //7
    int reverse(int x);
    //判断x+y是否溢出
    bool add_overflow(int x, int y);
    int reverseII(int x);

    //8
    int myAtoi(string str);
};


#endif //SWORD2OFFER_UNSORTED_H
