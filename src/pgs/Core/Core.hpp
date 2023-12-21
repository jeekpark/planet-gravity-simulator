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
#include "pgs/World/World.hpp"

namespace Pgs
{
	class Core
	{
	public:
		void run();
		
	private:
		sf::CircleShape a;
		sf::CircleShape b;
		sf::CircleShape c;
		sf::RenderWindow mWindow;
		World mSpace;

		
	};
}