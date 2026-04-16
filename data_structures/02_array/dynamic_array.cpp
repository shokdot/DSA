#include <iostream>
#include "Vector.hpp"
#include <cassert>

void test_push_back()
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    assert(v.size() == 3);
    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 3);
}

void test_pop_back()
{
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    assert(v.pop_back() == 20);
    assert(v.size() == 1);
    assert(v.pop_back() == 10);
    assert(v.empty());
}

void test_insertAt()
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.insertAt(1, 2);
    assert(v.size() == 3);
    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 3);
}

void test_deleteAt()
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.deleteAt(1);
    assert(v.size() == 2);
    assert(v[0] == 1);
    assert(v[1] == 3);
}

void test_at()
{
    Vector<int> v;
    v.push_back(5);
    assert(v.at(0) == 5);
    try
    {
        v.at(1);
        assert(false); // Should not reach here
    }
    catch (const std::out_of_range &)
    {
    }
}

void test_reserve()
{
    Vector<int> v;
    v.reserve(100);
    assert(v.capacity() >= 100);
}

void test_front_back()
{
    Vector<int> v;
    v.push_back(7);
    v.push_back(8);
    assert(v.front() == 7);
    assert(v.back() == 8);
}

int main()
{
    test_push_back();
    test_pop_back();
    test_insertAt();
    test_deleteAt();
    test_at();
    test_reserve();
    test_front_back();
    std::cout << "All Vector tests passed!\n";
    return 0;
}
