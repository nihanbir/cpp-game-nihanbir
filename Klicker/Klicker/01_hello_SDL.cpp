#include "Window.h"
#include "Image.h"
#include "Door.h"
#include <vector>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 419;

SDL_Rect leftDoorRect{14,84,88,335};
SDL_Rect rightDoorRect{240,177,24,92};

vector<Door*> doors{};

int main(int argc, char* args[])
{
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT };
	//Start up SDL and create window
	if (!window.wasSuccesful())
	{
		printf("Failed to initialize!\n");
		return -1;
	}

	Door leftDoor{ leftDoorRect, "img/DoorL_Closed.bmp", "img/DoorL_Open.bmp" };
	Door rightDoor{ rightDoorRect, "img/DoorR_Closed.bmp", "img/DoorR_Open.bmp" };

	doors.push_back(&leftDoor);
	doors.push_back(&rightDoor);

	//Load media
	auto image = make_unique<Image>("img/main.bmp");
	
	window.render(image.get(),nullptr);

	//Hack to get window to stay up
	SDL_Event e;
	while (!gameOver) {
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) return 0;
			for (Door* door : doors)
			{
				door->update(e, *door, window);
			}
		}
	}
	return 0;
}