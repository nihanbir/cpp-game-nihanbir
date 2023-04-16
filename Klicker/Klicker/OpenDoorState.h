#pragma once
#include "DoorState.h"

class OpenDoorState : public DoorState {
public:
	OpenDoorState(Door& door);
	unique_ptr<DoorState> update(const SDL_Event& e, Door& door, Window& window) override;
};

