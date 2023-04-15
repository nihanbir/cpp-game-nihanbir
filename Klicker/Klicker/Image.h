#pragma once
#include <cstdio>
#include <SDL.h>
#include <string>

using namespace std;

class Image
{
	//The image we will load and show on the screen
	SDL_Surface* imageSurface{};
	bool success;
public:
	Image(string path);
	~Image();
	bool wasSuccesful() { return success; }
	SDL_Surface* getResource() {return imageSurface; }
};