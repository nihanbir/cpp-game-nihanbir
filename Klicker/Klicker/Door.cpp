#include "Door.h"

using namespace std;

Door::Door(int width, int height) 
{
	state = new ClosedDoorState;

	mPosition.x = 14;
	mPosition.y = 84;

	this->width = width;
	this->height = height;
}

void Door::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}

bool Door::isHovered()
{
	//Get mouse position
	int x, y;
	SDL_GetMouseState(&x, &y);
	//Mouse is left of the button
	if (x < mPosition.x) return false;
	//Mouse is right of the button
	else if (x > mPosition.x + width) return false;
	//Mouse above the button
	else if (y < mPosition.y) return false;
	//Mouse below the button
	else if (y > mPosition.y + height) return false;
	return true;
}

ClosedDoorState::ClosedDoorState() {
	image = make_unique<Image>("img/openTheDoor.bmp");
}
DoorState* ClosedDoorState::update(const SDL_Event& e, Door& door, Window& window) {
	if (e.type != SDL_MOUSEBUTTONDOWN) return this;
	if (!door.isHovered()) return this;
	// show image
	window.render(image.get());
	return new OpenDoorState();
}

OpenDoorState::OpenDoorState() {
	image = make_unique<Image>("img/main.bmp");
}
DoorState* OpenDoorState::update(const SDL_Event& e, Door& door, Window& window) {
	if (e.type != SDL_MOUSEBUTTONDOWN) return this;
	if (!door.isHovered()) return this;
	// show image
	window.render(image.get());
	return new ClosedDoorState();
}
