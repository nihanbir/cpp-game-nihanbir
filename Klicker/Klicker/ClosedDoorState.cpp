#include "Door.h"
#include "ClosedDoorState.h"
#include "OpenDoorState.h"

ClosedDoorState::ClosedDoorState(Door& door) {
	image = make_unique<Image>(door.images[1]);
}

unique_ptr<DoorState> ClosedDoorState::update(const SDL_Event& e, Door& door, Window& window) {
	if (e.type != SDL_MOUSEBUTTONDOWN) return nullptr;
	if (!door.isHovered()) return nullptr;
	// show image
	window.render(image.get(), &door.rect);
	return make_unique<OpenDoorState>(door);
}