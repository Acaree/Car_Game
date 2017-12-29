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

	App->audio->PlayMusic("Audio/Music.ogg", 0);

	pugi::xml_document track_file;
	pugi::xml_parse_result result = track_file.load_file("track.xml");
	pugi::xml_node wall_node = track_file.child("track").child("walls").child("wall");
	pugi::xml_node road_node = track_file.child("track").child("roads").child("road");
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

	check_1 = CreateCheckPoint(check1, vec3(12, 0.5, 0.1), vec3(      0,  1,    0),  0, vec3(0,1,0), true, this);
	check_2 = CreateCheckPoint(check2, vec3(12, 0.5, 0.1), vec3(    -73,4.2,247.9),  0, vec3(0,1,0), true, this);
	check_3 = CreateCheckPoint(check3, vec3(17, 0.5, 0.1), vec3(     30, 11,415.2),  0, vec3(0,1,0), true, this);
	check_4 = CreateCheckPoint(check4, vec3( 9, 0.5, 0.1), vec3(    129, 11,  253), 40, vec3(0,1,0), true, this);
	check_5 = CreateCheckPoint(check5, vec3(10, 0.5, 0.1), vec3(-122.25, 11, 73.3),  0, vec3(0,1,0), true, this);
	check_6 = CreateCheckPoint(check6, vec3(11, 0.5, 0.1), vec3(  -76.5,  4,   77),  0, vec3(0,1,0), true, this);
	check_7 = CreateCheckPoint(check7, vec3(12, 0.5, 0.1), vec3(   -186,  1,  -47),-10, vec3(0,1,0), true, this);

	cin.height = 5;
	cin.SetPos(87.5, 12.482, 347.15);
	cin.radius = 2;
	cin.color = Grey;
	cin.SetRotation(90, vec3(0, 0, 1));
	cinn = App->physics->AddBody(cin, 0.0f);
	cinn->collision_listeners.add(this);

	//First
	helix1.size = vec3(0.25, 12, 1);
	helix1.SetPos(-76.5, 7.245, 55);
	helix1.SetRotation(90, vec3(0, 1, 0));
	helix1.color = Orange;
	helix_1 = App->physics->AddBody(helix1, 10000.0f);
	helix_1->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	motor1.height = 2;
	motor1.SetPos(-76.5, 7.245, 57);
	motor1.radius = 0.1f;
	motor1.SetRotation(90, vec3(0, 1, 0));
	motor_1 = App->physics->AddBody(motor1, 10000.0f);
	motor_1->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	helix2.size = vec3(0.25, 12, 1);
	helix2.SetPos(-76.5, 7.245, 25);
	helix2.SetRotation(90, vec3(0, 1, 0));
	helix2.color = Orange;
	helix_2 = App->physics->AddBody(helix2, 10000.0f);
	helix_2->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	motor2.height = 2;
	motor2.SetPos(-76.5, 7.245, 27);
	motor2.radius = 0.1f;
	motor2.SetRotation(90, vec3(0, 1, 0));
	motor_2 = App->physics->AddBody(motor2, 10000.0f);
	motor_2->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	helix3.size = vec3(0.25, 12, 1);
	helix3.SetPos(-76.5, 7.245, -5);
	helix3.SetRotation(90, vec3(0, 1, 0));
	helix3.color = Orange;
	helix_3 = App->physics->AddBody(helix3, 10000.0f);
	helix_3->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	motor3.height = 2;
	motor3.SetPos(-76.5, 7.245, -3);
	motor3.radius = 0.1f;
	motor3.SetRotation(90, vec3(0, 1, 0));
	motor_3 = App->physics->AddBody(motor3, 10000.0f);
	motor_3->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	helix4.size = vec3(0.25, 12, 1);
	helix4.SetPos(-76.5, 7.245, -35);
	helix4.SetRotation(90, vec3(0, 1, 0));
	helix4.color = Orange;
	helix_4 = App->physics->AddBody(helix4, 10000.0f);
	helix_4->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	motor4.height = 2;
	motor4.SetPos(-76.5, 7.245, -33);
	motor4.radius = 0.1f;
	motor4.SetRotation(90, vec3(0, 1, 0));
	motor_4 = App->physics->AddBody(motor4, 10000.0f);
	motor_4->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	helix5.size = vec3(0.25, 12, 1);
	helix5.SetPos(-76.5, 7.245, -60);
	helix5.SetRotation(90, vec3(0, 1, 0));
	helix5.color = Orange;
	helix_5 = App->physics->AddBody(helix5, 10000.0f);
	helix_5->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	motor5.height = 2;
	motor5.SetPos(-76.5, 7.245, -60);
	motor5.radius = 0.1f;
	motor5.SetRotation(90, vec3(0, 1, 0));
	motor_5 = App->physics->AddBody(motor5, 10000.0f);
	motor_5->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	//Second
	helix6.size = vec3(0.25, 12, 1);
	helix6.SetPos(-132, 4, -129.5);
	helix6.SetRotation(0, vec3(0, 1, 0));
	helix6.color = Orange;
	helix_6 = App->physics->AddBody(helix6, 10000.0f);
	helix_6->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	motor6.height = 2;
	motor6.SetPos(-130, 4, -129.5);
	motor6.radius = 0.1f;
	motor6.SetRotation(90, vec3(1, 0, 0));
	motor_6 = App->physics->AddBody(motor6, 10000.0f);
	motor_6->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	helix7.size = vec3(0.25, 12, 1);
	helix7.SetPos(-102, 4, -129.5);
	helix7.SetRotation(0, vec3(0, 1, 0));
	helix7.color = Orange;
	helix_7 = App->physics->AddBody(helix7, 10000.0f);
	helix_7->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	motor7.height = 2;
	motor7.SetPos(-100, 4, -129.5);
	motor7.radius = 0.1f;
	motor7.SetRotation(90, vec3(1, 0, 0));
	motor_7 = App->physics->AddBody(motor7, 10000.0f);
	motor_7->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	helix8.size = vec3(0.25, 12, 1);
	helix8.SetPos(-72, 4, -129.5);
	helix8.SetRotation(0, vec3(0, 1, 0));
	helix8.color = Orange;
	helix_8 = App->physics->AddBody(helix8, 10000.0f);
	helix_8->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	motor8.height = 2;
	motor8.SetPos(-70, 4, -129.5);
	motor8.radius = 0.1f;
	motor8.SetRotation(90, vec3(1, 0, 0));
	motor_8 = App->physics->AddBody(motor8, 10000.0f);
	motor_8->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	helix9.size = vec3(0.25, 12, 1);
	helix9.SetPos(-42, 4, -129.5);
	helix9.SetRotation(0, vec3(0, 1, 0));
	helix9.color = Orange;
	helix_9 = App->physics->AddBody(helix9, 10000.0f);
	helix_9->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	motor9.height = 2;
	motor9.SetPos(-40, 4, -129.5);
	motor9.radius = 0.1f;
	motor9.SetRotation(90, vec3(1, 0, 0));
	motor_9 = App->physics->AddBody(motor9, 10000.0f);
	motor_9->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	App->physics->AddConstraintHinge(*motor_1, *helix_1, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_2, *helix_2, vec3(0, 0, 0), vec3(0, 0, 0), vec3(-1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_3, *helix_3, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_4, *helix_4, vec3(0, 0, 0), vec3(0, 0, 0), vec3(-1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_5, *helix_5, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_6, *helix_6, vec3(0, 0, 0), vec3(0, 0, 0), vec3(-1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_7, *helix_7, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_8, *helix_8, vec3(0, 0, 0), vec3(0, 0, 0), vec3(-1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_9, *helix_9, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0), true, true);

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
	if (App->input->GetKey(SDL_SCANCODE_T) == KEY_DOWN) {
		lap_timer.Start();
	}

	if (App->input->GetKey(SDL_SCANCODE_P) == KEY_DOWN) {
		Uint32 lap_time=lap_timer.Read();
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

	cinn->GetTransform(&cin.transform);
	cin.Render();

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
		if (checkpoint == 6)
			laps++;
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

PhysBody3D* ModuleSceneIntro::CreateCubePhysbody(Cube* cube,bool isSensor, Module* Callback) {

	PhysBody3D* wall_pbody;
	wall_pbody = App->physics->AddBody(*cube, 0.0f);
	wall_pbody->SetAsSensor(isSensor);
	wall_pbody->collision_listeners.add(Callback);
	return wall_pbody;
}

//PhysBody3D* ModuleSceneIntro::CreateHelixPhysbody(Cube* cube) {
//
//	PhysBody3D* helix_pbody;
//	helix_pbody = App->physics->AddBody(*cube, 10000.0f);
//	helix_pbody->GetBody()->setLinearFactor(btVector3(0, 0, 0));
//	return helix_pbody;
//}

Cube* ModuleSceneIntro::CreateCube(vec3 size, vec3 pos, Color color, float angle, vec3 pivot) {
	Cube* cube= new Cube;
	cube->size = size;
	cube->SetPos(pos.x, pos.y, pos.z);
	cube->color = color;
	cube->SetRotation(angle, pivot);
	return cube;
}

PhysBody3D* ModuleSceneIntro::CreateCheckPoint(Cube &cube, vec3 size, vec3 pos, float angle, vec3 pivot, bool isSensor, Module* Callback) {

	PhysBody3D* wall_pbody;
	cube.size = size;
	cube.SetPos(pos.x, pos.y, pos.z);
	wall_pbody = App->physics->AddBody(cube, 0.0f);
	wall_pbody->SetAsSensor(isSensor);
	wall_pbody->collision_listeners.add(Callback);
	return wall_pbody;
}