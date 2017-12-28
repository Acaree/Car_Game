#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"
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
	Cube stat, cub;
	PhysBody3D* statt, *cubb;

	Cone cin;
	PhysBody3D *cinn;

	Cylinder stat2;
	PhysBody3D *statt2;

	// Walls
	p2List<Cube*> wall;
	Cube wall1;

	p2List<PhysBody3D*> wall_body;
	PhysBody3D *wall_1;

	// Road
	p2List<Cube*> road;
	Cube road1;

	p2List<PhysBody3D*> road_body;
	PhysBody3D *road_1;

	
};
