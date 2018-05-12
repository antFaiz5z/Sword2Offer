//
// Created by faiz on 18-5-8.
//

#ifndef JIANZHIOFFER_SEARCH_AND_SORT_H
#define JIANZHIOFFER_SEARCH_AND_SORT_H

#include <vector>

class Search_and_Sort {

public:

    /*
     * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
     * 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
     * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
     * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
     */
    int minNumberInRotateArray(std::vector<int> rotateArray);//效率较低

    int minNumberInRotateArray_II(std::vector<int> rotateArray);//无法应对存在相等数据情况
    int find(std::vector<int> &rotateArray, int left, int right);

    int minNumberInRotateArray_standard(std::vector<int> rotateArray);
    int find_min(std::vector<int> &rotateArray, int left, int right);

    static void local_main_minNumberInRotateArray();


};


#endif //JIANZHIOFFER_SEARCH_AND_SORT_H
