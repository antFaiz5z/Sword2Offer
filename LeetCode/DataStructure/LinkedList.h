//
// Created by Faiz on 2019/1/9 0009.
//

#ifndef JIANZHIOFFER_LINKED_LIST_H
#define JIANZHIOFFER_LINKED_LIST_H

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};


class LinkedList {

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

};


#endif //JIANZHIOFFER_LINKED_LIST_H
