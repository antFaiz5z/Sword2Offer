//
// Created by Faiz on 2019/8/29 0029.
//

#ifndef SWORD2OFFER_IMPPOLYBYTMPLATE_H
#define SWORD2OFFER_IMPPOLYBYTMPLATE_H

#include <iostream>

using namespace std;

template<class derive>
class base
{
public:
    void print()
    {
        cout<<"in base print"<<endl;
        derive::print();
    }
    void m_print()
    {
        cout<<"in base member fun m_print"<<endl;
        downcast()->derive::m_print();
    }
protected:
    inline derive * downcast()
    {
        return static_cast<derive *>(this);
    };
    inline const derive * downcast()const
    {
        return static_cast<const derive *>(this);
    };
};

class der:public base<der>
{
public:
    der(int foo):_foo(foo){}
    static void print()
    {
        cout<<"in der print"<<endl;
    };
    void m_print()
    {
        cout<<"in der member fun m_print"<<endl;
        cout<<"has member foo="<<_foo<<endl;
    }
private:
    int _foo;
};

template<class base>
class der2:public base
{
public:
    static void print()
    {
        cout<<"in der2 print"<<endl;
    };
    void m_print()
    {
        cout<<"in der2 member fun m_print"<<endl;
    }
};

class tmpclass
{
public:
    void test()
    { cout<<"in test"<<endl;}
};



#endif //SWORD2OFFER_IMPPOLYBYTMPLATE_H
