#pragma once
using namespace sf;

class Player 
{
private:
	String textureFolder_ = "G:/Projects/Textures/";
	const int width_ = 73;			// Ширина текстурки
	const int hight_ = 97;			// Высота текстурки
	const short baseSpeed_ = 6;		// Базовая скорость юнитов

	float currentFrame_;			// Счётчик текущего кадра 
	unsigned short int frames_ = 6;	// Количество кадров в анимации
	float dx_, dy_;					// Приращение координаты
	float speed_;					// Скорость игрока относительно базовой
	Texture texture;				// Объект класса текстура
	Sprite sprite;					// ОбЪект спрайта, куда "натянем" текстуру
	short int dir_;					// Направление движения игрока 1-right, 2-left,3-up,4-down
	float x_, y_;					// Текущие координаты игрока
	float jumpTimePointer_;			// Счётчик прошедшего с момента прыжка времени
	const float gravity_ = 7;		// Ускорение свободного падения
public:
	
	Player(int xst, int yst, int DispHight);

	void moveLeft(float time);

	void moveRight(float time);

	void setSpeed(float speedup);			// Установка скорости относительно базовой

	void setDir(int dir);

	Sprite getSprite();
	
	void jump();

	void setCurrentFrame();


	void update(float time);
};
