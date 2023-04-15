#include "Door.h"

bool gameOver = false;

using namespace std;

Door::Door(SDL_Rect doorRect, const char* closedDoorImg, const char* openDoorImg) 
{
	images[0] = closedDoorImg;
	images[1] = openDoorImg;

	state = new ClosedDoorState(*this);

	rect = doorRect;
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

ClosedDoorState::ClosedDoorState(Door& door) {
	image = make_unique<Image>(door.images[1]);
}
DoorState* ClosedDoorState::update(const SDL_Event& e, Door& door, Window& window) {
	if (e.type != SDL_MOUSEBUTTONDOWN) return this;
	if (!door.isHovered()) return this;
	// show image
	window.render(image.get(), &door.rect);
	return new OpenDoorState(door);
}

OpenDoorState::OpenDoorState(Door& door) {
	image = make_unique<Image>(door.images[0]);
}
DoorState* OpenDoorState::update(const SDL_Event& e, Door& door, Window& window) {
	if (e.type != SDL_MOUSEBUTTONDOWN) return this;
	if (!door.isHovered()) return this;
	if (e.button.button == SDL_BUTTON_LEFT) {
		// show image
		window.render(image.get(), &door.rect);
		return new ClosedDoorState(door);
	}
	if (e.button.button == SDL_BUTTON_RIGHT) {
		gameOver = true;	
		return this;
	}
	return this;
}