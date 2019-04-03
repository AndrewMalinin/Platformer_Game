#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Camera.h"

using namespace sf;


Player::Player(int xst, int yst, int DispHight, int DispWidth)
{

	texture.loadFromFile(textureFolder_ + +"Base pack/Player/" + "p1_spritesheet.PNG");	// Загружаем текстурку
	sprite.setTexture(texture);			//
	sprite.setTextureRect(IntRect(xst, yst, WIDTH_, HIGHT_));
	x_ = WIDTH_;
	dispHight_ = DispHight;
	dispWidth_ = DispWidth;
	y_ = DispHight - HIGHT_;
	sprite.setPosition(x_, y_);
	dx_ = dy_ = 0;
	currentFrame_ = 0;			
}



void Player::moveLeft(float time) 
{
	currentFrame_ += 0.09*time;
	if (currentFrame_ > frames_) currentFrame_ -= frames_;
	sprite.setTextureRect(IntRect(WIDTH_ * int(currentFrame_) + WIDTH_, 0, -WIDTH_, HIGHT_));
}



void Player::moveRight(float time) 
{
	currentFrame_ += 0.09*time;
	if (currentFrame_ > frames_) currentFrame_ -= frames_;
	sprite.setTextureRect(IntRect(WIDTH_ * int(currentFrame_), 0, WIDTH_, HIGHT_));
}



void Player::setSpeedXY(float speedUpX, float speedUpY) // Метод установки скорости относительно базовой
{			
	speedX_ = speedUpX;
	speedY_ = -speedUpY;
}



void Player::setCurrentFrame(int FrameNo)
{
	currentFrame_ = FrameNo;
}


Sprite Player::getSprite()
{
	return sprite;
}


void Player::setDir(short Directory) 
{
	dir_ = Directory;
}

void Player::update(float time) 
{	
	switch (dir_)
	{
	case 1 :

		dx_ = speedX_ * time;
		dy_ = speedY_ * time/*- GRAVITY_*/;
		speedX_ += FRICTION_;
		if (speedX_ > 0)

	break;
	case 2 : 

		dx_ = speedX_ * time;
		dy_ = speedY_ * time/*- GRAVITY_*/;
		speedX_ -= FRICTION_;
		if (speedX_ < 0)
		{
			speedX_ = 0;
		}


	break;
	case 3 :
		dx_ = speedX_ * time;
		dy_ = speedY_ * time;

	break;
	case 4 : break;
	}

	if (((x_) < 0))
	{
		x_ = 0; dx_ = 0;
	}
	if((x_ + WIDTH_) > dispWidth_)
	{
		x_ = dispWidth_ - WIDTH_; dx_ = 0; speedX_ = 0;
	}

	if (y_ > dispHight_ - HIGHT_)
	{
		y_ = dispHight_- HIGHT_; speedY_ = 0; 	
	}
	else
	{
		speedY_ += GRAVITY_;
	}
	speedY_ += GRAVITY_;

	x_ += dx_;
	y_ += dy_;
	sprite.setPosition(x_,y_);
}
