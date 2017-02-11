#pragma once
#include "Entity.h"
#include "Animator.h"

class Player:public Entity
{
private:
	float movementSpeed = .1f;
	int attackDamage = 0;
	int counterWalking = 0;

public:
	void updateMovement();

	Player(sf::Texture &texture, sf::Vector2f startPosition);

	~Player();
};

