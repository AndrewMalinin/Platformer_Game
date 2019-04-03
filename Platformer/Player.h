#pragma once
using namespace sf;

class Player 
{
private:
	String textureFolder_ = "G:/Projects/Textures/";
	const int WIDTH_ = 73;			// Ширина текстурки
	const int HIGHT_ = 97;			// Высота текстурки
	const short BASE_SPEED_ = 6;		// Базовая скорость юнитов
	float currentFrame_;			// Счётчик текущего кадра 
	unsigned short int frames_ = 6;	// Количество кадров в анимации
	float dx_, dy_;					// Приращение координаты
	Texture texture;				// Объект класса текстура
	Sprite sprite;					// ОбЪект спрайта, куда "натянем" текстуру
	short dir_;					// Направление движения игрока 1-right, 2-left,3-up,4-down
	float x_, y_;					// Текущие координаты игрока
	const float GRAVITY_ = 0.5;		// Ускорение свободного падения
	const float FRICTION_ = 0.2;
	int dispHight_;
	int dispWidth_;
	float speedX_{0}, speedY_{0};
public:
	
	Player(int xst, int yst, int DispHight, int DispWidth);

	void moveLeft(float time);

	void moveRight(float time);

	void setSpeedXY(float speedUpX, float speedUpY);			// Установка скорости относительно базовой

	void setDir(short dir);

	Sprite getSprite();
	
	void jump();

	void setCurrentFrame(int FrameNo);


	void update(float time);
};
