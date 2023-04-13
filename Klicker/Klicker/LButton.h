#pragma once
#include <SDL.h>

//The mouse button
class LButton
{
public:
	
	//Initializes internal variables
	LButton();

	//Sets bottom left position
	void setPosition(int x, int y);

	//Checks if the click landed on the button
	bool isClicked(int width, int height);

private:
	//Button position
	SDL_Point mPosition;
};

