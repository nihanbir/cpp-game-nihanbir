#pragma once
#include <SDL.h>

//The mouse button
class Door
{
public:

	bool isOpen{};

	int width;
	int height;

	//Initializes internal variables
	Door(int width, int height);

	//Sets top left position
	void setPosition(int x, int y);

	//Checks if the click landed on the door
	bool isClicked();

private:
	//Door position
	SDL_Point mPosition;
};