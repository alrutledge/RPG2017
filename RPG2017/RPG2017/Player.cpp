#include "Player.h"
#include "Animator.h"
#include "SpriteAnimation.h"



Player::Player(sf::Vector2f startPosition)
{	
	sf::Texture texturePlayer;
	if (!texturePlayer.loadFromFile("tileset/test1.png"))
	{
		throw(std::runtime_error("Failed to load Player Texture"));
	}
	
	sf::Sprite moveDownFrame0;
	moveDownFrame0.setTexture(texturePlayer);
	moveDownFrame0.setTextureRect(sf::IntRect(0, 0, 17, 32));
	
	sf::Sprite moveDownFrame1;
	moveDownFrame1.setTexture(texturePlayer);
	moveDownFrame1.setTextureRect(sf::IntRect(17, 0, 17, 32));

	sf::Sprite moveDownFrame2;
	moveDownFrame2.setTexture(texturePlayer);
	moveDownFrame2.setTextureRect(sf::IntRect(34, 0, 17, 32));

	//m_rect.setSize(spriteSize);
	//m_rect.setPosition(startPosition);


	SpriteAnimation moveDown(.05f);

	moveDown.addFrame(moveDownFrame0);
	moveDown.addFrame(moveDownFrame1);
	moveDown.addFrame(moveDownFrame2);

	animator.addAnimation(moveDown, "Move Down");

}

Player::~Player()
{

}

void Player::updateMovement() 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
	{
		//movement(0, -movementSpeed);
		//setTextureArea(sf::IntRect(counterWalking * 17, 1 * 32, 17, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		//movement(0, movementSpeed);
		//setTextureArea(sf::IntRect(counterWalking * 17, 0 * 32, 17, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//movement(-movementSpeed, 0);
		//setTextureArea(sf::IntRect(counterWalking * 17, 2 * 32, 17, 32));

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		//movement(movementSpeed, 0);
		//setTextureArea(sf::IntRect(counterWalking * 17, 3 * 32, 17, 32));
		
	}

	counterWalking++;

	if (counterWalking > 2)
	{
		counterWalking = 0;
	}
}

