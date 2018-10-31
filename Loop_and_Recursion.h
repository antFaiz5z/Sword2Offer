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
     * 10.2 跳台阶
     * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
     */
    // 斐波那契数列
    int jumpFloor(int number);
    int jumpFloor_dynamic_programming(int number);
    int jumpFloor_dynamic_programming_2(int number);
    /*
     * 10.4 变态跳台阶
     * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
     */
    // XX三角
    int jumpFloorII(int number);
    int jumpFloorII_dynamic_programming(int number);
    static void local_main_jumpFloor();

    /*
     * 38. 字符串的排列
     *输入一个字符串,按字典序打印出该字符串中字符的所有排列。
     * 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
     * 描述：输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
     */
    vector<string> permutation(string str);
    void permutation_recur(vector<string> &res, int k, string str);
    static void local_main_permutation();

};


#endif //JIANZHIOFFER_LOOP_AND_RECURSION_H
