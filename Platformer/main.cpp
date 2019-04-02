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
	Player bob(0, 0, mainCamera.getDispHight());
	RenderWindow window(VideoMode(mainCamera.getDispWidth(), mainCamera.getDispHight()), "Aliens"/*,Style::Fullscreen*/);
	RenderWindow* Pwindow = &window;

	while (window.isOpen())
	{
		float time = tick.getElapsedTime().asMicroseconds(); //
		tick.restart();										 // ����-��������� ��� ��������
		time /= 10000;							 //

		Event event;										//
		while (window.pollEvent(event))						// ���������� 
		{													// ��������
			if (event.type == Event::Closed)				// ����
				window.close();								//
		}													//


		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
		{
			bob.setDir(2);	bob.setSpeed(1);
			bob.moveLeft(time);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) 
		{
			bob.setDir(1);	bob.setSpeed(1);
			bob.moveRight(time);

		}

		if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
		{
			bob.setDir(3);
		//	bob.jump();
			bob.setSpeed(5);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) 
		{
			bob.setDir(4);	bob.setSpeed(1);
		}

		bob.update(time);
		window.clear(Color::White);

		mainCamera.renderMap(Pwindow);

		window.draw(bob.getSprite());
		window.display();
	}

	return 0;
}