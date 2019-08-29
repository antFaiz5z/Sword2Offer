//
// Created by Faiz on 2019/8/29 0029.
//

#include "ImpPolyByTmplate.h"


int main(int argc, char* argv[])
{
    //模板实现虚函数多态
    base<der> * pb= new der(100);
    pb->print();
    pb->m_print();

    //动态继承
    der2<tmpclass> d2;
    d2.print();
    d2.m_print();
    d2.test();

    return 0;
}
