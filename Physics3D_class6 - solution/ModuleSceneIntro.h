#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:
	Cube s;
	PhysBody3D* sensor;

	// Walls
	Cube wall1, wall2, wall3, wall4, wall5, wall6, wall7, wall8;
	PhysBody3D *wall_1, *wall_2, *wall_3, *wall_4, *wall_5, *wall_6, *wall_7, *wall_8;

	// Road
	Cube road1, road2, road3;
	PhysBody3D *road_1, *road_2, *road_3;
};
