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
#include "Command.h"
#include "ResponsibilityChain.h"
#include "Memento.h"

using namespace std;

int main() {

    //Builder
    auto *director = new Director();
    auto *builder = new ConcreteBuilder();

    director->create(builder);
    auto *product = builder->get_result();

    cout << *product << endl;

    //Prototype
    Prototype *proto = new Concrete("instance");

    Prototype *proto2 = proto->clone();
    Prototype *proto3 = proto2->clone();

    proto->do_something();
    proto2->do_something();
    proto3->do_something();

    //Decorator
    Component *component1 = new ConcreteComponent1();
    cout << *component1 << endl;
    Decorator *decorator11 = new ConcreteDecorator1(component1);
    cout << *decorator11 << endl;
    Decorator *decorator12 = new ConcreteDecorator2(component1);
    cout << *decorator12 << endl;

    Component *component2 = new ConcreteComponent2();
    cout << *component2 << endl;
    Decorator *decorator21 = new ConcreteDecorator1(component2);
    cout << *decorator21 << endl;
    Decorator *decorator22 = new ConcreteDecorator2(component2);
    cout << *decorator22 << endl;

    //Command
    Reciever *reciever = new ConcreteReciever(12, 33);
    Command *command1 = new AddCommand(reciever);
    Command *command2 = new SubCommand(reciever);
    Invoker invoker;

    invoker.add_cmd(command1);
    invoker.add_cmd(command2);
    invoker.notify();

    //ResponsibilityChain
    Handler *handler1 = new ConcreteHandler1();
    Handler *handler2 = new ConcreteHandler2();
    Handler *handler3 = new ConcreteHandler3();

    handler1->set_next(handler2);
    handler2->set_next(handler3);

    handler1->handle_request(2);
    handler1->handle_request(5);
    handler1->handle_request(9);

    //Memento
    auto *memento = new Memento();
    auto *caretaker = new Caretaker(memento);

    memento->set_date_time("2000/10/01 00:00:00");
    caretaker->save();
    memento->set_date_time("2008/10/05 17:28:00");
    caretaker->save();
    memento->set_date_time("2018/11/05 17:28:00");
    caretaker->undo();
    memento->get_date_time();
    caretaker->undo();
    memento->get_date_time();
}