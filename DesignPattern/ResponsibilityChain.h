//
// Created by faiz on 18-11-5.
//
// 职责链模式（Chain of Responsibility Pattern）
// 使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。将
// 这些对象连成一条链，并沿着这条链传递该请求，直到有一个对象处理它为止。

#ifndef JIANZHIOFFER_RESPONSIBILITYCHAIN_H
#define JIANZHIOFFER_RESPONSIBILITYCHAIN_H

#include <iostream>

using namespace std;

class Handler {

public:
    Handler() { next = nullptr; }

    virtual ~Handler() = default;

    void set_next(Handler *next) {
        this->next = next;
    }

    virtual void handle_request(int days) = 0;

protected:
    Handler *next;
};

class ConcreteHandler1 : public Handler{

public:
    void handle_request(int days) override {
        if(days <= 1){
            cout << "handler1 yes" << endl;
        }else{
            next->handle_request(days);
        }
    }
};

class ConcreteHandler2 : public Handler{

public:
    void handle_request(int days) override {
        if(days <= 3){
            cout << "handler2 yes" << endl;
        }else{
            next->handle_request(days);
        }
    }
};

class ConcreteHandler3 : public Handler{

public:
    void handle_request(int days) override {
        if(days <= 7){
            cout << "handler3 yes" << endl;
        }else{
            cout << "in the end, no more next" << endl;
        }
    }
};

#endif //JIANZHIOFFER_RESPONSIBILITYCHAIN_H
