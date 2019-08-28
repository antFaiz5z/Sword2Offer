//
// Created by Faiz on 2019/8/28 0028.
//

#include "Rvalue.h"

int main() {
    auto p1 = make_unique1<A>(2);

    int i = 10;
    auto p2 = make_unique1<A>(i);

    int j = 100;
    auto p3 = make_unique<B>(i, 2, j);
    return 0;
}