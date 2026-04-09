#include <iostream>

int main()
{
    int a = 10;

    // pointer declaration
    int *p = &a;

    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Address of a: " << &a << std::endl;

    std::cout << "Pointer p (address): " << p << std::endl;
    std::cout << "Value at pointer p: " << *p << std::endl;

    // modifying value using pointer
    *p = 20;
    std::cout << "Modified value of a: " << a << std::endl;

    return 0;
}
