//
// Created by faiz on 18-4-25.
//
#include "DataStructure.h"

#include <iostream>
#include <algorithm>
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

    if (nullptr == head || k <= 0) {
        return nullptr;
    }
    ListNode *p = head, *q = head;
    for (int i = 1; i < k; ++i) {
        if (q->next) {
            q = q->next;
        } else {
            return nullptr;
        }
    }
    while (q->next) {
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

ListNode *Data_Structure::entry_node_of_loop(ListNode *head) {

    if (!head || !head->next || !head->next->next) {
        return nullptr;
    }
    ListNode *slow = head->next, *fast = head->next->next;
    while (fast != slow) {
        if (slow->next) {
            slow = slow->next;
        } else {
            return nullptr;
        }
        if (fast->next->next) {
            fast = fast->next->next;
        } else {
            return nullptr;
        }
    }
    fast = head;
    while (fast != slow) {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

void Data_Structure::local_main_entry_node_of_loop() {

    auto main = new Data_Structure();
    ListNode *head = Utility::get_list(vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
    ListNode *tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = head->next->next->next; //3
    cout << main->entry_node_of_loop(head)->val << endl;
}

ListNode *Data_Structure::reverse_list_recur(ListNode *head) {

    if (!head) {
        return nullptr;
    }
    ListNode *ret = reverse_list_recur(head->next);
    if (ret) {
        head->next->next = head;
        head->next = nullptr;
        return ret;
    } else {
        return head;
    }
}

ListNode *Data_Structure::reverse_list_recurII(ListNode *head) {

    if (!head || !head->next) {
        return head;
    }
    ListNode *next = head->next;
    head->next = nullptr;
    ListNode *ret = reverse_list_recurII(next);
    next->next = head;
    return ret;
}

ListNode *Data_Structure::reverse_list_itera(ListNode *head) {

    ListNode temp = ListNode(-1);
    ListNode *next;
    while (head) {
        next = head->next;
        head->next = temp.next;
        temp.next = head;
        head = next;
    }
    return temp.next;
}

void Data_Structure::local_main_reverse_list() {

    auto main = new Data_Structure();
    vector<int> v({1, 2, 3, 4, 5, 6, 7, 8, 9});
    Utility::print_list(main->reverse_list_recur(Utility::get_list(v)));
    Utility::print_list(main->reverse_list_recurII(Utility::get_list(v)));
    Utility::print_list(main->reverse_list_itera(Utility::get_list(v)));
}

ListNode *Data_Structure::merge(ListNode *head1, ListNode *head2) {

    if (!head1) return head2;
    if (!head2) return head1;
    ListNode *p1 = head1->val <= head2->val ? head1 : head2;
    ListNode *p2 = head1->val > head2->val ? head1 : head2;
    ListNode *p3;
    ListNode *ret = p1;
    while (p1 && p2){
        while (p1->next && p1->next->val <= p2->val){
            p1 = p1->next;
        }
        p3 = p1->next;
        p1->next = p2;
        p2 = p3;
    }
    return ret;
}

void Data_Structure::local_main_merge() {

    auto main = new Data_Structure();
    ListNode *head1 = Utility::get_list(vector<int>({1,3,5,7,9}));
    ListNode *head2 = Utility::get_list(vector<int>({2,4,6,8,10}));
    Utility::print_list(main->merge(head1, head2));
}

bool Data_Structure::is_sub_tree(TreeNode *root1, TreeNode *root2) {

    if (!root1 || !root2) {
        return false;
    }
    return recur_is_sub_tree(root1, root2)
           || is_sub_tree(root1->left, root2)
           || is_sub_tree(root1->right, root2);
}

bool Data_Structure::recur_is_sub_tree(TreeNode *root1, TreeNode *root2) {

    if (!root2) {
        return true;
    }
    if (!root1) {
        return false;
    }
    if (root1->val != root2->val) {
        return false;
    }
    return recur_is_sub_tree(root1->left, root2->left)
           && recur_is_sub_tree(root1->right, root2->right);
}

void Data_Structure::local_main_is_sub_tree() {

    auto main = new Data_Structure();
    cout << main->is_sub_tree(
            Utility::get_tree(vector<int>({1, 2, 3, 4, 5, 6, 7})),
            Utility::get_tree(vector<int>({2, 4, 5})))
         << endl;
}

bool Data_Structure::is_symmetrical(TreeNode *root) {

    if (!root) {
        return true;
    }
    return recur_is_symmetrical(root->left, root->right);
}

bool Data_Structure::recur_is_symmetrical(TreeNode *root1, TreeNode *root2) {

    if (!root1 && !root2) {
        return true;
    }
    if (!root1 || !root2) {
        return false;
    }
    if (root1->val != root2->val) {
        return false;
    }
    return recur_is_symmetrical(root1->left, root2->right)
           && recur_is_symmetrical(root1->right, root2->left);
}

void Data_Structure::local_main_is_symmetrical() {

    auto main = new Data_Structure();
    cout << main->is_symmetrical(Utility::get_tree(vector<int>({1, 2, 2, 3, 4, 4, 3}))) << endl;
}

bool Data_Structure::is_pop_order(vector<int> push, vector<int> pop) {

    if (push.empty() && pop.empty()) {
        return true;
    }
    if (push.size() != pop.size()) {
        return false;
    }
    stack<int> s;
    for (int push_index = 0, pop_index = 0; push_index < push.size(); ++push_index) {
        s.push(push[push_index]);
        while (pop_index < pop.size() && !s.empty() && s.top() == pop[pop_index]) {
            s.pop();
            pop_index++;

        }
    }
    return s.empty();
}

void Data_Structure::local_main_is_pop_order() {

    auto main = new Data_Structure();

    vector<int> pu({1, 2, 3, 4, 5});
    vector<int> po1({4, 5, 3, 2, 1});
    vector<int> po2({4, 3, 5, 1, 2});

    cout << main->is_pop_order(pu, po1) << endl
         << main->is_pop_order(pu, po2) << endl;
}


vector<int> Data_Structure::com_tree_2_vector(TreeNode *root) {

    vector<int> v;
    queue<TreeNode *> q;
    q.push(root);

    unsigned long count;

    while (!q.empty()) {
        count = q.size();
        while (count-- > 0) {
            TreeNode *node = q.front();
            q.pop();
            if (nullptr == node) {
                continue;
            }
            v.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        }
    }
    return v;
}

vector<vector<int>> Data_Structure::com_tree_2_vector_vector(TreeNode *root) {

    vector<vector<int>> v;
    queue<TreeNode *> q;
    q.push(root);

    unsigned long count;
    while (!q.empty()) {
        count = q.size();
        vector<int> row;
        while (count-- > 0) {
            TreeNode *node = q.front();
            q.pop();
            if (nullptr == node) {
                continue;
            }
            row.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        }
        if (!row.empty())
            v.push_back(row);
    }
    return v;
}

vector<vector<int>> Data_Structure::com_tree_2_vector_vector_zigzag(TreeNode *root) {

    vector<vector<int>> v;
    queue<TreeNode *> q;
    q.push(root);

    unsigned long count;
    bool re = false;
    while (!q.empty()) {
        count = q.size();
        vector<int> row;
        while (count-- > 0) {
            TreeNode *node = q.front();
            q.pop();
            if (nullptr == node) {
                continue;
            }
            row.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        }
        if (!row.empty()) {
            if (re) {
                reverse(row.begin(), row.end());
            }
            v.push_back(row);
        }
        re = !re;
    }
    return v;
}

void Data_Structure::local_main_tree_2_vector() {

    auto main = new Data_Structure();

    TreeNode *root = Utility::get_tree(vector<int>({1, 2, 3, 4, 5, 6, 7}));
    Utility::print_vector(main->com_tree_2_vector(root));
    vector<vector<int>> ret = main->com_tree_2_vector_vector(root);
    for (auto &it : ret) {
        Utility::print_vector(it);
    }
    vector<vector<int>> ret2 = main->com_tree_2_vector_vector_zigzag(root);
    for (auto &it : ret2) {
        Utility::print_vector(it);
    }
}

bool Data_Structure::is_seq_of_bst(vector<int> sequence) {

    if (sequence.empty()) {
        return false;
    }
    return is_seq_of_bst_judge(sequence, 0, static_cast<int>(sequence.size() - 1));
}

bool Data_Structure::is_seq_of_bst_judge(vector<int> &sequence, int left, int right) {

    if (right - left <= 1) {//right == left //error
        return true;        // right <= left //OK  //TODO:??
    }
    int middle = right;
    while (middle > left && sequence[middle - 1] > sequence[right]) {
        middle--;
    }
    for (int i = middle - 1; i >= left; --i) {
        if (sequence[i] > sequence[right]) {
            return false;
        }
    }
    return is_seq_of_bst_judge(sequence, left, middle - 1)
           && is_seq_of_bst_judge(sequence, middle, right - 1);
}

void Data_Structure::local_main_is_seq_of_bst() {

    auto main = new Data_Structure();
    cout << main->is_seq_of_bst(vector<int>({1, 3, 2}));
}

vector<vector<int>> Data_Structure::find_path(TreeNode *root, int expect_num) {

    vector<vector<int>> ret;
    vector<int> path;

    find_path_backtracking(root, expect_num, ret, path);
    return ret;
}

void
Data_Structure::find_path_backtracking(TreeNode *root, int expect_num, vector<vector<int>> &ret, vector<int> &path) {

    if (nullptr == root) {
        return;
    }
    path.push_back(root->val);
    expect_num -= root->val;

    if (expect_num == 0 && nullptr == root->left && nullptr == root->right) {
        ret.push_back(path);
    } else {
        find_path_backtracking(root->left, expect_num, ret, path);
        find_path_backtracking(root->right, expect_num, ret, path);
    }
    path.pop_back();
}

void Data_Structure::local_main_find_path() {

    auto main = new Data_Structure();

    TreeNode *root = Utility::get_tree(vector<int>({10, 5, 12, 4, 7}));
    vector<vector<int>> ret = main->find_path(root, 22);
    for (auto &it : ret) {
        Utility::print_vector(it);
    }
}

RandomListNode *Data_Structure::clone(RandomListNode *head) {

    if (!head) {
        return nullptr;
    }
    RandomListNode *p = head;
    //插入复制节点
    while (p) {
        auto *temp = new RandomListNode(p->label);
        //RandomListNode temp(le->label);//error TODO:??
        temp->next = p->next;
        p->next = temp;
        p = p->next->next;
    }
    //赋值random
    p = head;
    while (p) {
        if (p->random)
            p->next->random = p->random->next;
        p = p->next->next;
    }
    //拆分
    p = head;
    RandomListNode *next = head->next;
    RandomListNode *ret = head->next;
    while (p->next) {
        p->next = next->next;
        p = next;
        next = p->next;
    }
    return ret;
}

void Data_Structure::local_main_clone(){}

TreeNode *Data_Structure::tree_2_doubly_list_mine(TreeNode *root) {

    if (!root) {
        return nullptr;
    }
    TreeNode *new_root = nullptr;
    tree_2_doubly_list_mine_backtracking(new_root, root, true);
    return new_root;
}

TreeNode *Data_Structure::tree_2_doubly_list_mine_backtracking(TreeNode *&new_root, TreeNode *root, bool right) {

    if (!root) {
        return nullptr;
    }
    TreeNode *left_ret = tree_2_doubly_list_mine_backtracking(new_root, root->left, false);
    TreeNode *right_ret = tree_2_doubly_list_mine_backtracking(new_root, root->right, true);

    if (!left_ret && !right_ret && !new_root) {
        new_root = root;
    }
    if (left_ret) {
        root->left = left_ret;
        left_ret->right = root;
    }
    if (right_ret) {
        root->right = right_ret;
        right_ret->left = root;
    }
    if (right) {
        return left_ret ? left_ret : root;
    } else {
        return right_ret ? right_ret : root;
    }
}

TreeNode *Data_Structure::tree_2_doubly_list(TreeNode *root) {

    TreeNode *pre = nullptr;
    TreeNode *head = nullptr;
    tree_2_doubly_list_backtracking(root, pre, head);
    return head;
}

void Data_Structure::tree_2_doubly_list_backtracking(TreeNode *root, TreeNode *pre, TreeNode *head) {

    if (!root) {
        return;
    }
    tree_2_doubly_list_backtracking(root->left, pre, head);
    root->left = pre;
    if (pre) pre->right = root;
    pre = root;
    if (!head) head = root;
    tree_2_doubly_list_backtracking(root->right, pre, head);
}

void Data_Structure::local_main_tree_2_doubly_list() {

    auto main = new Data_Structure();
    TreeNode *root = Utility::get_tree(vector<int>({4, 2, 6, 1, 3, 5, 7}));
    TreeNode *ret = main->tree_2_doubly_list_mine(root);
    while (ret) {
        cout << ret->val << ",";
        ret = ret->right;
    }
    cout << endl;
    /*TreeNode *ret2 = main->tree_2_doubly_list(root);
    while (ret2) {
        cout << ret2->val << ",";
        ret2 = ret2->right;
    }
    cout << endl;*/
}

char *Data_Structure::serialize(TreeNode *root) {

    vector<int> str;
    serialize_recur(root, str);
    int *ret = new int[str.size()];
    for (int i = 0; i < str.size(); ++i) {
        ret[i] = str[i];
    }
    return (char *) ret;
}

void Data_Structure::serialize_recur(TreeNode *root, vector<int> &str) {

    if (!root) {
        str.push_back(0xFFFFFF);
        return;
    }
    str.push_back(root->val);
    serialize_recur(root->left, str);
    serialize_recur(root->right, str);
}

TreeNode *Data_Structure::deserialize(char *str) {

    int *index = (int *) str;
    return deserialize_recur(index);
}


TreeNode *Data_Structure::deserialize_recur(int *&index) {

    if (*index == 0xFFFFFF) {
        ++index;
        return nullptr;
    }
    auto *node = new TreeNode(*index);
    ++index;
    node->left = deserialize_recur(index);
    node->right = deserialize_recur(index);
    return node;
}

void Data_Structure::local_main_serialize() {

    auto main = new Data_Structure();

    TreeNode *root = Utility::get_tree(vector<int>({1, 2, 3, 4, 5, 6, 4, 6, 3, 5, 4, 6, 3, 6, 4}));
    Utility::print_vector(Utility::tree_traversal(root));
    char *str = main->serialize(root);
    //printf("%x\n", str);//zero inside, how to print TODO:??
    Utility::print_vector(Utility::tree_traversal(main->deserialize(str)));
}

ListNode *Data_Structure::find_first_common_node(ListNode *head1, ListNode *head2) {

    //if (!head1 || !head2) {
    //    return nullptr;
    //}
    ListNode *p1 = head1, *p2 = head2;
    while (p1 != p2) {
        p1 = p1 ? p1->next : head2;
        p2 = p2 ? p2->next : head1;
        //p1 = p1->next ? p1->next : head2;//错误，由于题目没有明确两链表一定相交，会造成无限循环
        //p2 = p2->next ? p2->next : head1;
    }
    return p1;
}

void Data_Structure::local_main_find_first_common_node() {}

vector<int> Data_Structure::max_in_windows(const vector<int> &num, unsigned int size) {

    vector<int> ret;
    deque<int> q;

    for (int i = 0; i < num.size(); ++i) {
        while (!q.empty() && num[q.back()] <= num[i]) q.pop_back();
        while (!q.empty() && i - q.front() >= size) q.pop_front();
        q.push_back(i);
        if (size && i +1 >= size) ret.push_back(num[q.front()]);//size==0时ret为空
    }
    return ret;
}

void Data_Structure::local_main_max_in_windows() {

    auto main = new Data_Structure();
    Utility::print_vector(main->max_in_windows(vector<int>({2, 3, 4, 2, 6, 2, 5, 1}), 3));
}


TreeNode *Data_Structure::reconstruct_binary_tree(vector<int> pre, vector<int> vin) {

    map<int, int> mp;
    for (int i = 0; i < vin.size(); ++i) {
        mp.insert(make_pair(vin[i], i));
    }
    int now = 0;
    return recur_reconstruct_binary_tree(mp, pre, 0, static_cast<int>(pre.size() - 1), now);
}

TreeNode *Data_Structure::recur_reconstruct_binary_tree(map<int, int> &mp, vector<int> &pre,
                                                            int low, int high, int &now) {
    int index = mp[pre[now]];
    auto *node = new TreeNode(pre[now]);
    if (low < high) {
        if (index > low) {
            node->left = recur_reconstruct_binary_tree(mp, pre, low, index - 1, ++now);
        }
        if (index < high) {
            node->right = recur_reconstruct_binary_tree(mp, pre, index + 1, high, ++now);
        }
    }
    return node;
}

void Data_Structure::local_main_reconstruct_binary_tree() {

    auto main = new Data_Structure();
    Utility::print_vector(Utility::tree_traversal(main->reconstruct_binary_tree(
            vector<int>({1, 2, 4, 7, 3, 5, 6, 8}), vector<int>({4, 7, 2, 1, 5, 3, 8, 6}))));

}

TreeLinkNode *Data_Structure::get_next(TreeLinkNode *node) {

    if (!node) return nullptr;
    TreeLinkNode *ret = nullptr;
    if (node->right) {
        ret = node->right;
        while (ret->left) {
            ret = ret->left;
        }
        return ret;
    } else {
        ret = node;
        while (ret->next){
            if (ret->next->left == ret){
                return ret->next;
            }
            ret = ret->next;
        }
        return nullptr;
    }
}

void Data_Structure::local_main_get_next() {}

