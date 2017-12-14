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

	PhysBody3D* CreateWall(Cube &cube, vec3 size, vec3 pos, Color color, float angle, vec3 pivot, bool isSensor, Module* Callback);

public:
	Cube s;
	PhysBody3D* sensor;

	// Walls
	Cube wall1, wall2, wall3, wall4, wall5, wall6, wall7, wall8, wall9, wall10, wall11, wall12, wall13, wall14, wall15, wall16, wall17, wall18,
		wall19, wall20, wall21, wall22, wall23, wall24, wall25, wall26, wall27, wall28, wall29, wall30, wall31, wall32, wall33, wall34, wall35,
		wall36, wall37, wall38, wall39, wall40, wall41, wall42, wall43, wall44, wall45, wall46, wall47, wall48, wall49, wall50;

	PhysBody3D *wall_1, *wall_2, *wall_3, *wall_4, *wall_5, *wall_6, *wall_7, *wall_8, *wall_9, *wall_10, *wall_11, *wall_12, *wall_13, *wall_14,
		*wall_15, *wall_16, *wall_17, *wall_18, *wall_19, *wall_20, *wall_21, *wall_22, *wall_23, *wall_24, *wall_25, *wall_26, *wall_27, *wall_28,
		*wall_29, *wall_30, *wall_31, *wall_32, *wall_33, *wall_34, *wall_35, *wall_36, *wall_37, *wall_38, *wall_39, *wall_40, *wall_41, *wall_42,
		*wall_43, *wall_44, *wall_45, *wall_46, *wall_47, *wall_48, *wall_49, *wall_50;

	// Road
	Cube road1, road2, road3, road4, road5, road6, road7, road8, road9, road10, road11, road12, road13, road14, road15, road16, road17, road18,
		road19, road20, road21, road22, road23, road24;

	PhysBody3D *road_1, *road_2, *road_3, *road_4, *road_5, *road_6, *road_7, *road_8, *road_9, *road_10, *road_11, *road_12, *road_13, *road_14,
		*road_15, *road_16, *road_17, *road_18, *road_19, *road_20, *road_21, *road_22, *road_23, *road_24;

	
};
