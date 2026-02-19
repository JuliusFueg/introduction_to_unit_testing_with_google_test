#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <exception>
#include <stdexcept>
#include <typeinfo>

class Square
{
protected:
    int width, height, area;

public:
    Square();
    Square(int, int);

    void set_values(int, int);
    void set_width(int);
    void set_height(int);

    int get_width();
    int get_height();
    int get_area();

    int calculateArea();
    bool checkArea();
    bool calculateAndCheckArea(int, int);
};

#endif
