//
// Created by faiz on 18-5-12.
//

#ifndef JIANZHIOFFER_CODE_THINKING_H
#define JIANZHIOFFER_CODE_THINKING_H

#include <iostream>
#include <vector>

using namespace std;

class Code_Thinking {

public:

    /*
     * 考察代码完整性
     * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
     */
    double power(double base, int expoent);//超出时间限制
    double power_standard(double base, int exponent);
    static void local_main_power();

    void reOrderArray(vector<int> &array);
    static void local_main_reOrderArray();


    /*
     * 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
     * 但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
     * 没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
     * 现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
     * 描述：输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
     */
    vector<vector<int>> find_continuous_seq(int sum);
    vector<vector<int>> find_continuous_seq_standard(int sum);
    static void local_main_find_continuous_seq();


    /*
     * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，
     * 使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
     * 描述：对应每个测试案例，输出两个数，小的先输出。
     */
    vector<int> find_nums_with_sum(const vector<int> &array, int sum);
    static void local_main_find_nums_with_sum();


    bool is_continuous(vector<int> nums);
    static void local_main_is_continuous();
};


#endif //JIANZHIOFFER_CODE_THINKING_H
