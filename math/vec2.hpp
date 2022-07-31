#pragma once

#include <array>
#include <iosfwd>

namespace GothEngine::math::vector
{

class vec2_t
{
public:
    vec2_t(float x, float y);
    
    float at(int index) const;

    float x() const;
    float y() const;

    void negate();

    auto rank() const;

    float length_squared() const;
    float length() const;

    vec2_t& operator*=(float k);
    vec2_t& operator/=(float k);
    vec2_t& operator+=(const vec2_t& vec);
    vec2_t& operator-=(const vec2_t& vec);

private:
    std::array<float, 2> _vec;
};

bool operator==(const vec2_t& vec, const vec2_t& other);
vec2_t operator-(const vec2_t& vec, const vec2_t& other);
vec2_t operator*(float k, const vec2_t& vec);
vec2_t operator*(const vec2_t& vec, float k);
vec2_t operator/(const vec2_t& vec, float k);

vec2_t unit_vector(const vec2_t& vec);
float distance(const vec2_t& start, const vec2_t& end);
float dot(const vec2_t& u, const vec2_t& v);

std::ostream& operator<<(std::ostream& out, const vec2_t& vec);

}