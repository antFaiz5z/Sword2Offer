//
// Created by faiz on 18-5-12.
//
#include "Loop_and_Recursion.h"

#include <unordered_set>
#include <algorithm>
#include <iostream>

#include "Utility.h"

int Loop_and_Recursion::jumpFloor(int number) {

    if (number <= 2) {
        return number;
    } else {
        return jumpFloor(number - 1) + jumpFloor(number - 2);
    }
}

int Loop_and_Recursion::jumpFloor_dynamic_programming(int number) {

    if (number <= 2) {
        return number;
    }
    vector<int> fibonacci(static_cast<unsigned long>(number));
    fibonacci[0] = 1;
    fibonacci[1] = 2;
    for (int i = 2; i < number; ++i) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    return fibonacci[number - 1];
}

int Loop_and_Recursion::jumpFloor_dynamic_programming_2(int number) {

    if (number <= 2) {
        return number;
    }
    int pre1 = 1, pre2 = 2;
    int ret = 0;
    for (int i = 3; i <= number; ++i) {
        ret = pre1 + pre2;
        pre1 = pre2;
        pre2 = ret;
    }
    return ret;
}

int Loop_and_Recursion::jumpFloorII(int number) {

    if (number == 0) {
        return 0;
    } else if (number == 1) {
        return 1;
    } else {
        return jumpFloorII(number - 1) * 2;
    }
}

int Loop_and_Recursion::jumpFloorII_dynamic_programming(int number) {

    /*int *dp = new int[number];
    for (int i = 0; i < number; ++i) {
        cout << dp[i] <<endl;
    }*/
    vector<int> dp(number, 1);
    for (int i = 0; i < number; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j];
        }
    }
    return dp[number - 1];

}

void Loop_and_Recursion::local_main_jumpFloor() {

    auto *main = new Loop_and_Recursion();
    int n = 11;
    cout << main->jumpFloor(n) << endl;
    cout << main->jumpFloor_dynamic_programming(n) << endl;
    cout << main->jumpFloor_dynamic_programming_2(n) << endl;
    cout << main->jumpFloorII(n) << endl;
    cout << main->jumpFloorII_dynamic_programming(n);
}

void Loop_and_Recursion::permutation_recur(vector<string> &res, int k, string str) {

    if (k == str.size() - 1) {
        res.push_back(str);
    }
    unordered_set<char> chars;
    sort(str.begin() + k, str.end());
    for (int i = k; i < str.size(); ++i) {

        if (chars.find(str[i]) == chars.end()) {
            chars.insert(str[i]);
            swap(str[i], str[k]);
            permutation_recur(res, k + 1, str);
            swap(str[i], str[k]);

        }
    }
}

vector<string> Loop_and_Recursion::permutation(string str) {

    vector<string> res;
    permutation_recur(res, 0, std::move(str));
    return res;
}

void Loop_and_Recursion::local_main_permutation() {

    string str = "abbc";
    Utility::print_vector(get_instance()->permutation(str));
}

bool Loop_and_Recursion::has_path(char *matrix, int rows, int cols, char *str) {

    if (rows <= 0 || cols <= 0 || matrix == nullptr || str == nullptr) {
        return false;
    }

    //int *flags = new int(strlen(matrix));//error
    //int *flags = new int[strlen(matrix)];//ok
    int *flags = (int *) malloc(sizeof(int) * strlen(matrix));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (backtracking_has_path(matrix, rows, cols, str, i, j, 0, flags)) {
                return true;
            }
        }
    }
    return false;
}

bool Loop_and_Recursion::backtracking_has_path(char *matrix, int rows, int cols, char *str,
                                               int i, int j, int k, int *flags) {

    int index = i * cols + j;
    if (i < 0 || rows <= i || j < 0 || cols <= j || matrix[index] != str[k] || flags[index] == 1) {
        return false;
    }
    if (k == strlen(str) - 1) {
        return true;
    }

    flags[index] = 1;
    if (backtracking_has_path(matrix, rows, cols, str, i - 1, j, k + 1, flags)
        || backtracking_has_path(matrix, rows, cols, str, i + 1, j, k + 1, flags)
        || backtracking_has_path(matrix, rows, cols, str, i, j - 1, k + 1, flags)
        || backtracking_has_path(matrix, rows, cols, str, i, j + 1, k + 1, flags)
            ) {
        return true;
    }
    flags[index] = 0;

    return false;
}

void Loop_and_Recursion::local_main_has_path() {

    char *matrix = const_cast<char *>("abcesfcsadee");
    char *str1 = const_cast<char *>("bcced");
    char *str2 = const_cast<char *>("abcb");

    std::cout << get_instance()->has_path(matrix, 3, 4, str1) << std::endl;
    std::cout << get_instance()->has_path(matrix, 3, 4, str2) << std::endl;
}

int Loop_and_Recursion::moving_count(int threshold, int rows, int cols) {

    bool *flags[rows];

    for (int i = 0; i < rows; ++i) {
        flags[i] = new bool[cols];
        for (int j = 0; j < cols; ++j) {
            flags[i][j] = false;
        }
    }
    return backtracking_moving_count(threshold, rows, cols, 0, 0, flags);
}

int Loop_and_Recursion::backtracking_moving_count(int threshold, int rows, int cols, int i, int j, bool *flags[]) {

    if (0 > i || i >= rows || 0 > j || j >= cols ||
        get_digit_sum(i) + get_digit_sum(j) > threshold || flags[i][j]) {
        return 0;
    }

    flags[i][j] = true;

    return backtracking_moving_count(threshold, rows, cols, i - 1, j, flags)
           + backtracking_moving_count(threshold, rows, cols, i + 1, j, flags)
           + backtracking_moving_count(threshold, rows, cols, i, j - 1, flags)
           + backtracking_moving_count(threshold, rows, cols, i, j + 1, flags)
           + 1;
}

int Loop_and_Recursion::get_digit_sum(int n) {

    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void Loop_and_Recursion::local_main_moving_count() {

    std::cout << get_instance()->moving_count(11, 10, 10) << std::endl;
}

void Loop_and_Recursion::print_1_to_n_digits(int n) {

    if (n < 0) {
        return;
    }
    char *nums = new char[n];
    backtracking_print_1_to_n_digits(nums, 0, n);
}

void Loop_and_Recursion::backtracking_print_1_to_n_digits(char *nums, int digit, int n) {

    if (digit == n) {
        print_num(nums);
        return;
    }
    for (int i = 0; i < 10; ++i) {
        nums[digit] = static_cast<char>('0' + i);
        backtracking_print_1_to_n_digits(nums, digit + 1, n);
    }
}

void Loop_and_Recursion::print_num(const char *nums) {

    int index = 0;
    while (index < strlen(nums) && nums[index] == '0') {
        index++;
    }
    while (index < strlen(nums)) {
        std::cout << nums[index++];
    }
    std::cout << std::endl;
}

void Loop_and_Recursion::local_main_print_1_to_n_digits() {

    get_instance()->print_1_to_n_digits(2);
}

ListNode *Loop_and_Recursion::delete_node(ListNode *head, ListNode *todelete) {

    if (head == nullptr || todelete == nullptr) {
        return nullptr;
    }

    if (todelete->next != nullptr) {
        todelete->val = todelete->next->val;
        todelete->next = todelete->next->next;
        return head;
    } else {
        ListNode *p = head;
        while (p->next != todelete) {
            p++;
        }
        p->next = nullptr;
        return head;
    }
}

ListNode *Loop_and_Recursion::delete_dup_node(ListNode *head) {

    if (nullptr == head || nullptr == head->next) {
        return head;
    }
    ListNode *next = head->next;
    if (head->val == next->val) {
        while (nullptr != next && head->val == next->val) {
            next = next->next;
        }
        return delete_dup_node(next);
    } else {
        head->next = delete_dup_node(next);
        return head;
    }
}

void Loop_and_Recursion::local_main_delete_node() {

    ListNode *head = Utility::get_list(vector<int>({1, 2, 2, 3, 4, 4, 5, 6, 6}));
    Utility::print_list(head);
    ListNode *todelete = head->next->next->next->next;
    get_instance()->delete_node(head, todelete);
    Utility::print_list(head);
    get_instance()->delete_dup_node(head);
    Utility::print_list(head);
}

bool Loop_and_Recursion::regx_match_backtracking_error(char *str, char *pattern) {

    /*if (nullptr == pattern) {
        return nullptr == str;
    }*/
    if ('\0' == *pattern) {
        return '\0' == *str;
    }

    if (*pattern == '.') {
        return regx_match_backtracking_error(str + 1, pattern + 1);
    }
    if (*(pattern + 1) == '*') {
        if (*str != *pattern) {
            return regx_match_backtracking_error(str, pattern + 2);
        } else {
            return regx_match_backtracking_error(str + 1, pattern) || regx_match_backtracking_error(str, pattern + 2);
        }
    } else {
        if (*str != *pattern) {
            return false;
        } else {
            return regx_match_backtracking_error(str + 1, pattern + 1);
        }
    }
}


bool Loop_and_Recursion::regx_match_backtracking(char *str, char *pattern) {

    if ('\0' == *pattern) {
        return '\0' == *str;
    }

    if (*(pattern + 1) == '*') {
        if (*str == *pattern || (*str != '\0' && '.' == *pattern)) {
            return regx_match_backtracking(str + 1, pattern) || regx_match_backtracking(str, pattern + 2);
        } else {
            return regx_match_backtracking(str, pattern + 2);
        }
    } else {
        if (*str == *pattern || (*str != '\0' && '.' == *pattern)) {
            return regx_match_backtracking(str + 1, pattern + 1);
        } else {
            return false;
        }
    }

}

bool Loop_and_Recursion::regx_match_matrix(char *str, char *pattern) {

    size_t m = strlen(str), n = strlen(pattern);
    bool *dp[m + 1];
    for (int i = 0; i < m + 1; ++i) {
        dp[i] = new bool[n + 1];
    }

    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
        if (pattern[i - 1] == '*')
            dp[0][i] = dp[0][i - 2];

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.')
                dp[i][j] = dp[i - 1][j - 1];
            else if (pattern[j - 1] == '*') {
                if (pattern[j - 2] == str[i - 1] || pattern[j - 2] == '.') {
                    dp[i][j] |= dp[i][j - 1]; // a* counts as single a
                    dp[i][j] |= dp[i - 1][j]; // a* counts as multiple a
                    dp[i][j] |= dp[i][j - 2]; // a* counts as empty
                } else {
                    dp[i][j] = dp[i][j - 2];   // a* only counts as empty
                }
            }
    return dp[m][n];
}


void Loop_and_Recursion::local_main_match() {

    char *str = const_cast<char *>("aaa");
    char *s1 = str, *s2 = str, *s3 = str, *s4 = str, *s5 = str;
    char *pattern1 = const_cast<char *>("a.a");
    char *pattern2 = const_cast<char *>("ab*ac*a");
    char *pattern3 = const_cast<char *>("aa.a");
    char *pattern4 = const_cast<char *>("ab*a");
    char *pattern5 = const_cast<char *>(".*");


    std::cout << get_instance()->regx_match_backtracking(s1, pattern1) << std::endl
              << get_instance()->regx_match_backtracking(s2, pattern2) << std::endl
              << get_instance()->regx_match_backtracking(s3, pattern3) << std::endl
              << get_instance()->regx_match_backtracking(s4, pattern4) << std::endl
              << get_instance()->regx_match_backtracking(s5, pattern5) << std::endl;

    std::cout << get_instance()->regx_match_matrix(s1, pattern1) << std::endl
              << get_instance()->regx_match_matrix(s2, pattern2) << std::endl
              << get_instance()->regx_match_matrix(s3, pattern3) << std::endl
              << get_instance()->regx_match_matrix(s4, pattern4) << std::endl
              << get_instance()->regx_match_matrix(s5, pattern5) << std::endl;

}

int Loop_and_Recursion::get_most(vector<vector<int>> board) {

    if (board.empty() || board[0].empty()) {
        return 0;
    }
    unsigned long n = board[0].size();
    int *dp = new int[n];
    for (vector<int> &row : board) {
        dp[0] += row[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i], dp[i - 1]) + row[i];
        }
    }
    return dp[n - 1];
}

void Loop_and_Recursion::local_main_get_most() {

    cout << get_instance()->get_most(vector<vector<int>>({{1, 2, 3, 4, 5, 6},
                                                          {1, 2, 3, 4, 5, 6},
                                                          {1, 2, 3, 4, 5, 6},
                                                          {1, 2, 3, 4, 5, 6}})) << endl;
}

TreeNode *Loop_and_Recursion::kth_node(TreeNode *root, int k) {

    int count = 0;
    return inorder_kth_node(root, k, count);
}

TreeNode *Loop_and_Recursion::inorder_kth_node(TreeNode *root, int k, int &count) {

    if (!root) return nullptr;
    TreeNode *ret;
    ret = inorder_kth_node(root->left, k, count);
    if (ret) return ret;
    if (++count == k) return root;
    ret = inorder_kth_node(root->right, k, count);
    if (ret) return ret;
    return nullptr;
}

void Loop_and_Recursion::local_main_kth_node() {

    cout << get_instance()->kth_node(Utility::get_tree(vector<int>({5, 3, 7, 2, 4, 6, 8})), 3)->val << endl;
}

int Loop_and_Recursion::tree_depth(TreeNode *root) {

    return !root ? 0 : 1 + max(tree_depth(root->left), tree_depth(root->right));
}

void Loop_and_Recursion::local_main_tree_depth() {

    cout << get_instance()->tree_depth(Utility::get_tree(vector<int>({5, 3, 7, 2, 4, 6, 8}))) << endl;
}

bool Loop_and_Recursion::is_balanced(TreeNode *root) {

    bool ret = true;
    backtracking_is_balanced(root, ret);
    return ret;
}

int Loop_and_Recursion::backtracking_is_balanced(TreeNode *root, bool &ret) {

    if (!root || !ret) return 0;
    int left = backtracking_is_balanced(root->left, ret);
    int right = backtracking_is_balanced(root->right, ret);
    if (!ret) return 0;
    if (left - right > 1 || left - right < -1) ret = false;
    return max(left, right) + 1;
}

void Loop_and_Recursion::local_main_is_balanced() {

    cout << get_instance()->is_balanced(Utility::get_tree(vector<int>({1, 2, 3, 4, 5, 6, 7, 8}))) << endl;
}

TreeNode *Loop_and_Recursion::lowest_common_ancestor_bst(TreeNode *root, TreeNode *p, TreeNode *q) {

    if (!root) return nullptr;
    if (root->val > p->val && root->val > q->val) {
        return lowest_common_ancestor_bst(root->left, p, q);
    }
    if (root->val < p->val && root->val < q->val) {
        return lowest_common_ancestor_bst(root->right, p, q);
    }
    return root;
}

TreeNode *Loop_and_Recursion::lowest_common_ancestor(TreeNode *root, TreeNode *p, TreeNode *q) {

    if (!root || root == p || root == q) return root;
    TreeNode *left = lowest_common_ancestor(root->left, p, q);
    TreeNode *right = lowest_common_ancestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}

void Loop_and_Recursion::local_main_lowest_common_ancestor() {

    TreeNode *root = Utility::get_tree(vector<int>({6, 2, 8, 0, 4, 7, 9}));
    TreeNode *p = root->left;
    TreeNode *q = root->left->right;
    cout << get_instance()->lowest_common_ancestor_bst(root, p, q)->val << endl;
    cout << get_instance()->lowest_common_ancestor(root, p, q)->val << endl;
}
