#pragma once
#include <SFML\Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& body);
	~Collider();

	void Move(float dx, float dy);

	bool CheckCollision(Collider& other, float push);

	sf::Vector2f GetPosition();

	sf::Vector2f GetHalfSize();

	sf::RectangleShape& getBody();

private:
	sf::RectangleShape & m_body;
};