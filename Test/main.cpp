//
// Created by Faiz on 2019/3/18 0018.
//
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <cstring>
#include <list>
#include <cmath>

#include "Others.h"

#include <string>

using namespace std;


int main() {

    Others others;
    //others.pdd_one();
    //others.four();

    //others.netease_two();
    //others.netease_three();

    //others.leiho_one();
    //others.leiho_three();
    //others.leiho_five();
    //others.intermo_one();
    //others.intermo_two();
    //others.intermo_three();

    cout << round(-0.0) << endl;
    cout << round(-INFINITY) << endl;
    cout << lround(INFINITY) << endl;
    cout << sizeof(round((long double) 123.456)) << endl;
    cout << sizeof(lround((long double) 123.456)) << endl;
    cout << INFINITY << endl;
    cout << LONG_LONG_MAX << endl;
    cout << INT_MAX << endl;
    std::cout << 0.0000987654321f << std::endl;
    cout << sizeof(int) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(long double) << endl;
    cout << sizeof(long long) << endl;
    auto d = 9.86756754e-0006f;
    cout << d << endl;
    cout << -4 / 5 << ":" << -4 % 5 << endl;
    int a;
    scanf("%d", &a);
    printf("%ld", a);

}
