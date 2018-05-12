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
     * 时间限制：1秒 空间限制：32768K 热度指数：565840
     * 本题知识点： 字符串
     * 请实现一个函数，将一个字符串中的空格替换成“%20”。
     * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
     */
    void replace_space(char *str, int length);
    void replace_space_standard(char *str, int length);
    static void local_main_replace_space();
    /*
     * 时间限制：1秒 空间限制：32768K 热度指数：646173
     * 本题知识点： 查找
     * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
     * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
     */
    vector<vector<int>> get_array(int m, int n);

    bool find_mine(int target, vector<vector<int> > array);
    bool find_standard(int target, vector<vector<int> > array);
    static void local_main();

    /*
     * 时间限制：1秒 空间限制：32768K 热度指数：496961
     * 本题知识点： 链表
     * 输入一个链表，从尾到头打印链表每个节点的值。
     */
    std::vector<int> printListFromTailToHead(ListNode* head);
    static void local_main_printListFromTailToHead();

    /*
     * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
     */
    void push(int node);
    int pop();
    static void local_main_2stacks_1queue();

private:

    std::stack<int> s1;
    std::stack<int> s2;
};


#endif //JIANZHIOFFER_LIST_H
