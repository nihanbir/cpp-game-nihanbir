#include "Window.h"
#include "Image.h"
#include "Door.h"
#include <vector>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 419;

SDL_Rect leftDoorRect{14,84,88,335};
SDL_Rect rightDoorRect{240,177,24,92};

vector<unique_ptr<Door>> doors{};

int main(int argc, char* args[])
{
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT };
	//Start up SDL and create window
	if (!window.wasSuccesful())
	{
		printf("Failed to initialize!\n");
		return -1;
	}

	doors.push_back(make_unique<Door>(leftDoorRect, "img/DoorL_Closed.bmp", "img/DoorL_Open.bmp"));
	doors.push_back(make_unique<Door>(rightDoorRect, "img/DoorR_Closed.bmp", "img/DoorR_Open.bmp"));

	//Load media
	auto image = make_unique<Image>("img/main.bmp");
	
	window.render(image.get(),nullptr);

	//Hack to get window to stay up
	SDL_Event e;
	while (!gameOver) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) return 0;
			for (auto& door : doors)
			{
				door->handleInput(e, *door, window);
			}
		}
	}
	return 0;
}