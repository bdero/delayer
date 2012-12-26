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
	Button(std::string, sf::Vector2i, sf::Vector2<unsigned int>, bool);
	virtual ~Button();

	int update(sf::RenderWindow&);
	void draw(sf::RenderWindow&);

	void setTitle(std::string);
	std::string getTitle();
	void setPosition(sf::Vector2i);
	sf::Vector2i getPosition();
	void setSize(sf::Vector2<unsigned int>);
	sf::Vector2<unsigned int> getSize();
	void setImage(sf::Image&, sf::Rect<int>&);
	void setToggle(bool);
	bool getToggle();
	void setDoesToggle(bool);
	bool getDoesToggle();
	bool isStateChanged();
	bool isToggleChanged();

private:
	std::string m_pTitle;
	sf::Vector2i m_pPosition;
	sf::Vector2<unsigned int> m_pSize;
	int m_pState;
	int m_pPreviousDrawState;
	sf::Rect<int> m_pImageRect;
	sf::Image* m_pDisplayImage;
	sf::Rect<int> m_pDisplayRect;
	bool m_pUsingTexture;
	bool m_pToggle;
	bool m_pPreviousDrawToggle;
	bool m_pDoesToggle;
};

#endif /* BUTTON_H_ */
