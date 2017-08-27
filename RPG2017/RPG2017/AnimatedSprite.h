#pragma once
#include <vector>
#include "SFML\Graphics.hpp"

class AnimatedSprite
{
private:
	float m_elapsedTime = 0.0f;
	float m_frameDuration;
	std::vector <sf::Sprite> spriteVector;

public:
	AnimatedSprite(float frameDuration);

	~AnimatedSprite();

	void addFrame(sf::Sprite sprite);

	void reset();

	void update(float deltaTime);

	void draw(sf::RenderTarget & renderTarget, sf::Vector2f position);


};

