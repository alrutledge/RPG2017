#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
private:
	sf::RectangleShape m_rect;
	sf::Sprite m_sprite;

protected:
	void movement(float xMovement, float yMovement);

	void setTextureArea(sf::IntRect textureArea);

public:
	Entity(sf::Texture &texture, sf::IntRect textureArea, sf::Vector2f spriteSize, sf::Vector2f startPosition);
	~Entity();

	void draw(sf::RenderTarget &renderTarget);

	sf::Vector2f getRectPosition();

	//void animate(int row, float deltaTime);



};



