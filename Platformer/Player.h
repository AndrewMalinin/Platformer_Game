#pragma once
class Player {
private:
	float currentFrame_;				// Счётчик текущего кадра 
	unsigned short int frames = 6;	// Количество кадров в анимации
	const int width = 73;			// Ширина текстурки
	const int hight = 97;			// Высота текстурки
	float dx, dy;				// Приращение координаты
	float speed_;				// Скорость игрока относительно базовой
	Texture t;					// Объект класса текстура
	Sprite s;					// ОбЪект спрайта, куда "натянем" текстуру
	short int dir_;			// Направление движения игрока 1-right, 2-left,3-up,4-down
	float x, y;					// Текущие координаты игрока
	float jumpTimePointer;		// Счётчик прошедшего с момента прыжка времени

public:
	
	Player(int xst, int yst, String file) {}

	void moveLeft(float time) {}

	void moveRight(float time) {}

	void setSpeed(float speedup) {}			// Установка скорости относительно базовой

	void setDir(int dir) {}

	void setSprite(Sprite s) {}

	void setCurrentFrame() {}


	void update(float time) {}
};
