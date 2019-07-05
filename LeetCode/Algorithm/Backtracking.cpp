//
// Created by Faiz on 2019/5/31 0031.
//

#include "Backtracking.h"

void Backtracking::grayCodeHelper(vector<int> &ret, unsigned int *now, unsigned int n) {
    if (n == 1) {
        *now = *now ^ 1;
        ret.push_back(*now);
        return;
    }
    grayCodeHelper(ret, now, n >> 1);
    *now = *now ^ n;
    ret.push_back(*now);
    grayCodeHelper(ret, now, n >> 1);

}

vector<int> Backtracking::grayCode(int n) {

    unsigned int now = 0;
    vector<int> ret{0};
    if (n > 0) grayCodeHelper(ret, &now, 1 << n - 1);
    return ret;
}

vector<int> Backtracking::grayCodeII(int n) {
    vector<int> result(1 << n);
    for (size_t i = 0; i < (1 << n); i++)
        result[i] = i ^ (i >> 1);
    return result;
}

vector<vector<string>> Backtracking::solveNQueens(int n) {

    vector<vector<pair<int, int>>> solutions;
    vector<pair<int, int>> solution;

    solveNQueens_backtracking(solutions, solution, 0, n);

    return draw(solutions, n);
}

void
Backtracking::solveNQueens_backtracking(vector<vector<pair<int, int>>> &solutions, vector<pair<int, int>> &solution,
                                        int row, int n) {

    if (row == n) solutions.push_back(solution);
    for (int col = 0; col < n; ++col) {
        if (isValid(solution, row, col)) {
            solution.emplace_back(row, col);
            solveNQueens_backtracking(solutions, solution, row + 1, n);
            solution.pop_back();
        }
    }
}

bool Backtracking::isValid(vector<pair<int, int>> &solution, int row, int col) {

    for (pair<int, int> &i : solution)
        if (i.first == row || i.second == col || i.first + i.second == row + col || i.first - i.second == row - col)
            return false;
    return true;
}

vector<vector<string>> Backtracking::draw(vector<vector<pair<int, int>>> &solutions, int n) {

    string stmp(n, '.');
    vector<string> tmp(n, stmp);
    vector<vector<string>> ret;
    for (vector<pair<int, int>> &solution : solutions) {
        vector<string> one(tmp);
        for (pair<int, int> &i : solution) {
            one[i.first][i.second] = 'Q';
        }
        ret.push_back(one);
    }
    return ret;
}

int Backtracking::totalNQueens(int n) {

    vector<int> queensInCol(n);
    int sum = 0;

    totalNQueens_backtracking(queensInCol, n, 0, sum);
    return sum;
}

void Backtracking::totalNQueens_backtracking(vector<int> &queensInCol, int n, int row, int &sum) {

    if (row == n) {
        sum += 1;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (isValid(queensInCol, row, i)) {
            queensInCol[row] = i;
            totalNQueens_backtracking(queensInCol, n, row + 1, sum);
        }
    }
}

bool Backtracking::isValid(vector<int> &queensInCol, int row, int col) {

    for (int i = 0; i < row; ++i) {
        if (queensInCol[i] == col || abs(i - row) == abs(queensInCol[i] - col)) return false;
    }
    return true;
}



