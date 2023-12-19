/**
 * @file main.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "pgs/Core/Core.hpp"

int main(const int argc, const char** argv)
{
	Pgs::Core* app = new Pgs::Core();

	app->run();
	
	delete app;

	return 0;
}