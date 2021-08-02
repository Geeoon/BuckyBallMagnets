#pragma once
#include <SFML/Graphics.hpp>
#include "../physics/Vector2.h"
// https://www.khanacademy.org/science/physics/magnetic-forces-and-magnetic-fields/magnets-magnetic/v/introduction-to-magnetism

class BuckyBall : public sf::Drawable {
public:
	BuckyBall(const Vector2& gravitationalAcceleration, const float m, const float r, const Vector2& pos);
	void update(float dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	float getRadius();

private:
	const Vector2 bound{ 800.0f, 800.0f };
	sf::CircleShape shape;
	const float mass, radius;
	const Vector2 g{};
	Vector2 magnetism{};
	Vector2 velocity{};
	Vector2 position{};
};