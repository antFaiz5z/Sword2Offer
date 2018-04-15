//
// Created by faiz on 18-4-13.
//

#ifndef JIANZHIOFFER_ARRAY_H
#define JIANZHIOFFER_ARRAY_H


#include <vector>

using namespace std;

class Array {

public:

    /*
     * 时间限制：1秒 空间限制：32768K 热度指数：646173
            本题知识点： 查找
     * 题目描述
            在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
            请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
     */
    vector<vector<int>> get_array(int m, int n);
    bool find_mine(int target, vector<vector<int> > array);
    bool find_standard(int target, vector<vector<int> > array);

    static void local_main();
};


#endif //JIANZHIOFFER_ARRAY_H
