#include "StaticStack.hpp"
#include "DynamicStack.hpp"
#include <iostream>

int main()
{
    StaticStack<int, 10> s;
    DynamicStack<double> d_stack;

    s.push(5);
    s.push(10);

    std::cout << s.peek(); // 10

    std::cout << s.pop(); // 10
    std::cout << s.pop(); // 5

    d_stack.push(3.14159);
    d_stack.push(2.7182);
}
