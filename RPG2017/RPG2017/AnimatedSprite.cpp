#include "AnimatedSprite.h"



AnimatedSprite::AnimatedSprite(float frameDuration):
m_frameDuration(frameDuration)
{
	
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::addFrame(sf::Sprite sprite)
{
	spriteVector.emplace_back(sprite);
}

void AnimatedSprite::reset()
{
	m_elapsedTime = 0.0f;
}

void AnimatedSprite::update(float deltaTime)
{
	m_elapsedTime += deltaTime;
	float totalAnimationTime = m_frameDuration * static_cast<float>(spriteVector.size());
	if (totalAnimationTime == 0.0f)
	{
		return;
	}
	while (m_elapsedTime >= totalAnimationTime)
	{
		m_elapsedTime -= totalAnimationTime;
	}
}

void AnimatedSprite::draw(sf::RenderTarget & renderTarget, sf::Vector2f position)
{
	int currentFrameIndex = static_cast<int>(m_elapsedTime / m_frameDuration);
	spriteVector[currentFrameIndex].setPosition(position);
	renderTarget.draw(spriteVector[currentFrameIndex]);

	
}
