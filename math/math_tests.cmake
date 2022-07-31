add_executable(math_tests tests.cpp)
target_link_libraries(math_tests 
                        PRIVATE  
                        math
                        GTest::gtest 
                        GTest::gtest_main
                        )