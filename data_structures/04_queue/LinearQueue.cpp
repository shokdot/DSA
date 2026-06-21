#include <iostream>
#include <stdexcept>
#define MAX_SIZE 5

class LinearQueue
{
    int front;
    int back;
    int data[MAX_SIZE];

public:
    LinearQueue() : front(-1), back(-1)
    {
    }

    bool isEmpty() const
    {
        return front == -1 && back == -1;
    }

    bool isFull() const
    {
        return back == MAX_SIZE - 1;
    }

    int peek() const
    {
        if (isEmpty())
            throw std::out_of_range("Queue is empty");

        return data[front];
    }

    void enqueue(int x)
    {
        if (isFull())
            throw std::out_of_range("Overflow");

        if (isEmpty())
        {
            front = back = 0;
            data[back] = x;
            return;
        }

        data[++back] = x;
    }

    void dequeue()
    {
        if (isEmpty())
            throw std::out_of_range("Underflow");

        if (front == back)
        {
            front = back = -1;
            return;
        }

        ++front;
    }
};
