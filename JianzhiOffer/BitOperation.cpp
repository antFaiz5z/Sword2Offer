//
// Created by faiz on 18-10-31.
//

#include "BitOperation.h"

int Bit_Operation::bit1count(int n) {

    int count = 0;
    while (n != 0) {
        count++;
        n &= (n - 1);
    }
    return count;
}

void Bit_Operation::local_main_bit1count() {

    auto *instance = get_instance();
    cout << instance->bit1count(12345) << endl;
}

int Bit_Operation::add(int num1, int num2) {

    int tmp;
    while (num2 != 0) {
        tmp = num1 ^ num2;
        num2 = (num1 & num2) << 1;
        num1 = tmp;
    }
    return num1;

}

void Bit_Operation::local_main_add() {

    auto *instance = get_instance();
    cout << instance->add(5, 5) << endl;
}

void Bit_Operation::find_nums_appear_once(vector<int> data, int *num1, int *num2) {

    //if (!num1) num1 = new int[1];//判题系统负责初始化
    //if (!num2) num2 = new int[1];
    int diff = 0;
    for (int num : data) diff ^= num;
    diff &= -diff;
    for (int num : data) {
        if (diff & num) {
            *num1 ^= num;
        } else {
            *num2 ^= num;
        }
    }
}

void Bit_Operation::local_main_find_nums_appear_once() {

    auto main = new Bit_Operation();
    int *num1 = new int[1], *num2 = new int[1];
    main->find_nums_appear_once(vector<int>({1, 2, 3, 4, 5, 6, 1, 2, 5, 6}), num1, num2);
    cout << *num1 << ", " << *num2 << endl;
}
