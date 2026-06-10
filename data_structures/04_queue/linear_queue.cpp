#include <iostream>
#define MAX_SIZE 10

class LinearQueue // Fixed Array Based
{
    int data[MAX_SIZE];
    int front = -1;
    int rear = -1;

public:
    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    bool isFull()
    {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            std::cout << "Overflow" << std::endl;
            return;
        }

        if (isEmpty())
            front = 0;

        data[++rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Underflow" << std::endl;
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
            return;
        }

        ++front;
    }

    int peek()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty\n";
            return -1;
        }

        return data[front];
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

        for (int i = front; i <= rear; i++)
        {
            std::cout << data[i] << " ";
        }

        std::cout << std::endl;
    }
};
