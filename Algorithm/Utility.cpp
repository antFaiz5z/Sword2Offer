//
// Created by faiz on 18-4-15.
//
#include "Utility.h"

#include <sys/time.h>
#include <iostream>

double Utility::get_time() {

    struct timeval time{};
    if (gettimeofday(&time, nullptr)) {
        return 0;
    }
    return (double) time.tv_sec + (double) time.tv_usec * .000001;
}

void Utility::print_during(double start, double end) {

    std::cout << "During: " << end - start << "ms." << std::endl;
}

ListNode *Utility::get_list(vector<int> v) {

    auto *head = new ListNode(0);//头结点值为0
    ListNode *now = head;

    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        auto *tmp = new ListNode(*it);
        now->next = tmp;
        now = tmp;
    }
    return head;
}

TreeNode *Utility::get_tree(vector<int> v) {//层次遍历

    queue<TreeNode*> q;
    int i = 0;
    auto *root = new TreeNode(v[i++]);
    q.push(root);

    while(i < v.size()){
        TreeNode *par = q.front();
        q.pop();

        auto *left = new TreeNode(v[i++]);
        par->left = left;
        q.push(left);

        if(i < v.size()){
            auto *right = new TreeNode(v[i++]);
            par->right = right;
            q.push(right);
        }
    }
    return root;
}

vector<int> Utility::tree_traversal(TreeNode *root) {//层次遍历

    vector<int> v;
    queue<TreeNode*> q;
    q.push(root);
    v.push_back(root->val);

    TreeNode *par;
    while(!q.empty()){
        par = q.front();
        q.pop();
        if(par->left || par->right){
            if(par->left){
                q.push(par->left);
                v.push_back(par->left->val);
            }else{
                v.push_back(-1);
            }
            if(par->right){
                q.push(par->right);
                v.push_back(par->right->val);
            }else{
                v.push_back(-1);
            }
        }
    }
    return v;
}
