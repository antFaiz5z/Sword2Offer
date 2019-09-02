//
// Created by Faiz on 2019/8/30 0030.
//

#ifndef SWORD2OFFER_SHAREDPTR_H
#define SWORD2OFFER_SHAREDPTR_H

/* shared_ptr实现 */
template<typename T>
class SharedPtr {
private:
    T *_ptr;
    int *_refCount;     //should be int*, rather than int

public:

    ~SharedPtr() {
        if (_ptr && --*_refCount == 0) {
            delete _ptr;
            delete _refCount;
        }
    }

    SharedPtr() : _ptr((T *) 0), _refCount(0) {}

    SharedPtr(T *obj) : _ptr(obj), _refCount(new int(1)) {}
    //这里无法防止循环引用，若我们用同一个普通指针去初始化两个shared_ptr，此时两个ptr均指向同一片内存区域，但是引用计数器均为1，使用时需要注意。

    SharedPtr(SharedPtr &other) : _ptr(other._ptr), _refCount(&(++*other._refCount)) {}

    SharedPtr &operator=(const SharedPtr &other) {
        if (this == &other)
            return *this;
        ++*other._refCount;
        if (--*_refCount == 0) {
            delete _ptr;
            delete _refCount;
        }
        _ptr = other._ptr;
        _refCount = other._refCount;
        return *this;
    }

    T &operator*() {
        if (_refCount == 0)
            return (T *) 0;
        return *_ptr;
    }

    T *operator->() {
        if (_refCount == 0)
            return 0;
        return _ptr;
    }
};


#endif //SWORD2OFFER_SHAREDPTR_H
