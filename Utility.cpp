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


void Utility::print_vector_int(vector<int> v) {

    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++){
        cout << *it << ",";
    }
    cout << endl;
}

void Utility::print_vector_string(vector<string> v) {

    vector<string>::iterator it;
    for(it = v.begin(); it != v.end(); it++){
        cout << *it << ",";
    }
    cout << endl;
}

ListNode *Utility::get_list(vector<int> v) {

    ListNode *head = new ListNode(0);
    ListNode *now = head;

    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        ListNode *tmp = new ListNode(*it);
        now->next = tmp;
        now = tmp;
    }
    return head;
}

TreeNode *Utility::get_tree(vector<int> v) {//层次遍历

    queue<TreeNode*> q;

    int i = 0;

    TreeNode *root = new TreeNode(v[i++]);
    q.push(root);

    while(i < v.size()){
        TreeNode *par = q.front();
        q.pop();

        TreeNode *left = new TreeNode(v[i++]);
        par->left = left;
        q.push(left);

        if(i < v.size()){
            TreeNode *right = new TreeNode(v[i++]);
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
