#pragma once
#include "Animator.h"

class Player
{
private:
	float movementSpeed = .1f;
	int attackDamage = 0;
	int counterWalking = 0;

	sf::Texture m_texturePlayer;

	Animator animator;

public:
	void updateMovement();

	Player(sf::Vector2f startPosition);

	~Player();
};

