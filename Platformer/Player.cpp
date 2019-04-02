#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Camera.h"
using namespace sf;


Player::Player(int xst, int yst, Camera mainCamera) 
{

	texture.loadFromFile(textureFolder_ + +"Base pack/Player/" + "p1_spritesheet.PNG");	// ��������� ���������
	sprite.setTexture(texture);			//
	sprite.setTextureRect(IntRect(xst, yst, width_, hight_));
	x_ = width_;	y_ = mainCamera.getDispHight - hight_;
	sprite.setPosition(x_, y_);
	dx_ = dy_ = 0;
	currentFrame_ = 0;
	speed_ = 1.0;					// ������������� ��������� �������� �����
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



void Player::setSpeed(float speedup) {			// ����� ��������� �������� ������������ �������
	speed_ = speedup;
}



void Player::update(float time) 
{

	switch (dir_) {
	case 1:		dx_ = (baseSpeed_ * speed_)*time;		dy_ = 0;				break;
	case 2:		dx_ = -(baseSpeed_* speed_)*time;		dy_ = 0;				break;
	case 3:		dx_ = 0;		dy_ = (baseSpeed_ * speed_)*time + gravity_;	break;
	case 4:		dx_ = 0;		dy_ = (baseSpeed_ * speed_)*time;				break;

	}


	x_ += dx_;
	y_ += dy_;
	sprite.setPosition(x_, y_);

	speed_ = 0;
}
