//
// Created by faiz on 18-4-25.
//
#include "List.h"

#include <iostream>

void List::local_main_printListFromTailToHead() {

    ListNode* head = new ListNode(-1);
    ListNode* tmp = head;
    for (int i = 0; i < 10; ++i) {
        ListNode* node = new ListNode(i);
        head->next = node;
        head = head->next;
    }
    head = tmp;
    while(tmp){
        std::cout << tmp->val << ", ";
        tmp = tmp->next;
    }
    std::cout << std::endl;

    auto *list = new List();
    std::vector<int> ret = list->printListFromTailToHead(head);
    std::vector<int>::iterator it;
    for (it = ret.begin(); it != ret.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

std::vector<int> List::printListFromTailToHead(ListNode *head) {

    std::vector<int> ret;
    while(head){
        ret.insert(ret.begin(), head->val);
        head = head->next;
    }
    return ret;
}