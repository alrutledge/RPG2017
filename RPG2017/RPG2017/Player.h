#pragma once
#include "Animator.h"

class Player
{
private:
	void setAnimation(std::string name);

	void movement(float xMovement, float yMovement);

	float movementSpeed = .1f;
	int attackDamage = 0;

	sf::Texture m_texturePlayer;
	sf::RectangleShape m_rect;

	Animator animator;

	std::string m_animationName;

	enum class PlayerFacing {UP, DOWN, LEFT, RIGHT};
	
	PlayerFacing playerDirection = PlayerFacing::DOWN;

public:

	void update(float deltaTime);

	Player(sf::Vector2f startPosition);

	~Player();

	void draw(sf::RenderTarget & renderTarget);
};

