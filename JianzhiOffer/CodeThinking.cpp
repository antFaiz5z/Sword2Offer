//
// Created by faiz on 18-5-12.
//
#include "CodeThinking.h"

#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>

#include "Utility.h"
#include "SearchAndSort.h"

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

void Code_Thinking::reOrderArray_copy(vector<int> &array) {

    if (array.empty()) {
        return;
    }
    int odd_count = 0;

    for (int &it : array) {
        if (it % 2 == 1) {
            odd_count++;
        }
    }
    vector<int> copy(array);

    int i = 0, j = odd_count;
    for (int &it : copy) {
        if (it % 2 == 1) {
            array[i++] = it;
        } else {
            array[j++] = it;
        }
    }
}

void Code_Thinking::reOrderArray_insert(vector<int> &array) {

    if (array.empty()) {
        return;
    }
    int even_index = 0, odd_index, temp = 0;
    while (even_index < array.size()) {
        while (even_index < array.size() && array[even_index] % 2 == 1) {
            even_index++;
        }
        if (even_index == (array.size() - 1) || even_index == array.size()) {
            return;
        }
        odd_index = even_index + 1;
        while (odd_index < array.size() && array[odd_index] % 2 == 0) {
            odd_index++;
        }
        if (odd_index == array.size()) {
            return;
        }
        temp = array[odd_index];
        for (int i = odd_index; i > even_index; --i) {
            array[i] = array[i - 1];
        }
        array[even_index++] = temp;
    }
}

void Code_Thinking::reOrderArray_stl(vector<int> &array) {

    if (array.empty()) {
        return;
    }
    stable_partition(array.begin(), array.end(), is_odd);
}

bool Code_Thinking::is_odd(int n) {
    //return n % 2 == 1;
    return (n & 1) == 1;
}

void Code_Thinking::local_main_reOrderArray() {

    auto main = new Code_Thinking();
    vector<int> v1({1, 5, 3, 6, 3, 7, 8, 4, 6, 3, 1});
    vector<int> v2(v1), v3(v1);
    Utility::print_vector(v1);
    main->reOrderArray_copy(v1);
    Utility::print_vector(v1);
    main->reOrderArray_insert(v2);
    Utility::print_vector(v2);
    main->reOrderArray_stl(v3);
    Utility::print_vector(v3);
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
    vector<int> a{1, 2, 5, 6, 8, 9, 20, 23, 34};
    Utility::print_vector(main->find_nums_with_sum(a, 25));

}

bool Code_Thinking::is_continuous(vector<int> numbers) {

    if (numbers.empty()) {
        return false;
    }
    sort(numbers.begin(), numbers.end());

    int count_0 = 0;
    int count_differ = 0;
    int num_before = 0;

    for (int i : numbers) {
        if (i == 0) {
            count_0++;
        } else {
            if (num_before != 0) {
                count_differ += (i - num_before - 1);
            }
            if (num_before == i) {
                return false;
            }
            num_before = i;
        }
    }
    return count_0 >= count_differ;
}

void Code_Thinking::local_main_is_continuous() {

    auto *main = new Code_Thinking();
    cout << main->is_continuous(vector<int>{4, 7, 2, 8, 0, 0, 5}) << endl;
}

int Code_Thinking::integer_break_greedy(int n) {

    if (n < 2) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n == 3) {
        return 2;
    }
    int timesof3 = n / 3;
    if (1 == n % 3) {
        return static_cast<int>(pow(3, timesof3 - 1) * 2 * 2);
    } else if (0 == n % 3) {
        return static_cast<int>(pow(3, timesof3));
    } else if (2 == n % 3) {
        return static_cast<int>(pow(3, timesof3) * 2);
    }
    return 0;
}

int Code_Thinking::integer_break_dp(int n) {

    if (n <= 1) {
        return 0;
    }
    //int dp[n + 1];//error, not 0
    //int dp[n + 1]{};//ok
    //int dp[n + 1]{0};//ok
    int *dp = new int[n + 1];//ok       //LeetCode: error, not 0
    //int *dp = new int[n +1]();//ok
    //int *dp = new int[n +1]{};//ok
    //int *dp = new int[n +1]{0};//ok
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            dp[i] = max(dp[i], max(j * (i - j), dp[j] * (i - j)));
        }
    }
    return dp[n];
}

void Code_Thinking::local_main_integer_break() {

    auto *main = new Code_Thinking();

    std::cout << main->integer_break_greedy(1) << std::endl
              << main->integer_break_greedy(3) << std::endl
              << main->integer_break_greedy(4) << std::endl
              << main->integer_break_greedy(5) << std::endl;
    std::cout << main->integer_break_dp(1) << std::endl
              << main->integer_break_dp(3) << std::endl
              << main->integer_break_dp(4) << std::endl
              << main->integer_break_dp(5) << std::endl;

}

bool Code_Thinking::is_numeric(char *string) {

    if (nullptr == string || 0 == strlen(string)) return false;
    bool point = false, e = false;
    int point_pos = -1, e_pos = -1;
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == '+' || string[i] == '-') {
            if (i == strlen(string) - 1) return false;
            if (i != e_pos + 1) return false;
        } else if (string[i] >= '0' && string[i] <= '9') {
        } else if (string[i] == '.') {
            if (i == strlen(string) - 1) return false;
            if (point || e) return false;
            point = true;
            point_pos = i;
            if (point_pos == e_pos + 1) return false;
        } else if (string[i] == 'e' || string[i] == 'E') {
            if (i == strlen(string) - 1) return false;
            if (e) return false;
            e = true;
            e_pos = i;
            if (e_pos == point_pos + 1) return false;
        } else {
            return false;
        }
    }
    return true;
}

void Code_Thinking::local_main_is_numeric() {

    auto main = new Code_Thinking();
    cout << main->is_numeric(const_cast<char *>("+100")) << endl
         << main->is_numeric(const_cast<char *>("5e2")) << endl
         << main->is_numeric(const_cast<char *>("3.1416")) << endl
         << main->is_numeric(const_cast<char *>("-1E-16")) << endl
         << main->is_numeric(const_cast<char *>("1a3.14")) << endl
         << main->is_numeric(const_cast<char *>("12e+4.3")) << endl;
}

int Code_Thinking::more_than_half_num(vector<int> nums) {

    int majority = nums[0];
    for (int i = 1, count = 1; i < nums.size(); ++i) {

        count = nums[i] == majority ? count + 1 : count - 1;
        if (0 == count) {
            majority = nums[i];
            count = 1;
        }
    }
    int count = 0;
    for (int val :nums) {
        if (val == majority) {
            ++count;
        }
    }
    return count > nums.size() / 2 ? majority : 0;
}

void Code_Thinking::local_main_more_than_half_num() {

    auto main = new Code_Thinking();
    cout << main->more_than_half_num(vector<int>({1, 2, 3, 2, 2, 2, 5, 4, 2})) << endl;
}

int Code_Thinking::find_greatest_sum_of_subarray(vector<int> array) {

    if (array.empty()) {
        return 0;
    }
    int greatest = numeric_limits<int>::min();
    int sum = 0;
    for (int val:array) {
        sum = sum < 0 ? val : sum + val;
        greatest = max(greatest, sum);
    }
    return greatest;
}

void Code_Thinking::local_main_find_greatest_sum_of_subarray() {

    auto main = new Code_Thinking();
    cout << main->find_greatest_sum_of_subarray(vector<int>({6, -3, -2, 7, -15, 1, 2, 2})) << endl;
}

int Code_Thinking::count_digit_one(int n) {

    if (n <= 0) {
        return 0;
    }
    int q = n, x = 1, ret = 0;
    do {
        int digit = q % 10;
        q /= 10;
        ret += q * x;
        if (digit == 1) ret += n % x + 1;
        if (digit > 1) ret += x;
        x *= 10;
    } while (q > 0);
    return ret;
}

int Code_Thinking::count_digit_one_std(int n) {
    int ret = 0;
    for (long long m = 1; m <= n; m *= 10)
        ret += (n / m + 8) / 10 * m + (n / m % 10 == 1) * (n % m + 1);
    return ret;
}

void Code_Thinking::local_main_count_digit_one() {

    auto main = new Code_Thinking();
    cout << main->count_digit_one(101) << endl;
    cout << main->count_digit_one_std(101) << endl;
}

string Code_Thinking::print_min_num(vector<int> nums) {

    string ret;
    if (nums.empty()) {
        return ret;
    }
    sort(nums.begin(), nums.end(), str_cmp);
    for (int num : nums) {
        ret += to_string(num);
    }
    return ret;
}

bool Code_Thinking::str_cmp(int a, int b) {
    return to_string(a) + to_string(b) < to_string(b) + to_string(a);
}

void Code_Thinking::local_main_print_min_num() {

    auto main = new Code_Thinking();
    cout << main->print_min_num(vector<int>({3, 32, 321})) << endl;
}

int Code_Thinking::num_decoding_dp(string s) {

    unsigned long n = s.length();
    if (0 == n) return 0;
    int *dp = new int[n + 1];
    //for(int i = 0; i <= n;i++) dp[i] = 0; //LeetCode默认不为0
    dp[0] = 1;
    dp[1] = s.at(0) == '0' ? 0 : 1;
    for (unsigned long i = 2; i <= n; ++i) {
        if (s.at(i - 1) != '0') {
            dp[i] += dp[i - 1];
        }
        if (s.at(i - 2) != '0') {
            if (stoi(s.substr(i - 2, 2)) <= 26) {
                dp[i] += dp[i - 2];
            }
        }
    }
    return dp[n];
}

int Code_Thinking::num_decoding_bt(string s) {

    if (s.empty()) {
        return 0;
    }
    int count = 0;
    backtracking_num_decoding_bt(s, count);
    return count;
}

void Code_Thinking::backtracking_num_decoding_bt(string s, int &count) {

    if (s.length() >= 1 && '0' == s.at(0)) {
        return;
    }
    unsigned long n = s.length();
    if (1 == n || 0 == n) {
        count++;
        return;
    }
    if ('1' == s.at(0) || ('2' == s.at(0) && '6' >= s.at(1))) {
        if ('0' != s.at(1)) {
            backtracking_num_decoding_bt(s.substr(1, n - 1), count);
        }
        backtracking_num_decoding_bt(s.substr(2, n - 2), count);
    } else {
        backtracking_num_decoding_bt(s.substr(1, n - 1), count);
    }
}

void Code_Thinking::local_main_num_decoding() {

    auto main = new Code_Thinking();
    cout << main->num_decoding_dp("0") << endl
         << main->num_decoding_dp("110") << endl
         << main->num_decoding_dp("27") << endl
         << main->num_decoding_dp("226") << endl
         << main->num_decoding_dp("111") << endl;

    cout << main->num_decoding_bt("0") << endl
         << main->num_decoding_bt("110") << endl
         << main->num_decoding_bt("27") << endl
         << main->num_decoding_bt("226") << endl
         << main->num_decoding_bt("226") << endl;
}

int Code_Thinking::longest_substr_no_dup(string str) {

    unsigned long n = str.length();
    if (0 == n || 1 == n) {
        return static_cast<int>(n);
    }
    bool *exist = new bool[26]{};
    int longest = 0, now = 1;
    exist[str.at(0) - 'a'] = true;

    for (unsigned long i = 0, j = 1; j < n; ++j) {
        if (exist[str.at(j) - 'a']) {
            while (str.at(i) != str.at(j)) {
                exist[str.at(i++) - 'a'] = false;
                now -= 1;
            }
            ++i;
        } else {
            exist[str.at(j) - 'a'] = true;
            ++now;
        }
        longest = max(longest, now);
    }
    return longest;
}

void Code_Thinking::local_main_longest_substr_no_dup() {

    auto main = new Code_Thinking();
    cout << main->longest_substr_no_dup("") << endl
         << main->longest_substr_no_dup("a") << endl
         << main->longest_substr_no_dup("aa") << endl
         << main->longest_substr_no_dup("aaa") << endl
         << main->longest_substr_no_dup("aba") << endl
         << main->longest_substr_no_dup("arabcacfr") << endl;
}

int Code_Thinking::get_ugly_num(int index) {

    if (index < 7) {
        return index;
    }
    int p2 = 0, p3 = 0, p5 = 0, now = 1;
    vector<int> ugly = {now};
    while (ugly.size() < index) {
        now = min(ugly[p2] * 2, min(ugly[p3] * 3, ugly[p5] * 5));
        if (ugly[p2] * 2 == now) p2++;
        if (ugly[p3] * 3 == now) p3++;
        if (ugly[p5] * 5 == now) p5++;
        ugly.push_back(now);
    }
    return now;
}

void Code_Thinking::local_main_get_ugly_num() {

    auto main = new Code_Thinking();
    for (int i = 1; i < 15; ++i) {
        cout << main->get_ugly_num(i) << endl;
    }
}

int Code_Thinking::first_not_repeat_char_index(string str) {//以上实现的空间复杂度还不是最优的。
    // 考虑到只需要找到只出现一次的字符，那么需要统计的次数信息只有 0,1,更大，使用两个比特位就能存储这些信息。

    map<char, int> mp;
    for (char i : str) {
        mp[i]++;
    }
    for (int i = 0; i < str.length(); ++i) {
        if (mp[str[i]] == 1) {
            return i;
        }
    }
    return -1;
}

void Code_Thinking::local_main_first_not_repeat_char_index() {

    auto main = new Code_Thinking();
    cout << main->first_not_repeat_char_index("eeggsregagage") << endl;
}

int Code_Thinking::inverse_pairs(vector<int> data) {

    if (data.empty()) {
        return 0;
    }
    vector<int> copy(data);
    return backtracking_inverse_pairs(data, copy, 0, static_cast<int>(data.size() - 1));
}

int Code_Thinking::backtracking_inverse_pairs(vector<int> &data, vector<int> &copy, int low, int high) {

    if (low == high) {
        return 0;
    }
    int mid = (low + high) >> 1;
    int left_count = backtracking_inverse_pairs(data, copy, low, mid);
    int right_count = backtracking_inverse_pairs(data, copy, mid + 1, high);
    int i = mid, j = high, k = high, count = 0;

    while (i >= low && j > mid) {
        if (data[i] > data[j]) {
            count += (j - mid);
            if (count >= 1000000007) {
                count %= 1000000007;
            }
            copy[k--] = data[i--];
        } else {
            copy[k--] = data[j--];
        }
    }
    while (i >= low) copy[k--] = data[i--];
    while (j > mid) copy[k--] = data[j--];
    for (int l = low; l < high; ++l) data[l] = copy[l];

    return (left_count + right_count + count) % 1000000007;
}

void Code_Thinking::local_main_inverse_pairs() {

    auto main = new Code_Thinking();
    cout << main->inverse_pairs(vector<int>({1, 2, 3, 4, 5, 6, 7, 0})) << endl;//7
}

int Code_Thinking::get_count_of_k(vector<int> data, int k) {
    /*if (data.empty()) {
        return 0;
    }*/
    int first = bs_get_count_of_k(data, k);
    int last = bs_get_count_of_k(data, k + 1);
    return (first == data.size() || data[first] != k) ? 0 : last - first;
    //  当data.empty时 防止访问越界|| 当数组中不含k时
    //  当数组全小于k时
}

int Code_Thinking::bs_get_count_of_k(vector<int> &data, int k) {//找到最小的不小于k的index

    int low = 0, high = static_cast<int>(data.size());//不为size-1， 是由于可能data[size-1]==k, 获取last时错误
    while (low < high) {
        int mid = (low + high) / 2;
        if (data[mid] >= k) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int Code_Thinking::get_count_of_k_stl(vector<int> data, int k) {

    auto pair = equal_range(data.begin(), data.end(), k);
    return static_cast<int>(pair.second - pair.first);
}

//因为data中都是整数，所以可以稍微变一下，不是搜索k的两个位置，而是搜索k-0.5和k+0.5
//这两个数应该插入的位置，然后相减即可。
/*class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return biSearch(data, k+0.5) - biSearch(data, k-0.5) ;
    }
private:
    int biSearch(const vector<int> & data, double num){
        int s = 0, e = data.size()-1;
        while(s <= e){
            int mid = (e - s)/2 + s;
            if(data[mid] < num)
                s = mid + 1;
            else if(data[mid] > num)
                e = mid - 1;
        }
        return s;
    }
};*/
void Code_Thinking::local_main_get_count_of_k() {

    auto main = new Code_Thinking();
    cout << main->get_count_of_k(vector<int>({1, 2, 3, 3, 3, 3, 4, 6}), 3) << endl;
    cout << main->get_count_of_k_stl(vector<int>({1, 2, 3, 3, 3, 3, 4, 6}), 3) << endl;
}

vector<pair<int, double>> Code_Thinking::dices_sum(int n) {

    vector<pair<int, double>> ret;
    vector<vector<double>> f(static_cast<unsigned long>(n + 1),
                             vector<double>(static_cast<unsigned long>(6 * n + 1)));
    for (int i = 1; i <= 6; ++i) {
        f[1][i] = 1.0 / 6;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= 6 * i; ++j) {
            for (int k = 1; k <= 6; ++k) {
                if (j > k) f[i][j] += f[i - 1][j - k];
            }
            f[i][j] /= 6.0;
        }
    }
    for (int i = n; i <= 6 * n; ++i) {
        ret.emplace_back(i, f[n][i]);
    }
    return ret;
}

void Code_Thinking::local_main_dices_sum() {

    auto main = new Code_Thinking();
    auto ret = main->dices_sum(4);
    for (auto &i : ret) {
        cout << "[" << i.first << "," << i.second << "], ";
    }

}

int Code_Thinking::last_remaining(int n, int m) {

    if (n == 0) return -1;
    if (n == 1) return 0;
    return (last_remaining(n - 1, m) + m) % n;
}

void Code_Thinking::local_main_last_remaining() {

    auto main = new Code_Thinking();
    cout << main->last_remaining(4, 2) << endl;
}

int Code_Thinking::max_profit(vector<int> prices) {

    if (prices.size() <= 1) {
        return 0;
    }
    int so_far_min = prices[0], max_profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
        so_far_min = min(so_far_min, prices[i]);
        max_profit = max(max_profit, prices[i] - so_far_min);
    }
    return max_profit;
}

void Code_Thinking::local_main_max_profit() {

    auto main = new Code_Thinking();
    cout << main->max_profit(vector<int>({7, 1, 5, 3, 6, 4})) << endl;
}

int Code_Thinking::sum(int n) {

    int s = n;
    n > 0 && (s += sum(n - 1));
    return s;
}

int Code_Thinking::sum_II(int n) {

    char a[n][n + 1];
    return sizeof(a) >> 1;
}

void Code_Thinking::local_main_sum() {

    auto main = new Code_Thinking();
    cout << main->sum(4) << endl;
    cout << main->sum_II(4) << endl;

}

vector<int> Code_Thinking::multiply(const vector<int> &A) {

    vector<int> ret;
    int size = static_cast<int>(A.size());
    if (0 == size) {
        return ret;
    }
    ret.push_back(1);
    for (int i = 1; i < size; ++i) {
        ret.push_back(ret.back() * A[i - 1]);
    }
    int tmp = 1;
    for (int j = size - 1; j >= 0; --j) {
        ret[j] *= tmp;
        tmp *= A[j];
    }
    return ret;
}

void Code_Thinking::local_main_multiply() {

    auto main = new Code_Thinking();
    Utility::print_vector(main->multiply(vector<int>({1, 2, 3, 4, 5, 6})));
}

int Code_Thinking::str2int(string str) {

    int n = static_cast<int>(str.length());
    if (0 == n) return 0;
    int ret = 0;
    bool is_negative = str[0] == '-';
    for (int i = 0; i < n; ++i) {
        char c = str[i];
        if (0 == i && ('+' == c || '-' == c)) continue;
        if ('0' > c || '9' < c) return 0;
        ret = ret * 10 + (c - '0');
    }
    return is_negative ? -ret : ret;
}

void Code_Thinking::local_main_str2int() {

    auto main = new Code_Thinking();
    cout << main->str2int("+3453465") << endl;
}
