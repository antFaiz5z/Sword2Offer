//
// Created by faiz on 18-5-12.
//

#include "Loop_and_Recursion.h"
#include "Utility.h"
#include <unordered_set>
#include <algorithm>

int Loop_and_Recursion::jumpFloor(int number) {

    if (number == 0) {
        return 0;
    } else if (number == 1) {
        return 1;
    } else if (number == 2) {
        return 2;
    } else {
        return jumpFloor(number - 1) + jumpFloor(number - 2);
    }
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

void Loop_and_Recursion::local_main_jumpFloor() {

    auto *main = new Loop_and_Recursion();
    std::cout << main->jumpFloor(3) << std::endl;
    std::cout << main->jumpFloorII(3) << std::endl;
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
    Utility::print_vector_string(main->permutation(str));
}