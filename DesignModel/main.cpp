//
// Created by faiz on 18-11-2.
//
#include <iostream>
#include <sstream>

#include "Singleton.h"
#include "Adapter.h"
#include "Builder.h"
#include "Observer.h"
#include "Prototype.h"

using namespace std;

int main(){


    auto * director = new Director();
    auto * builder = new ConcreteBuilder();

    director->create(builder);
    auto * product = builder->get_result();

    cout << *product << endl;

    Prototype* proto = new Concrete("afrf");




}