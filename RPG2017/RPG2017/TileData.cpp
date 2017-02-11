#include "TileData.h"



TileData::TileData(const sf::Texture &texture, sf::Vector2u startPoint, sf::Vector2u size):
	m_texture(&texture),
	m_startPoint(startPoint),
	m_size(size)
{

}


TileData::~TileData()
{
}

const sf::Texture& TileData::getTexture()const
{
	return *m_texture;
}

sf::Vector2u TileData::getStartPoint()const
{
	return m_startPoint;
}

sf::Vector2u TileData::getSize()const
{
	return m_size;
}