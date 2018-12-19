//
// Created by faiz on 18-4-25.
//
#include "Data_Structure.h"

#include <iostream>
#include <cstring>
#include <malloc.h>

void Data_Structure::local_main_replace_space() {

    auto *string = new Data_Structure();

    auto *str = const_cast<char *>("hello warlal");
    string->replace_space(str, static_cast<int>(strlen(str)));

    int length = 30;
    auto *str2 = (char *) (malloc(sizeof(char) * length));
    char tmp[] = "what the fuck";
    strcpy(str2, tmp);
    string->replace_space_standard(str2, 30);
}

void Data_Structure::replace_space(char *str, int length) {

    auto *tmp = new char[length * 3];
    int now = 0;
    for (int i = 0; i < length; ++i) {
        if (str[i] == ' ') {
            tmp[now++] = '%';
            tmp[now++] = '2';
            tmp[now++] = '0';
        } else {
            tmp[now++] = str[i];
        }
    }
    tmp[now] = '\n';
    str = tmp;
    std::cout << str << std::endl;
}

void Data_Structure::replace_space_standard(char *str, int length) {

    if (str == nullptr || length < 0) {
        return;
    }

    int i = 0;
    int old_length = 0;
    int space_count = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ') {
            space_count++;
        }
        old_length++;
        i++;
    }

    int new_length = old_length + space_count * 2;
    if (new_length > length) {
        return;
    }

    int p_old_length = old_length;
    int p_new_length = new_length;

    while (p_old_length >= 0 && p_new_length > p_old_length) {

        if (str[p_old_length] == ' ') {
            str[p_new_length--] = '0';
            str[p_new_length--] = '2';
            str[p_new_length--] = '%';
        } else {
            str[p_new_length--] = str[p_old_length];
        }
        p_old_length--;
    }
    std::cout << str << std::endl;
}

void Data_Structure::local_main_find() {

    auto *array = new Data_Structure();
    vector<vector<int>> a = array->get_array(10, 10);

    double start = Utility::get_time();
    array->find_mine(15, a);
    array->find_mine(20, a);
    array->find_mine(-1, a);
    double end = Utility::get_time();
    Utility::print_during(start, end);

    start = Utility::get_time();
    array->find_standard(15, a);
    array->find_standard(20, a);
    array->find_standard(-1, a);
    end = Utility::get_time();
    Utility::print_during(start, end);
}


vector<vector<int>> Data_Structure::get_array(int m, int n) {
    vector<vector<int>> tmp;
    vector<int> tmp2;
    for (int l = 0; l < n; ++l) {
        tmp2.push_back(0);
    }
    for (int j = 0; j < m; ++j) {
        //tmp2.reserve(n);
        for (int i = 0; i < n; ++i) {
            tmp2[i] = i + j;
        }
        tmp.push_back(tmp2);
    }
    return tmp;
}

bool Data_Structure::find_mine(int target, vector<vector<int> > array) {
    for (int i = 0; i < array.size(); i++) {
        if (target >= array[i].front() && target <= array[i].back()) {
            for (int j = 0; j < array[i].size(); j++) {
                if (target == array[i][j]) {
                    cout << i << "," << j << endl;
                    return true;
                }
            }
        }
        if (target > array[i].back()) {
            continue;
        }
        if (target < array[i].front()) {
            cout << "not found." << endl;
            return false;
        }
    }
    cout << "not found." << endl;
    return false;
}

bool Data_Structure::find_standard(int target, vector<vector<int> > array) {

    unsigned long rows = array.size();
    unsigned long cols = array[0].size();

    auto i = static_cast<int>(rows - 1);
    int j = 0;
    while (0 <= i && j < cols) {
        if (target == array[i][j]) {
            cout << i << "," << j << endl;
            return true;
        } else if (target > array[i][j]) {
            j++;
        } else {
            i--;
        }
    }
    cout << "not found." << endl;
    return false;
}

void Data_Structure::local_main_printListFromTailToHead() {

    auto *head = new ListNode(-1);
    auto tmp = head;
    for (int i = 0; i < 10; ++i) {
        auto *node = new ListNode(i);
        head->next = node;
        head = head->next;
    }
    head = tmp;
    while (tmp) {
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
    while (head) {
        ret.insert(ret.begin(), head->val);
        head = head->next;
    }
    return ret;
}

void Data_Structure::push_2(int node) {
    s1.push(node);
}

int Data_Structure::pop_2() {
    int tmp;
    if (s2.empty()) {
        while (!s1.empty()) {
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

    auto *main = new Data_Structure();
    main->push_2(10);
    main->push_2(9);
    std::cout << main->pop_2() << std::endl;
    main->push_2(8);
    std::cout << main->pop_2() << std::endl;
}

void Data_Structure::mirror_tree(TreeNode *root) {
    if (!root) {
        return;
    }
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    mirror_tree(root->left);
    mirror_tree(root->right);
}

void Data_Structure::local_main_mirror_tree() {

    auto *main = new Data_Structure();

    vector<int> v = {1, 2, 4, 5, 7, 8, 4};
    Utility::print_vector(v);
    TreeNode *root = Utility::get_tree(v);
    Utility::print_vector(Utility::tree_traversal(root));
    main->mirror_tree(root);
    Utility::print_vector(Utility::tree_traversal(root));

}

vector<int> Data_Structure::print_matrix(vector<vector<int>> matrix) {

    int row = static_cast<int>(matrix.size());
    int col = static_cast<int>(matrix[0].size());

    vector<int> a;
    if (row == 0 || col == 0) {
        return a;
    }
    int times = (row < col ? row - 1 : col - 1) / 2 + 1;

    for (int i = 0; i < times; ++i) {

        for (int j = i; j <= col - i - 1; ++j) {
            a.push_back(matrix[i][j]);
        }
        for (int k = i + 1; k <= row - i - 1; ++k) {
            a.push_back(matrix[k][col - i - 1]);
        }
        for (int l = col - i - 2; (l >= i) && (row - i - 1 != i); --l) {
            a.push_back(matrix[row - i - 1][l]);
        }
        for (int n = row - i - 2; (n > i) && (col - i - 1 != i); --n) {
            a.push_back(matrix[n][i]);
        }
    }
    return a;
}

void Data_Structure::local_main_print_matrix() {

    vector<vector<int>> m = {{1,  2,  3,  4},
                             {5,  6,  7,  8},
                             {9,  10, 11, 12},
                             {13, 14, 15, 16}};
    vector<vector<int>> m2 = {{1, 2,  3,  4},
                              {5, 6,  7,  8},
                              {9, 10, 11, 12}};
    auto *main = new Data_Structure();
    Utility::print_vector(main->print_matrix(m));
    Utility::print_vector(main->print_matrix(m2));
}

void Data_Structure::push(int value) {

    s3.push(value);
    if (s4.empty() || s4.top() >= value) {//“＝”重要
        s4.push(value);
    }
}

void Data_Structure::pop() {
    if (s3.top() == s4.top()) {
        s4.pop();
    }
    s3.pop();
}

int Data_Structure::top() {
    return s3.top();
}

int Data_Structure::min() {
    return s4.top();
}

void Data_Structure::local_main_stack_min() {

    auto *main = new Data_Structure();

    main->push(3);
    main->push(2);
    main->push(3);
    main->push(2);
    cout << main->min() << endl;
    main->pop();
    cout << main->min() << endl;
    main->push(1);
    cout << main->min() << endl;
}

string Data_Structure::left_rotate_string(string str, int n) {

    unsigned long len = str.size();
    if (len == 0) {
        return str;
    }
    n %= len;
    str += str;
    return str.substr(static_cast<unsigned long>(n), len);

}

string Data_Structure::left_rotate_string_standard(string str, int n) {

    int len = static_cast<int>(str.size());
    if (len == 0 || n == 0) {
        return str;
    }
    n %= len;
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        swap(str[i], str[j]);
    }
    for (int i = n, j = len - 1; i < j; ++i, --j) {
        swap(str[i], str[j]);
    }
    for (int i = 0, j = len - 1; i < j; ++i, --j) {
        swap(str[i], str[j]);
    }
    return str;

}

void reverse(string &str, int m, int n) {

    char temp;
    while (m < n) {
        swap(str[m++], str[n--]);
    }
}

string Data_Structure::left_rotate_string_standard_II(string str, int n) {

    int len = static_cast<int>(str.size());
    if (len == 0 || n == 0) {
        return str;
    }
    n %= len;
    reverse(str, 0, n - 1);
    reverse(str, n, len - 1);
    reverse(str, 0, len - 1);
    return str;
}

void Data_Structure::local_main_left_rotate_string() {

    auto *main = new Data_Structure();
    string str = "abcdefghijkl";
    cout << main->left_rotate_string(str, 7) << endl;
    str = "abcdefghijkl";
    cout << main->left_rotate_string_standard(str, 7) << endl;
    str = "abcdefghijkl";
    cout << main->left_rotate_string_standard_II(str, 7) << endl;
}

string Data_Structure::reverse_sentence(string str) {

    string res, tmp;
    for (char i : str) {
        i == ' ' ? (res = i + tmp + res, tmp = "") : (tmp += i); // NOLINT
    }
    if (!tmp.empty()) res = tmp + res;
    return res;
}

void Data_Structure::local_main_reverse_sentence() {

    auto *main = new Data_Structure();
    string str = "student. incredible a am I";
    cout << main->reverse_sentence(str) << endl;
    cout << main->reverse_sentence(main->reverse_sentence(str)) << endl;

}

ListNode *Data_Structure::find_Kth2tail_mine(ListNode *head, unsigned int k) {

    if (nullptr == head || k <= 0) {
        return nullptr;
    }
    int counter = 0;
    ListNode *now = head;
    return find_Kth2tail_mine_backtracking(now, counter, k);
}

ListNode *Data_Structure::find_Kth2tail_mine_backtracking(ListNode *now, int &counter, int k) {

    ListNode *temp = now;
    if (temp->next) {
        temp = temp->next;
    } else {
        counter = 1;
        if (k == 1) {
            return now;
        }
        return nullptr;
    }
    ListNode *ret = find_Kth2tail_mine_backtracking(temp, counter, k);
    if (!ret) {
        if (++counter == k) {
            return now;
        }
        return nullptr;
    } else {
        return ret;
    }
    /*if (++counter == k) {
        return now;
    }
    if (ret) {
        return ret;
    } else {
        return nullptr;
    }*/
}

ListNode *Data_Structure::find_Kth2tail(ListNode *head, unsigned int k) {

    if (nullptr == head || k <= 0){
        return nullptr;
    }
    ListNode *p = head, *q = head;
    for (int i = 1; i < k; ++i) {
        if(q->next){
            q = q->next;
        }else{
            return nullptr;
        }
    }
    while (q->next){
        p = p->next;
        q = q->next;
    }
    return p;
}

void Data_Structure::local_main_find_Kth2tail() {

    auto main = new Data_Structure();
    vector<int> v({1, 2, 3, 4, 5, 6, 7, 8, 9});
    ListNode *head = Utility::get_list(v);  //头结点值为0
    ListNode *ret = main->find_Kth2tail_mine(head, 10);
    if (ret) {
        cout << ret->val << endl;
    } else {
        cout << "null" << endl;
    }
    ListNode *ret2 = main->find_Kth2tail(head, 0);
    if (ret2) {
        cout << ret2->val << endl;
    } else {
        cout << "null" << endl;
    }
}
