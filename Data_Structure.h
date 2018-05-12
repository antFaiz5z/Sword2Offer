//
// Created by faiz on 18-4-25.
//

#ifndef JIANZHIOFFER_LIST_H
#define JIANZHIOFFER_LIST_H


#include "Utility.h"

#include <vector>
#include <stack>

class Data_Structure {

public:

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
