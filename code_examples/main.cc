#include <iostream>
#include "classes.h"
#include "functions.h"

int main()
{
    // use function
    int a = 10, b = 5, c;
    c = divideTwoInts(a, b);
    std::cout << "The quotient of " << a << " and " << b << " = " << c << std::endl;

    // use class
    Square SquareA;
    SquareA.set_values(4, 5);
    std::cout << "The area of SquareA = " << SquareA.calculateArea() << std::endl;

    return 0;
}
