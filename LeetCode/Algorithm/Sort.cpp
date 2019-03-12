//
// Created by Faiz on 2019/1/11 0011.
//

#include "Sort.h"


int Sort::findKthLargest_stl(vector<int> &nums, int k) {

    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

int Sort::findKthLargest_heap(vector<int> &nums, int k) {

    priority_queue<int, vector<int>, greater<int>> q;
    for (auto &val : nums) {
        q.push(val);
        if (q.size() > k) {
            q.pop();
        }
    }
    return q.top();
}

int Sort::findKthLargest_quick(vector<int> &nums, int k) {

    k = nums.size() - k;
    int l = 0, h = nums.size() - 1;
    while (l < h) {
        int j = partition(nums, l, h);
        if (j == k) {
            break;
        } else if (j < k) {
            l = j + 1;
        } else {
            h = j - 1;
        }
    }
    return nums[k];
}

int Sort::partition(vector<int> &nums, int l, int h) {

    int i = l, j = h + 1;
    while (true) {
        while (nums[++i] < nums[l] && i < h);    //改成从大到小排列,部分用例未成功 TODO:??
        while (nums[--j] > nums[l] && j > l);
        if (i >= j) break;
        swap(nums, i, j);
    }
    swap(nums, l, j);
    return j;
}

void Sort::swap(vector<int> &nums, int i, int j) {

    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

vector<int> Sort::topKFrequent(vector<int> &nums, int k) {

    map<int, int> m;
    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> ret;

    for (auto &val: nums) {
        if (!m[val]) m.insert(make_pair(val, 0));
        ++m[val];
    }
    for (auto &val : m) {
        q.push(val.second);
        if (q.size() > k) q.pop();
    }
    while (!q.empty()) {
        auto it = m.rend();
        while (it->second != q.top()) ++it;
        ret.push_back(it->first);
        m.erase(it->first);
        q.pop();
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<int> topKFrequent(vector<int> &nums, int k) {

    map<int, int> m;
    vector<int> *fre = new vector<int>[nums.size() + 1];
    vector<int> ret;

    for (auto &val: nums) {
        if (!m[val]) m.insert(make_pair(val, 0));
        ++m[val];
    }
    for (auto &pair : m) {
        fre[pair.second].push_back(pair.first);
    }
    for (int i = nums.size(); i > 0 ; --i) {
        for (auto &val : fre[i]){
            if (k-- > 0){
                ret.push_back(val);
            }else {
                return ret;
            }
        }
    }
    return ret;
}

string Sort::frequencySort(string s) {


    string ret = &s[0];
    return ret.append("353");

}