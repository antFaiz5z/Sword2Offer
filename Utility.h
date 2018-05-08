//
// Created by faiz on 18-4-15.
//

#ifndef JIANZHIOFFER_UTILITY_H
#define JIANZHIOFFER_UTILITY_H

struct ListNode {
    int val;
    struct ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {};
};


class Utility {

public:

    static double get_time();

    static void print_during(double start, double end);
};


#endif //JIANZHIOFFER_UTILITY_H
