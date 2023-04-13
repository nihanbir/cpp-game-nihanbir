//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Image.h"
#include "Door.h"

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 419;

//Button constants
const int DOOR_WIDTH = 88;
const int DOOR_HEIGHT = 335;

int main(int argc, char* args[])
{
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT };
	//Start up SDL and create window
	if (!window.wasSuccesful())
	{
		printf("Failed to initialize!\n");
		return -1;
	}

	Door door{DOOR_WIDTH,DOOR_HEIGHT};
	
	//Load media
	auto image = make_unique<Image>();
	
	//Hack to get window to stay up
	SDL_Event e;
	while (true) {
		if (SDL_PollEvent(&e)) {
			switch (e.type) {

				case SDL_QUIT: {
					return 0;
				} break;
				case SDL_MOUSEBUTTONDOWN: {
					image = image->SetImage(door);
				} break;
			}
		}
		window.render(image.get());
	}
	return 0;
}