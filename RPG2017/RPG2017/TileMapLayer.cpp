#include "TileMapLayer.h"
#include "SFML\Graphics\RenderTarget.hpp"



TileMapLayer::TileMapLayer()
{

}


TileMapLayer::~TileMapLayer()
{

}

void TileMapLayer::addSprite(sf::Sprite sprite)
{
	m_sprites.emplace_back(sprite);
}

void TileMapLayer::draw(sf::RenderTarget & renderTarget) const
{
	for (auto & sprite : m_sprites)
	{
		renderTarget.draw(sprite);
	}
}