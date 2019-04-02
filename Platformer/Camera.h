#pragma once

class Camera
{
private:
	int sizeBlock_;						// ������� ������������ ��������
	short int  blocksHight_, blocksWidth_;	// ������� ���� ���� � ���������� ������				
	int dispHight_, dispWidth_;			// ������� ���� � ��������
	unsigned int currentLocation_;		// ������� ���������� ��������������� ������������ �����

	char cameraBuffer_[10][14];
	Sprite spriteBlock_;
	Texture grass_;
	Texture bg_;
	Texture water_;

	String textureFolder_{ "G:/Projects/Textures/" };

public:
	Camera(int blocksHight, int blocksWidth, int sizeBlock, String Tilemap);

	void renderMap(RenderWindow* window);

	int getDispWidth();

	int getDispHight();

	void set_location(int location);
};