#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "PhysVehicle3D.h"


ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->audio->PlayMusic("Audio/Music.ogg",0);

	pugi::xml_document track_file;
	pugi::xml_parse_result result = track_file.load_file("track.xml");
	pugi::xml_node wall_node = track_file.child("track").child("walls").child("wall");
	pugi::xml_node road_node = track_file.child("track").child("roads").child("road");
	pugi::xml_node cone_node = track_file.child("track").child("cones").child("cone");
	//pugi::xml_node check_node = track_file.child("track").child("checks").child("check");
	//pugi::xml_node helix_node = track_file.child("track").child("helixs").child("helix");

	while (wall_node != nullptr) {
		Cube* cube = CreateCube(vec3(wall_node.attribute("x").as_float(), wall_node.attribute("y").as_float(), wall_node.attribute("z").as_float()), vec3(wall_node.attribute("posx").as_float(), wall_node.attribute("posy").as_float(), wall_node.attribute("posz").as_float()), Color(wall_node.attribute("r").as_float(), wall_node.attribute("g").as_float(), wall_node.attribute("b").as_float()), wall_node.attribute("angle").as_float(), vec3(wall_node.attribute("rotx").as_float(), wall_node.attribute("roty").as_float(), wall_node.attribute("rotz").as_float()));
		wall_body.add(CreateCubePhysbody(cube, wall_node.attribute("bool").as_bool(), this));
		wall.add(cube);
		wall_node = wall_node.next_sibling();
	}

	while (road_node != nullptr) {
		Cube* cube = CreateCube(vec3(road_node.attribute("x").as_float(), road_node.attribute("y").as_float(), road_node.attribute("z").as_float()), vec3(road_node.attribute("posx").as_float(), road_node.attribute("posy").as_float(), road_node.attribute("posz").as_float()), Color(road_node.attribute("r").as_float(), road_node.attribute("g").as_float(), road_node.attribute("b").as_float()), road_node.attribute("angle").as_float(), vec3(road_node.attribute("rotx").as_float(), road_node.attribute("roty").as_float(), road_node.attribute("rotz").as_float()));
		road_body.add(CreateCubePhysbody(cube, road_node.attribute("bool").as_bool(), this));
		road.add(cube);
		road_node = road_node.next_sibling();
	}

	while (cone_node != nullptr) {
		Cone* coni = CreateCone(vec3(cone_node.attribute("posx").as_float(), cone_node.attribute("posy").as_float(), cone_node.attribute("posz").as_float()));
		cone_body.add(CreateConePhysbody(coni, this));
		cone.add(coni);
		cone_node = cone_node.next_sibling();
	}

	//while (check_node != nullptr) {
	//	Cube* cube = CreateCube(vec3(check_node.attribute("x").as_float(), check_node.attribute("y").as_float(), check_node.attribute("z").as_float()), vec3(check_node.attribute("posx").as_float(), check_node.attribute("posy").as_float(), check_node.attribute("posz").as_float()), Color(check_node.attribute("r").as_float(), check_node.attribute("g").as_float(), check_node.attribute("b").as_float()), check_node.attribute("angle").as_float(), vec3(check_node.attribute("rotx").as_float(), check_node.attribute("roty").as_float(), check_node.attribute("rotz").as_float()));
	//	check_body.add(CreateCubePhysbody(cube, check_node.attribute("bool").as_bool(), this));
	//	check.add(cube);
	//	check_node = check_node.next_sibling();
	//}

	//while (helix_node != nullptr) {
	//	Cube* cube = CreateCube(vec3(helix_node.attribute("x").as_float(), helix_node.attribute("y").as_float(), helix_node.attribute("z").as_float()), vec3(helix_node.attribute("posx").as_float(), helix_node.attribute("posy").as_float(), helix_node.attribute("posz").as_float()), Color(helix_node.attribute("r").as_float(), helix_node.attribute("g").as_float(), helix_node.attribute("b").as_float()), helix_node.attribute("angle").as_float(), vec3(helix_node.attribute("rotx").as_float(), helix_node.attribute("roty").as_float(), helix_node.attribute("rotz").as_float()));
	//	helix_body.add(CreateHelixPhysbody(cube));
	//	helix.add(cube);
	//	helix_node = helix_node.next_sibling();
	//}

	check_1 = CreateCheckPoint(check1, vec3(12, 0.5, 0.1), vec3(      0,   1,     0), true, this);
	check_2 = CreateCheckPoint(check2, vec3(12, 0.5, 0.1), vec3(    -73, 4.2, 247.9), true, this);
	check_3 = CreateCheckPoint(check3, vec3(17, 0.5, 0.1), vec3(     30,  11, 415.2), true, this);
	check_4 = CreateCheckPoint(check4, vec3( 9, 0.5, 0.1), vec3(    129,  11,   253), true, this);
	check_5 = CreateCheckPoint(check5, vec3(10, 0.5, 0.1), vec3(-122.25,  11,  73.3), true, this);
	check_6 = CreateCheckPoint(check6, vec3(11, 0.5, 0.1), vec3(  -76.5,   4,    77), true, this);
	check_7 = CreateCheckPoint(check7, vec3(12, 0.5, 0.1), vec3(   -186,   1,   -47), true, this);

	helix_1 = CreateHelix(helix1, vec3(-76.5, 7.245,     55), 90);
	helix_2 = CreateHelix(helix2, vec3(-76.5, 7.245,     25), 90);
	helix_3 = CreateHelix(helix3, vec3(-76.5, 7.245,     -5), 90);
	helix_4 = CreateHelix(helix4, vec3(-76.5, 7.245,    -35), 90);
	helix_5 = CreateHelix(helix5, vec3(-76.5, 7.245,    -60), 90);
	helix_6 = CreateHelix(helix6, vec3( -132,     4, -129.5),  0);
	helix_7 = CreateHelix(helix7, vec3( -102,     4, -129.5),  0);
	helix_8 = CreateHelix(helix8, vec3(  -72,     4, -129.5),  0);
	helix_9 = CreateHelix(helix9, vec3(  -42,     4, -129.5),  0);

	motor_1 = CreateMotor(motor1, vec3(-76.5, 7.245,    57), 90);
	motor_2 = CreateMotor(motor2, vec3(-76.5, 7.245,    27), 90);
	motor_3 = CreateMotor(motor3, vec3(-76.5, 7.245,    -3), 90);
	motor_4 = CreateMotor(motor4, vec3(-76.5, 7.245,   -33), 90);
	motor_5 = CreateMotor(motor5, vec3(-76.5, 7.245,   -60), 90);
	motor_6 = CreateMotor(motor6, vec3( -132,     4, -129.5), 0);
	motor_7 = CreateMotor(motor7, vec3( -102,     4, -129.5), 0);
	motor_8 = CreateMotor(motor8, vec3(  -72,     4, -129.5), 0);
	motor_9 = CreateMotor(motor9, vec3(  -42,     4, -129.5), 0);

	App->physics->AddConstraintHinge(*motor_1, *helix_1, vec3(0, 0, 0), vec3(0, 0, 0), vec3( 1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_2, *helix_2, vec3(0, 0, 0), vec3(0, 0, 0), vec3(-1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_3, *helix_3, vec3(0, 0, 0), vec3(0, 0, 0), vec3( 1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_4, *helix_4, vec3(0, 0, 0), vec3(0, 0, 0), vec3(-1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_5, *helix_5, vec3(0, 0, 0), vec3(0, 0, 0), vec3( 1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_6, *helix_6, vec3(0, 0, 0), vec3(0, 0, 0), vec3(-1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_7, *helix_7, vec3(0, 0, 0), vec3(0, 0, 0), vec3( 1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_8, *helix_8, vec3(0, 0, 0), vec3(0, 0, 0), vec3(-1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_9, *helix_9, vec3(0, 0, 0), vec3(0, 0, 0), vec3( 1, 0, 0), vec3(0, 0, 0), true, true);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	if (laps == 3) {
		if (finalLap == false)
		App->audio->PlayMusic("Audio/MusicF.ogg", 0);
		finalLap = true;
	}


	if (App->input->GetKey(SDL_SCANCODE_T) == KEY_DOWN) {
		lap_timer.Start();
	}

	p2List_item <PhysBody3D*>* wall_render_body = wall_body.getFirst();
	p2List_item <Cube*>* wall_render = wall.getFirst();
	while (wall_render != nullptr) {
		wall_render_body->data->GetTransform(&wall_render->data->transform);
		wall_render->data->Render();
		wall_render = wall_render->next;
		wall_render_body = wall_render_body->next;
	}

	p2List_item <PhysBody3D*>* road_render_body = road_body.getFirst();
	p2List_item <Cube*>* road_render = road.getFirst();
	while (road_render != nullptr) {
		road_render_body->data->GetTransform(&road_render->data->transform);
		road_render->data->Render();
		road_render = road_render->next;
		road_render_body = road_render_body->next;
	}

	p2List_item <PhysBody3D*>* cone_render_body = cone_body.getFirst();
	p2List_item <Cone*>* cone_render = cone.getFirst();
	while (cone_render != nullptr) {
		cone_render_body->data->GetTransform(&cone_render->data->transform);
		cone_render->data->Render();
		cone_render = cone_render->next;
		cone_render_body = cone_render_body->next;
	}

	helix_1->GetTransform(&helix1.transform);
	helix1.Render();
	helix_2->GetTransform(&helix2.transform);
	helix2.Render();
	helix_3->GetTransform(&helix3.transform);
	helix3.Render();
	helix_4->GetTransform(&helix4.transform);
	helix4.Render();
	helix_5->GetTransform(&helix5.transform);
	helix5.Render();
	helix_6->GetTransform(&helix6.transform);
	helix6.Render();
	helix_7->GetTransform(&helix7.transform);
	helix7.Render();
	helix_8->GetTransform(&helix8.transform);
	helix8.Render();
	helix_9->GetTransform(&helix9.transform);
	helix9.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("Hit!");
	if (body1 == check_1) {
		if (checkpoint == 6 && halfLap == true) {
			laps++;
			halfLap = false;
		}
		checkpoint = 0;
	}

	if (body1 == check_2) {
		checkpoint = 1;
	}

	if (body1 == check_3) {
		checkpoint = 2;
	}

	if (body1 == check_4) {
		checkpoint = 3;
		halfLap = true;
	}

	if (body1 == check_5) {
		checkpoint = 4;
	}

	if (body1 == check_6) {
		checkpoint = 5;
	}

	if (body1 == check_7) {
		checkpoint = 6;
	}
}

PhysBody3D* ModuleSceneIntro::CreateCubePhysbody(Cube* cube, bool isSensor, Module* Callback) {

	PhysBody3D* wall_pbody;
	wall_pbody = App->physics->AddBody(*cube, 0.0f);
	wall_pbody->SetAsSensor(isSensor);
	wall_pbody->collision_listeners.add(Callback);
	return wall_pbody;
}

Cube* ModuleSceneIntro::CreateCube(vec3 size, vec3 pos, Color color, float angle, vec3 pivot) {
	Cube* cube = new Cube;
	cube->size = size;
	cube->SetPos(pos.x, pos.y, pos.z);
	cube->color = color;
	cube->SetRotation(angle, pivot);
	return cube;
}

PhysBody3D* ModuleSceneIntro::CreateConePhysbody(Cone* cone, Module* Callback) {

	PhysBody3D* cone_pbody;
	cone_pbody = App->physics->AddBody(*cone, 0.0f);
	cone_pbody->collision_listeners.add(Callback);
	return cone_pbody;
}

Cone* ModuleSceneIntro::CreateCone(vec3 pos) {
	Cone* cone = new Cone;
	cone->height = 1;
	cone->SetPos(pos.x, pos.y, pos.z);
	cone->radius = 1;
	cone->color = White;
	cone->SetRotation(90, vec3(0, 0, 1));
	return cone;
}

PhysBody3D* ModuleSceneIntro::CreateCheckPoint(Cube &cube, vec3 size, vec3 pos, bool isSensor, Module* Callback) {

	PhysBody3D* wall_pbody;
	cube.size = size;
	cube.SetPos(pos.x, pos.y, pos.z);
	wall_pbody = App->physics->AddBody(cube, 0.0f);
	wall_pbody->SetAsSensor(isSensor);
	wall_pbody->collision_listeners.add(Callback);
	return wall_pbody;
}

PhysBody3D* ModuleSceneIntro::CreateHelix(Cube &cube, vec3 pos, float angle) {

	PhysBody3D* wall_pbody;
	cube.size = vec3(0.25, 12, 1);
	cube.SetPos(pos.x, pos.y, pos.z);
	cube.SetRotation(angle, vec3(0, 1, 0));
	cube.color = Orange;
	wall_pbody = App->physics->AddBody(cube, 10000.0f);
	wall_pbody->GetBody()->setLinearFactor(btVector3(0, 0, 0));
	return wall_pbody;
}

PhysBody3D* ModuleSceneIntro::CreateMotor(Cylinder &cylinder, vec3 pos, float angle) {

	PhysBody3D* wall_pbody;
	cylinder.height = 2;
	cylinder.radius = 0.1f;
	cylinder.SetPos(pos.x, pos.y, pos.z);
	cylinder.SetRotation(angle, vec3(0, 1, 0));
	wall_pbody = App->physics->AddBody(cylinder, 10000.0f);
	wall_pbody->GetBody()->setLinearFactor(btVector3(0, 0, 0));
	return wall_pbody;
}

//PhysBody3D* ModuleSceneIntro::CreateHelixPhysbody(Cube* cube) {
//
//	PhysBody3D* helix_pbody;
//	helix_pbody = App->physics->AddBody(*cube, 10000.0f);
//	helix_pbody->GetBody()->setLinearFactor(btVector3(0, 0, 0));
//	return helix_pbody;
//}