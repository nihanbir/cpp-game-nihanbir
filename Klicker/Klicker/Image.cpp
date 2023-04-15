#include "Image.h"

Image::Image(string path) : success{}
{
	//Load splash image
	imageSurface = SDL_LoadBMP(path.c_str());
	if (!imageSurface)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		return;
	}
	success = true;
}

Image::~Image() {
	SDL_FreeSurface(imageSurface);
	imageSurface = nullptr;
}