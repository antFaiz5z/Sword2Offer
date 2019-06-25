//
// Created by Faiz on 2019/5/31 0031.
//

#ifndef SWORD2OFFER_BACKTRACKING_H
#define SWORD2OFFER_BACKTRACKING_H

#include <vector>
#include <string>

using namespace std;

class Backtracking {
public:

    //89
    void grayCodeHelper(vector<int> &ret, unsigned int *now, unsigned int n);

    vector<int> grayCode(int n);

    vector<int> grayCodeII(int n);

    //51
    vector<vector<string>> solveNQueens(int n);

    void solveNQueens_backtracking(vector<vector<pair<int, int>>> &solutions, vector<pair<int, int>> &solution,
                                   int row, int n);

    bool isValid(vector<pair<int, int>> &solution, int row, int col);

    vector<vector<string>> draw(vector<vector<pair<int, int>>> &solutions, int n);

    //52
    int totalNQueens(int n);

    void totalNQueens_backtracking(vector<int> &queensInCol, int n, int row, int &sum);

    bool isValid(vector<int> &queensInCol, int row, int col);


};


#endif //SWORD2OFFER_BACKTRACKING_H
