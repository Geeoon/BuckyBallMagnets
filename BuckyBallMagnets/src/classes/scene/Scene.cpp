#include "Scene.h"

Scene::Scene() {
	buckyballs.push_back(std::make_unique<BuckyBall>(Vector2{ 0.0f, -9.81f }, 0.01f, 20.0f, Vector2{ 50.0f, 50.0f }));
	clock.restart();
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (const std::unique_ptr<BuckyBall>& ball : buckyballs) {
		target.draw(*ball);
	}
}

void Scene::update() {
	float dt{ clock.getElapsedTime().asSeconds() };
	for (const std::unique_ptr<BuckyBall>& ball : buckyballs) {
		ball->update(dt);
	}
	clock.restart();
}