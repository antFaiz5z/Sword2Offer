//
// Created by Faiz on 2019/5/31 0031.
//

#ifndef SWORD2OFFER_BACKTRACKING_H
#define SWORD2OFFER_BACKTRACKING_H

#include <vector>

using namespace std;

class Backtracking {
public:

    //89
    void grayCodeHelper(vector<int> &ret, unsigned int *now, unsigned int n);

    vector<int> grayCode(int n);
    vector<int> grayCodeII(int n);


};


#endif //SWORD2OFFER_BACKTRACKING_H
