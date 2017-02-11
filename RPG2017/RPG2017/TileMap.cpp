#include "TileMap.h"
#include <SFML/Graphics.hpp>
#include <stdexcpt.h>
#include <tmxlite\Tileset.hpp>
#include <tmxlite\TileLayer.hpp>
#include <iostream>
#include <Windows.h>


TileMap::TileMap(const std::string &mapPath, sf::RenderTarget &window) :
	m_mapPath(mapPath),
	m_renderTarget(window)
{
	if (!m_tileMap.load(m_mapPath))
	{
		throw(std::runtime_error("Failed to load map"));
	}
	loadTileSet();;
	createTileLayer();
}


TileMap::~TileMap()
{
}



void TileMap::draw()
{
	for (auto & layer : m_tileLayers)
	{
		layer.draw(m_renderTarget);
	}

}

//void TileMap::loadTileMap()
//{
//
//
//
//}

void TileMap::loadTileSet()
{
	const std::vector <tmx::Tileset> & tileSets = m_tileMap.getTilesets();
	
	for (auto & tileSet : tileSets)
	{
		m_textures.emplace_back();
		sf::Texture &tempTexture = m_textures.back();

		if (!tempTexture.loadFromFile(tileSet.getImagePath()))
		{
			throw(std::runtime_error("Failed to load " + tileSet.getImagePath()));
		}

		const tmx::Vector2u tmxTileSize = tileSet.getTileSize();

		const sf::Vector2u tileSize(tmxTileSize.x, tmxTileSize.y);

		uint32_t guid = tileSet.getFirstGID();

		for (uint32_t yPixelCounter = 0; yPixelCounter < tempTexture.getSize().y; yPixelCounter += tileSize.y)
		{
			for (uint32_t xPixelCounter = 0; xPixelCounter < tempTexture.getSize().x; xPixelCounter += tileSize.x)
			{
				sf::Vector2u startPoint(xPixelCounter, yPixelCounter);
				m_tileData.insert(std::make_pair(guid ++, TileData(tempTexture, startPoint, tileSize)));
			}
		}
	}
}

void TileMap::createTileLayer()
{
	const std::vector<tmx::Layer::Ptr>& mapLayers = m_tileMap.getLayers();

	tmx::Vector2u tileCount = m_tileMap.getTileCount();
	tmx::Vector2u tileSize = m_tileMap.getTileSize();
	
	for (auto & mapLayer : mapLayers)
	{
		if (mapLayer->getType() != tmx::Layer::Type::Tile)
		{
			continue;
		}

		tmx::TileLayer & tileLayer = static_cast<tmx::TileLayer&>(*mapLayer);

		m_tileLayers.emplace_back();
		TileMapLayer & newLayer= m_tileLayers.back();
		const std::vector<tmx::TileLayer::Tile>& tiles = tileLayer.getTiles();
		int tileIndex = 0;

		for (uint32_t yTileCount = 0; yTileCount < tileCount.y; ++yTileCount)
		{
			for (uint32_t xTileCount = 0; xTileCount < tileCount.x; ++xTileCount)
			{
				const tmx::TileLayer::Tile & tile = tiles[tileIndex];
				
				if (tile.ID != 0)
				{
					sf::Sprite tileSprite;
					auto tileEntry = m_tileData.find(tile.ID);

					if (tileEntry == m_tileData.end())
					{
						throw(std::runtime_error("Referenced unknow tile ID"));
					}

					const TileData & tileData = tileEntry->second;
					tileSprite.setTexture(tileData.getTexture());
					tileSprite.setTextureRect(sf::IntRect(tileData.getStartPoint().x, tileData.getStartPoint().y, tileData.getSize().x, tileData.getSize().y));
					tileSprite.setPosition(static_cast<float>(xTileCount * tileSize.x), static_cast<float>(yTileCount * tileSize.y));
					newLayer.addSprite(tileSprite);


					}

				++tileIndex;

			}
		}

	}



}


