#include <iostream>

int main()
{
    const int SIZE = 5;
    int x[SIZE]; // static array without intialization (stack)

    int x1[6] = {0, 1, 2, 3, 4, 5}; // static array with initialization (stack)

    int *heap_arr = new int[SIZE]; // allocating SIZE array (heap)

    for (int i = 0; i < SIZE; i++) // iterating through array for initialization (heap)
    {
        heap_arr[i] = (i + 2) * 12; // some kind of math formula to fill array
    }

    for (int i = 0; i < SIZE; i++) // iterating through array to print it
    {
        std::cout << heap_arr[i] << std::endl; // stdout array
    }

    delete[] heap_arr;
}
