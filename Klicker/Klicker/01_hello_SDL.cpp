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
const int SCREEN_HEIGHT = 419;

//Button constants
const int BUTTON_WIDTH = 88;
const int BUTTON_HEIGHT = 335;

//The mouse button
class LButton
{
public:
	//Initializes internal variables
	LButton();

	//Sets bottom left position
	void setPosition(int x, int y);

	//Checks if the click landed on the button
	bool isClicked();

private:
	//Button position
	SDL_Point mPosition;
};

LButton::LButton()
{
	mPosition.x = 14;
	mPosition.y = 84;
}

void LButton::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}

bool LButton::isClicked()
{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);
		//Mouse is left of the button
		if (x < mPosition.x)
		{
			return false;
		}
		//Mouse is right of the button
		else if (x > mPosition.x + BUTTON_WIDTH)
		{
			return false;
		}
		//Mouse above the button
		else if (y < mPosition.y)
		{
			return false;
		}
		//Mouse below the button
		else if (y > mPosition.y + BUTTON_HEIGHT)
		{
			return false;
		}
		return true;
}

LButton gButtons{};


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
	
	//Hack to get window to stay up
	SDL_Event e;
	while (true) {
		if (SDL_PollEvent(&e)) {
			switch (e.type) {

				case SDL_QUIT: {
					return 0;
				} break;
				case SDL_MOUSEBUTTONDOWN: {
					if (gButtons.isClicked()) {
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
