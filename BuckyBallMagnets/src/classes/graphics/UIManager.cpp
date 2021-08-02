#include "UIManager.h"

UIManager::UIManager() {
	window.create(sf::VideoMode::getFullscreenModes()[0], "Bucky Balls", sf::Style::Fullscreen);
	window.setFramerateLimit(300);
	texture.create(window.getSize().x, window.getSize().y);
}

UIManager::UIManager(unsigned int x, unsigned int y) {
	window.create(sf::VideoMode(x, y), "Bucky Balls", sf::Style::Close);
	window.setFramerateLimit(300);
	texture.create(x, y);
}

void UIManager::update() {
	window.clear();
	window.draw(sf::Sprite(texture.getTexture()));
	window.display();
	texture.clear();
	pollEvents();
}

void UIManager::draw(sf::Drawable& drawable) {
	texture.draw(drawable);
}

bool UIManager::isOpen() {
	return window.isOpen();
}

void UIManager::pollEvents() {
	sf::Event e;
	while (window.pollEvent(e)) {
		switch (e.type) {
			case sf::Event::Closed: {
				window.close();
			} break;
			case sf::Event::KeyPressed: {
				switch (e.key.code) {
					case sf::Keyboard::Escape: {
						window.close();
					} break;
				}
			} break;
		}
	}
}