#include "BuckyBall.h"

BuckyBall::BuckyBall(const Vector2& gravitationalAcceleration, const float m, const float r, const Vector2& pos) : mass{ m }, radius{ r }, g{ gravitationalAcceleration }, magnetism{ 0.0f, 0.0f }, velocity{ 0.0f, 0.0f }, position{ pos } {

}

void BuckyBall::update(float dt) {
	Vector2 netForce;
	netForce += mass * g;

	Vector2 acceleration;
	acceleration = netForce / mass;

	velocity += acceleration;
	position += velocity * dt;
}