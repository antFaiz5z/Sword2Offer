//
// Created by Faiz on 2019/4/8 0008.
//

#include "Map.h"


Node *Map::cloneGraph_BFS(Node *node) {

    if (!node) return nullptr;
    unordered_map<Node *, Node *> map;
    queue<Node *> q;
    vector<Node *> neighbors;
    Node *p1 = node;
    Node *p2 = new Node(node->val, neighbors);
    map[p1] = p2;
    q.push(node);

    while (!q.empty()) {
        p1 = q.front();
        p2 = map[p1];
        q.pop();
        for (auto &i : p1->neighbors) {
            if (map.count(i)) {
                p2->neighbors.push_back(map[i]);
            } else {
                Node *tmp = new Node(i->val, neighbors);
                p2->neighbors.push_back(tmp);
                map[i] = tmp;
                q.push(i);
            }
        }
    }
    return map[node];
}

Node *Map::cloneGraph_DFS(Node *node) {

    map<int, Node *> map;
    return clone_recur(node, map);
}

Node *Map::clone_recur(Node *node, map<int, Node *> &map) {

    if (!node) return nullptr;
    if (map.find(node->val) != map.end()) {
        return map[node->val];
    }
    vector<Node *> neighbors;
    Node *tmp = new Node(node->val, neighbors);
    map[node->val] = tmp;
    for (auto &i : node->neighbors) {
        Node *neighbor = clone_recur(i, map);
        tmp->neighbors.push_back(neighbor);
    }
    return tmp;
}


