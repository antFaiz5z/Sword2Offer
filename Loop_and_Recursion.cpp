//
// Created by faiz on 18-5-12.
//

#include "Loop_and_Recursion.h"

#include <unordered_set>
#include <algorithm>

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
        fibonacci[i] = fibonacci[i -1] + fibonacci[i -2];
    }
    return fibonacci[number -1];
}

int Loop_and_Recursion::jumpFloor_dynamic_programming_2(int number) {

    if (number <= 2) {
        return number;
    }
    int pre1 = 1, pre2 = 2;
    int ret = 0;
    for (int i = 3; i <= number ; ++i) {
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
    return dp[number -1];

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

    if(k == str.size() -1){
        res.push_back(str);
    }
    unordered_set<char> chars;
    sort(str.begin() + k, str.end());
    for (int i = k; i < str.size(); ++i) {

        if(chars.find(str[i]) == chars.end()){
            chars.insert(str[i]);
            swap(str[i], str[k]);
            permutation_recur(res, k+1, str);
            swap(str[i], str[k]);

        }
    }
}

vector<string> Loop_and_Recursion::permutation(string str) {

    vector<string> res;
    permutation_recur(res, 0, str);
    return res;
}

void Loop_and_Recursion::local_main_permutation() {

    auto *main = new Loop_and_Recursion();
    string str = "abbc";
    Utility::print_vector(main->permutation(str));
}