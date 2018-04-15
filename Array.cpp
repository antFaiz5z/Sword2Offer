//
// Created by faiz on 18-4-13.
//
#include "Array.h"
#include "Utility.h"

#include <iostream>

void Array::local_main() {

    auto *array = new Array();
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


vector<vector<int>> Array::get_array(int m, int n) {
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

bool Array::find_mine(int target, vector<vector<int> > array) {
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

bool Array::find_standard(int target, vector<vector<int> > array) {

    unsigned long rows = array.size();
    unsigned long cols = array[0].size();

    auto i = static_cast<int>(rows - 1);
    int j = 0;
    while(0 <= i && j < cols){
        if(target == array[i][j]){
            cout << i << "," << j << endl;
            return true;
        }else if(target > array[i][j]){
            j++;
        } else{
            i--;
        }
    }
    cout << "not found." << endl;
    return false;
}