//
// Created by faiz on 18-10-31.
//

#include "Bit_Operation.h"

int Bit_Operation::bit1count(int n) {

    int count = 0;
    while (n != 0){
        count ++;
        n &= (n -1);
    }
    return count;
}

void Bit_Operation::local_main_bit1count() {

    auto *instance = get_instance();
    cout << instance->bit1count(12345) << endl;
}

int Bit_Operation::add(int num1, int num2) {

    int tmp;
    while (num2 != 0){
        tmp = num1^num2;
        num2 = (num1&num2) << 1;
        num1 = tmp;
    }
    return num1;

}

void Bit_Operation::local_main_add() {

    auto *main = new Bit_Operation();
    cout << main->add(5,5) << endl;
}