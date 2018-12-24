//
// Created by faiz on 18-4-15.
//
#ifndef JIANZHIOFFER_UTILITY_H
#define JIANZHIOFFER_UTILITY_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {};
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Utility {

public:

    static double get_time();//获取当前时间
    static void print_during(double start, double end);//获取时间间隔

    static ListNode *get_list(vector<int> v);//创建链表， 头结点值为0
    static TreeNode *get_tree(vector<int> v);//创建树
    static vector<int> tree_traversal(TreeNode *root);//树层次遍历  //TODO:bug


    template<typename T>
    static void print_vector(vector<T> v) {//打印vector
        typename vector<T>::iterator it;
        for (it = v.begin(); it != v.end(); it++) {
            cout << *it << ",";
        }
        cout << endl;
    }

    static void print_list(ListNode *head) {//打印链表

        if (nullptr == head) {
            return;
        }
        ListNode *p = head;
        cout << p->val << ", ";
        while (nullptr != p->next) {
            p = p->next;
            cout << p->val << ", ";
        }
        cout << endl;
    }
};

#endif //JIANZHIOFFER_UTILITY_H
