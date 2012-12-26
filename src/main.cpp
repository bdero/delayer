/*
 * main.cpp
 *
 *  Created on: Nov 27, 2012
 *      Author: Brandon DeRosier
 */

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <functional>

#include "threads.h"
#include "Delayer.h"
#include "config.h"

int main(int argc, char** argv) {
	/*Delayer* pDelayer = */Delayer::Instance();

	sf::RenderWindow window(sf::VideoMode(WINDOW_BOUNDS), WINDOW_TITLE, sf::Style::Default);

	sf::Thread updateThread(&updateFunc, &window);
	//sf::Thread drawThread(&drawFunc, &window);

	updateThread.launch();

	drawFunc(&window);

	updateThread.wait();

	//sf::sleep(sf::milliseconds(200));

	return 0;
}
