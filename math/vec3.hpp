#pragma once
#include <array>
#include <iosfwd>

namespace GothEngine::math::vector
{

class vec3_t
{
public:
    vec3_t(float x, float y, float z);

    float x() const;
    float y() const;
    float z() const;

    void negate();

    auto rank() const;

    float length_squared() const;
    float length() const;

    vec3_t& operator*=(float k);
    vec3_t& operator/=(float k);
    vec3_t& operator+=(const vec3_t& vec);
    vec3_t& operator-=(const vec3_t& vec);
    
private:
    std::array<float, 3> _vec;
};

bool operator==(const vec3_t& vec, const vec3_t& other);
vec3_t operator-(const vec3_t& vec, const vec3_t& other);
vec3_t operator*(float k, const vec3_t& vec);
vec3_t operator*(const vec3_t& vec, float k);
vec3_t operator/(const vec3_t& vec, float k);

vec3_t unit_vector(const vec3_t& vec);
float distance(const vec3_t& start, const vec3_t& end);
float dot(const vec3_t& u, const vec3_t& v);
vec3_t cross(const vec3_t& u, const vec3_t& v);

std::ostream& operator<<(std::ostream& out, const vec3_t& vec);
}