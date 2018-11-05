#include <utility>

//
// Created by faiz on 18-11-2.
//
// 原型模式（Prototype Pattern）
// 是一种创建型设计模式，允许一个对象再创建另外一个可定制的对象，而无需知道任何创建的细节。

#ifndef JIANZHIOFFER_PROTOTYPE_H
#define JIANZHIOFFER_PROTOTYPE_H

#include <iostream>
#include <string>

using namespace std;

class Prototype {

public:

    Prototype() = default;

    virtual ~Prototype() = default;

    virtual Prototype *clone() = 0;

    virtual void do_something() = 0;
};

class Concrete : public Prototype {

public:

    Concrete(string name) : name(std::move(name)) {}

    Concrete(const Concrete &concrete) {
        name = concrete.name;
    }

    Concrete *clone() override {
        return new Concrete(*this);
    }

    void do_something() override {
        cout << "------" << name << "------" << endl;
    }

private:

    string name;
};


#endif //JIANZHIOFFER_PROTOTYPE_H
