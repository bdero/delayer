/*
 * threads.h
 *
 *  Created on: Nov 27, 2012
 *      Author: Brandon DeRosier
 */

#ifndef THREADS_H_
#define THREADS_H_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Delayer.h"
#include "config.h"

void updateFunc(sf::RenderWindow*);

void drawFunc(sf::RenderWindow*);

#endif /* THREADS_H_ */
