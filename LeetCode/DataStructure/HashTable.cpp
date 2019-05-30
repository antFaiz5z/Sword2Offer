//
// Created by Faiz on 2019/1/9 0009.
//

#include "HashTable.h"

#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>

#include <iostream>

using namespace std;

vector<int> HashTable::twoSum(vector<int> &nums, int target) {

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return vector<int>{i, j};
            }
        }
    }
    return vector<int>();
}

vector<int> HashTable::twoSum_hashI(vector<int> &nums, int target) {

    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        map.insert(unordered_map<int, int>::value_type(nums[i], i));
    }
    for (int i = 0; i < nums.size(); ++i) {
        int tmp = target - nums[i];
        if (map.find(tmp) != map.end() && map[tmp] != i) {
            return vector<int>{map.at(tmp), i};
        }
    }
    return vector<int>();
}

vector<int> HashTable::twoSum_hashII(vector<int> &nums, int target) {

    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        int tmp = target - nums[i];
        if (map.find(tmp) != map.end() && map[tmp] != i) {
            return vector<int>{map.at(tmp), i};
        }
        map.insert(pair<int, int>{nums[i], i});
    }
    return vector<int>();
}

int HashTable::lengthOfLongestSubstring(string s) {

    unordered_map<char, int> map;
    int ret = 0;
    for (int i = -1, j = 0; j < s.size(); ++j) {
        if (map.find(s[j]) != map.end()) {
            i = max(i, map[s[j]]);
        }
        //or
        /*if (map.find(s[j]) != map.end() && i < map[s[j]]){
            i = map[s[j]];
        }*/
        ret = max(ret, j - i);
        map[s[j]] = j;
    }
    return 0;
}

int HashTable::lengthOfLongestSubstringII(string s) {

    int index[128]{};//0
    int ret = 0;
    //error
    /*for (int i = -1, j = 0; j < s.size(); ++j) {
        i = max(i, index[s[j]]);
        ret = max(ret, j - i);
        index[s[j]] = j;
    }*/
    for (int i = 0, j = 0; j < s.size(); ++j) {
        i = max(i, index[s[j]]);
        ret = max(ret, j - i + 1);
        index[s[j]] = j + 1;
    }
    return ret;
}

vector<vector<int>> HashTable::fourSum(vector<int> &nums, int target) {

    vector<vector<int>> ret;
    if (nums.size() < 4) return ret;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        vector<int> tmp(nums.begin() + i + 1, nums.end());
        vector<vector<int>> re = threeSum(tmp, target - nums[i]);
        for (auto &j : re) {
            j.push_back(nums[i]);
            ret.push_back(j);
        }
    }
    return ret;
}

vector<vector<int>> HashTable::threeSum(vector<int> &nums, int target) {

    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int low, high, a, b, c;
    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        low = i + 1;
        high = n - 1;
        a = nums[i];
        while (low < high) {
            b = nums[low];
            c = nums[high];
            if (a + b + c == target) {
                ret.push_back(vector<int>{a, b, c});
                while (low < high && nums[low] == nums[low + 1]) ++low;
                ++low;
                while (low < high && nums[high] == nums[high - 1]) --high;
                --high;
            } else if (a + b + c < target) {
                while (low < high && nums[low] == nums[low + 1]) ++low;
                ++low;
            } else {
                while (low < high && nums[high] == nums[high - 1]) --high;
                --high;
            }
        }
    }
    return ret;
}

//FIXME: return empty
vector<vector<int>> HashTable::kSum(vector<int> &nums, int target, int k, int start) {

    vector<vector<int>> ret;
    int n = nums.size();
    if (start >= n - k) return ret;
    sort(nums.begin(), nums.end());
    if (k == 2) {
        int low = start + 1;
        int high = n - 1;
        while (low < high) {
            if (nums[low] + nums[high] == target) {
                ret.push_back(vector<int>{nums[low], nums[high]});
                while (low < high && nums[low] == nums[low + 1]) ++low;
                while (low < high && nums[high] == nums[high - 1]) --high;
                ++low;
                --high;
            } else if (nums[low] + nums[high] < target) {
                while (low < high && nums[low] == nums[low + 1]) ++low;
                ++low;
            } else {
                while (low < high && nums[high] == nums[high - 1]) --high;
                --high;
            }
        }
        return ret;
    }
    if (k > 2) {
        for (int i = start; i < n - k; ++i) {
            vector<vector<int>> tmp = kSum(nums, target - nums[i], k - 1, start + 1);
            if (!tmp.empty()) {
                for (auto &j : tmp) {
                    j.insert(j.begin(), nums[i]);
                    ret.push_back(j);
                }
            }
            while (i < n - k && nums[i] == nums[i + 1]) ++i;
        }
    }
    return ret;
}

int HashTable::fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {

    //NOTICE: map 使用 operator[] 时，value 初始为 0
    int ret = 0;
    map<int, int> map;
    for (auto &i : A) {
        for (auto &j : B) {
            ++map[i + j];

        }
    }
    for (auto &i : C) {
        for (auto &j : D) {
            if (map.find(-i - j) != map.end()) {
                ret += map[-i - j];
            }
        }
    }
    return ret;
}

//run out of time
vector<int> HashTable::findSubstring(string s, vector<string> &words) {

    vector<int> ret;
    if (words.empty()) return ret;

    int step = words[0].size();
    int size = words.size();
    map<string, int> m;
    for (auto &k : words) ++m[k];
    int j, count;

    for (int i = 0; i < s.size(); ++i) {
        map<string, int> tmp = m;
        j = i;
        count = size;

        while (j + step <= s.size()) {
            string sub = s.substr(j, step);
            if (tmp.find(sub) != tmp.end() && tmp[sub]) {
                --tmp[sub];
                j += step;
                if (--count == 0) {
                    ret.push_back(i);
                    break;
                }
            } else {
                break;
            }
        }
    }
    return ret;
}

vector<int> HashTable::findSubstringII(string s, vector<string> &words) {

    vector<int> result;
    if (s.empty() || words.empty()) {
        return result;
    }

    int n = s.size(), m = words.size(), l = words[0].size();

    //put all of words into a map
    map<string, int> expected;
    for (int i = 0; i < m; i++) {
        if (expected.find(words[i]) != expected.end()) {
            expected[words[i]]++;
        } else {
            expected[words[i]] = 1;
        }
    }

    for (int i = 0; i < l; i++) {
        map<string, int> actual;
        int count = 0; //total count
        int winLeft = i;
        for (int j = i; j <= n - l; j += l) {
            //if ((n -j) / l + count < m) break; //additional
            string word = s.substr(j, l);
            //if not found, then restart from j+1;
            if (expected.find(word) == expected.end()) {
                actual.clear();
                count = 0;
                winLeft = j + l;
                continue;
            }
            count++;
            //count the number of "word"
            if (actual.find(word) == actual.end()) {
                actual[word] = 1;
            } else {
                actual[word]++;
            }
            // If there is more appearance of "word" than expected
            if (actual[word] > expected[word]) {
                string tmp;
                do {
                    tmp = s.substr(winLeft, l);
                    count--;
                    actual[tmp]--;
                    winLeft += l;
                } while (tmp != word);
            }

            // if total count equals words's size, find one result
            if (count == m) {
                result.push_back(winLeft);
                string tmp = s.substr(winLeft, l);
                actual[tmp]--;
                winLeft += l;
                count--;
            }

        }
    }

    return result;
}

string HashTable::minWindow(string s, string t) { //FIXME: SOME ERROR

    string ret;
    int start = -1, now = 0;
    int m = s.size(), n = t.size();
    int count = n;
    int len = m +1;
    unordered_map<char, int> hm;

    for (auto &i : t) ++hm[i];
    while (hm.find(s[now]) == hm.end()) ++now;
    if (--hm[s[now]] == 0) --count;
    if (now + n > m) return ret;
    start = now++;
    while (now <= m) {
        if (count == 0) {
            if (now - start < len) {
                ret.clear();
                ret = s.substr(start, now - start);
                len = now - start;
            }
            if (hm[s[start]]++ == 0) ++count;
            ++start;
            while (hm.find(s[start]) == hm.end()) ++start;
            continue;
        }
        if (now == m) break;
        if (hm.find(s[now]) != hm.end()) {
            if (--hm[s[now]] == 0) --count;
        }
        ++now;
    }
    return ret;
}

string HashTable::minWindowII(string s, string t) {
    unordered_map<char, int> mp;
    for (char now : t) mp[now]++;
    int count = mp.size();
    int j = 0;
    int ans = numeric_limits<int>::max();
    string res;
    for (int i = 0; i < s.size(); i++) {
        while (count != 0 && j < s.size()) {
            if (--mp[s[j]] == 0) count--;
            j++;
            if (count == 0) break;
        }
        if (count == 0 && j - i < ans) {
            ans = j - i;
            res = s.substr(i, j - i);
        }
        if (mp[s[i]]++ == 0) count++;
    }
    return res;
}

