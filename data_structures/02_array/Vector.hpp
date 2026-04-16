#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>
class Vector
{
private:
    std::size_t m_size;
    std::size_t m_capacity;
    T *m_elements;

private:
    void resize();

public:
    // ctors
    Vector();
    Vector(std::size_t cap);
    Vector(const Vector<T> &);
    Vector<T> &operator=(const Vector<T> &other);
    ~Vector();

    // operators
    T &operator[](std::size_t index);
    const T &operator[](std::size_t index) const;

    // operations
    void push_back(T);
    bool empty() const;

    T pop_back();

    void insertAt(std::size_t index, T value);

    void deleteAt(std::size_t index);

    T &at(std::size_t pos);
    const T &at(std::size_t pos) const;

    T *data();
    const T *data() const;

    std::size_t size() const;
    std::size_t capacity() const;

    void reserve(std::size_t new_cap);

    T &front();
    const T &front() const;

    T &back();
    const T &back() const;
};

#include "Vector.tpp"
