#pragma once
#include<SFML/Graphics.hpp>

class TileData
{
private:
	const sf::Texture *m_texture;
	sf::Vector2u m_startPoint;
	sf::Vector2u m_size; 

public:
	TileData(const sf::Texture &texture, sf::Vector2u startPoint, sf::Vector2u size);
	const sf::Texture& getTexture()const;
	sf::Vector2u getStartPoint()const;
	sf::Vector2u getSize()const;

	~TileData();
};

