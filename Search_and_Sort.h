//
// Created by faiz on 18-5-8.
//

#ifndef JIANZHIOFFER_SEARCH_AND_SORT_H
#define JIANZHIOFFER_SEARCH_AND_SORT_H

#include <vector>

class Search_and_Sort {

public:
    int minNumberInRotateArray(std::vector<int> rotateArray);//效率较低

    int minNumberInRotateArray_II(std::vector<int> rotateArray);//无法应对存在相等数据情况
    int find(std::vector<int> &rotateArray, int left, int right);

    int minNumberInRotateArray_standard(std::vector<int> rotateArray);
    int find_min(std::vector<int> &rotateArray, int left, int right);

    static void local_main_minNumberInRotateArray();


};


#endif //JIANZHIOFFER_SEARCH_AND_SORT_H
