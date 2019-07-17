//
// Created by Faiz on 2019/7/17 0017.
//
#include <iostream>

#include "RoundRobin.h"

using namespace std;

int local_main_roundrobin(){

    int index;
    std::vector<entity>  entitites;
    entitites.emplace_back(entity(4, "a"));
    entitites.emplace_back(entity(2, "b"));
    entitites.emplace_back(entity(1, "c"));

    SmoothWeightedRoundRobin swr = SmoothWeightedRoundRobin(entitites);
    for (int i = 0; i < 14; ++i) {
        index = swr.get_index();
        std::cout << "selected server: " << index << " - " << swr.servers[index].name << std::endl << "cur_weights: | ";
        for (auto &j : swr.servers){
            std::cout << j.cur_weight << " | " ;
        }
        std::cout << std::endl;
    }
}

int main(){
    
    local_main_roundrobin();
    
    return 0;
}
