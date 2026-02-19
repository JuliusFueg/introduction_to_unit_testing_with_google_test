#include "functions.h"

int divideTwoInts(int dividend, int divisor) {

    if ( divisor == 0) {

        throw std::invalid_argument("The divisor is 0.");
    }
    else {
        return dividend / divisor;
    }

}

















bool isIntEven(int a) {
    if (a % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

float divideTwoFloats(float a, float b) {
    
    if (b == 0) {

        throw std::invalid_argument("The divisor is 0.");
    }
    else {
        return a / b;
    }
}

double divideTwoDoubles(double a, double b) {
    
    if (b == 0) {

        throw std::invalid_argument("The divisor is 0.");
    }
    else {
        return a / b;
    }
}


bool isIntSumEven(int a, int b) {
    if ( (a+b) % 2 == 0 ) {
        return true;
    }
    else {
        return false;
    }
}

void zeroCheck(int a) {
    
    if (a == 0) {
        std::cerr << "The number is 0. Can't be used as divisor. " << std::endl;
        exit(1);
    }
    else
    {
        //std::cerr << "The number is !0. Can be used as divisor. " << std::endl;
        exit(0);
    }

}
