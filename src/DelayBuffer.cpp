/*
 * DelayBuffer.cpp
 *
 *  Created on: Nov 29, 2012
 *      Author: Brandon DeRosier
 */

#include "DelayBuffer.h"

DelayBuffer::DelayBuffer() :
m_pDelay(0) {}

DelayBuffer::~DelayBuffer() {
	clear();
}

void DelayBuffer::slot(const sf::Int16* samples, std::size_t sampleCount) {
	std::vector<sf::Int16> sampleCollection;
	std::copy(samples, samples + sampleCount, std::back_inserter(sampleCollection));

	m_pSampleCollections.push_front(sampleCollection);
}

void DelayBuffer::pop() {
	m_pSampleCollections[m_pSampleCollections.size() - 1].clear();
	m_pSampleCollections.pop_back();
}

void DelayBuffer::clear() {
	int size = m_pSampleCollections.size();
	for (int i = 0; i < size; i++) {
		pop();
	}
}

void DelayBuffer::setDelay(unsigned int delay) {
	m_pDelay = delay;
}

unsigned int DelayBuffer::getDelay() {
	return m_pDelay;
}

void draw(sf::RenderWindow& w) {

}

std::vector<sf::Int16>& DelayBuffer::getSampleCollection() {
	return m_pSampleCollections[m_pSampleCollections.size() - 1];
}

int DelayBuffer::getTotalSampleCollections() {
	return m_pSampleCollections.size();
}
