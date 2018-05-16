//
// Created by faiz on 18-5-12.
//

#include "Code_Thinking.h"


double Code_Thinking::power(double base, int exponent) {
    double ret = 1;
    while (exponent--) {
        ret *= base;
    }
    return ret;
}

double Code_Thinking::power_standard(double base, int exponent) {
    double ret = 1;
    int n;
    double curr = base;
    if (exponent > 0) {
        n = exponent;
    } else if (exponent < 0) {
        if (base == 0) {
            exit(-1);
        }
        n = -exponent;
    } else {
        return 1;
    }
    while (n) {
        if (n & 1) {
            ret *= curr;
        }
        curr *= curr;
        n >>= 1;
    }
    return exponent > 0 ? ret : 1 / ret;
}

void Code_Thinking::local_main_power() {
    auto *main = new Code_Thinking();
    std::cout << main->power(5, 3) << std::endl;
    std::cout << main->power_standard(5, 3) << std::endl;

}

void Code_Thinking::reOrderArray(std::vector<int> &array) {


}

void Code_Thinking::local_main_reOrderArray() {

}