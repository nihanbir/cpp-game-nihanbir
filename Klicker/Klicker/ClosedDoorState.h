#pragma once
#include "DoorState.h"

class ClosedDoorState : public DoorState {
public:
	ClosedDoorState(Door& door);
	unique_ptr<DoorState> update(const SDL_Event& e, Door& door, Window& window) override;
};