/*
 * Delayer.cpp
 *
 *  Created on: Nov 27, 2012
 *      Author: Brandon DeRosier
 */

#include "Delayer.h"

Delayer* Delayer::m_pInstance = NULL;

Delayer::Delayer() :
m_pBuffer(new DelayBuffer()),
m_pRecorder(new DelayRecorder(m_pBuffer)),
m_pStream(new DelayStream(m_pBuffer)),
m_pExitButton(new Button("Exit", sf::Vector2i(0, 0), sf::Vector2<unsigned int>(150, 50), true)),
m_pStartButton(new Button("Start", sf::Vector2i(0, 0), sf::Vector2<unsigned int>(150, 50), true)),
m_pRecording(false),
m_pButtonsImage(sf::Image()) {
	if (!sf::SoundRecorder::isAvailable()) {
		std::cout << "Audio capture not available!";
	} else {
		m_pStream->play();
		//sf::sleep(sf::milliseconds(2000));
		//m_pRecorder->start(SAMPLE_COUNT);
	}

	// Load images
	if (m_pButtonsImage.loadFromFile("content/image/button/buttons.png")) {
		sf::Rect<int> rect(0, 0, 150, 200);
		m_pStartButton->setImage(m_pButtonsImage, rect);
		rect = sf::Rect<int>(0, 200, 150, 100);
		m_pExitButton->setImage(m_pButtonsImage, rect);
	} else {
		std::cout << "Unable to load image file.";
	}
}

//Delayer::Delayer(Delayer const& copy) {}

Delayer::~Delayer() {}


bool Delayer::update(sf::RenderWindow& w, float& tm) {
	{
		sf::Lock lock(m_pMutex);

		if (w.getSize().x < WINDOW_MIN_WIDTH)
			w.setSize(sf::Vector2u(WINDOW_MIN_WIDTH, w.getSize().y));
		if (w.getSize().y < WINDOW_MIN_HEIGHT)
			w.setSize(sf::Vector2u(w.getSize().x, WINDOW_MIN_HEIGHT));
		w.setView(sf::View(sf::FloatRect(0, 0, w.getSize().x, w.getSize().y)));

		m_pExitButton->setPosition(sf::Vector2i(
				w.getSize().x - m_pExitButton->getSize().x - 10,
				w.getSize().y - m_pExitButton->getSize().y - 10));
		if (m_pExitButton->update(w) == 3) {
			m_pRecorder->stop();
			// ADDED
			w.close();
			return false;
		}

		m_pStartButton->setPosition(sf::Vector2i(
				10,
				w.getSize().y - m_pStartButton->getSize().y - 10));
		if (m_pStartButton->update(w) == 3) {
			if (!m_pRecording) {
				m_pRecorder->start(SAMPLE_COUNT);
				m_pStartButton->setTitle("Stop");
				m_pRecording = true;
			} else {
				m_pRecorder->stop();
				m_pBuffer->clear();
				m_pStartButton->setTitle("Start");
				m_pRecording = false;
			}
		}

		sf::Event event;
		while (w.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				m_pRecorder->stop();
				// ADDED
				w.close();
				return false;
			}
		}
	}

	return true;
}

void Delayer::draw(sf::RenderWindow& w) {
	sf::Lock lock(m_pMutex);

	w.clear(sf::Color::Black);
	m_pExitButton->draw(w);
	m_pStartButton->draw(w);
	w.display();
}

Delayer& Delayer::operator=(Delayer const& assignment) {
	return *this;
}

Delayer* Delayer::Instance() {
	if (!m_pInstance) {
		m_pInstance = new Delayer;
	}

	return m_pInstance;
}
