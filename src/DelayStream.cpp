/*
 * DelayStream.cpp
 *
 *  Created on: Nov 29, 2012
 *      Author: Brandon DeRosier
 */

#include "DelayStream.h"

DelayStream::DelayStream(DelayBuffer* buffer) :
m_pBuffer(buffer) {
	initialize(1, SAMPLE_COUNT);
}

DelayStream::~DelayStream() {}

bool DelayStream::onGetData(sf::SoundStream::Chunk& data) {
	while (m_pBuffer->getTotalSampleCollections() < m_pBuffer->getDelay() + 1)
		sf::sleep(sf::milliseconds(10));

	std::vector<sf::Int16>& samples = m_pBuffer->getSampleCollection();
	m_pTempBuffer.assign(samples.begin(), samples.end());
	m_pBuffer->pop();

	data.samples = &m_pTempBuffer[0];
	data.sampleCount = m_pTempBuffer.size();

	return true;
}

void DelayStream::onSeek(sf::Time timeOffset) {}
