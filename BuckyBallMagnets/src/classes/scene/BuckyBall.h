#include <SFML/Graphics.hpp>
#include "../physics/Vector2.h"
// https://www.khanacademy.org/science/physics/magnetic-forces-and-magnetic-fields/magnets-magnetic/v/introduction-to-magnetism

class BuckyBall : public sf::Drawable {
public:
	BuckyBall(const Vector2& gravitationalAcceleration, const float m, const float r, const Vector2& pos);
	void update(float dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states);

private:
	sf::CircleShape shape;
	const float mass, radius;
	const Vector2 g;
	Vector2 magnetism;
	Vector2 velocity;
	Vector2 position;
};