#pragma once
using namespace sf;

class Camera
{

public:
	Camera(int blocksHight, int blocksWidth, int sizeBlock, String Tilemap[10]);

	void renderMap(RenderWindow* window);

	int getDispWidth();

	int getDispHight();
	 
	void set_location(int location);
};