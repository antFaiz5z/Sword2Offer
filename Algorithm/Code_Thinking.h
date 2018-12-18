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
     * 16. 数值的整数次方
     * 考察代码完整性
     * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
     */
    double power(double base, int expoent);//超出时间限制
    double power_standard(double base, int exponent);
    static void local_main_power();

    void reOrderArray(vector<int> &array);
    static void local_main_reOrderArray();

    /*
     * 57.2 和为 S 的连续正数序列
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
     * 57.1 和为 S 的两个数字
     * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，
     * 使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
     * 描述：对应每个测试案例，输出两个数，小的先输出。
     */
    vector<int> find_nums_with_sum(const vector<int> &array, int sum);
    static void local_main_find_nums_with_sum();

    /*
     * 61. 扑克牌顺子
     * LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
     * 他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
     * “红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....
     * LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
     * 上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。
     * 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。
     */
    bool is_continuous(vector<int> numbers);
    static void local_main_is_continuous();

    /*
     * 14. 整数拆分 (Leetcode.343)
     * 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
     *
     * 贪心思路：
     * 尽可能多剪长度为 3 的绳子，并且不允许有长度为 1 的绳子出现。
     * 如果出现了，就从已经切好长度为 3 的绳子中拿出一段与长度为 1 的绳子重新组合，把它们切成两段长度为 2 的绳子。
     * 证明：当 n >= 5 时，3(n - 3) - 2(n - 2) = n - 5 >= 0。
     * 因此把长度大于 5 的绳子切成两段，令其中一段长度为 3 可以使得两段的乘积最大。
     */
    int integer_break_greedy(int n);
    int integer_break_dp(int n);
    static void local_main_integer_break();

    /*
     * 20. 表示数值的字符串
     * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
     * 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
     * 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
     */
    /*
     * java或python可正则表达式求解
     *  []  ： 字符集合
        ()  ： 分组
        ?   ： 重复 0 ~ 1
        +   ： 重复 1 ~ n
        *   ： 重复 0 ~ n
        .   ： 任意字符
        \\. ： 转义后的 .
        \\d ： 数字
     * public boolean isNumeric(char[] str) {
            if (str == null || str.length == 0)
                return false;
            return new String(str).matches("[+-]?\\d*(\\.\\d+)?([eE][+-]?\\d+)?");
        }
     */
    bool is_numeric(char *string);
    static void local_main_is_numeric();

};


#endif //JIANZHIOFFER_CODE_THINKING_H
