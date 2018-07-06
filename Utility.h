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

    static double get_time();
    static void print_during(double start, double end);


    static void print_vector_int(vector<int> v);
    static void print_vector_string(vector<string> v);


    static ListNode *get_list(vector<int> v);

    static TreeNode *get_tree(vector<int> v);
    static vector<int> tree_traversal(TreeNode* root);
};


#endif //JIANZHIOFFER_UTILITY_H
