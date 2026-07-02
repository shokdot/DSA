#include <iostream>
#include <stdexcept>
#define MAX_SIZE 5

class LinearQueue
{
    int front;
    int rear;
    int data[MAX_SIZE];

public:
    LinearQueue() : front(-1), rear(-1)
    {
    }

    bool isEmpty() const
    {
        return front == -1 && rear == -1;
    }

    bool isFull() const
    {
        return rear == MAX_SIZE - 1;
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
            front = rear = 0;
            data[rear] = x;
            return;
        }

        data[++rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
            throw std::out_of_range("Underflow");

        if (front == rear)
        {
            front = rear = -1;
            return;
        }

        ++front;
    }

    int size()
    {
        if (isEmpty())
            return 0;

        return rear - front + 1;
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty\n";
            return;
        }

        for (int i = front; i <= rear; ++i)
        {
            std::cout << data[i] << ' ';
        }

        std::cout << '\n';
    }
};
