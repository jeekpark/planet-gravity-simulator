/**
 * @file World.hpp
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

#include "pgs/World/Planet.hpp"

namespace Pgs
{
  class World
  {
  public:
    World();

  public:
    void addPlanet(double mass, double radius, Vec2 pos, Vec2 vel, Vec2 acc);
  public:
    void update(double ms);
    const std::vector<Planet>& getPlanets() const
    {
      return mPlanets;
    }
  private:
    std::vector<Planet> mPlanets;
  };
}
