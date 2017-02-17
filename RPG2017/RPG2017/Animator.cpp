#include "Animator.h"




//Animator::Animator(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
//{
	//this->imageCount = imageCount;
	//this->switchTime = switchTime;
	//totalTime = 1.0f;
	//currentImage.x = 0;
//}


//Animator::~Animator()
//{
//}

void Animator::update()
{


}

void Animator::draw(sf::RenderTarget & renderTarget)
{

}

void Animator::addAnimation(SpriteAnimation spriteAnimation, std::string animationName)
{
	m_animations.emplace(animationName, spriteAnimation);
}
