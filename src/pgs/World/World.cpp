/**
 * @file World.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "pgs/World/World.hpp"


namespace Pgs
{
  World::World()
  {}
  
  void World::addPlanet(double mass, double radius, Vec2 pos, Vec2 vel, Vec2 acc)
  {
    mPlanets.push_back(Planet(mass, radius, pos, vel, acc));
  }

  void World::update(double ms)
  {
    const double G = 6.674e-11;
    
    for (Planet& p : mPlanets)
    {
      p.setAcceleration(Vec2(0, 0));
    }

    for (size_t i = 0; i < mPlanets.size(); ++i)
    {
      for (size_t j = i + 1; j < mPlanets.size(); ++j)
      {
        Vec2 pos1 = mPlanets[i].getPosition();
        Vec2 pos2 = mPlanets[j].getPosition();
        Vec2 direction = pos2 - pos1;
        double distance = direction.length();
        double forceMagnitude = (G * mPlanets[i].getMass() * mPlanets[j].getMass()) / (distance * distance);
        Vec2 force = direction.normalize() * forceMagnitude;
        Vec2 acceleration1 = force / mPlanets[i].getMass();
        mPlanets[i].setAcceleration(mPlanets[i].getAcceleration() + acceleration1);
        Vec2 acceleration2 = force / mPlanets[j].getMass();
        mPlanets[j].setAcceleration(mPlanets[j].getAcceleration() - acceleration2);

      }
    }

    for (Planet &planet : mPlanets)
    {
      Vec2 newVelocity = planet.getVelocity() + planet.getAcceleration() * (ms / 1000.0);
      Vec2 newPosition = planet.getPosition() + newVelocity * (ms / 1000.0);
      
      planet.setVelocity(newVelocity);
      planet.setPosition(newPosition);
    }
  }

}