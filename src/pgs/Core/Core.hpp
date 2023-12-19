/**
 * @file Core.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "pgs/common.hpp"


namespace Pgs
{
	class Core
	{
	public:
		void run()
		{
			mScale =  0.000021541139268;
			mSunRadius = 1392684. / 2;
			mWindow.create(sf::VideoMode(WINDOW_X, WINDOW_Y), "a");
			mWindow.setFramerateLimit(60);

			mSun.setFillColor(sf::Color::Red);
			mSun.setPosition((float)WINDOW_X / 2, (float)WINDOW_Y / 2);
			mSun.setRadius(50.f);
			mSun.setOrigin(mSun.getRadius(), mSun.getRadius());
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

				mWindow.clear();

				mWindow.draw(mSun);
				mWindow.display();
			}
		}
	private:
		double mScale;
		double mSunRadius;//km
		sf::RenderWindow mWindow;
		sf::CircleShape mSun;

		
	};
}