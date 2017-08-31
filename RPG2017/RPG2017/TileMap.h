#pragma once
#include<SFML/Graphics.hpp>
#include <tmxlite\Map.hpp>
#include "TileData.h"
#include "TileMapLayer.h"

class TileMap
{
private:
	void createTileLayer();
	void loadTileSet();
	std::map<uint32_t, TileData> m_tileData;
	std::vector<TileMapLayer> m_tileLayers;

	std::vector<sf::Texture> m_textures;  //vector of tileset textures
	std::string m_mapPath;
	sf::RenderTarget &m_renderTarget;
	tmx::Map m_tileMap;



public:
	TileMap(const std::string &mapPath, sf::RenderTarget &window);
	~TileMap();

	void draw();


};

