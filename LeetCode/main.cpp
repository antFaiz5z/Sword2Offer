//
// Created by Faiz on 2019/1/4 0004.
//

#include "Algorithm/Bit.h"
#include "Algorithm/DoublePointer.h"
#include "Algorithm/Sort.h"
#include "Algorithm/Greedy.h"
#include "DataStructure/Map.h"
#include "DataStructure/TrieTree.h"
#include "DataStructure/HashTable.h"

int main() {

    //vector<string> d({"ale","apple","monkey","plea"});
    //cout << DoublePointer::findLongestWord("abpcplea", d) << endl;

    HashTable ht;
/*    vector<int> nums{2, 7, 11, 15};
    vector<int> ret = ht.twoSum_hashI(nums, 9);
    for (auto &i : ret) cout << i << endl;
    ret = ht.twoSum_hashII(nums, 9);
    for (auto &i : ret) cout << i << endl;
    vector<vector<int>> res = ht.kSum(nums, 9, 2, 0);
    cout << (res.empty() ? "empty" : "y")  << endl;
    for (auto &i : res) {
        for (auto &j : i) {
            cout << j << ", ";
        }
        cout << endl;
    }*/

    string a = "ADSFGBDFGCFGBFDGADFGBVBFDGAACDFGBA";
    string b = "ABC";
    cout << ht.minWindow(a, b) << endl;
    a = "a";
    b = "a";
    cout << ht.minWindow(a, b) << endl;

    return 0;
}