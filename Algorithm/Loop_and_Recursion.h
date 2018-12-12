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
     * 10.1 斐波那契数列
     * 10.2 跳台阶
     * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
     * 10.3 矩形覆盖
     * 我们可以用 2*1 的小矩形横着或者竖着去覆盖更大的矩形。请问用 n 个 2*1 的小矩形无重叠地覆盖一个 2*n 的大矩形，总共有多少种方法？
     */
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
     * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
     * 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
     * 描述：输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
     */
    vector<string> permutation(string str);
    void permutation_recur(vector<string> &res, int k, string str);
    static void local_main_permutation();

    /*
     * 12. 矩阵中的路径
     * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
     * 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
     * 如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。
     * 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
     * 但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
     */
    bool has_path(char *matrix, int rows, int cols, char *str);
    bool backtracking_has_path(char *matrix, int rows, int cols, char *str, int i, int j, int k, int *flags);
    static void local_main_has_path();

    /*
     * 13. 机器人的运动范围
     * 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
     * 每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
     * 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
     * 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
     */
    int moving_count(int threshold, int rows, int cols);
    int backtracking_moving_count(int threshold, int rows, int cols, int i, int j, bool *flags);
    int get_digit_sum(int n);
    static void local_main_moving_count();
};


#endif //JIANZHIOFFER_LOOP_AND_RECURSION_H
