#include <SFML/Graphics.hpp>
#include <iostream>
#include "Camera.h"
#include "Player.h"

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
	Camera mainCamera(10, 14, 70, Tilemap);
	Player bob(0, 0, mainCamera.getDispHight(), mainCamera.getDispWidth());
	RenderWindow window(VideoMode(mainCamera.getDispWidth(), mainCamera.getDispHight()), "Aliens");
	RenderWindow* Pwindow = &window;

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
			bob.setDir(1);	bob.setSpeedXY(-5, 0);
			bob.moveLeft(time);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) 
		{
			bob.setDir(2);	bob.setSpeedXY(5, 0);
			bob.moveRight(time);

		}

		if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
		{
			bob.setDir(3);
		//	bob.jump();
			bob.setSpeedXY(0, 20);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) 
		{
			bob.setDir(4);	bob.setSpeedXY(0, -1);
		}

		bob.update(time);
		window.clear(Color::White);

		mainCamera.renderMap(Pwindow);
		window.draw(bob.getSprite());
		window.display();
	}

	return 0;
}