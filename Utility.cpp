//
// Created by faiz on 18-4-15.
//
#include "Utility.h"

#include <sys/time.h>
#include <iostream>


double Utility::get_time() {

    struct timeval time{};
    if (gettimeofday(&time, nullptr)) {
        return 0;
    }
    return (double) time.tv_sec + (double) time.tv_usec * .000001;
}

void Utility::print_during(double start, double end) {

    std::cout << "During: " << end - start << "ms." << std::endl;
}
