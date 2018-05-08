//
// Created by faiz on 18-5-8.
//

#include "Search_and_Sort.h"

#include <iostream>

int Search_and_Sort::minNumberInRotateArray(std::vector<int> rotateArray) {

    if(rotateArray.empty()){
        return 0;
    }
    auto it = rotateArray.begin();
    int a;
    int b;
    for(; it != rotateArray.end(); ++it){
        a = *it;
        b = *(it +1);
        if(a > b){
            return b;
        }
    }
    return -1;
}

void Search_and_Sort::local_main_minNumberInRotateArray() {

    std::vector<int> a;
    for (int i = 3; i < 10; ++i) {
        a.push_back(i);
    }
    for (int i = 1; i < 3; ++i) {
        a.push_back(i);
    }
    auto * main = new Search_and_Sort();
    std::cout << main->minNumberInRotateArray(a) << std::endl;
}