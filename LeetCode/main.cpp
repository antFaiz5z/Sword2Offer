//
// Created by Faiz on 2019/1/4 0004.
//

#include "Algorithm/DoublePointer.h"
#include "Algorithm/Greedy.h"

int main() {

    vector<string> d({"ale","apple","monkey","plea"});
    cout << DoublePointer::findLongestWord("abpcplea", d) << endl;

    return 0;
}