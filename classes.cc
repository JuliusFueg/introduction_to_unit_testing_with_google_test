#include "classes.h"

// Square
// default constructor
Square::Square() {
    width = 0;
    height = 0;
    area = 0;
}

// overloaded constructor
Square::Square(int w, int h) {
    width = w;
    height = h;
    area = w*h;
}

// setter functions
void Square::set_values(int w, int h) {
    if (w >= 100 || h >= 100) {
        throw std::range_error("set_values: Values for width or height are too big.");
    }
    else {
        width = w;
        height = h;
        area = w * h;
    }
}

void Square::set_width(int w) {
    if (w >= 100 ) {
        throw std::range_error("set_width: Value for width is too big.");
    }
    else {
        width = w;
    }
}

void Square::set_height(int h) {
    if (h >= 100) {
        throw std::range_error("set_height: Value for heigth is too big.");
    }
    else {
        height = h;
    }
}

// getter functions
int Square::get_width() {
    return width;
}

int Square::get_height() {
    return height;
}

int Square::get_area() {
    return area;
}

// area functions
int Square::calculateArea() { 
    area = width * height;
    return area;
}

bool Square::checkArea() {
    if (area >= 10) {
        return true;
    }
    else {
        return false;
    }
}

bool Square::calculateAndCheckArea(int w, int h) {
    int tmpArea = w * h;

    if (tmpArea >= 10) {
        return true;
    }
    else {
        return false;
    }
}