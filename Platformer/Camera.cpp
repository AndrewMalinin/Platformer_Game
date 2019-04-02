#include <SFML/Graphics.hpp>
#include "Camera.h"

using namespace sf;


	Camera::Camera(int blocksHight, int blocksWidth, int sizeBlock, String Tilemap)
	{
		currentLocation_ = 0;
		blocksWidth_ = blocksWidth;		// Получаем желаемые размеры окна
		blocksHight_ = blocksHight;
		dispHight_ = blocksWidth_*sizeBlock_;

		for (int i = 0; i < blocksHight; i++)
		{
			for (int j = 0; j < blocksWidth; j++)
			{
			//	cameraBuffer_[i][j] = Tilemap[i][j + currentLocation_];
			}
		}

		bg_.loadFromFile(textureFolder_ + "Base pack/bg.PNG");				// Задний план
		grass_.loadFromFile(textureFolder_ + "Base pack/Tiles/Grass.PNG");
		water_.loadFromFile(textureFolder_ + "Base pack/Tiles/liquidWater.PNG");
	}


	void Camera::renderMap(RenderWindow* window)
	{
		for (int i = 0; i < blocksHight_; i++) 
		{
			for (int j = 0; j < blocksWidth_; j++) 
			{
				if (cameraBuffer_[i][j] == '.')
				{
					spriteBlock_.setTexture(bg_);
					spriteBlock_.setPosition(j * sizeBlock_, i * sizeBlock_);
					window-> draw(spriteBlock_);
				}

				if (cameraBuffer_[i][j] == 'G')
				{
					spriteBlock_.setTexture(grass_);
					spriteBlock_.setPosition(j * sizeBlock_, i * sizeBlock_);
					window-> draw(spriteBlock_);
				}
			}
		}
	}



	int Camera::getDispWidth()
	{
		return dispWidth_;
	}



	int Camera::getDispHight()
	{
		return dispHight_;
	}



	void Camera::set_location(int location)
	{
		currentLocation_ = location;
	}

