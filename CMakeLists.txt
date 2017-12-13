cmake_minimum_required(VERSION 3.8)
project(COMP220Bookstore)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCE_FILES bookstoreMain.cpp testMain.cpp ListTests.cpp QueueTests.cpp UI.cpp InventoryManager.cpp Person.cpp Title.cpp UITester.cpp main.cpp ArrayTitleList.cpp)

add_executable(COMP220Bookstore ${SOURCE_FILES})