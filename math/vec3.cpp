#include "vec3.hpp"
#include "utility.hpp"

#include <cmath>
#include <tuple>
#include <iostream>


namespace GothEngine::math::vector
{

vec3_t::vec3_t(float x, float y, float z) : _vec{x, y, z}
{}

float vec3_t::x() const
{
    return _vec.at(0);
}

float vec3_t::y() const
{
    return _vec.at(1);
}

float vec3_t::z() const
{
    return _vec.at(2);
}

void vec3_t::negate()
{
    _vec[0] = _vec.at(0) * (-1);
    _vec[1] = _vec.at(1) * (-1);
    _vec[2] = _vec.at(2) * (-1);
}

auto vec3_t::rank() const
{
    return std::tie(_vec.at(0), _vec.at(1), _vec.at(2));
}

float vec3_t::length_squared() const
{
    return _vec.at(0) * _vec.at(0) + _vec.at(1) * _vec.at(1) + _vec.at(2) * _vec.at(2);
}

float vec3_t::length() const
{
    return utility::fast_sqrt(length_squared());
}

vec3_t& vec3_t::operator*=(float k)
{
    _vec[0] *= k;
    _vec[1] *= k;
    _vec[2] *= k;
    return *this;
}

vec3_t& vec3_t::operator/=(float k)
{
    _vec[0] /= k;
    _vec[1] /= k;
    _vec[2] /= k;
    return *this;
}

vec3_t& vec3_t::operator+=(const vec3_t& vec)
{
    _vec[0] += vec.x();
    _vec[1] += vec.y();
    _vec[2] += vec.z();
    return *this;
}

vec3_t& vec3_t::operator-=(const vec3_t& vec)
{
    _vec[0] -= vec.x();
    _vec[1] -= vec.y();
    _vec[2] -= vec.z();
    return *this;
}

bool operator==(const vec3_t& vec, const vec3_t& other)
{
    return std::fabs(vec.x() - other.x()) <= std::numeric_limits<float>::epsilon()
        && std::fabs(vec.y() - other.y()) <= std::numeric_limits<float>::epsilon()
        && std::fabs(vec.z() - other.z()) <= std::numeric_limits<float>::epsilon();
}

vec3_t operator-(const vec3_t& vec, const vec3_t& other)
{
    return {other.x() - vec.x(), other.y() - vec.y(), other.z() - vec.z()};
}

vec3_t operator*(float k, const vec3_t& vec)
{
    return {k * vec.x(), k * vec.y(), k * vec.z()};
}

vec3_t operator*(const vec3_t& vec, float k)
{
    return vec * k;
}

vec3_t operator/(const vec3_t& vec, float k)
{
    return (1 / k) * vec;
}

vec3_t unit_vector(const vec3_t& vec)
{
    return vec / vec.length();
}

float distance(const vec3_t& start, const vec3_t& end)
{
    return (end - start).length();
}

float dot(const vec3_t& u, const vec3_t& v)
{
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

vec3_t cross(const vec3_t& u, const vec3_t& v)
{
    return { u.y() * v.z() - u.z() * v.y(), u.z() * v.x() - u.x() * v.z(), u.x() * v.y() - u.y() * v.x() };
}

std::ostream& operator<<(std::ostream& out, const vec3_t& vec)
{
    return out << "{" << vec.x() << ", " << vec.y() << ", " << vec.z() << "}\n";
}

}