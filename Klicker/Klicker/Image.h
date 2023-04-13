#pragma once
#include "Door.h"
#include <SDL.h>
#include <cstdio>
#include <memory>

using namespace std;

class Image
{
	//The image we will load and show on the screen
	SDL_Surface* imageSurface{};
	bool success;
public:
	static const char* images[3];

	Image();
	Image(const char* path);
	~Image();
	bool wasSuccesful() { return success; }
	unique_ptr<Image> SetImage(Door& door);
	SDL_Surface* getResource() {return imageSurface; }
};

