#include "pgs/World/Planet.hpp"

namespace Pgs
{
  Planet::Planet(double mass, double radius, Vec2 pos, Vec2 vel, Vec2 acc)
  : mMass(mass)
  , mRadius(radius)
  , mPos(pos)
  , mVel(vel)
  , mAcc(acc)
  {}

  double Planet::getMass() const
  {
    return mMass;
  }

  double Planet::getRadius() const
  {
    return mRadius;
  }

  const Vec2& Planet::getPosition() const
  {
    return mPos;
  }

  const Vec2& Planet::getVelocity() const
  {
    return mVel;
  }

  const Vec2& Planet::getAcceleration() const
  {
    return mAcc;
  }


  void Planet::setMass(double mass)
  {
    mMass = mass;
  }

  void Planet::setRadius(double radius)
  {
    mRadius = radius;
  }

  void Planet::setPosition(Vec2 pos)
  {
    mPos = pos;
  }

  void Planet::setVelocity(Vec2 vel)
  {
    mVel = vel;
  }

  void Planet::setAcceleration(Vec2 acc)
  {
    mAcc = acc;
  }
}