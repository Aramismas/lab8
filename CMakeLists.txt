MAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(main
  preorder_iterator.cpp
  binary_iterator.cpp
  visitor.cpp
  main.cpp
)

ADD_EXECUTABLE(test
   preorder_iterator.cpp
   binary_iterator.cpp
   visitor.cpp 
   unit_test.cpp
    
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON) 
