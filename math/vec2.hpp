#pragma once

namespace GothEngine::math::vector
{

class vec2_t
{
public:
    vec2_t(float x, float y);
    float x() const;
    float y() const;

    void negate();

private:
    float _x, _y;
};

}