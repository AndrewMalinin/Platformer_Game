#pragma once
using namespace sf;

class Player 
{
private:
	String textureFolder_ = "G:/Projects/Textures/";
	const int WIDTH_ = 73;			// ������ ���������
	const int HIGHT_ = 97;			// ������ ���������
	const short BASE_SPEED_ = 6;		// ������� �������� ������
	float currentFrame_;			// ������� �������� ����� 
	unsigned short int frames_ = 6;	// ���������� ������ � ��������
	float dx_, dy_;					// ���������� ����������
	Texture texture;				// ������ ������ ��������
	Sprite sprite;					// ������ �������, ���� "�������" ��������
	short dir_;					// ����������� �������� ������ 1-right, 2-left,3-up,4-down
	float x_, y_;					// ������� ���������� ������
	const float GRAVITY_ = 0.5;		// ��������� ���������� �������
	const float FRICTION_ = 0.2;
	int dispHight_;
	int dispWidth_;
	float speedX_{0}, speedY_{0};
public:
	
	Player(int xst, int yst, int DispHight, int DispWidth);

	void moveLeft(float time);

	void moveRight(float time);

	void setSpeedXY(float speedUpX, float speedUpY);			// ��������� �������� ������������ �������

	void setDir(short dir);

	Sprite getSprite();
	
	void jump();

	void setCurrentFrame(int FrameNo);


	void update(float time);
};
