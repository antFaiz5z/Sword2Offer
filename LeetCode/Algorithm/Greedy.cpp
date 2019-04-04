//
// Created by Faiz on 2019/1/9 0009.
//

#include "Greedy.h"

#include <algorithm>

int Greedy::getContentChildren(vector<int> &g, vector<int> &s) {

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i, j;
    for (i = 0, j = 0; i < g.size() && j < s.size(); ++j) {
        if (g[i] <= s[j]) ++i;
    }
    return i;
}

int Greedy::eraseOverlapIntervals(vector<Interval> &intervals) {

    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.end < b.end; });
    int count = 1, end = 0;
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i].start < intervals[end].end) continue;
        ++count;
        end = i;
    }
    return static_cast<int>(intervals.size()) - count;
}

int Greedy::findMinArrowShots(vector<pair<int, int>> &points) {

    if (points.empty()) return 0;
    sort(points.begin(), points.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
    int count = 1, end = 0;
    for (int i = 1; i < points.size(); ++i) {
        if (points[i].first <= points[end].second) continue;
        ++count;
        end = i;
    }
    return count;
}

vector<pair<int, int>> Greedy::reconstructQueue(vector<pair<int, int>> &people) {

    sort(people.begin(), people.end(), [](pair<int, int> p1, pair<int, int> p2) {
        return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
    });
    vector<pair<int, int>> ret;
    for (auto &p : people) {
        ret.insert(ret.begin() + p.second, p);
    }
    return ret;
}

vector<int> Greedy::partitionLabels(string S) {

    int last[26];
    for (int i = 0; i < S.length(); ++i) {
        last[S[i] - 'a'] = i;
    }
    vector<int> ret;
    int right = 0, left = 0;
    for (int i = 0; i < S.length(); ++i) {
        right = max(right, last[S[i] - 'a']);
        if (i == right) {
            ret.push_back(right - left + 1);
            left = i + 1;
        }
    }
    return ret;
}

bool Greedy::canPlaceFlowers(vector<int> &flowerbed, int n) {

    int count = 0;
    for (int i = 0; i < flowerbed.size(); ++i) {
        if (flowerbed[i] == 0
            && (i == 0 || flowerbed[i - 1] == 0)
            && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1;
            ++count;
        }
    }
    return count >= n;
}

bool Greedy::isSubsequence(string s, string t) {

    if (s.empty()) return true;
    int index = 0;
    for (char i : t) {
        if (s[index] == i) {
            if (index == s.size() - 1) return true;
            ++index;
        }
    }
    return false;
}

bool Greedy::checkPossibility(vector<int> &nums) {

    if (nums.size() <= 2) return true;
    int count = 0, index = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] < nums[i - 1]) {
            index = i;
            if (++count > 1) return false;
        }
    }
    if (count == 0) {
        return true;
    } else {
        if ((index == 1 || nums[index - 2] <= nums[index])
            && (index == nums.size() - 1 || nums[index] <= nums[index + 1]))
            return true;
        if ((index == 1 || nums[index - 2] <= nums[index - 1])
            && (index == nums.size() - 1 || nums[index - 1] <= nums[index + 1]))
            return true;
    }
    return false;
}


bool Greedy::checkPossibilityII(vector<int> &nums) {

    int count = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] >= nums[i - 1]) continue;
        if (++count > 1) return false;
        if (i >= 2 && nums[i] < nums[i - 2]) {
            nums[i] = nums[i - 1];
        } else {
            nums[i - 1] = nums[i];
        }
    }
    return true;
}

int Greedy::maxProfit(vector<int> &prices) {

    if (prices.empty()) return 0;
    int buy = prices[0], sell = -1, profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
        if (sell < 0) {
            if (prices[i] <= buy) {
                buy = prices[i];
                continue;
            } else {
                sell = prices[i];
                if (i == prices.size() - 1) {
                    profit += (sell - buy);
                }
            }
        } else {
            if (prices[i] >= sell) {
                sell = prices[i];
                if (i == prices.size() - 1) {
                    profit += (sell - buy);
                }
            } else {
                profit += (sell - buy);
                buy = prices[i];
                sell = -1;
            }
        }
    }
    return profit;
}

int Greedy::maxProfitII(vector<int> &prices) {

    int profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
    }
    return profit;
}

int Greedy::maxSubArray(vector<int> &nums) {

    int ret = numeric_limits<int>::min(), now = 0;
    bool positive = false;
    for (int num : nums) {
        if (positive) {
            now += num;
            ret = max(ret, now);
            if (now < 0) {
                now = 0;
                positive = false;
            }
        } else {
            ret = max(ret, num);
            if (num > 0) {
                positive = true;
                now = num;
            }
        }
    }
    return ret;
}

int Greedy::maxSubArrayII(vector<int> &nums) {
    //sum记录前i个数的和，maxSum记录全局最大值，minSum记录前i个数中0-k的最小值
    int sum = 0, minSum = 0, maxSum = numeric_limits<int>::min();
    for (int num : nums) {
        sum += num;
        maxSum = max(maxSum, sum - minSum);
        minSum = min(minSum, sum);
    }
    return maxSum;
}

bool Greedy::canJump(vector<int> &nums) {

    int now = 1;
    for (int i = 1; i <= now; ++i) {
        if (now >= nums.size()) return true;
        //if (i == nums.size()) return true;
        now = max(now, i + nums[i - 1]);
    }
    return false;
}

int Greedy::jump(vector<int> &nums) {

    int count = 0, begin = 0, end = 0, new_end = 0, possible_end = 0;

    if (nums.size() == 1) return 0;
    while (begin <= end) {

        ++count;
        for (int i = begin; i <= end; ++i) {
            possible_end = i + nums[i];
            if (possible_end >= nums.size() - 1) {
                return count;
            }
            if (possible_end > end) {
                new_end = max(new_end, possible_end);
            }
        }
        begin = end + 1;
        end = new_end;
    }
    return 0;//"假设你总是可以到达数组的最后一个位置。"
}
