/**
 * @file Planet.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include "pgs/common.hpp"
#include "pgs/Helper/Vec2.hpp"

namespace Pgs
{
  class Planet
  {
  public:
    Planet(double mass, double radius, Vec2 pos, Vec2 vel, Vec2 acc);
  
  public:
    double getMass() const;
    double getRadius() const;
    const Vec2& getPosition() const;
    const Vec2& getVelocity() const;
    const Vec2& getAcceleration() const;

    void setMass(double mass);
    void setRadius(double radius);
    void setPosition(Vec2 pos);
    void setVelocity(Vec2 vel);
    void setAcceleration(Vec2 acc);
    
  private:
    double mMass;
    double mRadius;
    Vec2 mPos;
    Vec2 mVel;
    Vec2 mAcc;
  };
}