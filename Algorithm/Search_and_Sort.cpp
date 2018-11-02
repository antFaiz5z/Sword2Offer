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
