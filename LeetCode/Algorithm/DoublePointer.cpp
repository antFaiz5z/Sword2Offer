//
// Created by Faiz on 2019/1/9 0009.
//

#include "DoublePointer.h"

#include <cmath>

vector<int> DoublePointer::twoSum(vector<int> &numbers, int target) {

    int i = 0, j = static_cast<int>(numbers.size() - 1);
    while (numbers[i] + numbers[j] != target){
        while (numbers[i] + numbers[j] > target){
            --j;
        }
        while (numbers[i] + numbers[j] < target){
            ++i;
        }
    }
    return vector<int>({i +1, j +1});
}

bool DoublePointer::judgeSquareSum(int c) {
    int i = 0, j = (int)sqrt(c);
    while (i <= j){
        int s = i *i + j *j;
        if (s > c ){
            --j;
        }else if (s < c){
            ++i;
        }else{
            return true;
        }
    }
    return false;
}