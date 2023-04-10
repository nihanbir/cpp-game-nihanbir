/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Image.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT };
	//Start up SDL and create window
	if (!window.wasSuccesful())
	{
		printf("Failed to initialize!\n");
		return -1;
	}

	//Load media
	Image image{ "02_getting_an_image_on_the_screen/hello_world.bmp" };
	if (!image.wasSuccesful())
	{
		printf("Failed to load media!\n");
		return -1;
	}
	window.render(image);

	//Hack to get window to stay up
	SDL_Event e; 
	while (true) { 
		if (SDL_PollEvent(&e) && e.type == SDL_QUIT) break;
	}
	return 0;
}