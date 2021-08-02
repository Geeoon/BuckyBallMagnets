#include "BuckyBall.h"

BuckyBall::BuckyBall(const Vector2& gravitationalAcceleration, const float m, const float r, const Vector2& pos) : shape{ r }, mass { m }, radius{ r }, g{ gravitationalAcceleration }, magnetism{ 0.0f, 0.0f }, velocity{ 0.0f, 0.0f }, position{ pos } {
	shape.setPosition(pos.x, -pos.y);
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::Red);
	shape.setOutlineThickness(2);
	shape.setOrigin(shape.getRadius() + shape.getOutlineThickness() / 2.0f, shape.getRadius() + shape.getOutlineThickness() / 2.0f);
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
		// find better way of returning sign.
		if (velocity.y != 0) {
			velocity.y = (velocity.y / fabsf(velocity.y)) * sqrtf(velocity.y * velocity.y - 2.0f * g.y * deltaH);  // derived from KE = mgh
		}
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
		if (velocity.x != 0) {
			velocity.x = (velocity.x / fabsf(velocity.x)) * sqrtf(velocity.x * velocity.x - 2.0f * g.x * deltaX);
		}
	}
}

void BuckyBall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(shape);
}

float BuckyBall::getRadius() {
	return radius;
}