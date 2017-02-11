#include "Animator.h"



Animator::Animator(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 1.0f;
	currentImage.x = 0;
}


Animator::~Animator()
{
}

void Animator::update(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x > imageCount.x)
		{
			currentImage.x = 0;
		}
	}
}
