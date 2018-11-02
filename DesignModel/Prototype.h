#include <utility>

//
// Created by faiz on 18-11-2.
//

#ifndef JIANZHIOFFER_PROTOTYPE_H
#define JIANZHIOFFER_PROTOTYPE_H

#include <iostream>
#include <string>

using namespace std;

class Prototype {

public:

    Prototype() = default;
    virtual ~Prototype() = default;
    virtual Prototype* clone() = 0;
    virtual void dosomething() = 0;
};

class Concrete : public Prototype{

public:

    Concrete(string name) : name(std::move(name)){}
    Concrete(const Concrete& concrete){
        name = concrete.name;
    }

    Concrete* clone() override{
        return new Concrete(*this);
    }

    void dosomething() override{
        cout << "------" << name << endl;
    }

private:

    string name;
};


#endif //JIANZHIOFFER_PROTOTYPE_H
