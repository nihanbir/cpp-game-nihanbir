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

bool doorIsOpen{};

const char* images[]{ "img/main.bmp", "img/openTheDoor.bmp", "img/GJ.bmp" };

enum class GameState { DoorClosed, DoorOpen, GameOver };

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
	auto image = make_unique<Image>(images[(int)GameState::DoorClosed]);
	
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
						if (doorIsOpen) {					
							image = make_unique<Image>(images[(int)GameState::GameOver]);
							if (!image->wasSuccesful())
							{
								printf("Failed to load media!\n");
								return -1;
							}
						}
						else { 
							image = make_unique<Image>(images[(int)GameState::DoorOpen]);
							doorIsOpen = true;
							if (!image->wasSuccesful())
							{
								printf("Failed to load media!\n");
								return -1;
							}
						}
					}
					else {
						image = make_unique<Image>(images[(int)GameState::DoorClosed]);
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