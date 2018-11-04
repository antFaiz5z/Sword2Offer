//
// Created by faiz on 18-11-2.
//
// 建造者模式（Builder Pattern），
// 旨在将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。

#ifndef JIANZHIOFFER_BUILDER_H
#define JIANZHIOFFER_BUILDER_H

#include <iostream>

using namespace std;

class Product{

public:

    const string &getCpu() const;
    void setCpu(const string &cpu);
    const string &getMem() const;
    void setMem(const string &mem);
    const string &getDisk() const;
    void setDisk(const string &disk);

    friend ostream &operator<<(ostream &os, const Product &product);

private:

    string cpu;
    string mem;
    string disk;
};


class Builder {

public:

    virtual void build_cpu() = 0;
    virtual void build_mem() = 0;
    virtual void build_disk() = 0;
    virtual Product* get_result() = 0;
};


class ConcreteBuilder : public Builder{

public:

    ConcreteBuilder(){m_product = new Product();}
    void build_cpu() override {m_product->setCpu("i5-8500");}
    void build_mem() override {m_product->setMem("DDR4");}
    void build_disk() override {m_product->setDisk("WDBlue");}
    Product *get_result() override {return m_product;}

private:
    Product* m_product;
};

class Director{

public:
    void create(Builder* builder){
        builder->build_cpu();
        builder->build_mem();
        builder->build_disk();
    }
};


#endif //JIANZHIOFFER_BUILDER_H
