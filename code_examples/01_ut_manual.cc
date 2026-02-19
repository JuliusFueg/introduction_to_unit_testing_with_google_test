#include <iostream>
#include "functions.h"

// example of manual testing the divideTwoInts function

// test suite
int main() {

  // test case
  // define preconditions and expected results
  int a=10, b=5, expectedResult=2, result; 
 
  // trigger function under test
  result = divideTwoInts(a, b);

  // define postconditions and evaluate results
  if (result == expectedResult){
      std::cout << "The test passed." << std::endl;
      return 0;
  }else{
      std::cout << "The test failed." << std::endl;
      return 1;
  }
 
}



/*
Things that could be tested and added :

- functionality: Does defined input - always - lead to the expected output
- range of input parameters and output parameters
- error handling: Does the function call throw an exception? How does the function handle false input? 
- manual writing of assertions
- information about test result missing: test suite, test case, output, errors, etc.

etc.

-> its possible to write a unit test with C++ syntax but it will probably be more tedious, less flexible and harder to scale.
-> testing frameworks will make this easier :)

*/