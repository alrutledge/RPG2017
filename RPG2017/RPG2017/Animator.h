#pragma once
#include "Appearance.h"
#include <SFML\Graphics.hpp>
#include "AnimatedSprite.h"

class Animator : public Appearance
{

private:


	std::map<std::string, AnimatedSprite> m_animations;

	std::string m_animationName;

public:
	//Animator(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	
	//~Animator();

	void setCurrentAnimation(std::string animationName);

	void update(float deltaTime);

	virtual void draw(sf::RenderTarget &renderTarget, sf::Vector2f position) override;  //virtual function from Apperance Interface

	void addAnimation(AnimatedSprite spriteAnimation, std::string animationName);

};

