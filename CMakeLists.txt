cmake_minimum_required(VERSION 3.2)

project(DynamicTextSearch)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -pthread")

set(SOURCE_FILES
    TextSearch.cpp TextSearch.h
    Naive.cpp Naive.h
    KnuthMorrisPratt.cpp KnuthMorrisPratt.h
    BoyerMooreHorspool.cpp BoyerMooreHorspool.h
    PerformanceChecker.cpp PerformanceChecker.h)

add_executable(DynamicTextSearch ${SOURCE_FILES})

include(ExternalProject)
ExternalProject_Add(gtest
        URL http://googletest.googlecode.com/files/gtest-1.7.0.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        INSTALL_COMMAND ""
        )
ExternalProject_Get_Property(gtest source_dir binary_dir)

################
# Define a test
set(TEST_SOURCE_FILES
        Naive.cpp Naive.h
        KnuthMorrisPratt.cpp KnuthMorrisPratt.h
        BoyerMooreHorspool.cpp BoyerMooreHorspool.h)

add_executable(textsearch_test UnitTests.cpp ${TEST_SOURCE_FILES})

######################################
# Configure the test to use GoogleTest
add_dependencies(textsearch_test gtest)
include_directories(${source_dir}/include)
target_link_libraries(textsearch_test ${binary_dir}/libgtest.a)
target_link_libraries(textsearch_test ${binary_dir}/libgtest_main.a)

##################################
# Just make the test runnable with
#   $ make test
enable_testing()
add_test(NAME   textsearch_test
        COMMAND textsearch_test)
