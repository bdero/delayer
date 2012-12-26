/*
 * Button.cpp
 *
 *  Created on: Nov 29, 2012
 *      Author: Brandon DeRosier
 */

#include <iostream>
#include "Button.h"

Button::Button(std::string title, sf::Vector2i position, sf::Vector2<unsigned int> size, bool doesToggle) :
m_pTitle(title),
m_pPosition(position),
m_pSize(size),
m_pState(0),
m_pPreviousDrawState(-1),
m_pImageRect(),
m_pDisplayImage(),
m_pDisplayRect(0, 0, m_pSize.x, m_pSize.y),
m_pUsingTexture(false),
m_pToggle(false),
m_pPreviousDrawToggle(false),
m_pDoesToggle(doesToggle) {
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

			if (m_pDoesToggle)
				m_pToggle = !m_pToggle;
		} else {
			m_pState = 1; // Mouse over
		}
	} else {
		m_pState = 0; // Mouse out
	}

	return m_pState;
}

void Button::draw(sf::RenderWindow& w) {
	if (!m_pUsingTexture) {
		sf::Vector2f size(m_pSize.x, m_pSize.y);
		sf::RectangleShape rect(size);
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
	} else {
		//sf::Rect<int> rect(0, 0, m_pSize.x, m_pSize.y);
		if (isStateChanged() || isToggleChanged()) {
			m_pDisplayRect.top = 0;
			switch(m_pState) {
			case 0:
				break;
			default:
				m_pDisplayRect.top = 50;
				break;
			}

			if (m_pToggle)
				m_pDisplayRect.top += 100;
		}

		sf::Texture tex;
		tex.loadFromImage(*m_pDisplayImage, m_pImageRect);
		sf::Sprite spr;
		spr.setTexture(tex);
		spr.setTextureRect(m_pDisplayRect);
		spr.setPosition(m_pPosition.x, m_pPosition.y);
		w.draw(spr);
	}
}

bool Button::isStateChanged() {
	bool result = m_pState != m_pPreviousDrawState;

	if (result)
		m_pPreviousDrawState = m_pState;

	return result;
}

bool Button::isToggleChanged() {
	bool result = m_pToggle != m_pPreviousDrawToggle;

	if (result)
		m_pPreviousDrawToggle = m_pToggle;

	return result;
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

void Button::setImage(sf::Image& image, sf::Rect<int>& rect) {
	m_pDisplayImage = new sf::Image(image);
	m_pImageRect = rect;

	if (!m_pUsingTexture)
		m_pUsingTexture = true;
}

void Button::setToggle(bool toggle) {
	m_pToggle = toggle;
}

bool Button::getToggle() {
	return m_pToggle;
}

void Button::setDoesToggle(bool doesToggle) {
	m_pDoesToggle = doesToggle;
}

bool Button::getDoesToggle() {
	return m_pDoesToggle;
}
