//
// Created by faiz on 18-5-12.
//

#ifndef JIANZHIOFFER_CODE_THINKING_H
#define JIANZHIOFFER_CODE_THINKING_H

#include <iostream>
#include <vector>

class Code_Thinking {

public:

    /*
     * 考察代码完整性
     * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
     */
    double power(double base, int expoent);//超出时间限制
    double power_standard(double base, int exponent);
    static void local_main_power();

    void reOrderArray(std::vector<int> &array);
    static void local_main_reOrderArray();
};


#endif //JIANZHIOFFER_CODE_THINKING_H
