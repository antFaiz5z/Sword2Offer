//
// Created by faiz on 18-5-8.
//

#ifndef JIANZHIOFFER_SEARCH_AND_SORT_H
#define JIANZHIOFFER_SEARCH_AND_SORT_H

#include <vector>
#include <string>

#include "Utility.h"

using namespace std;

class Search_and_Sort {

public:

    template<typename T>
    static void bubble_sort(vector<T> &v) {
        T tmp;
        for (auto i = static_cast<int>(v.size() - 1); i >= 1; --i) {
            for (int j = 0; j < i; ++j) {
                if (v[j] > v[j + 1]) {
                    tmp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = tmp;
                }
            }
        }
    }

    template<typename T>
    static void insert_sort(vector<T> &v) {

        T tmp;
        int j;
        for (int i = 1; i < v.size(); ++i) {
            tmp = v[i];
            for (j = i - 1; j >= 0 && tmp < v[j]; --j) {
                v[j + 1] = v[j];
            }
            v[j + 1] = tmp;
        }
    }

    template<typename T>
    static void quick_sort(vector<T> &v) {

        if(v.size() == 0 || v.size() == 1){
            return;
        }
        quick_sort_recur(v, 0, static_cast<int>(v.size() - 1));
    }
    template<typename T>
    static void quick_sort_recur(vector<T> &v, int left, int right){

        if(left < right){
            T pivot = v[left];
            int i = left, j = right;
            while(i < j){
                while(i < j && pivot < v[j]) j--;///=
                if(i < j){
                    v[i] = v[j];
                    i++;
                }
                while(i < j && v[i] < pivot) i++;
                if(i < j){
                    v[j] = v[i];
                    j--;
                }
                v[i] = pivot;
                quick_sort_recur(v, left, i-1);///i
                quick_sort_recur(v, i+1, right);
            }

        }
    }

    /*
     * 11. 旋转数组的最小数字
     * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
     * 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
     * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
     * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
     */
    int minNumberInRotateArray(vector<int> rotateArray);//效率较低
    int minNumberInRotateArray_II(vector<int> rotateArray);//无法应对存在相等数据情况
    int find(vector<int> &rotateArray, int left, int right);

    int minNumberInRotateArray_standard(vector<int> rotateArray);
    int find_min(vector<int> &rotateArray, int left, int right);
    static void local_main_minNumberInRotateArray();

    /*
     * 40. 最小的 K 个数
     * 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
     * *基于堆排序算法，构建最大堆。时间复杂度为O(nlogk)
     * *如果用快速排序，时间复杂度为O(nlogn)；
     * *如果用冒泡排序，时间复杂度为O(n*k)
     */
    vector<int> get_least_nums_libfunc(vector<int> inputs, int k);
    vector<int> get_least_nums_heap(vector<int> inputs, int k);//TODO: to complete
    vector<int> get_least_nums_quicksort(vector<int> inputs, int k);//TODO: to complete
    vector<int> get_least_nums_bubble(vector<int> inputs, int k);
    static void local_main_get_least_nums();

    /*
     * 41.1 数据流中的中位数
     * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
     * 那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
     * 那么中位数就是所有数值排序之后中间两个数的平均值。
     * 我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
     */
    void insert_priorityq(int num);
    double get_median_priorityq();
    void insert_insert(int num);
    double get_median_insert();
    static void local_main_get_median();

private:
    //41.1
    priority_queue<int, vector<int>, less<int>> p;
    priority_queue<int, vector<int>, greater<int>> q;
};


#endif //JIANZHIOFFER_SEARCH_AND_SORT_H
