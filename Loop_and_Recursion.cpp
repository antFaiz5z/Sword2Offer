//
// Created by faiz on 18-5-12.
//

#include "Loop_and_Recursion.h"

#include <iostream>

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