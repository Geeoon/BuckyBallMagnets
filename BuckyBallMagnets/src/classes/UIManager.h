#pragma once
#include <SFML/Graphics.hpp>

class UIManager {
public:
	UIManager();
	UIManager(unsigned int x, unsigned int y);
	void update();
	void draw(sf::Drawable& drawable);

private:
	sf::RenderWindow window;
	sf::RenderTexture texture;
};