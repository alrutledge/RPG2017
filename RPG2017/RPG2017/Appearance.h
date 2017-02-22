#pragma once
#include<SFML\Graphics.hpp>


class Appearance  //interface
{
public:
	virtual void draw(sf::RenderTarget &renderTarget, sf::Vector2f position) = 0;  //pure virtual function specify derived classes must draw()

	virtual ~Appearance() = default;  //virtual destructor 
};
