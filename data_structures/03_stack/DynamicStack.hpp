#include <vector>

template <typename T>
class DynamicStack
{
private:
    std::vector<T> data;

public:
    void push(T value)
    {
        data.push_back(value);
    }

    T peek(void) const
    {
        if (data.empty())
            throw std::out_of_range("Stack Underflow");

        return data.back();
    }

    T pop(void)
    {
        if (data.empty())
            throw std::out_of_range("Stack Underflow");

        return data.pop_back();
    }

    int size() const
    {
        return data.size();
    }

    bool isEmpty() const
    {
        return data.empty();
    }
};
