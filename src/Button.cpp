/*
 * Button.cpp
 *
 *  Created on: Nov 29, 2012
 *      Author: Brandon DeRosier
 */

#include "Button.h"

Button::Button(std::string title, sf::Vector2i position, sf::Vector2<unsigned int> size) :
m_pTitle(title),
m_pPosition(position),
m_pSize(size),
m_pState(0) {
}

Button::~Button() {}

int Button::update(sf::RenderWindow& w) {
	sf::Vector2i mp = sf::Mouse::getPosition(w);

	if (mp.x > m_pPosition.x && mp.x < m_pPosition.x + m_pSize.x &&
			mp.y > m_pPosition.y && mp.y < m_pPosition.y + m_pSize.y) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			m_pState = 2; // Mouse down
		} else if (m_pState == 2) {
			m_pState = 3; // Mouse up (clicked)
		} else {
			m_pState = 1; // Mouse over
		}
	} else {
		m_pState = 0; // Mouse out
	}

	return m_pState;
}

void Button::draw(sf::RenderWindow& w) {
	sf::RectangleShape rect(sf::Vector2f(m_pSize.x, m_pSize.y));
	rect.setPosition(m_pPosition.x, m_pPosition.y);
	sf::Color color;
	switch(m_pState) {
	case 0:
		color = sf::Color::Cyan;
		break;
	case 1:
		color = sf::Color::Green;
		break;
	case 2:
		color = sf::Color::Yellow;
		break;
	case 3:
		color = sf::Color::Red;
		break;
	}
	rect.setFillColor(color);

	w.draw(rect);
}

void Button::setTitle(std::string title) {
	m_pTitle = title;
}

std::string Button::getTitle() {
	return m_pTitle;
}

void Button::setPosition(sf::Vector2i position) {
	m_pPosition = position;
}

sf::Vector2i Button::getPosition() {
	return m_pPosition;
}

void Button::setSize(sf::Vector2<unsigned int> size) {
	m_pSize = size;
}

sf::Vector2<unsigned int> Button::getSize() {
	return m_pSize;
}
