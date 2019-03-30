#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

Clock tick;
const int ground = 560;			// ������� ����� � ����
const int baseSpeed = 6;		// ������� �������� ������
const float acc = 8;			// ��������� ���������� ������� � ����
const int dispHight = 700, dispWidth = 700;
String Texture_Folder = "G:/Projects/Textures/";

class map {
public:
	String Tilemap[10] = {
		"..........",
		"..........",
		"..........",
		"..........",
		"..........",
		"..........",
		"..........",
		"..........",
		"GGGGGGGGGG",
		"GGGGGGGGGG"
	};

	Texture t, bg;
	Sprite s;
	map() {
		bg.loadFromFile(Texture_Folder + "Base pack/bg.PNG");  // ������ ����
		t.loadFromFile(Texture_Folder + "Base pack/Tiles/Grass.PNG");
	}

};


class player {
private:
	float currentFrame;		// ������� ���������-������� �������� ����� 
	unsigned short int frames = 6;	// ���������� ������ � ��������
	int width = 73;			// ������ ���������
	int hight = 97;			// ������ ���������
	float dx, dy;				// ���������� ����������
	float speed;				// �������� ������ ������������ �������


public:
	Texture t;					// ������ ������ ������ ��������
	Sprite s;					// ������ ������ ������, ���� "�������" ��������
	short int dir = 0;				// ���������, �������� ����������� �������� ������ 1-right, 2-left,3-up,4-down
	float x, y;					// ������� ���������� ������
	bool onGround = true;
	float jumpTimePointer;		// ������� ���������� � ������� ������ �������
	float jumpTime = 10000;		// ����� ������

	player(int xst, int yst, String file) {

		t.loadFromFile(Texture_Folder + +"Base pack/Player/" + file);		// ��������� ���������
		s.setTexture(t);			//
		s.setTextureRect(IntRect(xst, yst, width, hight));
		x = width;	y = dispHight - hight;
		s.setPosition(x, y);
		dx = dy = 0;
		currentFrame = 0;
		speed = 1.0;					// ������������� ��������� �������� �����
	}

	void moveLeft(float time) {
		currentFrame += 0.09*time;
		if (currentFrame > frames) currentFrame -= frames;
		s.setTextureRect(IntRect(width * int(currentFrame) + width, 0, -width, hight));
	}

	void moveRight(float time) {
		currentFrame += 0.09*time;
		if (currentFrame > frames) currentFrame -= frames;
		s.setTextureRect(IntRect(width * int(currentFrame), 0, width, hight));
	}

	void setSpeed(float speedup) {			// ����� ��������� �������� ������������ �������
		speed = speedup;
	}



	void update(float time) {

		switch (dir) {
		case 1:		dx = (baseSpeed * speed)*time;	dy = 0;									break;
		case 2:		dx = -(baseSpeed* speed)*time;	dy = 0;									break;
		case 3:		dx = 0;						dy = -(baseSpeed * speed * 3)*time + acc;	break;
		case 4:		dx = 0;						dy = (baseSpeed * speed)*time;	break;

		}

		if (!onGround)
			dy += acc * time;

		onGround = false;

		if (y >= ground - hight) {
			y = ground - hight;				// ������ �������� �� ������
			jumpTimePointer = 0;			// ����� ������ ������������� � ����
			onGround = true;
		}
		x += dx;
		y += dy;
		s.setPosition(x, y);

		speed = 0;
	}
};


int main()
{

	player bob(0, 0, "p1_spritesheet.PNG");
	map map;
	RenderWindow window(VideoMode(dispWidth, dispHight), "Video-Game"/*,Style::Fullscreen*/);

	while (window.isOpen())
	{
		float time = tick.getElapsedTime().asMicroseconds(); //
		tick.restart();										 // ����-��������� ��� ��������
		time /= 10000;							 //
		bob.jumpTimePointer += time;

		Event event;										//
		while (window.pollEvent(event))						// ���������� 
		{													// ��������
			if (event.type == Event::Closed)				// ����
				window.close();								//
		}													//


		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
			bob.dir = 2;	bob.setSpeed(1);
			bob.moveLeft(time);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
			bob.dir = 1;	bob.setSpeed(1);
			bob.moveRight(time);

		}

		if (Keyboard::isKeyPressed(Keyboard::Up)) {

			if (bob.onGround) {
				bob.dir = 3;	bob.setSpeed(10); bob.onGround = false;
			}


		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			bob.dir = 4;	bob.setSpeed(1);
		}

		bob.update(time);
		window.clear(Color::White);

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (map.Tilemap[i][j] == '.') {
					map.s.setTexture(map.bg);
					map.s.setPosition(j * 70, i * 70);
					window.draw(map.s);
				}
				if (map.Tilemap[i][j] == 'G') {
					map.s.setTexture(map.t);
					map.s.setPosition(j * 70, i * 70);
					window.draw(map.s);
				}
			}
		}
		window.draw(bob.s);
		window.display();
	}

	return 0;
}