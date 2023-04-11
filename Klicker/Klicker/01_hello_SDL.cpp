/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Image.h"
#include <map>
#include <memory>

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Key press surfaces constants

std::map <SDL_KeyCode, const char*> surfaceMap = {
	{SDLK_UP, "img/up.bmp"},
	{SDLK_DOWN, "img/down.bmp"},
	{SDLK_LEFT, "img/left.bmp"},
	{SDLK_RIGHT, "img/right.bmp"},
};
const char* fallbackSurface{ "img/press.bmp" };

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
	auto image = make_unique<Image>( fallbackSurface );
	
	//Hack to get window to stay up
	SDL_Event e; 
	while (true) { 
		if (SDL_PollEvent(&e)) {
			switch (e.type) {

				case SDL_QUIT: {
					return 0;
				} break;
				case SDL_KEYDOWN: {
					if (auto result = surfaceMap.find((SDL_KeyCode)e.key.keysym.sym); result != surfaceMap.end()) {
						auto value = *result;
						auto imageName = value.second;
						image = make_unique<Image>( imageName );
						if (!image->wasSuccesful())
						{
							printf("Failed to load media!\n");
							return -1;
						}
					}
					else {
						image = make_unique<Image>( fallbackSurface );
						if (!image->wasSuccesful())
						{
							printf("Failed to load media!\n");
							return -1;
						}

					}
				} break;
			}
		}
		window.render(image.get());
	}
	return 0;
}
