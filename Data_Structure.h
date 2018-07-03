//
// Created by faiz on 18-4-25.
//

#ifndef JIANZHIOFFER_LIST_H
#define JIANZHIOFFER_LIST_H


#include "Utility.h"

#include <vector>
#include <stack>

using namespace std;

class Data_Structure {

public:

    /*
     * 请实现一个函数，将一个字符串中的空格替换成“%20”。
     * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
     */
    void replace_space(char *str, int length);
    void replace_space_standard(char *str, int length);
    static void local_main_replace_space();
    /*
     * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
     * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
     */
    vector<vector<int>> get_array(int m, int n);

    bool find_mine(int target, vector<vector<int> > array);
    bool find_standard(int target, vector<vector<int> > array);
    static void local_main_find();

    /*
     * 输入一个链表，从尾到头打印链表每个节点的值。
     */
    std::vector<int> printListFromTailToHead(ListNode* head);
    static void local_main_printListFromTailToHead();

    /*
     * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
     */
    void push_2(int node);
    int pop_2();
    static void local_main_2stacks_1queue();

    /*
     * 操作给定的二叉树，将其变换为源二叉树的镜像。
     */
    void mirror_tree(TreeNode *root);
    static void local_main_mirror_tree();

    /*
     * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
     * 例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
     * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
     */
    vector<int> print_matrix(vector<vector<int>> matrix);
    static void local_main_print_matrix();

    /*
     * 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数。
     */
    void push(int value);
    void pop();
    int top();
    int min();
    static void local_main_stack_min();

private:

    std::stack<int> s1;
    std::stack<int> s2;

    std::stack<int> s3;
    std::stack<int> s4;



};


#endif //JIANZHIOFFER_LIST_H
