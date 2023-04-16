#pragma once
#include <memory>
#include "Image.h"
#include "Window.h"
#include "GlobalVariables.h"
#include "DoorState.h"

using namespace std;

//The button
class Door
{

public:	
	//Door state
	unique_ptr<DoorState> state;
	
	string images[2];

	SDL_Rect rect;

	//Initializes internal variables
	Door(SDL_Rect doorRect, const char* closedDoorImg, const char* openDoorImg);

	//Checks if the click landed on the door
	bool isHovered();

	void handleInput(const SDL_Event& e, Door& door, Window& window);
};
