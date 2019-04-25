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

bool Map::canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {

    vector<unordered_multiset<int>> edges(numCourses);
    vector<int> preCount(numCourses, 0);
    for (auto &i : prerequisites) {
        edges[i.second].insert(i.first);
        preCount[i.first]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (preCount[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        count++;
        for (auto &i : edges[now]) {
            if (--preCount[i] == 0) {
                q.push(i);
            }
        }
    }
    return count == numCourses;
}

vector<int> Map::findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {

    vector<int> ret;
    vector<unordered_multiset<int>> edges(numCourses);
    vector<int> preCount(numCourses, 0);
    for (auto &i : prerequisites) {
        edges[i.second].insert(i.first);
        preCount[i.first]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (preCount[i] == 0) {
            q.push(i);
            ret.push_back(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        count++;
        for (auto &i : edges[now]) {
            if (--preCount[i] == 0) {
                q.push(i);
                ret.push_back(i);
            }
        }
    }
    return count == numCourses ? ret : vector<int>();
}

bool Map::isBipartite(vector<vector<int>> &graph) {

    size_t n = graph.size();
    vector<int> colors(n, 0);
    for (size_t i = 0; i < n; ++i) {
        if (!colors[i] && !colored(i, graph, colors, 1)) {
            return false;
        }
    }
    return true;
}

bool Map::colored(int now, vector<vector<int>> &graph, vector<int> &colors, int color) {

    colors[now] = color;
    for (int next: graph[now]) {
        if (!colors[next] && !colored(next, graph, colors, -color)) {
            return false;
        }
        if (colors[next] == color) {
            return false;
        }
    }
    return true;
}

vector<int> Map::findRedundantConnection(vector<vector<int>> &edges) {

    size_t n = edges.size();
    vector<int> ret;
    vector<int> fathers;
    fathers.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        fathers[i] = i;
    }
    for (auto i : edges) {
        if (isRedundant(i[0], i[1], fathers)) {
            ret = i;
            break;
        }
    }
    return ret;
}

int Map::getFather(int x, vector<int> &fathers) {

    if (x == fathers[x]) {
        return x;
    }
    return fathers[x] = getFather(fathers[x], fathers);
}

bool Map::isRedundant(int x, int y, vector<int> &fathers) {

    int x_father = getFather(x, fathers);
    int y_father = getFather(y, fathers);

    if (x_father == y_father) {
        return true;
    }
    for (int &father : fathers) {
        if (father == x_father) {
            father = y_father;
        }
    }
    return false;
}




