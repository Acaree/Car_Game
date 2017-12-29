#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define ACCELERATION 2500.0f
#define TURN_DEGREES 7.0f * DEGTORAD
#define BRAKE_POWER 2500.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

public:

	PhysVehicle3D* vehicle;
	mat4x4 matrix;
	float turn;
	float acceleration;
	float brake;
	bool bababooey = false;
};