//
// Created by faiz on 18-11-5.
//
// 命令模式（Command Pattern）
// 是一种数据驱动的设计模式，它属于行为型模式。
// 请求以命令的形式包裹在对象中，并传递给调用对象。
// 调用对象寻找可以处理该命令的合适对象，并把该命令传给相应的对象，该对象执行命令。

#ifndef JIANZHIOFFER_COMMAND_H
#define JIANZHIOFFER_COMMAND_H

#include <iostream>
#include <list>

using namespace std;

enum actions {
    ADD,
    SUB
};

class Reciever {

public:
    virtual void set_action(actions action) = 0;

    virtual int get_result() = 0;
};

class ConcreteReciever : public Reciever {

public:
    ConcreteReciever(int x, int y) : x(x), y(y) {}

    void set_action(actions act) override {
        action = act;
    }

    int get_result() override;

private:
    int x;
    int y;
    actions action;
};

class Command {

public:

    explicit Command(Reciever *reciever) : reciever(reciever) {}

    virtual int execute() = 0;

protected:
    Reciever *reciever;
};

class AddCommand : public Command {

public:

    explicit AddCommand(Reciever *reciever) : Command(reciever) {}

    int execute() override {
        reciever->set_action(actions::ADD);
        return reciever->get_result();
    }
};

class SubCommand : public Command {

public:

    explicit SubCommand(Reciever *reciever) : Command(reciever) {}

    int execute() override {
        reciever->set_action(actions::SUB);
        return reciever->get_result();
    }
};

class Invoker {

public:
    void add_cmd(Command *cmd) {
        commands.push_back(cmd);
    }

    void del_cmd(Command *cmd) {
        commands.remove(cmd);
    }

    void notify() {
        auto it = commands.begin();
        while (it != commands.end()) {
            cout << (*it)->execute() << endl;
            ++it;
        }
    }

private:
    list<Command *> commands;
};

#endif //JIANZHIOFFER_COMMAND_H
