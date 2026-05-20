#include <stdexcept>

template <typename T, int SIZE>
class StaticStack
{
private:
    T data[SIZE];
    int top = -1;

public:
    void push(const T &item)
    {
        if (isFull())
            throw std::out_of_range("Stack Overflow");

        data[++top] = item;
    }

    T pop(void)
    {
        if (isEmpty())
            throw std::out_of_range("Stack Underflow");

        return data[top--];
    }

    bool isEmpty(void) const
    {
        return top == -1;
    }

    bool isFull(void) const
    {
        return top == SIZE - 1;
    }

    const T &peek() const
    {
        if (isEmpty())
            throw std::out_of_range("Stack is Empty");
        return data[top];
    }

    int size() const
    {
        return top + 1;
    }
};
