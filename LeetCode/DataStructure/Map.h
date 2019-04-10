#include <utility>

//
// Created by Faiz on 2019/4/8 0008.
//

#ifndef JIANZHIOFFER_MAP_H
#define JIANZHIOFFER_MAP_H

#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>


using namespace std;

class Node {
public:
    int val{};
    vector<Node*> neighbors;

    Node() = default;

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = std::move(_neighbors);
    }
};

class Map {

public:

    //133
    Node* cloneGraph_BFS(Node* node);

    Node* cloneGraph_DFS(Node* node);
    Node* clone_recur(Node* node, map<int, Node*>& map);

    //207
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);

    //210
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites);
};


#endif //JIANZHIOFFER_MAP_H
