#pragma once
#include "Image.h"
class Window
{
	//The window we'll be rendering to
	SDL_Window* gWindow{};

	//The surface contained by the window
	SDL_Surface* gScreenSurface{};

	bool success;
	//Starts up SDL and creates window
	bool init(int witdh, int height);


public:
	Window(int width, int height) {
		success = init(width, height);
	}
	~Window();

	bool wasSuccesful() { return success; }

	void render(Image& image);
};