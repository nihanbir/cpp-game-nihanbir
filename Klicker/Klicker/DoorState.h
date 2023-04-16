#pragma once
#include <memory>
extern class Door;
extern union SDL_Event;
extern class Window;
extern class Image;

using namespace std;

class DoorState {
public:
	Door* door;

	unique_ptr<Image> image;

	virtual unique_ptr<DoorState> update(const SDL_Event& e, Door& door, Window& window) = 0;
};