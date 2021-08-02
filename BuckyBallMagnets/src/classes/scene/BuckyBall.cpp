#include "BuckyBall.h"

BuckyBall::BuckyBall(const Vector2& gravitationalAcceleration, const float m, const float r, const Vector2& pos) : shape{ r }, mass { m }, radius{ r }, g{ gravitationalAcceleration }, magnetism{ 0.0f, 0.0f }, velocity{ 0.0f, 0.0f }, position{ pos } {
	shape.setPosition(pos.x, -pos.y);
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::Red);
	shape.setOutlineThickness(2);
	shape.setOrigin(shape.getRadius() + shape.getOutlineThickness() / 2.0f, shape.getRadius() + shape.getOutlineThickness() / 2.0f);
	velocity.x = 20;
}

void BuckyBall::update(float dt) {
	Vector2 netForce;
	netForce += mass * g;

	Vector2 acceleration;
	acceleration = netForce / mass;

	velocity += acceleration * dt;
	position += velocity * dt;
	shape.setPosition(position.x, position.y);
	if (position.y < 0 || position.y > 800) {
		velocity.y = -velocity.y;
	}
	if (position.x < 0 || position.x > 800) {
		velocity.x = -velocity.x;
	}
}

void BuckyBall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(shape);
}