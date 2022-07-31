set(HEADER_FILES vec2.hpp vec3.hpp utility.hpp)
set(SOURCE_FILES vec2.cpp vec3.cpp utility.cpp)

add_library(math 
            STATIC 
            ${HEADER_FILES}
            ${SOURCE_FILES}
            )