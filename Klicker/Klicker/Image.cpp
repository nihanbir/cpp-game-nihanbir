#include "Image.h"

const char* Image::images[3] = {"img/main.bmp", "img/openTheDoor.bmp", "img/GJ.bmp"};

enum class GameState { DoorClosed, DoorOpen, GameOver };

Image::Image() : success{} 
{
	imageSurface = SDL_LoadBMP(images[0]);
	if (!imageSurface)
	{
		printf("Unable to load image %s! SDL Error: %s\n", images[0], SDL_GetError());
		return;
	}
	success = true;
}

Image::Image(const char* path) : success{}
{
	//Load splash image
	imageSurface = SDL_LoadBMP(path);
	if (!imageSurface)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
		return;
	}
	success = true;
}

unique_ptr<Image> Image::SetImage(Door& door) {

	if (door.isClicked()) {
		if (door.isOpen) {
			return make_unique<Image>(images[(int)GameState::GameOver]);
		}
		else {
			door.isOpen = true;
			return make_unique<Image>(images[(int)GameState::DoorOpen]);
		}
	}
	else {
		door.isOpen = false;
		return make_unique<Image>(images[(int)GameState::DoorClosed]);
	}
}

Image::~Image() {
	SDL_FreeSurface(imageSurface);
	imageSurface = nullptr;
}