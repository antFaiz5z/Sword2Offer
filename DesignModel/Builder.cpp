//
// Created by faiz on 18-11-2.
//

#include "Builder.h"

const string &Product::getCpu() const {
    return cpu;
}

void Product::setCpu(const string &cpu) {
    Product::cpu = cpu;
}

const string &Product::getMem() const {
    return mem;
}

void Product::setMem(const string &mem) {
    Product::mem = mem;
}

const string &Product::getDisk() const {
    return disk;
}

void Product::setDisk(const string &disk) {
    Product::disk = disk;
}

ostream &operator<<(ostream &os, const Product &product) {
    os << "cpu: " << product.cpu << " mem: " << product.mem << " disk: " << product.disk;
    return os;
}
