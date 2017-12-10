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
	Cube wall1, wall2, wall3, wall4, wall5, wall6, wall7, wall8, wall9, wall10, wall11, wall12, wall13, wall14, wall15, wall16, wall17, wall18;
	PhysBody3D *wall_1, *wall_2, *wall_3, *wall_4, *wall_5, *wall_6, *wall_7, *wall_8, *wall_9, *wall_10, *wall_11, *wall_12, *wall_13, *wall_14,
		*wall_15, *wall_16, *wall_17, *wall_18;

	// Road
	Cube road1, road2, road3, road4, road5, road6, road7, road8, road9;
	PhysBody3D *road_1, *road_2, *road_3, *road_4, *road_5, *road_6, *road_7, *road_8, *road_9;
};
