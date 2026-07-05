#include <iostream>
#include <stdexcept>

template <typename T>
class VectorStack
{
private:
    T *m_data;
    int m_size;
    int m_capacity;

public:
    VectorStack() : m_size(0), m_capacity(1)
    {
        this->m_data = new T[m_capacity];
    }

    ~VectorStack()
    {
        delete[] this->m_data;
    }

    bool isFull() const
    {
        return m_size >= m_capacity;
    }

    void resize(int capacity)
    {
        T *temp = new T[capacity];

        for (int i = 0; i < m_size; ++i)
            temp[i] = this->m_data[i];

        delete[] this->m_data;
        this->m_data = temp;
        this->m_capacity = capacity;
    }

    void push(const T &element)
    {
        if (isFull())
            resize(m_capacity * 2);

        this->m_data[m_size++] = element;
    }

    T pop()
    {
        if (empty())
            throw std::out_of_range("Stack is empty");

        return this->m_data[--this->m_size];
    }

    const T &peek() const
    {
        if (empty())
            throw std::out_of_range("Stack is empty");

        return this->m_data[this->m_size - 1];
    }

    bool empty() const
    {
        return this->m_size == 0;
    }

    int size() const
    {
        return this->m_size;
    }
};
