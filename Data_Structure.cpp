//
// Created by faiz on 18-4-25.
//
#include "Data_Structure.h"

#include <iostream>

void Data_Structure::local_main_printListFromTailToHead() {

    auto * head = new ListNode(-1);
    auto tmp = head;
    for (int i = 0; i < 10; ++i) {
        auto * node = new ListNode(i);
        head->next = node;
        head = head->next;
    }
    head = tmp;
    while(tmp){
        std::cout << tmp->val << ", ";
        tmp = tmp->next;
    }
    std::cout << std::endl;

    auto *list = new Data_Structure();
    std::vector<int> ret = list->printListFromTailToHead(head);
    std::vector<int>::iterator it;
    for (it = ret.begin(); it != ret.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

std::vector<int> Data_Structure::printListFromTailToHead(ListNode *head) {

    std::vector<int> ret;
    while(head){
        ret.insert(ret.begin(), head->val);
        head = head->next;
    }
    return ret;
}

void Data_Structure::push(int node) {
    s1.push(node);
}

int Data_Structure::pop() {
    int tmp;
    if(s2.empty()){
        while(!s1.empty()){
            tmp = s1.top();
            s2.push(tmp);
            s1.pop();
        }
    }
    tmp = s2.top();
    s2.pop();
    return tmp;
}

void Data_Structure::local_main_2stacks_1queue() {

    auto * main = new Data_Structure();
    main->push(10);
    main->push(9);
    std::cout << main->pop() << std::endl;
    main->push(8);
    std::cout << main->pop() << std::endl;

}