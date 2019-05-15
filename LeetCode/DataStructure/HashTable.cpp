//
// Created by Faiz on 2019/1/9 0009.
//

#include "HashTable.h"

#include <unordered_map>
#include <unordered_set>

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
    int ans = 0;
    int lastRepeat = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (map.find(s[i]) != map.end() && lastRepeat < map[s[i]]){
            lastRepeat = map[s[i]];
        }
        ans = max(ans, i - lastRepeat);
        map[s[i]] = i;
    }
    return ans;
}

int HashTable::lengthOfLongestSubstringII(string s) {

    
    return 0;
}
