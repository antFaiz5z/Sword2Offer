//
// Created by Faiz on 2019/4/23 0023.
//

#include "RoundRobin.h"

#include <iostream>

int RoundRobin::get_index() {
    index = (index + 1) % size;
    return index;
}

SmoothWeightedRoundRobin::SmoothWeightedRoundRobin(const std::vector<entity> &entities) {
    total_weight = 0;
    for (auto &i : entities) {
        servers.push_back(server{i.first, 0, i.second});
        total_weight += i.first;
    }
    size = entities.size();
}

int SmoothWeightedRoundRobin::get_index() {
    int cur_index = -1;
    int cur_weight = -1;

    for (int i = 0; i < size; ++i) {
        servers[i].cur_weight += servers[i].weight;
        if (servers[i].cur_weight > cur_weight){
            cur_weight = servers[i].cur_weight;
            cur_index = i;
        }
    }
    servers[cur_index].cur_weight -= total_weight;

    return cur_index;
}
