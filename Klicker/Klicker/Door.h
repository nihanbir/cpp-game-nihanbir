#pragma once
#include <SDL.h>
#include "Image.h"
#include <memory>
#include "Window.h"

class Door;

class DoorState {
public:

	unique_ptr<Image> image;

	virtual DoorState* update(const SDL_Event& e, Door& door, Window& window) = 0;

	DoorState() {};
};

class ClosedDoorState : public DoorState{
public:
	ClosedDoorState();
	DoorState* update(const SDL_Event& e, Door& door, Window& window) override;
};

class OpenDoorState : public DoorState{
public:
	OpenDoorState();
	DoorState* update(const SDL_Event& e, Door& door, Window& window) override;

};

//The button
class Door : public DoorState
{
	//Door position
	SDL_Point mPosition;

	//Door state
	DoorState* state;

public:

	int width;
	int height;

	unique_ptr<Image> onClick();

	//Initializes internal variables
	Door(int width, int height);

	//Sets top left position
	void setPosition(int x, int y);

	//Checks if the click landed on the door
	bool isHovered();

	DoorState* update(const SDL_Event& e, Door& door, Window& window) {
		DoorState* oldState = state;
		state = state->update(e, door, window);
		oldState = nullptr;
		return state;
	}
};
