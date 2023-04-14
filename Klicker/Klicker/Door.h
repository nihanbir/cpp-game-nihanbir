#pragma once

#include <SDL.h>
#include "Image.h"
#include <memory>

//The button
class Door
{
public:

	bool isOpen{};

	int width;
	int height;

	const char* images[3]{ "img/main.bmp", "img/openTheDoor.bmp", "img/GJ.bmp" };

	unique_ptr<Image> SetImage();

	//Initializes internal variables
	Door(int width, int height);

	//Sets top left position
	void setPosition(int x, int y);

	//Checks if the click landed on the door
	bool isHovered();

private:
	//Door position
	SDL_Point mPosition;
};