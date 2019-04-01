#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

using namespace sf;

Clock tick;
const short baseSpeed = 6;		// ������� �������� ������
const float g_gravity = 7;  // ��������� ���������� �������


String textureFolder = "G:/Projects/Textures/";



class map 
{
private:
/*	String *Tilemap = new String[g_gravity]
	{
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
	};*/
public:
	
	Texture t, bg;
	Sprite s;
	map() 
	{
		bg.loadFromFile(Texture_Folder + "Base pack/bg.PNG");			// ������ ����
		t.loadFromFile(Texture_Folder + "Base pack/Tiles/Grass.PNG");
	}

};

class camera
{
private:
	int SizeBlock = 70;		// ������� ������������ ��������
	const short blocksHight = 10;					//
	const short blocksWidth = 14;					// ������� ���� ���� � ���������� ������
	int dispHight = blocksHight * SizeBlock;	 //
	int dispWidth = blocksWidth * SizeBlock;  // ���������� ������� ������
	char camera_buffer[blocksHight][14];
	unsigned int current_location;

	void set_location(int location)
	{
		current_location = location;
	}
public:
	camera()
	{
		current_location = 0;
		for (int i = 0; i < blocksHight; i++)
		{
			for (int j = 0; j < blocksWidth; j++)
			{
				camera_buffer[i][j] = Tilemap[i][j + current_location];
			}
		}
	}
};




int main()
{

	Player bob(0, 0, "p1_spritesheet.PNG");
	map map;
	camera camera1;
	RenderWindow window(VideoMode(dispWidth, dispHight), "Aliens"/*,Style::Fullscreen*/);

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
			bob.setDir = 2;	bob.setSpeed(1);
			bob.moveLeft(time);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) 
		{
			bob.set_dir = 1;	bob.setSpeed(1);
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
			bob.set_dir = 4;	bob.setSpeed(1);
		}

		bob.update(time);
		window.clear(Color::White);

		for (int i = 0; i < blocksHight; i++) {
			for (int j = 0; j < blocksWidth; j++) {
				if (Tilemap[i][j] == '.') {
					map.s.setTexture(map.bg);
					map.s.setPosition(j * SizeBlock, i * SizeBlock);
					window.draw(map.s);
				}
				if (Tilemap[i][j] == 'G') {
					map.s.setTexture(map.t);
					map.s.setPosition(j * SizeBlock, i * SizeBlock);
					window.draw(map.s);
				}
			}
		}
		window.draw(bob.setSprite);
		window.display();
	}

	return 0;
}