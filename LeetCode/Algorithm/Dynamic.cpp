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
        a[j] = a[j -1]? 1 - obstacleGrid[0][j] : 0;
    }
    for (int i = 1; i < m; ++i) {
        if (obstacleGrid[i][0] || !a[0]){
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
    return 0;
}
