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
