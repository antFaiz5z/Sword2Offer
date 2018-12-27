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

    /*
     * 21. 调整数组顺序使奇数位于偶数前面
     * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
     * 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
     * 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
     */
    void reOrderArray_copy(vector<int> &array);
    void reOrderArray_insert(vector<int> &array);
    void reOrderArray_stl(vector<int> &array);
    static bool is_odd(int n);
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
    bool is_numeric(char *string);//TODO: to complete
    static void local_main_is_numeric();

    /*
     * 39. 数组中出现次数超过一半的数字
     * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
     * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
     * 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
     */
    int more_than_half_num(vector<int> nums);
    static void local_main_more_than_half_num();

    /*
     * 42. 连续子数组的最大和
     * 例如:{6,-3,-2,7,-15,1,2,2},
     * 连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，
     * 返回它的最大连续子序列的和(子向量的长度至少是1)
     */
    int find_greatest_sum_of_subarray(vector<int> array);
    static void local_main_find_greatest_sum_of_subarray();

    /*
     * 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
     * 例如：1~13中包含1的数字有1、10、11、12、13因此共出现6次
     * （注意：非含1数字个数, 因此多个数位上为1的数应被count多次，
     *  即问题转化为求各个数位上为1时的含1数字的个数）
     *
     *  思路：
     * if n = xyzdabc
     * and we are considering the occurrence of one on thousand, it should be:
     * (1) xyz * 1000                     if d == 0
     * (2) xyz * 1000 + abc + 1           if d == 1
     * (3) xyz * 1000 + 1000              if d > 1
     */
    int count_digit_one(int n);
    int count_digit_one_std(int n);
    static void local_main_count_digit_one();

};


#endif //JIANZHIOFFER_CODE_THINKING_H
