//
// Created by faiz on 18-5-12.
//

#ifndef JIANZHIOFFER_LOOP_AND_RECURSION_H
#define JIANZHIOFFER_LOOP_AND_RECURSION_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Loop_and_Recursion {

public:

    /*
     * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
     */
    int jumpFloor(int number);
    /*
     * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
     */
    int jumpFloorII(int number);
    static void local_main_jumpFloor();


    vector<string> permutation(string str);
    void permutation_recur(vector<string> &res, int k, string str);
    static void local_main_permutation();

};


#endif //JIANZHIOFFER_LOOP_AND_RECURSION_H
