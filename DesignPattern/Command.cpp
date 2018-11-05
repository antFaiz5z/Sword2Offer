//
// Created by faiz on 18-11-5.
//

#include "Command.h"

int ConcreteReciever::get_result() {
    int ret = 0;
    switch (action) {
        case actions::ADD:
            ret = x + y;
            break;
        case actions::SUB:
            ret = x- y;
            break;
        default:
            break;
    }
    return ret;
}
