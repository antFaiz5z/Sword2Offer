//
// Created by faiz on 18-5-12.
//

#include "Code_Thinking.h"

#include <iostream>

double Code_Thinking::power(double base, int expoent) {
    double ret = 1;
    while (expoent--){
        ret *= base;
    }
    return ret;
}

void Code_Thinking::local_main_power() {
    auto * main = new Code_Thinking();
    std::cout << main->power(5,3) << std::endl;
}