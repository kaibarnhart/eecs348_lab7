#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

// Template class for MyVector
template <typename DataType>
class MyVector {
private:
    size_t theSize;
    size_t theCapacity;
    DataType *data;

public:
    static const size_t SPARE_CAPACITY = 16;

    // Default Constructor
    explicit MyVector(size_t initSize = 0) : theSize{initSize},
        theCapacity{initSize + SPARE_CAPACITY} {
        data = new DataType[theCapacity]{};
    }

    // Copy Constructor
    MyVector(const MyVector &rhs) : theSize{rhs.theSize},
        theCapacity{rhs.theCapacity} {
        data = new DataType[theCapacity];
        std::copy(rhs.data, rhs.data + theSize, data);
    }

    // Move Constructor
    MyVector(MyVector &&rhs) noexcept : theSize{rhs.theSize},
        theCapacity{rhs.theCapacity}, data{rhs.data} {
        rhs.data = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }

    // Copy Constructor from STL Vector
    MyVector(const std::vector<DataType> &rhs) : theSize{rhs.size()},
        theCapacity{rhs.size() + SPARE_CAPACITY} {
        data = new DataType[theCapacity];
        std::copy(rhs.begin(), rhs.end(), data);
    }

    // Destructor
    ~MyVector() {
        delete[] data;
    }

    // Copy Assignment
    MyVector &operator=(const MyVector &rhs) {
        if (this != &rhs) {
            delete[] data;
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            data = new DataType[theCapacity];
            std::copy(rhs.data, rhs.data + theSize, data);
        }
        return *this;
    }

    // Move Assignments
    MyVector &operator=(MyVector &&rhs) noexcept {
        if (this != &rhs) {
            delete[] data;
            data = rhs.data;
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            rhs.data = nullptr;
            rhs.theSize = 0;
            rhs.theCapacity = 0;
        }
        return *this;
    }

    // Resize the vector
    void resize(size_t newSize) {
        if (newSize > theCapacity) {
            reserve(newSize * 2);
        }
        theSize = newSize;
    }

    // Reserve more memory
    void reserve(size_t newCapacity) {
        if (newCapacity < theSize) return;
        DataType *newData = new DataType[newCapacity];
        std::copy(data, data + theSize, newData);
        delete[] data;
        data = newData;
        theCapacity = newCapacity;
    }

    // Operator
    DataType &operator[](size_t index) {
        return data[index];
    }

    const DataType &operator[](size_t index) const {
        return data[index];
    }

    // Checks if its empty
    bool empty() const {
        return theSize == 0;
    }

    // Returns size
    size_t size() const {
        return theSize;
    }

    // Return capacity
    size_t capacity() const {
        return theCapacity;
    }

    // Push back
    void push_back(const DataType &x) {
        if (theSize == theCapacity) reserve(2 * theCapacity);
        data[theSize++] = x;
    }

    void push_back(DataType &&x) {
        if (theSize == theCapacity) reserve(2 * theCapacity);
        data[theSize++] = std::move(x);
    }

    // Append vector
    MyVector<DataType> &append(MyVector<DataType> &&rhs) {
        for (size_t i = 0; i < rhs.theSize; ++i) {
            push_back(std::move(rhs.data[i]));
        }
        rhs.theSize = 0;
        return *this;
    }

    // Pop back
    void pop_back() {
        if (!empty()) --theSize;
    }

    // Returns last element
    const DataType &back() const {
        return data[theSize - 1];
    }

    // Iterator implementation
    typedef DataType* iterator;
    typedef const DataType* const_iterator;

    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return data + theSize; }
    const_iterator end() const { return data + theSize; }
};

#endif // __MYVECTOR_H__
