//
// Created by faiz on 18-11-4.
//

#include "Decorator.h"

ostream &operator<<(ostream &os, Component &component) {
    os << component.name() << " : " << component.price();
    return os;
}
