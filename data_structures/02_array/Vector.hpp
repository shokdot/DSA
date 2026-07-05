#include <iostream>
#include <stdexcept>

class Vector
{
private:
    int *m_data;
    int m_size;
    int m_capacity;

    bool isFull() const
    {
        return m_size >= m_capacity;
    }

public:
    Vector() : m_size(0), m_capacity(1)
    {
        this->m_data = new int[m_capacity];
    }

    Vector(int capacity) : m_size(0), m_capacity(capacity)
    {
        if (m_capacity <= 0)
            throw std::invalid_argument("Can't be capacity negative");

        this->m_data = new int[m_capacity];
    }

    ~Vector()
    {
        delete[] this->m_data;
    }

    void resize(void)
    {
        this->m_capacity *= 2;
        int *temp = new int[this->m_capacity];

        for (int i = 0; i < this->m_size; i++)
        {
            temp[i] = this->m_data[i];
        }

        delete[] this->m_data;
        this->m_data = temp;
    }

    void push_back(int element)
    {
        if (isFull())
            resize();

        this->m_data[this->m_size++] = element;
    }

    int &operator[](int index)
    {
        if (index < 0 || index >= this->m_size)
        {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }

    int size()
    {
        return m_size;
    }

    void print(void) const
    {
        for (int i = 0; i < this->m_size; ++i)
            std::cout << this->m_data[i] << std::endl;
    }
};
