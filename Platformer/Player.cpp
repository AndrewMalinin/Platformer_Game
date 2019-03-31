#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>
	
Player::Player(int xst, int yst, String file) {

		t.loadFromFile(textureFolder + +"Base pack/Player/" + file);		// «агружаем текстурку
		s.setTexture(t);			//
		s.setTextureRect(IntRect(xst, yst, width, hight));
		x = width;	y = dispHight - hight;
		s.setPosition(x, y);
		dx = dy = 0;
		currentFrame_ = 0;
		speed_ = 1.0;					// ”станавливаем начальную скорость геро€
	}

	void Player::moveLeft(float time) {
		currentFrame_ += 0.09*time;
		if (currentFrame_ > frames) currentFrame_ -= frames;
		s.setTextureRect(IntRect(width * int(currentFrame_) + width, 0, -width, hight));
	}

	void Player::moveRight(float time) {
		currentFrame_ += 0.09*time;
		if (currentFrame_ > frames) currentFrame -= frames;
		s.setTextureRect(IntRect(width * int(currentFrame), 0, width, hight));
	}

	void Player::setSpeed(float speedup) {			// ћетод установки скорости относительно базовой
		speed_ = speedup;
	}



	void Player::update(float time) {

		switch (dir_) {
		case 1:		dx = (baseSpeed * speed_)*time;		dy = 0;				break;
		case 2:		dx = -(baseSpeed* speed_)*time;		dy = 0;				break;
		case 3:		dx = 0;		dy = (baseSpeed * speed_)*time + G_const;	break;
		case 4:		dx = 0;		dy = (baseSpeed * speed_)*time;				break;

		}


		x += dx;
		y += dy;
		s.setPosition(x, y);

		speed_ = 0;
	}
