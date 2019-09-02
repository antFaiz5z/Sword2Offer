//
// Created by Faiz on 2019/4/23 0023.
//

#ifndef JIANZHIOFFER_ROUNDROBIN_H
#define JIANZHIOFFER_ROUNDROBIN_H

/* 加权轮询算法实现 */

#include <string>
#include <vector>

typedef struct {
    int weight;
    int cur_weight;
    std::string name;
} server;

typedef std::pair<int, std::string> entity;

class RoundRobin {

public:

    RoundRobin() : size(0), index(0) {}

    int get_index();

private:
    int size;
    int index;
};

class WeightedRoundRobin {
};

class SmoothWeightedRoundRobin {

public:

    explicit SmoothWeightedRoundRobin(const std::vector<entity> &entities);

    int get_index();

    std::vector<server> servers;

private:
    int size;
    int total_weight;
};


#endif //JIANZHIOFFER_ROUNDROBIN_H
