#include <stdexcept>
#include <iostream>

class Vector
{
private:
    int *arr;
    int size;
    int capacity;

public:
    Vector() : size(0), capacity(1)
    {
        this->arr = new int[capacity];
    }
    Vector(int capacity) : size(0), capacity(capacity)
    {
        this->arr = new int[capacity];
    }
    ~Vector()
    {
        delete[] this->arr;
    }
    void resize(void)
    {
        this->capacity *= 2;
        int *temp = new int[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            temp[i] = this->arr[i];
        }
        delete[] this->arr;
        this->arr = temp;
    }
    void push_back(int data)
    {
        if (this->size >= this->capacity)
            resize();
        this->arr[this->size] = data;
        ++this->size;
    }
    int &operator[](int index)
    {
        if (index < 0 || index >= this->size)
        {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
    void print(void) const
    {
        for (int i = 0; i < this->size; ++i)
            std::cout << arr[i] << std::endl;
    }
};
