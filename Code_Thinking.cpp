//
// Created by faiz on 18-5-12.
//
#include "Utility.h"
#include "Code_Thinking.h"

#include <algorithm>
#include <math.h>

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
    reverse(ret.begin(),ret.end());
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
    for (int i = 0; i < ret.size(); ++i) {
        Utility::print_vector_int(ret[i]);
    }
    ret = main->find_continuous_seq(45);
    for (int i = 0; i < ret.size(); ++i) {
        Utility::print_vector_int(ret[i]);
    }
}



