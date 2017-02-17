#pragma once
#include "Animator.h"

class Player
{
private:
	float movementSpeed = .1f;
	int attackDamage = 0;
	int counterWalking = 0;

	sf::Texture m_texturePlayer;
	sf::RectangleShape m_rect;

	Animator animator;

public:
	void updateMovement(sf::RenderTarget & renderTarget);

	Player(sf::Vector2f startPosition);

	~Player();

	void Player::movement(float xMovement, float yMovement);
};

