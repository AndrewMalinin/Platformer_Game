#pragma once
class Player {
private:
	float currentFrame_;				// ������� �������� ����� 
	unsigned short int frames = 6;	// ���������� ������ � ��������
	const int width = 73;			// ������ ���������
	const int hight = 97;			// ������ ���������
	float dx, dy;				// ���������� ����������
	float speed_;				// �������� ������ ������������ �������
	Texture t;					// ������ ������ ��������
	Sprite s;					// ������ �������, ���� "�������" ��������
	short int dir_;			// ����������� �������� ������ 1-right, 2-left,3-up,4-down
	float x, y;					// ������� ���������� ������
	float jumpTimePointer;		// ������� ���������� � ������� ������ �������

public:
	
	Player(int xst, int yst, String file) {}

	void moveLeft(float time) {}

	void moveRight(float time) {}

	void setSpeed(float speedup) {}			// ��������� �������� ������������ �������

	void setDir(int dir) {}

	void setSprite(Sprite s) {}

	void setCurrentFrame() {}


	void update(float time) {}
};
