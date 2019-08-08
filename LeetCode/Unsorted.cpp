//
// Created by Faiz on 2019/6/30 0030.
//

#include "Unsorted.h"

#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> Unsorted::pathInZigZagTree(int label) {
    vector<int> ret;
    vector<vector<int>> seqs;
    int floor = 0;
    int direction = 0;
    int count = 0;
    int begin = 1, end = 1;
    int index = 0;
    while (count < label) {
        ++floor;
        vector<int> seq;
        begin = end;
        //end = 2 ^ floor;
        end = pow(2, floor);
        for (int i = begin; i < end; ++i) {
            seq.push_back(i);
            ++count;
        }
        if (direction) {
            ::reverse(seq.begin(), seq.end());
        }
        seqs.push_back(seq);
        direction = 1 - direction;
    }
    //vector<int> seq = seqs[floor -1];
    for (int i = 0; i < seqs[floor - 1].size(); ++i) {
        if (label == seqs[floor - 1][i]) {
            index = i;
            break;
        }
    }
    while (floor) {
        ret.push_back(seqs[--floor][index]);
        index /= 2;
    }
    ::reverse(ret.begin(), ret.end());
    return ret;

}

int Unsorted::reverse(int x) {

    int ret = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        //32位环境下，max=2147483647，min=-2147483648
        if (ret > numeric_limits<int>::max() / 10 || (ret == numeric_limits<int>::max() / 10 && pop > 7)) return 0;
        if (ret < numeric_limits<int>::min() / 10 || (ret == numeric_limits<int>::min() / 10 && pop < -8)) return 0;
        ret = ret * 10 + pop;
    }
    return ret;
}

bool Unsorted::add_overflow(int x, int y) {

    //cout << x  << "+" << y << "=" << x+y <<endl;
    return (x >= 0 && y >= 0 && x + y < 0) || (x < 0 && y < 0 && x + y >= 0);
}

int Unsorted::reverseII(int x) {

    int ret = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (ret > numeric_limits<int>::max() / 10 || ret < numeric_limits<int>::min() / 10 ||
            add_overflow(ret * 10, pop))
            return 0;
        ret = ret * 10 + pop;
    }
    return ret;
}

int Unsorted::myAtoi(string str) {

    int index = 0, ret = 0;
    bool flag = true;
    int n = str.size();
    while (index < n && str[index] == ' ') ++index;
    if (index < n && str[index] == '+') {
        ++index;
    } else if (index < n && str[index] == '-') {
        flag = false;
        ++index;
    }
    for (int i = index; i < n; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            int pop = str[i] - '0';
            if (flag &&
                (ret > numeric_limits<int>::max() / 10 || (ret == numeric_limits<int>::max() / 10 && pop > 7))) {
                return numeric_limits<int>::max();
            }
            if (!flag &&
                (-ret < numeric_limits<int>::min() / 10 ||
                 (-ret == numeric_limits<int>::min() / 10 && pop >= 8))) {//!!!
                return numeric_limits<int>::min();
            }
            ret = ret * 10 + pop;
            //cout << ret << " " << pop << endl
        } else {
            break;
        }
    }

    return flag ? ret : -ret;
}

bool Unsorted::isAnagram(string s, string t) {

    if (s.size() != t.size()) {
        return false;
    }
    multiset<char> set;
    for (auto &i : s) {
        set.insert(i);
    }
    for (auto &i : t) {
        if (set.find(i) != set.end()) {
            set.erase(set.find(i));
        } else {
            return false;
        }
    }
    return true;
}

int Unsorted::longestSubstring(string s, int k) {

    if (k <= 1) return s.size();
    if (s.size() < k) return 0;

    unordered_map<char, int> map;
    for (auto &i : s) {
        map[i]++;
    }
    int i = 0;
    while (i < s.size() && map[s[i]] >= k) ++i;
    if (i == s.size()) return i;

    int l = longestSubstring(s.substr(0, i), k);
    while (i < s.size() && map[s[i]] < k) ++i;
    int r = longestSubstring(s.substr(i), k);

    return max(l, r);
}

int Unsorted::maxPathSum(TreeNode *root) {

    int max_sum = INT_MIN;
    max_gain(root, max_sum);
    return max_sum;
}

int Unsorted::max_gain(TreeNode *root, int &max_sum) {

    if (root == nullptr) return 0;

    int left = max(max_gain(root->left, max_sum), 0);
    int right = max(max_gain(root->right, max_sum), 0);

    int new_sum = root->val + left + right;
    max_sum = max(max_sum, new_sum);

    return root->val + max(left, right);
}

int Unsorted::longestConsecutive(vector<int> &nums) {

    unordered_set<int> set(nums.begin(), nums.end());
    int ret = 0;
    for (auto &i : nums) {
        if (set.find(i - 1) == set.end()) {
            int now_num = i;
            int now_count = 1;
            while (set.find(++now_num) != set.end()) {
                ++now_count;
            }
            ret = max(ret, now_count);
        }
    }
    return ret;
}

bool Unsorted::validUtf8(vector<int> &data) {

    for (auto &i : data) {
        i &= 255;
    }
    for (unsigned long j = 0; j < data.size(); ++j) {

        if (data[j] >= 0 && data[j] <= 0x7f) {
            continue;
        } else if (data[j] >= 0xc0 && data[j] <= 0xdf) {
            for (int k = 0; k < 1; ++k) {
                ++j;
                if (j >= data.size() || data[j] < 0x80 || data[j] > 0xbf) {
                    return false;
                }
            }
        } else if (data[j] >= 0xe0 && data[j] <= 0xef) {
            for (int k = 0; k < 2; ++k) {
                ++j;
                if (j >= data.size() || data[j] < 0x80 || data[j] > 0xbf) {
                    return false;
                }
            }
        } else if (data[j] >= 0xf0 && data[j] <= 0xf7) {
            for (int k = 0; k < 3; ++k) {
                ++j;
                if (j >= data.size() || data[j] < 0x80 || data[j] > 0xbf) {
                    return false;
                }
            }
        } else {
            return false;
        }
    }
    return true;
}

bool Unsorted::validUtf8II(vector<int> &data) {

    int n = data.size();
    for (int i = 0; i < n; i++) {
        // 查找前缀1个数
        int ans = 0;
/*        int mask = 1 << 7;
        while (data[i] & mask){
            ++ans;
            mask >>= 1;
        }*/
        for (int j = 7; j >= 0; j--) {
            if ((data[i] >> j) & 1) ans++;
            else break;
        }
        if (ans == 0) continue;
        // 个数不能为1，不能大于4，不能超过数组长度
        if (ans == 1 || ans > 4 || i + ans > n) return false;
        // 依次判断前缀
        for (int j = 1; j < ans; j++) {
            if ((data[i + j] >> 6) != 2) return false;
        }
        i += ans - 1;
    }
    return true;
}

vector<string> Unsorted::restoreIpAddresses(string s) {


    vector<string> ret;
    vector<int> nums;

    restoreIpAddresses_bt(ret, s, nums, 0, 0);
    return ret;
}

void Unsorted::restoreIpAddresses_bt(vector<string> &ret, string &s, vector<int> &nums, int index, int count) {

    if (count == 4) {
        if (index != s.size()) {
            return;
        } else {
            string tmp;
            for (auto &i : nums) {
                tmp += to_string(i);
                tmp += '.';
            }
            tmp.pop_back();
            ret.push_back(tmp);
        }
    }

    for (int i = 0; i < 3 && index + i < s.size(); ++i) {
        int num = stoi(s.substr(index, i + 1));
        if (num >= 256) {
            return;
        } else {
            nums.push_back(num);
            cout << num << endl;
            restoreIpAddresses_bt(ret, s, nums, index + i + 1, count + 1);
            nums.pop_back();
        }
        if (s[index] == '0') break;
    }
}

string Unsorted::validIPAddress(string IP) {

    if (IP.empty()) return "Neither";
    int count = 0;
    bool last = false;
    bool error = false;
    string tmp(IP);
    while (!last) {
        string sub;
        unsigned long it = tmp.find_first_of('.');
        if (it == 0) break;
        if (it == string::npos) {
            sub = tmp;
            last = true;
        } else {
            sub = tmp.substr(0, it);
            if (it + 1 <= tmp.size() - 1)
                tmp = tmp.substr(it + 1);
            else break;
        }
        if (sub.size() > 3) break;
        if (sub != "0" && sub[0] == '0') break;
        for (auto &c : sub) {
            if (c < '0' || c > '9') {
                error = true;
                break;
            }
        }
        if (error) break;
        if (stoi(sub) >= 256) break;
        ++count;
        if (count > 4) break;
        if (count == 4 && last) return "IPv4";
    }
    count = 0;
    last = false;
    tmp = IP;
    error = false;
    while (!tmp.empty()) {
        string sub;
        unsigned long it = tmp.find_first_of(':');
        if (it == 0) break;
        if (it == string::npos) {
            sub = tmp;
            last = true;
        } else {
            sub = tmp.substr(0, it);
            if (it + 1 <= tmp.size() - 1)
                tmp = tmp.substr(it + 1);
            else break;
        }
        if (sub.size() > 4) break;
        for (auto &c: sub) {
            if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) {
                error = true;
                break;
            }
        }
        if (error) break;
        ++count;
        if (count > 8) break;
        if (last && count == 8) return "IPv6";
    }
    return "Neither";
}


string Unsorted::validIPAddressII(string IP) {
    if (isValidIPv4(IP)) return "IPv4";
    if (isValidIPv6(IP)) return "IPv6";
    return "Neither";
}

// 优雅的split
void Unsorted::split(const string& s, vector<string> &vs, const char delim) {
    istringstream iss(s);
    string temp;
    while (getline(iss, temp, delim)) {
        vs.emplace_back(move(temp));
    }
    if (!s.empty() && s.back() == delim)
        vs.emplace_back();
    //加这句的原因是getline不会识别最后一个delim,避免误判"172.16.254.1.","2001:0db8:85a3:0:0:8A2E:0370:7334:"之类的情况
}

// 判定是否IPv4
bool Unsorted::isValidIPv4(const string& IP) {
    vector<string> vs;
    split(IP, vs, '.');
    if (vs.size() != 4) return false;
    for (auto &v:vs) {
        if (v.empty() || (v.size() > 1 && v[0] == '0') || v.size() > 3) return false;
        for (auto c:v) {
            if (!isdigit(c)) return false;
        }
        int n = stoi(v);
        if (n < 0 || n > 255) return false;
    }
    return true;
}

// 判定是否IPv6
bool Unsorted::isValidIPv6(const string& IP) {
    vector<string> vs;
    split(IP, vs, ':');
    if (vs.size() != 8) return false;
    for (auto &v:vs) {
        if (v.empty() || v.size() > 4) return false;
        for (auto c:v) {
            if (!(isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) return false;
        }
    }
    return true;
}
