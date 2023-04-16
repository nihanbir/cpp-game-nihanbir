#include "Door.h"
#include "ClosedDoorState.h"

bool gameOver = false;

using namespace std;

Door::Door(SDL_Rect doorRect, const char* closedDoorImg, const char* openDoorImg) 
{
	rect = doorRect;
	images[0] = closedDoorImg;
	images[1] = openDoorImg;
	state = make_unique<ClosedDoorState>(*this);
	
}

void Door::handleInput(const SDL_Event& e, Door& door, Window& window) {
	unique_ptr<DoorState> newState = state->update(e, door, window);
	if (newState != nullptr) state = move(newState);
}

bool Door::isHovered()
{
	//Get mouse position
	int x, y;
	SDL_GetMouseState(&x, &y);
	//Mouse is left of the button
	if (x < rect.x) return false;
	//Mouse is right of the button
	else if (x > rect.x + rect.w) return false;
	//Mouse above the button
	else if (y < rect.y) return false;
	//Mouse below the button
	else if (y > rect.y + rect.h) return false;
	return true;
}