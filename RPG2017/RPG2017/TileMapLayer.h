#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <vector>


class TileMapLayer
{
public:
	TileMapLayer();
	~TileMapLayer();
	void addSprite(sf::Sprite sprite);
	void draw(sf::RenderTarget & renderTarger) const;

private:
	std::vector <sf::Sprite> m_sprites;


};

