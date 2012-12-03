/*
 * DelayBuffer.h
 *
 *  Created on: Nov 29, 2012
 *      Author: Brandon DeRosier
 */

#ifndef DELAYBUFFER_H_
#define DELAYBUFFER_H_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <deque>

class DelayBuffer {
public:
	DelayBuffer();
	virtual ~DelayBuffer();

	void slot(const sf::Int16*, std::size_t);
	void pop();
	void clear();

	void setDelay(unsigned int);
	unsigned int getDelay();

	void draw(sf::RenderWindow&);

	std::vector<sf::Int16>& getSampleCollection();
	int getTotalSampleCollections();

private:
	std::deque<std::vector<sf::Int16> > m_pSampleCollections;
	unsigned int m_pDelay;
};

#endif /* DELAYBUFFER_H_ */
