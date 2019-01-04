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

    /*
     * 56. 数组中只出现一次的数字
     * 一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。
     *
     * 思路：
     * 这个题目的突破口在哪里？题目为什么要强调有一个数字出现一次，其他的出现两次？
     * 我们想到了异或运算的性质：任何一个数字异或它自己都等于0 。也就是说，
     * 如果我们从头到尾依次异或数组中的每一个数字，那么最终的结果刚好是那个只出现一次的数字，
     * 因为那些出现两次的数字全部在异或中抵消掉了。
     * 有了上面简单问题的解决方案之后，我们回到原始的问题。如果能够把原数组分为两个子数组。
     * 在每个子数组中，包含一个只出现一次的数字，而其它数字都出现两次。如果能够这样拆分原数组，
     * 按照前面的办法就是分别求出这两个只出现一次的数字了。
     * 我们还是从头到尾依次异或数组中的每一个数字，那么最终得到的结果就是两个只出现一次的数字的异或结果。
     * 因为其它数字都出现了两次，在异或中全部抵消掉了。由于这两个数字肯定不一样，
     * 那么这个异或结果肯定不为0 ，也就是说在这个结果数字的二进制表示中至少就有一位为1 。
     * 我们在结果数字中找到第一个为1 的位的位置，记为第N 位。
     * 现在我们以第N 位是不是1 为标准把原数组中的数字分成两个子数组，
     * 第一个子数组中每个数字的第N 位都为1 ，而第二个子数组的每个数字的第N 位都为0 。
     * 现在我们已经把原数组分成了两个子数组，每个子数组都包含一个只出现一次的数字，而其它数字都出现了两次。
     * 因此到此为止，所有的问题我们都已经解决
     *
     * 两个不相等的元素在位级表示上必定会有一位存在不同，
     * 将数组的所有元素异或得到的结果为不存在重复的两个元素异或的结果。
     * diff &= -diff 得到出 diff 最右侧不为 0 的位，
     * 也就是不存在重复的两个元素在位级表示上最右侧不同的那一位，利用这一位就可以将两个元素区分开来。
     */
    void find_nums_appear_once(vector<int> data, int *num1, int *num2);
    static void local_main_find_nums_appear_once();

    /* a * b可以这样算
     * 原理就是，类似快速幂，俗称快速模乘。
     *
     * res = 0
     * while(a){
     * if(a & 1) res += b;
     * a >>= 1;
     * b <<= 1;
     * }
     */


private:

    Bit_Operation() = default;
    ~Bit_Operation() = default;
    Bit_Operation(const Bit_Operation&);
    Bit_Operation& operator=(const Bit_Operation&);

};


#endif //JIANZHIOFFER_BIT_OPERATION_H
