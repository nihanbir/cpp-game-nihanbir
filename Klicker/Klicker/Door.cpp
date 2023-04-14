#include "Door.h"

using namespace std;

Door::Door(int width, int height)
{
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

enum class GameState { DoorClosed, DoorOpen, GameOver };

unique_ptr<Image> Door::SetImage() {

	if (isHovered()) {
		if (isOpen) {
			return make_unique<Image>(images[(int)GameState::GameOver]);
		}
		else {
			isOpen = true;
			return make_unique<Image>(images[(int)GameState::DoorOpen]);
		}
	}
	else {
		isOpen = false;
		return make_unique<Image>(images[(int)GameState::DoorClosed]);
	}
}