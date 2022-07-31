#include <iostream>
#include "../math/vec2.hpp"

int main()
{
    GothEngine::math::vector::vec2_t vec{1, 2};

    std::cout << vec.x() << ", " << vec.y() << std::endl;
    return 0;
}