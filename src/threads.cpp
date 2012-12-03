/*
 * threads.cpp
 *
 *  Created on: Nov 27, 2012
 *      Author: Brandon DeRosier
 */

#include "threads.h"

bool isRunning = true;

void updateFunc(sf::RenderWindow* window) {
	Delayer* delayer = Delayer::Instance();
	//delayer->start();

	sf::Clock clock;

	float timeMultiplier = 0.0f;
	sf::Int64 optimalTime = 1000000/UPDATE_RATE;
	sf::Int64 time;

	while (isRunning) {
		clock.restart();
		if (!delayer->update(*window, timeMultiplier)) {
			isRunning = false;
			break;
		}
		time = clock.getElapsedTime().asMicroseconds();

		if (time > optimalTime) {
			timeMultiplier = static_cast<float>(time)/static_cast<float>(optimalTime);
		} else {
			timeMultiplier = 1.0f;

			if (time < optimalTime) {
				sf::sleep(sf::microseconds(optimalTime - time));
			}
		}
	}
}

void drawFunc(sf::RenderWindow* window) {
	Delayer* delayer = Delayer::Instance();
	sf::Clock clock;

	sf::Int64 optimalTime = 1000000/DRAW_RATE;
	sf::Int64 time;

	while (isRunning) {
		clock.restart();
		delayer->draw(*window);
		time = clock.getElapsedTime().asMicroseconds();

		if (time < optimalTime) {
			sf::sleep(sf::microseconds(optimalTime - time));
		}
	}

	window->close();
}

