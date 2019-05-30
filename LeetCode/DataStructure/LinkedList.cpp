//
// Created by Faiz on 2019/1/9 0009.
//

#include "LinkedList.h"

ListNode *LinkedList::addTwoNumbers(ListNode *l1, ListNode *l2) {

    int add = 0, sum = 0, val = 0;
    auto *ret = new ListNode(0);
    ListNode *now = ret;
    ListNode *p = l1, *q = l2;

    while (p || q || add) {
        sum = (p ? p->val : 0) + (q ? q->val : 0) + add;
        val = sum % 10;
        add = sum / 10;
        auto *tmp = new ListNode(val);
        now->next = tmp;
        now = tmp;
        if (p) p = p->next;
        if (q) q = q->next;
    }
    return ret->next;
}
