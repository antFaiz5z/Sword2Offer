//
// Created by faiz on 18-5-12.
//

#ifndef JIANZHIOFFER_LOOP_AND_RECURSION_H
#define JIANZHIOFFER_LOOP_AND_RECURSION_H

#include <iostream>
#include <cstring>
#include <vector>

#include "Utility.h"

using namespace std;

class Loop_and_Recursion {

public:

    static Loop_and_Recursion *get_instance(){
        static Loop_and_Recursion *instance;
        if (instance == nullptr){
            instance = new Loop_and_Recursion;
        }
        return instance;
    }
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
    int backtracking_moving_count(int threshold, int rows, int cols, int i, int j, bool *flags[]);
    int get_digit_sum(int n);
    static void local_main_moving_count();

    /*
     * 17. 打印从 1 到最大的 n 位数
     * 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数即 999。
     *
     * 思路:
     * 由于 n 可能会非常大，因此不能直接用 int 表示数字，而是用 char 数组进行存储。
     * 使用回溯法得到所有的数。
     */
    void print_1_to_n_digits(int n);
    void backtracking_print_1_to_n_digits(char nums[], int digit, int n);
    void print_num(const char nums[]);
    static void local_main_print_1_to_n_digits();

    /*
     * 18.1 在 O(1) 时间内删除链表节点
     * 已知头指针与删除目标节点指针
     *
     * 思路：
     * ① 如果该节点不是尾节点，那么可以直接将下一个节点的值赋给该节点，
     * 然后令该节点指向下下个节点，再删除下一个节点，时间复杂度为 O(1)。
     * ② 否则，就需要先遍历链表，找到节点的前一个节点，然后让前一个节点指向 null，时间复杂度为 O(N)。
     * 综上，如果进行 N 次操作，那么大约需要操作节点的次数为 N-1+N=2N-1，
     * 其中 N-1 表示 N-1 个不是尾节点的每个节点以 O(1) 的时间复杂度操作节点的总次数，
     * N 表示 1 个尾节点以 O(N) 的时间复杂度操作节点的总次数。(2N-1)/N ~ 2，因此该算法的平均时间复杂度为 O(1)。
     */
    ListNode* delete_node(ListNode *head, ListNode *todelete);
    /*
     * 18.2 删除链表中重复的结点
     * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
     * 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
     */
    ListNode* delete_dup_node(ListNode *head);
    static void local_main_delete_node();

    /*
     * 19. 正则表达式匹配
     * 请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
     * 而'*'表示它前面的字符可以出现任意次（包含0次）。
     * 在本题中，匹配是指字符串的所有字符匹配整个模式。
     * 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
     */
    bool regx_match_backtracking_error(char *str, char *pattern);//未考虑“.*”情况
    bool regx_match_backtracking(char *str, char *pattern);
    bool regx_match_matrix(char *str, char *pattern);
    static void local_main_match();

    /*
     * 47. 礼物的最大价值
     * 在一个 m*n 的棋盘的每一个格都放有一个礼物，每个礼物都有一定价值（大于 0）。
     * 从左上角开始拿礼物，每次向右或向下移动一格，直到右下角结束。给定一个棋盘，求拿到礼物的最大价值。
     */
    int get_most(vector<vector<int>> board);
    static void local_main_get_most();



private:
    Loop_and_Recursion() = default;
    ~Loop_and_Recursion() = default;
    Loop_and_Recursion(const Loop_and_Recursion &);
    Loop_and_Recursion & operator=(const Loop_and_Recursion &);
};


#endif //JIANZHIOFFER_LOOP_AND_RECURSION_H
