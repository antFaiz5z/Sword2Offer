#include <utility>

//
// Created by faiz on 18-11-2.
//
// 观察者模式（Observer Pattern），
// 定义了对象间的一对多的依赖关系，让多个观察者对象同时监听某一个主题对象（被观察者）。
// 当主题对象的状态发生更改时，会通知所有观察者，让它们能够自动更新。

#ifndef JIANZHIOFFER_OBSERVER_H
#define JIANZHIOFFER_OBSERVER_H

#include <iostream>
#include <list>

using namespace std;

class Observer{

public:

    virtual void update(float price) = 0;
};

class Subject{

public:

    virtual void attach(Observer*) = 0;
    virtual void detach(Observer*) = 0;
    virtual void notify() = 0;
};


class ConcreteObserver : public Observer{

public:

    explicit ConcreteObserver(string name) : m_name(std::move(name)){}

    void update(float price){
        cout << m_name << ":" << price << endl;
    }

private:

    string m_name;
};

class ConcreteSubject : public Subject{

public:

    ConcreteSubject(){m_price = 0;}
    explicit ConcreteSubject(float price) : m_price(price){}
    void set_price(float price){
        m_price = price;
    }

    void attach(Observer* ob) override {

        m_observers.push_back(ob);
    }

    void detach(Observer* ob) override {
        m_observers.remove(ob);
    }

    void notify() override{

        auto it = m_observers.begin();
        while (it != m_observers.end()){
            (*it)->update(m_price);
            ++it;
        }
    }
private:

    list<Observer*> m_observers;
    float m_price;

};

#endif //JIANZHIOFFER_OBSERVER_H
