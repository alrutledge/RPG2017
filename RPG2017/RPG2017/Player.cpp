#include "Player.h"
#include "Animator.h"
#include "SpriteAnimation.h"
#include <iostream>



Player::Player(sf::Vector2f startPosition)
{	
	if (!m_texturePlayer.loadFromFile("tileset/test1.png"))
	{
		throw(std::runtime_error("Failed to load Player Texture"));
	}
	
	sf::Sprite moveDownFrame0;
	moveDownFrame0.setTexture(m_texturePlayer);
	moveDownFrame0.setTextureRect(sf::IntRect(0, 0, 17, 32));
	
	sf::Sprite moveDownFrame1;
	moveDownFrame1.setTexture(m_texturePlayer);
	moveDownFrame1.setTextureRect(sf::IntRect(17, 0, 17, 32));

	sf::Sprite moveDownFrame2;
	moveDownFrame2.setTexture(m_texturePlayer);
	moveDownFrame2.setTextureRect(sf::IntRect(34, 0, 17, 32));

	//m_rect.setSize(spriteSize);

	m_rect.setPosition(startPosition);


	SpriteAnimation moveDown(1.0f);

	moveDown.addFrame(moveDownFrame0);
	moveDown.addFrame(moveDownFrame1);
	moveDown.addFrame(moveDownFrame0);
	moveDown.addFrame(moveDownFrame2);

	animator.addAnimation(moveDown, "Move Down");

}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
	{
		movement(0, -movementSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement(0, movementSpeed);
		setAnimation("Move Down");
		std::cout << "Down pressed" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement(-movementSpeed, 0);
		//setTextureArea(sf::IntRect(counterWalking * 17, 2 * 32, 17, 32));

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement(movementSpeed, 0);
		//setTextureArea(sf::IntRect(counterWalking * 17, 3 * 32, 17, 32));
		
	}

	animator.update(deltaTime);

	counterWalking++;

	if (counterWalking > 2)
	{
		counterWalking = 0;
	}
}

void Player::setAnimation(std::string name)
{
	if (name != m_animationName)
	{
		m_animationName = name;
		animator.setCurrentAnimation(m_animationName);

	}


}

void Player::movement(float xMovement, float yMovement)
{
	m_rect.move(xMovement, yMovement);
}

void Player::draw(sf::RenderTarget & renderTarget)
{
	animator.draw(renderTarget, m_rect.getPosition());
	
}

