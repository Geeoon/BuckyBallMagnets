#pragma once
#include <SFML/Graphics.hpp>

class Scene : public sf::Drawable {
public:
	Scene();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

};