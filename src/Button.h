/*
 * Button.h
 *
 *  Created on: Nov 29, 2012
 *      Author: Brandon DeRosier
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
	Button(std::string, sf::Vector2i, sf::Vector2<unsigned int>);
	virtual ~Button();

	int update(sf::RenderWindow&);
	void draw(sf::RenderWindow&);

	void setTitle(std::string);
	std::string getTitle();
	void setPosition(sf::Vector2i);
	sf::Vector2i getPosition();
	void setSize(sf::Vector2<unsigned int>);
	sf::Vector2<unsigned int> getSize();

private:
	std::string m_pTitle;
	sf::Vector2i m_pPosition;
	sf::Vector2<unsigned int> m_pSize;
	int m_pState;
};

#endif /* BUTTON_H_ */
