/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow{};

//The surface contained by the window
SDL_Surface* gScreenSurface{};

//The image we will load and show on the screen
SDL_Surface* gHelloWorld{};

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
		return -1;
	}

	//Load media
	if (!loadMedia())
	{
		printf("Failed to load media!\n");
		return -1;
	}
	//Apply the image
	SDL_BlitSurface(gHelloWorld, nullptr, gScreenSurface, nullptr);
	//Update the surface
	SDL_UpdateWindowSurface(gWindow);
	//Hack to get window to stay up
	SDL_Event e; 
	while (true) { 
		if (SDL_PollEvent(&e) && e.type == SDL_QUIT) break;
	}
	//Free resources and close SDL
	close();
	return 0;
}

bool init()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	//Create window
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!gWindow)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	//Get window surface
	gScreenSurface = SDL_GetWindowSurface(gWindow);
	return true;
}

bool loadMedia()
{
	//Load splash image
	gHelloWorld = SDL_LoadBMP("02_getting_an_image_on_the_screen/hello_world.bmp");
	if (!gHelloWorld)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
		return false;
	}
	return true;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = nullptr;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}
