#include <iostream>

void update(int &x)
{
    x = x + 10;
}

int main()
{
    int a = 5;

    int &ref = a;

    std::cout << "Original a: " << a << std::endl;

    ref = 15;
    std::cout << "After modifying ref: " << a << std::endl;

    update(a);
    std::cout << "After function call: " << a << std::endl;

    return 0;
}
