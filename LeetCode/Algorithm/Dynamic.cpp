//
// Created by Faiz on 2019/7/9 0009.
//

#include "Dynamic.h"


int Dynamic::uniquePaths(int m, int n) {

    if (m > n) {
        m = m + n;
        n = m - n;
        m = m - n;
    }
    int a[m][n];
    for (int i = 0; i < n; ++i) {
        a[0][i] = 1;
    }
    for (int i = 1; i < m; ++i) {
        for (int j = i; j < n; ++j) {
            if (i == j) {
                a[i][j] = 2 * a[i - 1][j];
            } else {
                a[i][j] = a[i - 1][j] + a[i][j - 1];
            }

        }
    }
    return a[m - 1][n - 1];

}

int Dynamic::uniquePathsII(int m, int n) {

    vector<int> pre(n, 1);
    vector<int> cur = pre;
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            cur[j] = pre[j] + cur[j - 1];
        }
        pre = cur;
    }

    return cur[n - 1];
}

int Dynamic::uniquePathsIII(int m, int n) {

    vector<int> a(n, 1);
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            a[j] += a[j - 1];
        }
    }
    return a[n - 1];
}

int Dynamic::uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {

    if (obstacleGrid[0][0]) return 0;

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<int> a(n);
    a[0] = 1;
    for (int j = 1; j < n; ++j) {
        a[j] = a[j - 1] ? 1 - obstacleGrid[0][j] : 0;
    }
    for (int i = 1; i < m; ++i) {
        if (obstacleGrid[i][0] || !a[0]) {
            a[0] = 0;
        }
        for (int j = 1; j < n; ++j) {
            a[j] = obstacleGrid[i][j] ? 0 : a[j] + a[j - 1];
        }
    }
    return a[n - 1];
}

int Dynamic::uniquePathsWithObstaclesII(vector<vector<int>> &obstacleGrid) {

    int R = obstacleGrid.size();
    int C = obstacleGrid[0].size();

    // If the starting cell has an obstacle, then simply return as there would be
    // no paths to the destination.
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }

    // Number of ways of reaching the starting cell = 1.
    obstacleGrid[0][0] = 1;

    // Filling the values for the first column
    for (int i = 1; i < R; i++) {
        obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1 : 0;
    }

    // Filling the values for the first row
    for (int i = 1; i < C; i++) {
        obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) ? 1 : 0;
    }

    // Starting from cell(1,1) fill up the values
    // No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
    // i.e. From above and left.
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {
            if (obstacleGrid[i][j] == 0) {
                obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            } else {
                obstacleGrid[i][j] = 0;
            }
        }
    }

    // Return value stored in rightmost bottommost cell. That is the destination.
    return obstacleGrid[R - 1][C - 1];
}

bool Dynamic::wordBreak(string s, vector<string> &wordDict) {

    unordered_set<string> t(wordDict.begin(), wordDict.end());
    bool dp[s.size() + 1];
    for (int i = 0; i <= s.size(); ++i) {
        dp[i] = false;
    }
    dp[0] = true;
    //或者 bool dp[s.size() + 1]{true}; //IDE不通过
    for (int i = 1; i <= s.size(); ++i) {

        for (int j = 0; j < i; ++j) {
            if (dp[j] && t.find(s.substr(j, i - j)) != t.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

vector<string> Dynamic::wordBreak2(string s, vector<string> &wordDict) {

    unordered_set<string> t(wordDict.begin(), wordDict.end());
    vector<vector<string>> dp(s.size() + 1);
    dp[0].push_back("");

    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (!dp[j].empty() && t.find(s.substr(j, i - j)) != t.end()) {
                for (auto &k : dp[j]) {
                    dp[i].push_back(k + (k.empty() ? "" : " ") + s.substr(j, i - j));
                }
            }
        }
    }
    return dp[s.size()];
}

vector<string> Dynamic::wordBreak2II(string s, vector<string> &wordDict) {

    unordered_set<string> t(wordDict.begin(), wordDict.end());
    unordered_map<int, vector<string>> m;

    return wordBreak2II_bt(s, t, m, 0);
}

vector<string>
Dynamic::wordBreak2II_bt(string s, unordered_set<string> &t, unordered_map<int, vector<string>> &m, int index) {

    if (m.count(index)) {
        return m[index];
    }
    vector<string> ret;
    if (index == s.size()) {
        ret.emplace_back("");
    }
    for (int i = index + 1; i <= s.size(); ++i) {

        if (t.count(s.substr(index, i - index))) {
            vector<string> tmp = wordBreak2II_bt(s, t, m, i);
            for (auto &j : tmp) {
                ret.push_back(s.substr(index, i - index) + (j.empty() ? "" : " ") + j);
            }
        }
    }
    m[index] = ret;
    return ret;
}

int Dynamic::rob(vector<int> &nums) {

    int n = nums.size();
    if (n == 0) return 0;
    int dp[n];
    dp[0] = nums[0];
    if (n >= 2)
        dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
        dp[i] = max(nums[i] + dp[i - 2], nums[i - 1]);
    }
    return dp[n - 1];
}

int Dynamic::numSquares(int n) {

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; i + j * j <= n; ++j) {
            dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
        }
    }
    return dp.back();
}

int Dynamic::numSquaresIIbfs(int n) {

    if (n == 0) return 0;
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    vector<bool> visited(n + 1, false);
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        visited[now.first] = true;
        for (int i = 1; now.first - i * i >= 0; ++i) {
            if (now.first - i * i == 0) {
                return now.second + 1;
            }
            if (!visited[now.first - i * i]) {
                q.push(make_pair(now.first - i * i, now.second + 1));
            }
        }
    }
    return 0;
}

int Dynamic::lengthOfLIS(vector<int> &nums) {

    int n = nums.size();
    if (n <= 1) return n;
    int dp[n];
    dp[0] = 1;
    int ret = 1;
    for (int i = 1; i < n; ++i) {
        int m = 0;
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                m = max(m, dp[j]);
            }
        }
        dp[i] = m + 1;
        ret = max(ret, dp[i]);
    }
    return ret;
}

int Dynamic::maxEnvelopes(vector<vector<int>> &envelopes) {

    int size = envelopes.size();
    if (size < 2) return size;
    int ret = 0;
    int dp[size];
    dp[0] = 1;
    sort(envelopes.begin(), envelopes.end(), [this](vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] <= b[1];
        } else return a[0] <= b[0];
        //return a[0] <= b[0] && a[1] <= b[1];
    });
/*    for (auto &i : envelopes){
        for (auto &j : i){
            cout << j << ",";
        }
        cout << endl;
    }*/
    for (int i = 1; i < size; ++i) {
        int ma = 0;
        for (int j = 0; j < i; ++j) {
            if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]){
                ma = max(ma, dp[j]);
            }
        }
        dp[i] = ma +1;
        ret = max(ret, dp[i]);
    }
    return ret;
}

int Dynamic::coinChange(vector<int> &coins, int amount) {

    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (auto &j : coins) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int Dynamic::longestIncreasingPath(vector<vector<int>> &matrix) {

    int row = matrix.size();
    if (row == 0) return 0;
    int col = matrix[0].size();
    vector<vector<int>> count(row, vector<int>(col, 1));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            helper(matrix, count, i, j);
        }
    }
    int ret = 0;
    for (auto &i : count) {
        for (auto &j : i) {
            ret = max(ret, j);
        }
    }
    return ret;
}

void Dynamic::helper(vector<vector<int>> &matrix, vector<vector<int>> &count, int x, int y) {

    int row = matrix.size();
    int col = matrix[0].size();
    if (x - 1 >= 0 && matrix[x - 1][y] > matrix[x][y]) {
        if (count[x - 1][y] < count[x][y] + 1) {
            count[x - 1][y] = count[x][y] + 1;
            helper(matrix, count, x - 1, y);
        }
    }
    if (y - 1 >= 0 && matrix[x][y - 1] > matrix[x][y]) {
        if (count[x][y - 1] < count[x][y] + 1) {
            count[x][y - 1] = count[x][y] + 1;
            helper(matrix, count, x, y - 1);
        }
    }
    if (x + 1 < row && matrix[x + 1][y] > matrix[x][y]) {
        if (count[x + 1][y] < count[x][y] + 1) {
            count[x + 1][y] = count[x][y] + 1;
            helper(matrix, count, x + 1, y);
        }
    }
    if (y + 1 < col && matrix[x][y + 1] > matrix[x][y]) {
        if (count[x][y + 1] < count[x][y] + 1) {
            count[x][y + 1] = count[x][y] + 1;
            helper(matrix, count, x, y + 1);
        }
    }
}
