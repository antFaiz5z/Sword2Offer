#include <utility>

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

    auto *main = new Loop_and_Recursion();
    string str = "abbc";
    Utility::print_vector(main->permutation(str));
}

bool Loop_and_Recursion::has_path(char *matrix, int rows, int cols, char *str) {

    if (rows <= 0 || cols <= 0 || matrix == nullptr || str == nullptr){
        return false;
    }

    //int *flags = new int(strlen(matrix));//error
    //int *flags = new int[strlen(matrix)];//ok
    int *flags = (int *)malloc(sizeof(int) * strlen(matrix));

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

    auto *main = new Loop_and_Recursion();

    char *matrix = const_cast<char *>("abcesfcsadee");
    char *str1 = const_cast<char *>("bcced");
    char *str2 = const_cast<char *>("abcb");

    std::cout << main->has_path(matrix, 3, 4, str1) << std::endl;
    std::cout << main->has_path(matrix, 3, 4, str2) << std::endl;

}

int Loop_and_Recursion::moving_count(int threshold, int rows, int cols) {
    return 0;
}

int Loop_and_Recursion::backtracking_moving_count(int threshold, int rows, int cols, int i, int j, bool *flags) {
    return 0;
}

int Loop_and_Recursion::get_digit_sum(int n) {
    return 0;
}

void Loop_and_Recursion::local_main_moving_count() {

}
