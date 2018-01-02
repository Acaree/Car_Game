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

	PhysBody3D* CreateCubePhysbody(Cube* cube, bool isSensor, Module* Callback);
	//PhysBody3D* CreateHelixPhysbody(Cube* cube);
	Cube* CreateCube(vec3 size, vec3 pos, Color color, float angle, vec3 pivot);
	PhysBody3D* CreateConePhysbody(Cone* cube, Module* Callback);
	Cone* CreateCone(float h, vec3 pos, float r);
	PhysBody3D* CreateSphePhysbody(Sphere* sphe, Module* Callback);
	Sphere* CreateSphe(vec3 pos);
	PhysBody3D* CreateCheckPoint(Cube &cube, vec3 size, vec3 pos, bool isSensor, Module* Callback);
	PhysBody3D* CreateHelix(Cube &cube, vec3 pos, float angle);
	PhysBody3D* CreateMotor(Cylinder &cylinder, vec3 pos, float angle);

public:
	//Constraits
	Cube helix1, helix2, helix3, helix4, helix5, helix6, helix7, helix8, helix9;
	PhysBody3D *helix_1, *helix_2, *helix_3, *helix_4, *helix_5, *helix_6, *helix_7, *helix_8, *helix_9;

	Cylinder motor1, motor2, motor3, motor4, motor5, motor6, motor7, motor8, motor9;
	PhysBody3D *motor_1, *motor_2, *motor_3, *motor_4, *motor_5, *motor_6, *motor_7, *motor_8, *motor_9;

	//Cones
	p2List<Cone*> cone;
	Cone cone1;

	p2List<PhysBody3D*> cone_body;
	PhysBody3D *cone_1;

	//Spheres
	p2List<Sphere*> sphere;
	Sphere sphere1;

	p2List<PhysBody3D*> sphere_body;
	PhysBody3D *sphere_1;

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

	//Check points
	p2List<Cube*> check;
	Cube check1, check2, check3, check4, check5, check6, check7;

	p2List<PhysBody3D*> check_body;
	PhysBody3D *check_1, *check_2, *check_3, *check_4, *check_5, *check_6, *check_7;

	uint checkpoint = 0;
	bool halfLap = false;
	bool finalLap = false;
	uint laps = 1;

	uint checkp, fl;

	//// Helix
	//p2List<Cube*> helix;
	//Cube helix1;

	//p2List<PhysBody3D*> helix_body;
	//PhysBody3D *helix_1;

	Timer lap_timer;
};
