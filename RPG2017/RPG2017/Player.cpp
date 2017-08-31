#include "Player.h"
#include "Animator.h"
#include "AnimatedSprite.h"
#include <iostream>
#include "Collider.h"



Player::Player(sf::Vector2f startPosition)
{	
	if (!m_texturePlayer.loadFromFile("tileset/test1.png"))
	{
		throw(std::runtime_error("Failed to load Player Texture"));
	}
	
	sf::Sprite moveDownFrameIdle;
	moveDownFrameIdle.setTexture(m_texturePlayer);
	moveDownFrameIdle.setTextureRect(sf::IntRect(0, 0, 17, 32));
	
	sf::Sprite moveDownFrame1;
	moveDownFrame1.setTexture(m_texturePlayer);
	moveDownFrame1.setTextureRect(sf::IntRect(17, 0, 17, 32));

	sf::Sprite moveDownFrame2;
	moveDownFrame2.setTexture(m_texturePlayer);
	moveDownFrame2.setTextureRect(sf::IntRect(34, 0, 17, 32));

	sf::Sprite moveUpFrameIdle;
	moveUpFrameIdle.setTexture(m_texturePlayer);
	moveUpFrameIdle.setTextureRect(sf::IntRect(0, 32, 17, 32));

	sf::Sprite moveUpFrame1;
	moveUpFrame1.setTexture(m_texturePlayer);
	moveUpFrame1.setTextureRect(sf::IntRect(17, 32, 17, 32));

	sf::Sprite moveUpFrame2;
	moveUpFrame2.setTexture(m_texturePlayer);
	moveUpFrame2.setTextureRect(sf::IntRect (34, 32, 17, 32));

	sf::Sprite moveLeftFrameIdle;
	moveLeftFrameIdle.setTexture(m_texturePlayer);
	moveLeftFrameIdle.setTextureRect(sf::IntRect(0, 64, 17, 32));

	sf::Sprite moveLeftFrame1;
	moveLeftFrame1.setTexture(m_texturePlayer);
	moveLeftFrame1.setTextureRect(sf::IntRect(17, 64, 17, 32));

	sf::Sprite moveLeftFrame2;
	moveLeftFrame2.setTexture(m_texturePlayer);
	moveLeftFrame2.setTextureRect(sf::IntRect(34, 64, 17, 32));

	sf::Sprite moveRightFrameIdle;
	moveRightFrameIdle.setTexture(m_texturePlayer);
	moveRightFrameIdle.setTextureRect(sf::IntRect(0, 96, 17, 32));

	sf::Sprite moveRightFrame1;
	moveRightFrame1.setTexture(m_texturePlayer);
	moveRightFrame1.setTextureRect(sf::IntRect(17, 96, 17, 32));

	sf::Sprite moveRightFrame2;
	moveRightFrame2.setTexture(m_texturePlayer);
	moveRightFrame2.setTextureRect(sf::IntRect(34, 96, 17, 32));


	//m_rect.setSize(spriteSize);

	m_rect.setPosition(startPosition);


	AnimatedSprite moveDown(.25f);

	moveDown.addFrame(moveDownFrame2);
	//moveDown.addFrame(moveDownFrameIdle);
	moveDown.addFrame(moveDownFrame1);
	//moveDown.addFrame(moveDownFrameIdle);

	animator.addAnimation(moveDown, "Move Down");


	AnimatedSprite moveUp(.25f);

	moveUp.addFrame(moveUpFrame2);
	moveUp.addFrame(moveUpFrameIdle);
	moveUp.addFrame(moveUpFrame1);
	moveUp.addFrame(moveUpFrameIdle);

	animator.addAnimation(moveUp, "Move Up");

	AnimatedSprite moveLeft(.25f);

	moveLeft.addFrame(moveLeftFrame2);
	moveLeft.addFrame(moveLeftFrameIdle);
	moveLeft.addFrame(moveLeftFrame1);
	moveLeft.addFrame(moveLeftFrameIdle);

	animator.addAnimation(moveLeft, "Move Left");

	AnimatedSprite moveRight(.25f);

	moveRight.addFrame(moveRightFrame2);
	moveRight.addFrame(moveRightFrameIdle);
	moveRight.addFrame(moveRightFrame1);
	moveRight.addFrame(moveRightFrameIdle);

	animator.addAnimation(moveRight, "Move Right");

	AnimatedSprite downIdle(1.0f);
	downIdle.addFrame(moveDownFrameIdle);
	animator.addAnimation(downIdle, "Idle Down");


	AnimatedSprite upIdle(1.0f);
	upIdle.addFrame(moveUpFrameIdle);
	animator.addAnimation(upIdle, "Idle Up");

	AnimatedSprite leftIdle(1.0f);
	leftIdle.addFrame(moveLeftFrameIdle);
	animator.addAnimation(leftIdle, "Idle Left");

	AnimatedSprite rightIdle(1.0f);
	rightIdle.addFrame(moveRightFrameIdle);
	animator.addAnimation(rightIdle, "Idle Right");
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
	{
		movement(0, -movementSpeed);
		setAnimation("Move Up");
		playerDirection = PlayerFacing::UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement(0, movementSpeed);
		setAnimation("Move Down");
		playerDirection = PlayerFacing::DOWN;

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement(-movementSpeed, 0);
		setAnimation("Move Left");
		playerDirection = PlayerFacing::LEFT;

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement(movementSpeed, 0);
		setAnimation("Move Right");
		playerDirection = PlayerFacing::RIGHT;
	}

	else
	{
		switch (playerDirection)
		{
		case Player::PlayerFacing::UP:
			setAnimation("Idle Up");
			break;
		case Player::PlayerFacing::DOWN:
			setAnimation("Idle Down");
			break;
		case Player::PlayerFacing::LEFT:
			setAnimation("Idle Left");
			break;
		case Player::PlayerFacing::RIGHT:
			setAnimation("Idle Right");
			break;
		default:
			break;
		}
	}

	animator.update(deltaTime);

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

Collider Player::GetCollider()
{
	return Collider(m_rect);
}


