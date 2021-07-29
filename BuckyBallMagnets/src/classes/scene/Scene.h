#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "../physics/Vector2.h"
#include "BuckyBall.h"

class Scene : public sf::Drawable {
public:
	Scene();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update();

private:
	sf::Clock clock;
	std::vector<std::unique_ptr<BuckyBall>> buckyballs;
};