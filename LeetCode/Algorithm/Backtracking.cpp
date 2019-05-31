//
// Created by Faiz on 2019/5/31 0031.
//

#include "Backtracking.h"

void Backtracking::grayCodeHelper(vector<int> &ret, unsigned int *now, unsigned int n) {
    if (n == 1) {
        *now = *now ^ 1;
        ret.push_back(*now);
        return;
    }
    grayCodeHelper(ret, now, n >> 1);
    *now = *now ^ n;
    ret.push_back(*now);
    grayCodeHelper(ret, now, n >> 1);

}

vector<int> Backtracking::grayCode(int n) {

    unsigned int now = 0;
    vector<int> ret{0};
    if (n > 0) grayCodeHelper(ret, &now, 1 << n - 1);
    return ret;
}

vector<int> Backtracking::grayCodeII(int n) {
    vector<int> result(1 << n);
    for (size_t i = 0; i < (1 << n); i++)
        result[i] = i ^ (i >> 1);
    return result;
}



