//
// Created by faiz on 18-11-4.
//
// 装饰者模式（Decorator Pattern）
// 是在不必改变原类文件和使用继承的情况下，动态地扩展一个对象的功能。它是通过创建一个包装对象，也就是装饰来包裹真实的对象。

#ifndef JIANZHIOFFER_DECORATOR_H
#define JIANZHIOFFER_DECORATOR_H

#include <string>
#include <ostream>

using namespace std;

class Component{

public:

    virtual string name() = 0;
    virtual double price() = 0;

    friend ostream &operator<<(ostream &os, Component &component);
};

class ConcreteComponent1 : public Component{

public:

    string name() override {

        return "component_1";
    }

    double price() override {
        return 34.5;
    }
};

class ConcreteComponent2 : public Component{

public:

    string name() override {

        return "component_2";
    }

    double price() override {
        return 12.3;
    }
};

class Decorator : public Component{

public:

    Decorator(Component* component): component(component){}

    string name() override {
        return component->name();
    }
    double price() override {
        return component->price();
    }

protected:
    Component* component;
};

class ConcreteDecorator1 : public Decorator{

public:

    ConcreteDecorator1(Component* component) : Decorator(component){}

    string name() override {
        return component->name() + " decorator_1";
    }

    double price() override {
        return component->price() + 3.5;
    }
};

class ConcreteDecorator2 : public Decorator{

public:

    ConcreteDecorator2(Component* component) : Decorator(component){}

    string name() override {
        return component->name() + " decorator_2";
    }

    double price() override {
        return component->price() + 7.5;
    }
};

#endif //JIANZHIOFFER_DECORATOR_H
