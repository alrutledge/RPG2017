#pragma once
#include "Appearance.h"
#include <SFML\Graphics.hpp>
#include "SpriteAnimation.h"

class Animator : public Appearance
{

private:


private:
	std::map<std::string, SpriteAnimation> m_animations;


public:
	//Animator(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	
	//~Animator();

	void update(int row, float deltaTime);

	virtual void draw(sf::RenderTarget &renderTarget) override;  //virtual function from Apperance Interface

	void addAnimation(SpriteAnimation spriteAnimation, std::string animationName);

};

