//
// Created by faiz on 18-5-12.
//
#include "Utility.h"
#include "Code_Thinking.h"
#include "Search_and_Sort.h"

#include <algorithm>
#include <cmath>

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

vector<vector<int>> Code_Thinking::find_continuous_seq(int sum) {

    vector<vector<int>> ret;
    for (int i = 2; i < sum; ++i) {

        int re = sum / i;
        if (re * 2 < i) {
            break;
        }

        if (i % 2 == 1 && sum % i == 0) {
            vector<int> sub_ret;
            for (int j = re - i / 2; j <= re + i / 2; ++j) {
                sub_ret.push_back(j);
            }
            ret.push_back(sub_ret);
        }
        if (/*i % 2 == 0 &&*/ sum % i * 2 == i) {
            vector<int> sub_ret;
            for (int j = re - i / 2 + 1; j <= re + i / 2; ++j) {
                sub_ret.push_back(j);
            }
            ret.push_back(sub_ret);
        }
    }
    reverse(ret.begin(), ret.end());
    return ret;

}

vector<vector<int>> Code_Thinking::find_continuous_seq_standard(int sum) {

    vector<vector<int>> ans;
    for (int n = (int) sqrt(2 * sum); n >= 2; n--) {
        if ((n & 1) == 1 && sum % n == 0 || (sum % n) * 2 == n) {
            vector<int> an;
            for (int j = 0, k = (sum / n) - (n - 1) / 2; j < n; j++, k++) {
                an.push_back(k);
            }
            ans.push_back(an);
        }
    }
    return ans;
}

void Code_Thinking::local_main_find_continuous_seq() {

    auto *main = new Code_Thinking();
    vector<vector<int>> ret = main->find_continuous_seq_standard(45);
    for (const auto &i : ret) {
        Utility::print_vector(i);
    }
    ret = main->find_continuous_seq(45);
    for (const auto &i : ret) {
        Utility::print_vector(i);
    }
}


vector<int> Code_Thinking::find_nums_with_sum(const vector<int> &array, int sum) {

    int head = 0, tail = static_cast<int>(array.size() - 1);
    vector<int> ret;
    while (head < tail) {

        if (array[head] + array[tail] == sum) {
            ret.push_back(array[head]);
            ret.push_back(array[tail]);
            return ret;
        } else if (array[head] + array[tail] < sum) {
            head++;
        } else {
            tail--;
        }
    }
    return ret;
}

void Code_Thinking::local_main_find_nums_with_sum() {

    auto *main = new Code_Thinking();
    vector<int> a{1,2,5,6,8,9,20,23,34};
    Utility::print_vector(main->find_nums_with_sum(a, 25));

}

bool Code_Thinking::is_continuous(vector<int> numbers) {

    if(numbers.empty()){
        return false;
    }
    sort(numbers.begin(), numbers.end());

    int count_0 = 0;
    int count_differ = 0;
    int num_before = 0;

    for(int i : numbers){
        if(i == 0){
            count_0++;
        }else{
            if(num_before != 0){
                count_differ += (i - num_before -1);
            }
            if(num_before == i){
                return false;
            }
            num_before = i;
        }
    }
    return count_0 >= count_differ;
}

void Code_Thinking::local_main_is_continuous() {

    auto *main = new Code_Thinking();
    cout << main->is_continuous(vector<int>{4,7,2,8,0,0,5}) << endl;
}






