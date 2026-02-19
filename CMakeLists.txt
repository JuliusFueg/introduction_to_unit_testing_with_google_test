cmake_minimum_required(VERSION 3.14)
project(google_test_presentation)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# main
add_executable(
  main
  main.cc
  functions.h
  functions.cc
  classes.h
  classes.cc
)

# set main lib 
set(mainlib_files
  functions.h
  functions.cc
  classes.h
  classes.cc
)

add_library(mainlib STATIC ${mainlib_files})

# manual unit test
add_executable(
  01_ut_manual
  01_ut_manual.cc
)
target_link_libraries(
  01_ut_manual
  mainlib
)
  
##################
# gtest unit tests
enable_testing()

# include GoogleTest
include(GoogleTest)

# add all unit tests to solution
set(unitTests   02_ut_gtest;
                #03_ut_TEST;
                04_ut_TEST_F;
                #05_ut_TEST_P;
                #06_ut_TYPED_TEST;
                #07_ut_FRIEND_TEST;
                #08_ut_assert_vs_expect;
                09_ut_explicit_success_and_failure;
                10_ut_generalized_assertion;
                11_ut_boolean_conditions;
                #12_ut_binary_comparison;
                #13_ut_string_comparison;
                14_ut_floating-point_comparison;
                #15_ut_exception_assertions;
                16_ut_predicate_assertions;
                #17_ut_windows_HRESULT_assertion;
                18_ut_death_assertions)
                     
foreach(testName IN LISTS unitTests)
    message(STATUS "unit test added: ${testName}")
    
    add_executable(${testName} ${testName}.cc)
    
    #set_target_properties(${testName} PROPERTIES FOLDER "Tests")

    #target_include_directories(${testName}
    #  PRIVATE 
    #  ../src 
    #)

    target_link_libraries(${testName} gtest_main mainlib)

    add_test(NAME ${testName} COMMAND ${testName})
    
    gtest_discover_tests(${testName})
endforeach()