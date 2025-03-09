#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__

#include <iostream>
#include <algorithm>
#include "MyVector_k298b686.h"

template <typename DataType>
class MyQueue : private MyVector<DataType>
{
private:
    size_t dataStart, dataEnd;

    void resize(size_t newSize)
    {
        MyVector<DataType>::resize(newSize);
    }

    void reserve(size_t newCapacity)
    {
        MyVector<DataType>::reserve(newCapacity);
    }

public:
    explicit MyQueue(size_t initSize = 0) : MyVector<DataType>(initSize), dataStart(0), dataEnd(initSize) {}

    MyQueue(const MyQueue & rhs) : MyVector<DataType>(rhs), dataStart(rhs.dataStart), dataEnd(rhs.dataEnd) {}

    MyQueue(MyQueue && rhs) : MyVector<DataType>(std::move(rhs)), dataStart(rhs.dataStart), dataEnd(rhs.dataEnd) {}

    ~MyQueue() {}

    MyQueue & operator= (const MyQueue & rhs)
    {
        MyVector<DataType>::operator=(rhs);
        dataStart = rhs.dataStart;
        dataEnd = rhs.dataEnd;
        return *this;
    }

    MyQueue & operator= (MyQueue && rhs)
    {
        MyVector<DataType>::operator=(std::move(rhs));
        dataStart = rhs.dataStart;
        dataEnd = rhs.dataEnd;
        return *this;
    }

    void enqueue(const DataType & x)
    {
        MyVector<DataType>::push_back(x);
        ++dataEnd;
    }

    void enqueue(DataType && x)
    {
        MyVector<DataType>::push_back(std::move(x));
        ++dataEnd;
    }

    void dequeue(void)
    {
        if (!empty())
        {
            ++dataStart;
        }
    }

    const DataType & front(void) const
    {
        return (*this)[dataStart];
    }

    bool empty(void) const
    {
        return dataStart >= dataEnd;
    }

    size_t size() const
    {
        return dataEnd - dataStart;
    }

    size_t capacity(void) const
    {
        return MyVector<DataType>::capacity();
    }
};

#endif
