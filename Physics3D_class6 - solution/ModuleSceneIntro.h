#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"
#include "Timer.h"
#include "PugiXml/src/pugiconfig.hpp"
#include "PugiXml/src/pugixml.hpp"

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

	PhysBody3D* CreateCubePhysbody(Cube* cube,bool isSensor, Module* Callback);
	Cube* CreateCube(vec3 size, vec3 pos, Color color, float angle, vec3 pivot);

public:
	Cube s;
	PhysBody3D* sensor;

	Cone cin;
	PhysBody3D *cinn;

	Timer lap_timer;

	// Walls
	p2List<Cube*> wall;
	p2List<PhysBody3D*> wall_body;
	

	// Road
	p2List<Cube*> road;
	Cube road1, road2, road3, road4, road5, road6, road7, road8, road9, road10, road11, road12, road13, road14, road15, road16, road17, road18,
		road19, road20, road21, road22, road23, road24, road25, road26, road27, road28, road29, road30, road31, road32, road33, road34, road35,
		road36, road37, road38, road39, road40, road41, road42, road43, road44, road45, road46, road47, road48, road49, road50, road51, road52,
		road53, road54, road55, road56, road57, road58, road59, road60, road61, road62, road63, road64, road65, road66;

	p2List<PhysBody3D*> road_body;
	PhysBody3D *road_1, *road_2, *road_3, *road_4, *road_5, *road_6, *road_7, *road_8, *road_9, *road_10, *road_11, *road_12, *road_13, *road_14,
		*road_15, *road_16, *road_17, *road_18, *road_19, *road_20, *road_21, *road_22, *road_23, *road_24, *road_25, *road_26, *road_27, *road_28,
		*road_29, *road_30, *road_31, *road_32, *road_33, *road_34, *road_35, *road_36, *road_37, *road_38, *road_39, *road_40, *road_41, *road_42,
		*road_43, *road_44, *road_45, *road_46, *road_47, *road_48, *road_49, *road_50, *road_51, *road_52, *road_53, *road_54, *road_55, *road_56,
		*road_57, *road_58, *road_59, *road_60, *road_61, *road_62, *road_63, *road_64, *road_65, *road_66;

	
};
