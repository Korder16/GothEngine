#include "vec3.hpp"

namespace GothEngine::math::vector
{
    float vec3_t::x() const
    {
        return _x;
    }

    float vec3_t::y() const
    {
        return _y;
    }

    float vec3_t::z() const
    {
        return _z;
    }

    void vec3_t::negate()
    {
        _x = _x * (-1);
        _y = _y * (-1);
        _z = _z * (-1);
    }
}