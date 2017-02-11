#include "Entity.h"



Entity::Entity(sf::Texture &texture, sf::IntRect textureArea, sf::Vector2f spriteSize,sf::Vector2f startPosition)
{
	m_sprite.setTexture(texture);
	m_sprite.setTextureRect(textureArea);
	m_rect.setSize(spriteSize);
	m_rect.setPosition(startPosition);
}


Entity::~Entity()
{
}

void Entity::draw(sf::RenderTarget &renderTarget)
{
	m_sprite.setPosition(m_rect.getPosition());
	renderTarget.draw(m_sprite);
}

void Entity::movement(float xMovement, float yMovement)
{
	 m_rect.move(xMovement, yMovement);
}

void Entity::setTextureArea(sf::IntRect textureArea)
{
	m_sprite.setTextureRect(textureArea);
}

sf::Vector2f Entity::getRectPosition()
{
	return m_rect.getPosition();
}
