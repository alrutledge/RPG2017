#pragma once
#include <SFML\Graphics.hpp>

class Animator
{

private:


private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;

public:
	Animator(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	
	~Animator();

	void update(int row, float deltaTime);


public:
	sf::IntRect uvRect;
};

