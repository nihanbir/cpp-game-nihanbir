#include "Door.h"
#include "OpenDoorState.h"
#include "ClosedDoorState.h"

OpenDoorState::OpenDoorState(Door& door) {
	image = make_unique<Image>(door.images[0]);
}
unique_ptr<DoorState> OpenDoorState::update(const SDL_Event& e, Door& door, Window& window) {
	if (e.type != SDL_MOUSEBUTTONDOWN) return nullptr;
	if (!door.isHovered()) return nullptr;
	if (e.button.button == SDL_BUTTON_LEFT) {
		// show image
		window.render(image.get(), &door.rect);
		return make_unique<ClosedDoorState>(door);
	}
	if (e.button.button == SDL_BUTTON_RIGHT) {
		gameOver = true;
		return nullptr;
	}
	return nullptr;
}
