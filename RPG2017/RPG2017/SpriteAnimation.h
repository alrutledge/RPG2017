#pragma once
#include <vector>
#include "SFML\Graphics.hpp"

class SpriteAnimation
{
private:
	float m_frameDuration;
	std::vector <sf::Sprite> spriteVector;

public:
	SpriteAnimation(float frameDuration);

	~SpriteAnimation();

	void addFrame(sf::Sprite sprite);


};

