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
#include "Decorator.h"

using namespace std;

int main(){

    //Builder
    auto * director = new Director();
    auto * builder = new ConcreteBuilder();

    director->create(builder);
    auto * product = builder->get_result();

    cout << *product << endl;

    //Prototype
    Prototype* proto = new Concrete("instance");

    Prototype* proto2 = proto->clone();
    Prototype* proto3 = proto2->clone();

    proto->dosomething();
    proto2->dosomething();
    proto3->dosomething();

    //Decorator
    Component* component1 = new ConcreteComponent1();
    cout << *component1 << endl;
    Decorator* decorator11 = new ConcreteDecorator1(component1);
    cout << *decorator11 << endl;
    Decorator* decorator12 = new ConcreteDecorator2(component1);
    cout << *decorator12 << endl;

    Component* component2 = new ConcreteComponent2();
    cout << *component2 << endl;
    Decorator* decorator21 = new ConcreteDecorator1(component2);
    cout << *decorator21 << endl;
    Decorator* decorator22 = new ConcreteDecorator2(component2);
    cout << *decorator22 << endl;


}