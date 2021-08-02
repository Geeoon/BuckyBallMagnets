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
	if (position.y - radius <= 0.0f || position.y + radius >= bound.y) {
		velocity.y = -velocity.y;
		Vector2 newPos{ position };
		if (position.y - radius <= 0.0f) {
			newPos.y = radius;
		} else {
			newPos.y = bound.y - radius;
		}
		float deltaH{ newPos.y - position.y };
		position = newPos;
		velocity.y = (velocity.y / fabsf(velocity.y)) * sqrtf(2.0f * g.y * deltaH + velocity.y * velocity.y);  // derived from KE = mgh
	}

	if (position.x - radius <= 0.0f || position.x + radius >= bound.x) {
		velocity.x = -velocity.x;
		Vector2 newPos{ position };
		if (position.x - radius <= 0.0f) {
			newPos.x = radius;
		} else {
			newPos.x = bound.x - radius;
		}
		float deltaX{ newPos.x - position.x };
		position = newPos;
		velocity.x = (velocity.x / fabsf(velocity.x)) * sqrtf(2.0f * g.x * deltaX + velocity.x * velocity.x);
	}
}

void BuckyBall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(shape);
}