add_executable(math_tests tests.cpp)
target_link_libraries(math_tests 
                        PRIVATE  
                        math
                        GTest::gtest
                        GTest::gtest_main
                        )

set_target_properties(math_tests
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)