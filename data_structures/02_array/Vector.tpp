#include "Vector.hpp"

template <typename T>
Vector<T>::Vector() : m_size(0), m_capacity(2)
{
    this->m_elements = new T[this->m_capacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T> &other) : m_size(other.m_size), m_capacity(other.m_capacity)
{
    this->m_elements = new T[this->m_capacity];
    for (std::size_t i = 0; i < this->m_size; ++i)
    {
        this->m_elements[i] = other.m_elements[i];
    }
}

template <typename T>
Vector<T>::Vector(std::size_t cap) : m_size(0), m_capacity(cap)
{
    this->m_elements = new T[this->m_capacity];
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other)
{
    if (this == &other)
        return *this;

    delete[] this->m_elements;

    this->m_size = other.m_size;
    this->m_capacity = other.m_capacity;

    this->m_elements = new T[this->m_capacity];

    for (std::size_t i = 0; i < this->m_size; ++i)
    {
        this->m_elements[i] = other.m_elements[i];
    }

    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] this->m_elements;
}

template <typename T>
void Vector<T>::resize()
{
    this->m_capacity *= 2;

    T *newArr = new T[this->m_capacity];

    for (std::size_t i = 0; i < this->m_size; ++i)
    {
        newArr[i] = this->m_elements[i];
    }
    delete[] this->m_elements;
    this->m_elements = newArr;
}

template <typename T>
std::size_t Vector<T>::size() const
{
    return this->m_size;
}

template <typename T>
void Vector<T>::push_back(T item)
{
    if (this->m_size >= this->m_capacity)
    {
        resize();
    }
    this->m_elements[this->m_size] = item;
    this->m_size++;
}

template <typename T>
T &Vector<T>::operator[](std::size_t pos)
{
    if (pos >= this->m_size)
    {
        throw std::out_of_range("Index out of range");
    }

    return this->m_elements[pos];
}

template <typename T>
const T &Vector<T>::operator[](std::size_t pos) const
{
    if (pos >= this->m_size)
    {
        throw std::out_of_range("Index out of range");
    }

    return this->m_elements[pos];
}

template <typename T>
std::size_t Vector<T>::capacity() const
{
    return this->m_capacity;
}

template <typename T>
T &Vector<T>::front()
{
    if (this->empty())
    {
        throw std::out_of_range("Index out of range");
    }
    return this->m_elements[0];
}

template <typename T>
const T &Vector<T>::front() const
{
    if (this->empty())
    {
        throw std::out_of_range("Index out of range");
    }
    return this->m_elements[0];
}

template <typename T>
T &Vector<T>::back()
{
    if (this->empty())
    {
        throw std::out_of_range("Index out of range");
    }
    return this->m_elements[this->m_size - 1];
}

template <typename T>
const T &Vector<T>::back() const
{
    if (this->empty())
    {
        throw std::out_of_range("Index out of range");
    }
    return this->m_elements[this->m_size - 1];
}

template <typename T>
bool Vector<T>::empty() const
{
    return this->m_size == 0;
}

template <typename T>
T &Vector<T>::at(std::size_t pos)
{
    if (pos >= this->m_size)
    {
        throw std::out_of_range("Index out of range");
    }
    return this->m_elements[pos];
}

template <typename T>
const T &Vector<T>::at(std::size_t pos) const
{
    if (pos >= this->m_size)
    {
        throw std::out_of_range("Index out of range");
    }
    return this->m_elements[pos];
}

template <typename T>
T *Vector<T>::data()
{
    return this->m_elements;
}

template <typename T>
const T *Vector<T>::data() const
{
    return this->m_elements;
}

template <typename T>
void Vector<T>::reserve(std::size_t new_cap)
{
    if (new_cap <= this->m_capacity)
        return;

    T *new_data = new T[new_cap];

    for (std::size_t i = 0; i < this->m_size; ++i)
    {
        new_data[i] = this->m_elements[i];
    }

    delete[] this->m_elements;

    this->m_elements = new_data;
    this->m_capacity = new_cap;
}

template <typename T>
T Vector<T>::pop_back()
{
    if (m_size == 0)
        throw std::out_of_range("Index out of range");

    --this->m_size;
    return m_elements[m_size];
}

template <typename T>
void Vector<T>::insertAt(std::size_t index, T value)
{
    if (index > this->m_size)
        throw std::out_of_range("Index out of range");

    if (this->m_size >= this->m_capacity)
        resize();

    for (std::size_t i = m_size; i > index; --i)
    {
        m_elements[i] = m_elements[i - 1];
    }

    this->m_elements[index] = value;
    ++this->m_size;
}

template <typename T>
void Vector<T>::deleteAt(std::size_t index)
{
    if (index >= this->m_size)
        throw std::out_of_range("Index out of range");

    for (std::size_t i = index + 1; i < this->m_size; ++i)
    {
        this->m_elements[i - 1] = this->m_elements[i];
    }

    --this->m_size;
}
