#include <SFML/Graphics.hpp>
#include <windows.h>
#include "TileMap.h"
#include "Player.h"
#include <iostream>
#include "Animator.h"



int CALLBACK WinMain(_In_ HINSTANCE hInstance,_In_ HINSTANCE hPrevInstance,_In_ LPSTR     lpCmdLine,_In_ int       nCmdShow)
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "RPG YAYAYAYAYA!");
	
	TileMap tileMap("tilemap/testroom.tmx", window);

	sf::View playerView(sf::FloatRect(100, 100, 500, 500));

	//sf::Texture texturePlayer;
	
	//if (!texturePlayer.loadFromFile("tileset/test1.png"))
	//{
	//	return EXIT_FAILURE;
	//}
	
	Player player(sf::Vector2f(300,300));


	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}



		window.clear();

		tileMap.draw();

		//player.updateMovement();
		
		player.update(deltaTime);
		player.draw(window);
	
		
		window.display();

		//playerView.setCenter(player.getRectPosition());
		window.setView(playerView);

	}

	return 0;
}

