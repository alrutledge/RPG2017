#include "Animator.h"


void Animator::update(float deltaTime)
{
	auto iterator = m_animations.find(m_animationName);
	if (iterator == m_animations.end())
	{
		return;
		//throw(std::runtime_error("Current animation not exist"));
	}
	AnimatedSprite& currentAnimation = iterator->second;
	currentAnimation.update(deltaTime);

}

void Animator::draw(sf::RenderTarget & renderTarget, sf::Vector2f position)
{
	auto iterator = m_animations.find(m_animationName);
	if (iterator == m_animations.end())
	{
		return;
		//throw(std::runtime_error("No current animation to draw"));
	}
	AnimatedSprite& currentAnimation = iterator->second;
	currentAnimation.draw(renderTarget, position);
}

void Animator::addAnimation(AnimatedSprite spriteAnimation, std::string animationName)
{
	m_animations.emplace(animationName, spriteAnimation);
}

void Animator::setCurrentAnimation(std::string animationName)
{
	m_animationName = animationName;
	auto iterator = m_animations.find(m_animationName);
	if (iterator == m_animations.end())
	{
		return;
		//throw(std::runtime_error("No animation name found"));
	}
	AnimatedSprite& currentAnimation = iterator->second;
	currentAnimation.reset();
}