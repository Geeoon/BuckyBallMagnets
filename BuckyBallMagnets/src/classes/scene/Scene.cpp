#include "Scene.h"

Scene::Scene() {
	buckyballs.push_back(std::make_unique<BuckyBall>(Vector2{ 0.0f, -9.81f }, 0.01f, 10.0f, Vector2{ 0.0f, 0.0f }));
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (const std::unique_ptr<BuckyBall>& ball : buckyballs) {
		target.draw(*ball);
	}
}