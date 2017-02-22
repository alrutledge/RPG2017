#pragma once
#include <vector>
#include "SFML\Graphics.hpp"

class SpriteAnimation
{
private:
	float m_elapsedTime = 0.0f;
	float m_frameDuration;
	std::vector <sf::Sprite> spriteVector;

public:
	SpriteAnimation(float frameDuration);

	~SpriteAnimation();

	void addFrame(sf::Sprite sprite);

	void reset();

	void update(float deltaTime);

	void draw(sf::RenderTarget & renderTarget, sf::Vector2f position);


};

