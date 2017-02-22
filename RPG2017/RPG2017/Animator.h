#pragma once
#include "Appearance.h"
#include <SFML\Graphics.hpp>
#include "SpriteAnimation.h"

class Animator : public Appearance
{

private:


	std::map<std::string, SpriteAnimation> m_animations;

	std::string m_animationName;

public:
	//Animator(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	
	//~Animator();

	void setCurrentAnimation(std::string animationName);

	void update(float deltaTime);

	virtual void draw(sf::RenderTarget &renderTarget, sf::Vector2f position) override;  //virtual function from Apperance Interface

	void addAnimation(SpriteAnimation spriteAnimation, std::string animationName);

};

