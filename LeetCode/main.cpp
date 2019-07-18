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
#include "Algorithm/Design.h"
#include "Unsorted.h"
#include "Algorithm/Dynamic.h"

int main() {

    //vector<string> d({"ale","apple","monkey","plea"});
    //cout << DoublePointer::findLongestWord("abpcplea", d) << endl;

    HashTable ht;
    Unsorted unsorted;
    Dynamic dynamic;

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

/*    string a = "ADSFGBDFGCFGBFDGADFGBVBFDGAACDFGBA";
    string b = "ABC";
    cout << ht.minWindow(a, b) << endl;
    a = "a";
    b = "a";
    cout << ht.minWindow(a, b) << endl;*/

/*
    LRUCache ca(1);
    ca.put(1,2);
    ca.cache.print();
    cout << ca.get(1) << endl;
    ca.put(3,4);
    ca.put(5,6);
    ca.cache.print();
    cout << ca.get(1) <<endl;
    ca.put(3,6);
    ca.cache.print();
*/


/*    vector<int> ret = unsorted.pathInZigZagTree(14);
    for (auto &i : ret){
        cout << i << ", ";
    }
*/

/*    //cout << dynamic.uniquePaths(3,2) << endl;
    //cout << dynamic.uniquePathsII(3,2) << endl;
    //cout << dynamic.uniquePathsIII(3,2) << endl;

    vector<vector<int>> ob{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0}};//,[1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1],[0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0],[0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0],[1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0],[0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0],[0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0],[0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0],[1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1],[0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0],[0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0],[0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1],[1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0],[0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1],[0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1],[1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1],[0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0]];
    cout <<dynamic.uniquePathsWithObstacles(ob) << endl;
    cout <<dynamic.uniquePathsWithObstaclesII(ob) <<endl;*/

    cout << unsorted.add_overflow(numeric_limits<int>::max(), numeric_limits<int>::max()) << endl;
    cout << unsorted.add_overflow(numeric_limits<int>::min(), numeric_limits<int>::min()) << endl;



    return 0;


}