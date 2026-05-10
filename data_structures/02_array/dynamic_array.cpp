#include "Vector.hpp"

int main()
{
    Vector *lol = new Vector();
    lol->push_back(123);
    lol->push_back(23);
    lol->push_back(32);
    lol->push_back(84);
    lol->push_back(793);
    lol->push_back(140);
    lol->print();
}
