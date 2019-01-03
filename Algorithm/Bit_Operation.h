//
// Created by faiz on 18-10-31.
//

#ifndef JIANZHIOFFER_BIT_OPERATION_H
#define JIANZHIOFFER_BIT_OPERATION_H

#include <iostream>
#include <vector>

using namespace std;

class Bit_Operation {

public:

    static Bit_Operation* get_instance() {

        static Bit_Operation* instance;
        if(instance == nullptr){
            instance = new Bit_Operation();
        }
        return instance;
    }

    /*
     * 15. 二进制中 1 的个数
    *  输入一个整数，输出该数二进制表示中 1 的个数。
    */
    //n&(n-1)
    //该位运算去除 n 的位级表示中最低的那一位。
    int bit1count(int n);
    static void local_main_bit1count();

    /*
     * 65. 不用加减乘除做加法
     * 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
     */
    int add(int num1, int num2);
    static void local_main_add();

    void find_nums_appear_once(vector<int> data, int *num1, int *num2);
    static void local_main_find_nums_appear_once();




private:

    Bit_Operation() = default;
    ~Bit_Operation() = default;
    Bit_Operation(const Bit_Operation&);
    Bit_Operation& operator=(const Bit_Operation&);

};


#endif //JIANZHIOFFER_BIT_OPERATION_H
