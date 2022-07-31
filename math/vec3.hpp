#pragma once

namespace GothEngine::math::vector
{

class vec3_t
{
public:
    float x() const;
    float y() const;
    float z() const;

    void negate();
    
private:
    float _x, _y, _z;
};

}