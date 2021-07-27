#include "UIManager.h"

UIManager::UIManager() {
	window.create(sf::VideoMode::getFullscreenModes()[0], "Bucky Balls", sf::Style::Fullscreen);
	window.setFramerateLimit(300);
	texture.create(window.getSize().x, window.getSize().y);
}

UIManager::UIManager(unsigned int x, unsigned int y) {
	window.create(sf::VideoMode(x, y), "Bucky Balls", sf::Style::Fullscreen);
	window.setFramerateLimit(300);
	texture.create(x, y);
}

void UIManager::update() {
	window.clear();
	window.draw(sf::Sprite(texture.getTexture()));
	window.display();
	texture.clear();
}

void UIManager::draw(sf::Drawable& drawable) {
	texture.draw(drawable);
}