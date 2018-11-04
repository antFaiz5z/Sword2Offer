//
// Created by faiz on 18-11-2.
//
// 单例模式（Singleton Pattern）
// 是设计模式中最简单的形式之一，其目的是使得类的一个对象成为系统中的唯一实例。
// 这种模式涉及到一个单一的类，该类负责创建自己的对象，同时确保只有单个对象被创建。
// 这个类提供了一种访问其唯一对象的方式，可以直接访问，不需要实例化该类的对象。


#ifndef JIANZHIOFFER_SINGLETON_H
#define JIANZHIOFFER_SINGLETON_H


class Singleton {

public:

    Singleton* get_instance(){

        static Singleton* instance;
        if(instance == nullptr){
            instance = new Singleton();
        }
        return instance;
    }

private:

    Singleton() = default;
    ~Singleton() = default;
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

};


#endif //JIANZHIOFFER_SINGLETON_H
