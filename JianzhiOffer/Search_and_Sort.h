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
     * 3. 数组中重复的数字
     * 在一个长度为n的数组里的所有数字都在0到n-1的范围内。
     * 数组中某些数字是重复的，但不知道有几个数字是重复的。
     * 也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
     * 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
     *
     * 思路：
     * 要求复杂度为 O(N) + O(1)，也就是时间复杂度 O(N)，空间复杂度 O(1)。
     * 因此不能使用排序的方法，也不能使用额外的标记数组。
     * 这种数组元素在 [0, n-1] 范围内的问题，可以将值为 i 的元素调整到第 i 个位置上。
     */
    bool duplicate(int numbers[], int length, int *duplication);
    static void local_main_duplicate();

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
    void insert_num(int num);
    double get_median();
    static void local_main_get_median();

    /*
     * 41.2 字符流中第一个不重复的字符
     * 请实现一个函数用来找出字符流中第一个只出现一次的字符。
     * 例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
     * 当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
     * 如果当前字符流没有存在出现一次的字符，返回#字符。
     */
    void insert_char(char ch);
    char first_appearing_once();
    static void local_main_first_appearing_once();

private:
    //41.1
    priority_queue<int, vector<int>, less<int>> le;//大顶堆
    priority_queue<int, vector<int>, greater<int>> gr;//小顶堆
    //41.2
    int *counts = new int[256];
    queue<char> chars;
};


#endif //JIANZHIOFFER_SEARCH_AND_SORT_H
