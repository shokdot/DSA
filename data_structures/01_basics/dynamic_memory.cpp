#include <iostream>

int main()
{
    // allocate single int
    int *p = new int;
    *p = 42;

    std::cout << "Value: " << *p << std::endl;

    delete p;

    // allocate array
    int n = 5;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i * 10;
    }

    std::cout << "Array elements: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;

    return 0;
}
