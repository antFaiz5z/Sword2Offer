//
// Created by faiz on 18-4-25.
//

#ifndef JIANZHIOFFER_LIST_H
#define JIANZHIOFFER_LIST_H


#include "Utility.h"

#include <vector>

class List {

public:

    /*
     * 时间限制：1秒 空间限制：32768K 热度指数：496961
     * 本题知识点： 链表
     * 输入一个链表，从尾到头打印链表每个节点的值。
     */
    std::vector<int> printListFromTailToHead(ListNode* head);

    static void local_main_printListFromTailToHead();
};


#endif //JIANZHIOFFER_LIST_H
