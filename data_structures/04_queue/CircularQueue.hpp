#include <iostream>
#define MAX_SIZE 6

class CircularQueue
{
    int front;
    int rear;
    int data[MAX_SIZE];

public:
    CircularQueue() : front(-1), rear(-1)
    {
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    bool isFull()
    {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int element)
    {
        if (isFull())
        {
            std::cout << "Queue is full." << std::endl;
            return;
        }

        if (isEmpty())
        {
            rear = front = 0;
            data[front] = element;
            return;
        }

        rear = (rear + 1) % MAX_SIZE;
        data[rear] = element;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue underflow" << std::endl;
            return -1;
        }

        int element = data[rear];

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }

        return element;
    }
};
