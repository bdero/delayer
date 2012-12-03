/*
 * DelayRecorder.cpp
 *
 *  Created on: Nov 29, 2012
 *      Author: Brandon DeRosier
 */

#include "DelayRecorder.h"

DelayRecorder::DelayRecorder(DelayBuffer* buffer) :
m_pBuffer(buffer) {}

DelayRecorder::~DelayRecorder() {}

bool DelayRecorder::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount) {
	m_pBuffer->slot(samples, sampleCount);

	return true;
}
