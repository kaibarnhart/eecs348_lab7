#ifndef __MYSTACK_H__
#define __MYSTACK_H__

#include <iostream>
#include "MyVector_k298b686.h"

template <typename DataType>
class MyStack : private MyVector<DataType>
{
public:
    explicit MyStack(size_t initSize = 0) : MyVector<DataType>(initSize) {}

    MyStack(const MyStack & rhs) : MyVector<DataType>(rhs) {}

    MyStack(MyStack && rhs) : MyVector<DataType>(std::move(rhs)) {}

    ~MyStack() {}

    MyStack & operator= (const MyStack & rhs)
    {
        MyVector<DataType>::operator=(rhs);
        return *this;
    }

    MyStack & operator= (MyStack && rhs)
    {
        MyVector<DataType>::operator=(std::move(rhs));
        return *this;
    }

    void push(const DataType & x)
    {
        MyVector<DataType>::push_back(x);
    }

    void push(DataType && x)
    {
        MyVector<DataType>::push_back(std::move(x));
    }

    void pop(void)
    {
        if (!empty())
        {
            MyVector<DataType>::pop_back();
        }
    }

    const DataType & top(void) const
    {
        return MyVector<DataType>::back();
    }

    bool empty(void) const
    {
        return MyVector<DataType>::empty();
    }

    size_t size() const
    {
        return MyVector<DataType>::size();
    }

    size_t capacity(void) const
    {
        return MyVector<DataType>::capacity();
    }
};

#endif
