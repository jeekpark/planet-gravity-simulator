#pragma once

#include "pgs/common.hpp"

namespace Pgs
{
  class Vec2
  {
  public:
    Vec2(float x = 0.f, float y = 0.f) : mX(x), mY(y) {}

    float getX() const { return mX; }
    float getY() const { return mY; }

    void setX(float x) { mX = x; }
    void setY(float y) { mY = y; }

    Vec2 operator+(const Vec2& other) const { return Vec2(mX + other.mX, mY + other.mY); }
    Vec2 operator-(const Vec2& other) const { return Vec2(mX - other.mX, mY - other.mY); }
    Vec2 operator*(float scalar) const { return Vec2(mX * scalar, mY * scalar); }
    Vec2 operator/(float scalar) const { return Vec2(mX / scalar, mY / scalar); }

    float dot(const Vec2& other) const { return mX * other.mX + mY * other.mY; }
    float length() const { return std::sqrt(mX * mX + mY * mY); }
    float distance(const Vec2& other) const { return (*this - other).length(); }
    Vec2 normalize() const { return Vec2(mX / length(), mY / length()); }
    Vec2 rotate(float rad) const { return Vec2(mX * std::cos(rad) - mY * std::sin(rad), mX * std::sin(rad) + mY * std::cos(rad)); }

  private:
    float mX;
    float mY;
  };
}