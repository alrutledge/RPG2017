#include "SpriteAnimation.h"



SpriteAnimation::SpriteAnimation(float frameDuration):
m_frameDuration(frameDuration)
{
	
}

SpriteAnimation::~SpriteAnimation()
{
}

void SpriteAnimation::addFrame(sf::Sprite sprite)
{
	spriteVector.emplace_back(sprite);
}

void SpriteAnimation::reset()
{
	m_elapsedTime = 0.0f;
}

void SpriteAnimation::update(float deltaTime)
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

void SpriteAnimation::draw(sf::RenderTarget & renderTarget, sf::Vector2f position)
{
	int currentFrameIndex = static_cast<int>(m_elapsedTime / m_frameDuration);
	spriteVector[currentFrameIndex].setPosition(position);
	renderTarget.draw(spriteVector[currentFrameIndex]);

	
}
