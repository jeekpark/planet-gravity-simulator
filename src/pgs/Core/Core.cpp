/**
 * @file Core.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "pgs/Core/Core.hpp"


namespace Pgs
{
  void Core::run()
  {
    mSpace.addPlanet(500000000000000000, 10, Vec2(WINDOW_X/2, WINDOW_Y/2), Vec2(0, 0), Vec2(0, 0));
    mSpace.addPlanet(1, 10, Vec2(1000, 500), Vec2(1000, 0), Vec2(0, 0));
    mSpace.addPlanet(1, 10, Vec2(1000, 503), Vec2(1000, 0), Vec2(0, 0));
    mWindow.create(sf::VideoMode(WINDOW_X, WINDOW_Y), "a");
    mWindow.setFramerateLimit(60);
    a.setRadius(5);
    b.setRadius(1);
    c.setRadius(1);
    a.setFillColor(sf::Color::Red);
    b.setFillColor(sf::Color::Red);
    c.setFillColor(sf::Color::Green);


    while (mWindow.isOpen())
    {
      sf::Event event;
      while (mWindow.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
        {
          mWindow.close();
        }
        
      }
      mSpace.update(16.66);
      mWindow.clear();
      a.setPosition(mSpace.getPlanets()[0].getPosition().getX(),mSpace.getPlanets()[0].getPosition().getY());
      b.setPosition(mSpace.getPlanets()[1].getPosition().getX(),mSpace.getPlanets()[1].getPosition().getY());
      c.setPosition(mSpace.getPlanets()[2].getPosition().getX(),mSpace.getPlanets()[2].getPosition().getY());
      for (const Planet& p : mSpace.getPlanets())
      {
        std::cout << p.getPosition().getX() << " " << p.getPosition().getY() << std::endl;
      }
      mWindow.draw(a);
      mWindow.draw(b);
      mWindow.draw(c);
      mWindow.display();
    }
  }
}