#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Camera.h"


using namespace sf;

Clock tick;

String Tilemap[10] = {
		"............................",
		"............................",
		"............................",
		"............................",
		"............................",
		"............................",
		"............................",
		"............................",
		"GGGGGGGGGGGGGGGGGGGGGGGGGGGG",
		"GGGGGGGGGGGGGGGGGGGGGGGGGGGG"
}; 


int main()
{
	Camera mainCamera(10, 14, 70, Tilemap[10]);
	Player bob(0, 0, mainCamera);
	RenderWindow window(VideoMode(mainCamera.getDispWidth, mainCamera.getDispHight), "Aliens"/*,Style::Fullscreen*/);
	RenderWindow* Pwindow;

	while (window.isOpen())
	{
		float time = tick.getElapsedTime().asMicroseconds(); //
		tick.restart();										 // Мега-шаманства над временем
		time /= 10000;							 //

		Event event;										//
		while (window.pollEvent(event))						// Обработчик 
		{													// закрытия
			if (event.type == Event::Closed)				// окна
				window.close();								//
		}													//


		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
		{
			bob.setDir = 2;	bob.setSpeed(1);
			bob.moveLeft(time);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) 
		{
			bob.setDir = 1;	bob.setSpeed(1);
			bob.moveRight(time);

		}

		if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
		{
				bob.setDir = 3;
				bob.jump();
				bob.setSpeed(30);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) 
		{
			bob.setDir = 4;	bob.setSpeed(1);
		}

		bob.update(time);
		window.clear(Color::White);

		mainCamera.renderMap(Pwindow);

		window.draw(bob.setSprite);
		window.display();
	}

	return 0;
}