//
// Created by Faiz on 2019/3/18 0018.
//
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {

    int n, begin, end;
    int max = 0, min = numeric_limits<int32_t>::max();
    vector<vector<int>> num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &begin, &end);
        num.push_back(vector<int>{begin,end});
    }
    for (auto &i : num) {
        cout << i[0] << ":" <<i[1] <<endl;
        if (i[0] < min) min = i[0];
        if (i[1] > max) max = i[1];
    }
    int *sum = new int[max - min]();
    for (auto &i : num) {
        for (int j = i[0]; j < i[1]; ++j) {
            sum[j - min] += 1;
        }
    }
    int ret = 0;
    for (int k = 0; k < max - min; ++k) {
        if (sum[k] > ret) ret = sum[k];
    }
    cout << ret;
}