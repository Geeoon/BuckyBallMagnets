#pragma once
#include <SFML/Graphics.hpp>

class UIManager {
public:
	UIManager();
	UIManager(unsigned int x, unsigned int y);
	void update();
	void draw(sf::Drawable& drawable);
	bool isOpen();

private:
	void pollEvents();
	sf::RenderWindow window;
	sf::RenderTexture texture;
};