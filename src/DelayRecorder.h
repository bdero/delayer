/*
 * DelayRecorder.h
 *
 *  Created on: Nov 29, 2012
 *      Author: Brandon DeRosier
 */

#ifndef DELAYRECORDER_H_
#define DELAYRECORDER_H_

#include <SFML/Audio.hpp>
#include "DelayBuffer.h"

class DelayRecorder: public sf::SoundRecorder {
public:
	DelayRecorder(DelayBuffer*);
	virtual ~DelayRecorder();

private:
	DelayBuffer* m_pBuffer;

	virtual bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount);
};

#endif /* DELAYRECORDER_H_ */
