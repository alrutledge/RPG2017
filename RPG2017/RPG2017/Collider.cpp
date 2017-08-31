#include <SFML\Graphics.hpp>
#include "Collider.h"

Collider::Collider(sf::RectangleShape& body) :
	m_body(body)
{

}

Collider::~Collider()
{

}

bool Collider::CheckCollision(Collider & other, float push)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

			if (intersectX > intersectY)
			{
				if (deltaX > 0.0f)
				{
					Move(intersectX * (1.0f - push), 0.0f);
					other.Move(-intersectX * push, 0.0f);
				}
				else
				{
					Move(-intersectX * (1.0f - push), 0.0f);
					other.Move(intersectX * push, 0.0f);
				}
			}
			else
			{
				if (deltaY > 0.0f)
				{
					Move(0.0f, intersectY * (1.0f - push));
					other.Move(0.0f, intersectY * push);
				}
				else
				{
					Move(0.0f, -intersectY * (1.0f - push));
					other.Move(0.0f, intersectY * push);
				}
			}

		return true;
	}

	return false;
}

void Collider::Move(float dx, float dy)
{
	m_body.move(dx, dy);
}

sf::Vector2f Collider::GetPosition()
{
	return m_body.getPosition();
}

sf::Vector2f Collider::GetHalfSize()
{
	return m_body.getSize() / 2.0f;
}

sf::RectangleShape & Collider::getBody()
{
	return m_body;
}
