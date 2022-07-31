#include "vec2.hpp"
#include "utility.hpp"

#include <cmath>
#include <tuple>
#include <iostream>

namespace GothEngine::math::vector
{

vec2_t::vec2_t(float x, float y) : _vec{x, y}
{}

float vec2_t::x() const
{
    return _vec.at(0);
}

float vec2_t::y() const
{
    return _vec.at(1);
}

void vec2_t::negate()
{
    _vec[0] = _vec[0] * (-1);
    _vec[1] = _vec[1] * (-1);
}

float vec2_t::length_squared() const
{
    return _vec.at(0) * _vec.at(0) + _vec.at(1) * _vec.at(1);
}

float vec2_t::length() const
{
    return utility::fast_sqrt(length_squared());
}

vec2_t& vec2_t::operator*=(float k)
{
    _vec[0] *= k;
    _vec[1] *= k;
    return *this;
}

vec2_t& vec2_t::operator/=(float k)
{
    return *this *= 1 / k;
}

vec2_t& vec2_t::operator+=(const vec2_t& vec)
{
    _vec[0] += vec.x();
    _vec[1] += vec.y();
    return *this;
}

vec2_t& vec2_t::operator-=(const vec2_t& vec)
{
    _vec[0] -= vec.x();
    _vec[1] -= vec.y();
    return *this;
}

bool operator==(const vec2_t& vec, const vec2_t& other)
{
    return std::fabs(vec.x() - other.x()) <= std::numeric_limits<float>::epsilon()
        && std::fabs(vec.y() - other.y()) <= std::numeric_limits<float>::epsilon();
}

vec2_t operator-(const vec2_t& vec, const vec2_t& other)
{
    return {other.x() - vec.x(), other.y() - vec.y()};
}

vec2_t operator*(float k, const vec2_t& vec)
{
    return {k * vec.x(), k * vec.y()};
}

vec2_t operator*(const vec2_t& vec, float k)
{
    std::cout << k << std::endl;
    return vec * k;
}

vec2_t operator/(const vec2_t& vec, float k)
{
    return (1 / k) * vec;
}

vec2_t unit_vector(const vec2_t& vec)
{
    return vec / vec.length();
}

float distance(const vec2_t& start, const vec2_t& end)
{
    return (end - start).length();
}

float dot(const vec2_t& u, const vec2_t& v)
{
    return u.x() * v.x() + u.y() * v.y();
}

std::ostream& operator<<(std::ostream& out, const vec2_t& vec)
{
    return out << "{" << vec.x() << ", " << vec.y() << "}\n";
}

}