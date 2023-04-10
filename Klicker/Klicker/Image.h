#pragma once
#include <SDL.h>
class Image
{
	//The image we will load and show on the screen
	SDL_Surface* gHelloWorld{};

	//Loads media
	bool loadMedia(const char* path);

	bool success;
public:
	Image(const char* path) {
		success	= loadMedia(path);
	}
	~Image();
	bool wasSuccesful() { return success; }
	SDL_Surface* getResource() {return gHelloWorld; }
};

