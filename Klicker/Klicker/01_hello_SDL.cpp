/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Image.h"
#include <map>
#include <memory>
#include "LButton.h"

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 419;

//Button constants
const int BUTTON_WIDTH = 88;
const int BUTTON_HEIGHT = 335;

map <SDL_EventType, const char*> surfaceMap = {
	{SDL_MOUSEBUTTONDOWN, "img/openTheDoor.bmp"},
};
const char* fallbackSurface{ "img/main.bmp" };

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
	
	LButton button{};
	
	//Hack to get window to stay up
	SDL_Event e;
	while (true) {
		if (SDL_PollEvent(&e)) {
			switch (e.type) {

				case SDL_QUIT: {
					return 0;
				} break;
				case SDL_MOUSEBUTTONDOWN: {
					if (button.isClicked(BUTTON_WIDTH, BUTTON_HEIGHT)) {
						if (auto result = surfaceMap.find((SDL_EventType)e.button.type); result != surfaceMap.end()) {
							auto value = *result;
							auto imageName = value.second;
							image = make_unique<Image>(imageName);
							if (!image->wasSuccesful())
							{
								printf("Failed to load media!\n");
								return -1;
							}
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
