//
// Created by faiz on 18-5-8.
//

#include "Search_and_Sort.h"

#include <iostream>
#include <algorithm>

int Search_and_Sort::minNumberInRotateArray(vector<int> rotateArray) {

    if (rotateArray.empty()) {
        return 0;
    }
    auto it = rotateArray.begin();
    int a;
    int b;
    for (; it != rotateArray.end(); ++it) {
        a = *it;
        b = *(it + 1);
        if (a > b) {
            return b;
        }
    }
    return -1;
}

int Search_and_Sort::minNumberInRotateArray_II(vector<int> rotateArray) {

    if (rotateArray.empty()) {
        return 0;
    }
    int left = 0;
    int right = static_cast<int>(rotateArray.size() - 1);
    return find(rotateArray, left, right);
}

int Search_and_Sort::find(vector<int> &rotateArray, int left, int right) {

    int mid = (left + right) / 2;
    if (rotateArray[mid] < rotateArray[left] && rotateArray[mid] < rotateArray[right]) {
        find(rotateArray, left, mid);
    } else if (rotateArray[mid] > rotateArray[left] && rotateArray[mid] > rotateArray[right]) {
        find(rotateArray, mid, right);
    } else if (mid == left) {
        return rotateArray[right];
    }
}

int Search_and_Sort::minNumberInRotateArray_standard(vector<int> rotateArray) {

    if (rotateArray.empty()) {
        return 0;
    }
    int left = 0;
    int right = static_cast<int>(rotateArray.size() - 1);
    int mid = 0;

    while (rotateArray[left] >= rotateArray[right]) {

        if ((right - left) == 1) {
            mid = right;
            break;
        }
        mid = (left + right) / 2;
        if (rotateArray[left] == rotateArray[mid] && rotateArray[left] == rotateArray[right]) {
            find_min(rotateArray, left, right);
        }
        if (rotateArray[mid] >= rotateArray[left]) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return rotateArray[mid];
}

int Search_and_Sort::find_min(vector<int> &rotateArray, int left, int right) {

    int ret = rotateArray[0];
    for (int i = 1; i < rotateArray.size() - 1; ++i) {
        if (ret > rotateArray[i]) {
            ret = rotateArray[i];
        }
    }
    return ret;
}

void Search_and_Sort::local_main_minNumberInRotateArray() {

    //std::vector<int> a = {4,5,6,7,8,9,1,2,3};
    vector<int> a = {4, 5, 6, 7, 8, 8, 1, 3, 3};

    auto *main = new Search_and_Sort();
    std::cout << main->minNumberInRotateArray(a) << std::endl;
    std::cout << main->minNumberInRotateArray_II(a) << std::endl;
    std::cout << main->minNumberInRotateArray_standard(a) << std::endl;
}

vector<int> Search_and_Sort::get_least_nums_libfunc(vector<int> inputs, int k) {

    vector<int> ret;
    if (k <= 0 || k > inputs.size()) {
        return ret;
    }
    sort(inputs.begin(), inputs.end());
    for (int i = 0; i < k; ++i) {
        ret.push_back(inputs[i]);
    }
    return ret;
}

vector<int> Search_and_Sort::get_least_nums_heap(vector<int> inputs, int k) {
    return vector<int>();
}

vector<int> Search_and_Sort::get_least_nums_quicksort(vector<int> inputs, int k) {
    return vector<int>();
}

vector<int> Search_and_Sort::get_least_nums_bubble(vector<int> inputs, int k) {

    vector<int> ret;
    if (k <= 0 || k > inputs.size()) {
        return ret;
    }
    int temp;
    for (int i = 0; i < k; ++i) {
        for (unsigned long j = inputs.size() - 1; j > i; --j) {
            if (inputs[j - 1] > inputs[j]) {
                temp = inputs[j];
                inputs[j] = inputs[j - 1];
                inputs[j - 1] = temp;
            }
        }
        ret.push_back(inputs[i]);
    }
    return ret;
}

void Search_and_Sort::local_main_get_least_nums() {

    auto main = new Search_and_Sort();
    Utility::print_vector(main->get_least_nums_libfunc(vector<int>({4, 5, 1, 6, 2, 7, 3, 8}), 4));
    Utility::print_vector(main->get_least_nums_bubble(vector<int>({4, 5, 1, 6, 2, 7, 3, 8}), 4));
}

void Search_and_Sort::insert_priorityq(int num) {

    if (p.empty() || num < p.top()) {
        p.push(num);
    } else {
        q.push(num);
    }
    if (p.size() == q.size() + 2) {
        q.push(p.top());
        p.pop();
    }
    if (p.size() + 1 == q.size()) {
        p.push(q.top());
        q.pop();
    }
}

double Search_and_Sort::get_median_priorityq() {
    return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
}

void Search_and_Sort::insert_insert(int num) {

}

double Search_and_Sort::get_median_insert() {
    return 0;
}

void Search_and_Sort::local_main_get_median() {

}

