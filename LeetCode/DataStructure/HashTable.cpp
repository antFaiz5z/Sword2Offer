//
// Created by Faiz on 2019/1/9 0009.
//

#include "HashTable.h"

#include <unordered_map>
#include <unordered_set>
#include <algorithm>

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



    return vector<vector<int>>();
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

vector<vector<int>> HashTable::kSum(vector<int> &nums, int target) {
    return vector<vector<int>>();
}
