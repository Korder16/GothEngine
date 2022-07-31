#include "vec2.hpp"

namespace GothEngine::math::vector
{
    vec2_t::vec2_t(float x, float y) : _x{x}, _y{y}
    {}

    float vec2_t::x() const
    {
        return _x;
    }

    float vec2_t::y() const
    {
        return _y;
    }

    void vec2_t::negate()
    {
        _x = _x * (-1);
        _y = _y * (-1);
    }
}