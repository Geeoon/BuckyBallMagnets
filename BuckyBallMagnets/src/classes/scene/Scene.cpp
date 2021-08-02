#include "Scene.h"

Scene::Scene() {
	for (size_t i = 0; i < 10; i++) {
		buckyballs.push_back(std::make_unique<BuckyBall>(Vector2{ -9.81f, 0.0f * 10.0f }, 0.01f, 10.0f, Vector2{ 100.0f + 20.0f * i, 100.0f + 20.0f * i }));
	}
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