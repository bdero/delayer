/*
 * DelayStream.h
 *
 *  Created on: Nov 29, 2012
 *      Author: Brandon DeRosier
 */

#ifndef DELAYSTREAM_H_
#define DELAYSTREAM_H_

#include <SFML/Audio.hpp>
#include "DelayBuffer.h"
#include "config.h"

class DelayStream: public sf::SoundStream {
public:
	DelayStream(DelayBuffer*);
	virtual ~DelayStream();

private:
	DelayBuffer* m_pBuffer;
	std::vector<sf::Int16> m_pTempBuffer;

	virtual bool onGetData(sf::SoundStream::Chunk& data);
	virtual void onSeek(sf::Time);
};

#endif /* DELAYSTREAM_H_ */
