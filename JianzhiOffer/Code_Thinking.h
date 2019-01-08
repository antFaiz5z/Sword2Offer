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
    bool is_numeric(char *string);
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
     * 43. 从 1 到 n 整数中 1 出现的次数
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

    /*
     * 45. 把数组排成最小的数
     * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
     * 打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
     * 则打印出这三个数字能排成的最小数字为321323。
     */
    string print_min_num(vector<int> nums);
    static bool str_cmp(int a, int b);
    static void local_main_print_min_num();

    /*
     * 46. 把数字翻译成字符串  LeetCode.91
     * 给定一个数字，按照如下规则翻译成字符串：1 翻译成“a”，2 翻译成“b”... 26 翻译成“z”。
     * 一个数字有多种翻译可能，例如 12258 一共有 5 种，分别是 bccfi，bwfi，bczi，mcfi，mzi。
     * 实现一个函数，用来计算一个数字有多少种不同的翻译方法。
     */
    int num_decoding_dp(string s);
    int num_decoding_bt(string s);//LeetCode显示超时
    void backtracking_num_decoding_bt(string s, int &count);
    static void local_main_num_decoding();

    /*
     * 48. 最长不含重复字符的子字符串
     * 输入一个字符串（只包含 a~z 的字符），求其最长不含重复字符的子字符串的长度。
     * 例如对于 arabcacfr，最长不含重复字符的子字符串为 acfr，长度为 4。
     */
    int longest_substr_no_dup(string str);
    static void local_main_longest_substr_no_dup();

    /*
     * 49. 丑数
     * 把只包含质因子2、3和5的数称作丑数（Ugly Number）。
     * 例如6、8都是丑数，但14不是，因为它包含质因子7。
     * 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
     */
    int get_ugly_num(int index);
    static void local_main_get_ugly_num();

    /*
     * 50. 第一个只出现一次的字符位置
     * 在一个字符串中找到第一个只出现一次的字符，并返回它的位置。
     */
    int first_not_repeat_char_index(string str);
    static void local_main_first_not_repeat_char_index();

    /*
     * 51. 数组中的逆序对
     * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
     * 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
     *
     * 思路：
     * 常规：O(n^2)    归并排序: 时间O(nlogn) 空间O(n)
     */
    int inverse_pairs(vector<int> data);//TODO: error
    int backtracking_inverse_pairs(vector<int> &data, vector<int> &copy, int low, int high);
    static void local_main_inverse_pairs();

    /*
     * 53. 数字在排序数组中出现的次数
     * 统计一个数字在排序数组中出现的次数。
     *
     * 思路：
     * 常规：O(n)      二分查找: O(logn)
     */
    int get_count_of_k(vector<int> data, int k);
    int bs_get_count_of_k(vector<int> &data, int k);
    int get_count_of_k_stl(vector<int> data, int k);
    static void local_main_get_count_of_k();

    /*
     * 62. 圆圈中最后剩下的数
     * 让小朋友们围成一个大圈。然后，随机指定一个数 m，让编号为 0 的小朋友开始报数。
     * 每次喊到 m-1 的那个小朋友要出列唱首歌，然后可以在礼品箱中任意的挑选礼物，
     * 并且不再回到圈中，从他的下一个小朋友开始，继续 0...m-1 报数 ....
     * 这样下去 .... 直到剩下最后一个小朋友，可以不用表演。
     *
     * 思路：
     * 约瑟夫环，圆圈长度为 n 的解可以看成长度为 n-1 的解再加上报数的长度 m。
     * 因为是圆圈，所以最后需要对 n 取余。
     */
    int last_remaining(int n, int m);
    static void local_main_last_remaining();

    /*
     * 63. Best Time to Buy and Sell Stock     LeetCode.121
     * 可以有一次买入和一次卖出，那么买入必须在前。求最大收益。
     */
    int max_profit(vector<int> prices);
    static void local_main_max_profit();

    /*
     * 64. 求 1+2+3+...+n
     * 要求不能使用乘除法、for、while、if、else、switch、case 等关键字及条件判断语句 A ? B : C。
     *
     * 思路：
     * 使用递归解法最重要的是指定返回条件，但是本题无法直接使用 if 语句来指定返回条件。
     * 条件与 && 具有短路原则，即在第一个条件语句为 false 的情况下不会去执行第二个条件语句。
     * 利用这一特性，将递归的返回条件取非然后作为 && 的第一个条件语句，递归的主体转换为第二个条件语句，
     * 那么当递归的返回条件为 true 的情况下就不会执行递归的主体部分，递归返回。
     * 本题的递归返回条件为 n <= 0，取非后就是 n > 0；
     * 递归的主体部分为 sum += Sum_Solution(n - 1)，
     * 转换为条件语句后就是 (sum += Sum_Solution(n - 1)) > 0。
     */
    int sum(int n);
    int sum_II(int n);
    static void local_main_sum();

    /*
     * 66. 构建乘积数组
     * 给定一个数组 A[0, 1,..., n-1]，请构建一个数组 B[0, 1,..., n-1]，
     * 其中 B 中的元素 B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
     * 要求不能使用除法。
     */
    vector<int> multiply(const vector<int> &A);
    static void local_main_multiply();

    /*
     * 67. 把字符串转换成整数
     * 将一个字符串转换成一个整数，字符串不是一个合法的数值则返回 0，要求不能使用字符串转换整数的库函数。
     */
    int str2int(string str);
    static void local_main_str2int();
};


#endif //JIANZHIOFFER_CODE_THINKING_H
