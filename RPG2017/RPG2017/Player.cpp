#include "Player.h"
#include "Animator.h"



Player::Player(sf::Texture &texture, sf::Vector2f startPosition):
Entity(texture, sf::IntRect(0, 0, 17, 32), sf::Vector2f(17,30),startPosition)
{
	
	
}


Player::~Player()
{

}

void Player::updateMovement() 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
	{
		movement(0, -movementSpeed);
		setTextureArea(sf::IntRect(counterWalking * 17, 1 * 32, 17, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement(0, movementSpeed);
		setTextureArea(sf::IntRect(counterWalking * 17, 0 * 32, 17, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement(-movementSpeed, 0);
		setTextureArea(sf::IntRect(counterWalking * 17, 2 * 32, 17, 32));

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement(movementSpeed, 0);
		setTextureArea(sf::IntRect(counterWalking * 17, 3 * 32, 17, 32));
		
	}

	counterWalking++;

	if (counterWalking > 2)
	{
		counterWalking = 0;
	}
}

