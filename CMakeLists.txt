cmake_minimum_required(VERSION 3.8)
project(COMP220Bookstore)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES bookstoreMain.cpp testMain.cpp ListTests.cpp QueueTests.cpp main.cpp UI.cpp SortedTitleList.cpp)

add_executable(COMP220Bookstore ${SOURCE_FILES})