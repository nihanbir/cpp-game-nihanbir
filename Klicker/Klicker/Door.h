#pragma once
#include <memory>
#include "Image.h"
#include "Window.h"
#include "GlobalVariables.h"

using namespace std;

class Door;

class DoorState {
public:
	Door* door;

	unique_ptr<Image> image;

	virtual DoorState* update(const SDL_Event& e, Door& door, Window& window) = 0;
};

class ClosedDoorState : public DoorState{
public:
	ClosedDoorState(Door& door);
	DoorState* update(const SDL_Event& e, Door& door, Window& window) override;
};

class OpenDoorState : public DoorState{
public:
	OpenDoorState(Door& door);
	DoorState* update(const SDL_Event& e, Door& door, Window& window) override;

};

//The button
class Door : public DoorState
{
	//Door state
	DoorState* state;

public:	
	string images[2];

	SDL_Rect rect;

	//Initializes internal variables
	Door(SDL_Rect doorRect, const char* closedDoorImg, const char* openDoorImg);

	//Checks if the click landed on the door
	bool isHovered();

	DoorState* update(const SDL_Event& e, Door& door, Window& window) {
		DoorState* oldState = state;
		state = state->update(e, door, window);
		oldState = nullptr;
		return state;
	}
};
