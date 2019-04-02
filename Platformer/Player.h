#pragma once

class Player 
{
private:
	const int width_ = 73;			// ������ ���������
	const int hight_ = 97;			// ������ ���������
	const short baseSpeed_ = 6;		// ������� �������� ������
	String textureFolder_ = "G:/Projects/Textures/";
	float currentFrame_;			// ������� �������� ����� 
	unsigned short int frames_ = 6;	// ���������� ������ � ��������
	float dx_, dy_;					// ���������� ����������
	float speed_;					// �������� ������ ������������ �������
	Texture texture;				// ������ ������ ��������
	Sprite sprite;					// ������ �������, ���� "�������" ��������
	short int dir_;					// ����������� �������� ������ 1-right, 2-left,3-up,4-down
	float x_, y_;					// ������� ���������� ������
	float jumpTimePointer_;			// ������� ���������� � ������� ������ �������
	const float gravity_ = 7;		// ��������� ���������� �������

public:
	
	Player(int xst, int yst, Camera mainCamera);

	void moveLeft(float time);

	void moveRight(float time);

	void setSpeed(float speedup);			// ��������� �������� ������������ �������

	void setDir(int dir);

	void setSprite();
	
	void jump();

	void setCurrentFrame();


	void update(float time);
};
