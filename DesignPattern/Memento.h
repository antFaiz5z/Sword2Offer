#include <utility>

//
// Created by faiz on 18-11-5.
//
// 备忘录模式（Memento Pattern）
// 在不破坏封装的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态，这样可以在以后将对象恢复到原先保存的状态。

#ifndef JIANZHIOFFER_MEMENTO_H
#define JIANZHIOFFER_MEMENTO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Originator {

public:
    Originator(string &date_time) : date_time(date_time) {}

    const string &get_date_time() const {
        return date_time;
    }

    void set_date_time(const string &date_time) {
        Originator::date_time = date_time;
    }

private:
    string date_time;
};

class Memento {

public:
    const string &get_date_time() const {
        cout << "date time now is " << date_time << endl;
        return date_time;
    }

    void set_date_time(const string &date_time) {
        cout << "set date time to " << date_time << endl;
        Memento::date_time = date_time;
    }

    void set_memento(Originator *date) {
        date_time = date->get_date_time();
    }

    Originator *create_memento() {
        return new Originator(date_time);
    }

private:
    string date_time;
};

class Caretaker {

public:

    Caretaker(Memento *memento) : memento(memento) {}

    ~Caretaker() {
        for (int i = 0; i < history.size(); ++i) {
            delete (history.at(static_cast<unsigned long>(i)));
        }
        history.clear();
    }

    void save() {
        cout << "save..." << endl;
        history.push_back(memento->create_memento());
    }

    void undo() {
        cout << "undo..." << endl;
        memento->set_memento(history.back());
        history.pop_back();
    }

private:
    Memento *memento;
    vector<Originator *> history;
};


#endif //JIANZHIOFFER_MEMENTO_H
