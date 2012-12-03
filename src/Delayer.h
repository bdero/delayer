/*
 * Delayer.h
 *
 *  Created on: Nov 27, 2012
 *      Author: Brandon DeRosier
 */

#ifndef Delayer_H_
#define Delayer_H_

#include <SFML/Graphics.hpp>
#include <stddef.h>
#include <iostream>
#include "DelayBuffer.h"
#include "DelayRecorder.h"
#include "DelayStream.h"
#include "Button.h"

class Delayer {
public:
	static Delayer* Instance();

	bool update(sf::RenderWindow&, float&);
	void draw(sf::RenderWindow&);

private:
	// Singleton design pattern
	Delayer();
	virtual ~Delayer();

	Delayer(Delayer const&); // Private copy constructor
	Delayer& operator=(Delayer const&); // Private assignment operator

	static Delayer* m_pInstance;

	// Private members
	DelayBuffer* m_pBuffer;
	DelayRecorder* m_pRecorder;
	DelayStream* m_pStream;
	Button* m_pExitButton;
	Button* m_pStartButton;
	sf::Mutex m_pMutex;
	bool m_pRecording;

};

#endif /* Delayer_H_ */
