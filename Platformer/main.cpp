#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

Clock tick;
const int ground = 560;			// Уровень земли в мире
#define baseSpeed  6		// Базовая скорость юнитов
const float acc = 8;			// Ускорение свободного падения в мире
#define SizeBlock  70		// Размеры элементарной текстуры
#define blocksHight  10
#define blocksWidth  14   // Размеры окна игры в количестве блоков
const int dispHight = blocksHight *SizeBlock, dispWidth = blocksWidth * SizeBlock;  // Пискельные размеры экрана
String Texture_Folder = "G:/Projects/Textures/";

String Tilemap[blocksHight] = {
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

class map {
public:
	
	Texture t, bg;
	Sprite s;
	map() 
	{
		bg.loadFromFile(Texture_Folder + "Base pack/bg.PNG");			// Задний план
		t.loadFromFile(Texture_Folder + "Base pack/Tiles/Grass.PNG");
	}

};

class camera
{
private:
	String camera_buffer[blocksHight];
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


class player {
private:
	float currentFrame;		// зададим пременную-счётчик текущего кадра 
	unsigned short int frames = 6;	// Количество кадров в анимации
	int width = 73;			// Ширина текстурки
	int hight = 97;			// Высота текстурки
	float dx, dy;				// Приращение координаты
	float speed;				// Скорость игрока относительно базовой


public:
	Texture t;					// Создаём обьект класса текстура
	Sprite s;					// Создаём обьект спрайт, куда "натянем" текстуру
	short int dir = 0;				// Переменая, хранящая направление движения игрока 1-right, 2-left,3-up,4-down
	float x, y;					// Текущие координаты игрока
	bool onGround = true;
	float jumpTimePointer;		// Счётчик прошедшего с момента прыжка времени
	float jumpTime = 10000;		// Время прыжка

	player(int xst, int yst, String file) {

		t.loadFromFile(Texture_Folder + +"Base pack/Player/" + file);		// Загружаем текстурку
		s.setTexture(t);			//
		s.setTextureRect(IntRect(xst, yst, width, hight));
		x = width;	y = dispHight - hight;
		s.setPosition(x, y);
		dx = dy = 0;
		currentFrame = 0;
		speed = 1.0;					// Устанавливаем начальную скорость героя
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

	void setSpeed(float speedup) {			// Метод установки скорости относительно базовой
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
			y = ground - hight;				// Игрока помещаем на земмлю
			jumpTimePointer = 0;			// Время прыжка устанавливаем в ноль
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
	camera camera1;
	RenderWindow window(VideoMode(dispWidth, dispHight), "Aliens"/*,Style::Fullscreen*/);

	while (window.isOpen())
	{
		float time = tick.getElapsedTime().asMicroseconds(); //
		tick.restart();										 // Мега-шаманства над временем
		time /= 10000;							 //
		bob.jumpTimePointer += time;

		Event event;										//
		while (window.pollEvent(event))						// Обработчик 
		{													// закрытия
			if (event.type == Event::Closed)				// окна
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
		window.draw(bob.s);
		window.display();
	}

	return 0;
}