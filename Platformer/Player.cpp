#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Camera.h"

using namespace sf;


Player::Player(int xst, int yst, int DispHight)
{

	texture.loadFromFile(textureFolder_ + +"Base pack/Player/" + "p1_spritesheet.PNG");	// «агружаем текстурку
	sprite.setTexture(texture);			//
	sprite.setTextureRect(IntRect(xst, yst, width_, hight_));
	x_ = width_;	
	dispHight_ = DispHight;
	y_ = DispHight - hight_;
	sprite.setPosition(x_, y_);
	dx_ = dy_ = 0;
	currentFrame_ = 0;
	speed_ = 0;				// ”станавливаем начальную скорость геро€
}



void Player::moveLeft(float time) 
{
	currentFrame_ += 0.09*time;
	if (currentFrame_ > frames_) currentFrame_ -= frames_;
	sprite.setTextureRect(IntRect(width_ * int(currentFrame_) + width_, 0, -width_, hight_));
}



void Player::moveRight(float time) 
{
	currentFrame_ += 0.09*time;
	if (currentFrame_ > frames_) currentFrame_ -= frames_;
	sprite.setTextureRect(IntRect(width_ * int(currentFrame_), 0, width_, hight_));
}



void Player::setSpeed(float speedup) // ћетод установки скорости относительно базовой
{			
	speed_ = speedup;
}



void Player::setCurrentFrame(int FrameNo)
{
	currentFrame_ = FrameNo;
}


Sprite Player::getSprite()
{
	return sprite;
}


void Player::setDir(int Directory) 
{
	dir_ = Directory;
}

void Player::update(float time) 
{

	switch (dir_) {
	case 1:
	{
	
		if (speed_ > 0)
		{
			dx_ = (baseSpeed_ * speed_)*time;		
			speed_ -= friction;
		}
		else {
			speed_ = 0;
		}
		dy_ = 0;
	}break;
	



	case 2: 
	{

		if (speed_ > 0)
		{
			dx_ = -(baseSpeed_* speed_)*time;
			speed_ -= friction;
		}
		else {
			speed_ = 0;
		}
		dy_ = 0;
	}break;		

	case 3:	
	{
			dy_ = -(baseSpeed_ * speed_)*time;


		dx_ = 0;
	}break;
	case 4:		dx_ = 0;		dy_ = (baseSpeed_ * speed_)*time;				break;

	}


	x_ += dx_; 
	if (y_ > -dispHight_+hight_)
	{
		y_ += dy_;
		dy_ -= gravity_;
	}
	else {
		y_ = -dispHight_+hight_;
	}
	sprite.setPosition(x_, y_);


}
