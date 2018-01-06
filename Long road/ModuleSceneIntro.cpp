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

	App->audio->PlayMusic("Audio/Music/Theme.ogg",0);
	checkp = App->audio->LoadFx("Audio/Fx/Check.wav");
	fl = App->audio->LoadFx("Audio/Fx/FinalLap.wav");

	pugi::xml_document track_file;
	pugi::xml_parse_result result = track_file.load_file("track.xml");
	pugi::xml_node wall_node = track_file.child("track").child("walls").child("wall");
	pugi::xml_node road_node = track_file.child("track").child("roads").child("road");
	pugi::xml_node cone_node = track_file.child("track").child("cones").child("cone");
	pugi::xml_node sphe_node = track_file.child("track").child("sphes").child("sphe");

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
		Cone* coni = CreateCone(cone_node.attribute("h").as_float(), vec3(cone_node.attribute("posx").as_float(), cone_node.attribute("posy").as_float(), cone_node.attribute("posz").as_float()), cone_node.attribute("r").as_float());
		cone_body.add(CreateConePhysbody(coni, this));
		cone.add(coni);
		cone_node = cone_node.next_sibling();
	}


	while (sphe_node != nullptr) {
		Sphere* sphi = CreateSphe(vec3(sphe_node.attribute("posx").as_float(), sphe_node.attribute("posy").as_float(), sphe_node.attribute("posz").as_float()), sphe_node.attribute("rad").as_float(), Color(sphe_node.attribute("r").as_float(), sphe_node.attribute("g").as_float(), sphe_node.attribute("b").as_float()));
		sphere_body.add(CreateSphePhysbody(sphi, this));
		sphere.add(sphi);
		sphe_node = sphe_node.next_sibling();
	}

	check_1 = CreateCheckPoint(check1, vec3(12, 0.5, 0.1), vec3(      0,   1,     0), true, this);
	check_2 = CreateCheckPoint(check2, vec3(12, 0.5, 0.1), vec3(    -73, 4.2, 247.9), true, this);
	check_3 = CreateCheckPoint(check3, vec3(17, 0.5, 0.1), vec3(     30,  11, 415.2), true, this);
	check_4 = CreateCheckPoint(check4, vec3( 9, 0.5, 0.1), vec3(    129,  11,   253), true, this);
	check_5 = CreateCheckPoint(check5, vec3(10, 0.5, 0.1), vec3(-122.25,  11,  73.3), true, this);
	check_6 = CreateCheckPoint(check6, vec3(11, 0.5, 0.1), vec3(  -76.5,   4,    77), true, this);
	check_7 = CreateCheckPoint(check7, vec3(12, 0.5, 0.1), vec3(   -186,   1,   -47), true, this);

	helix_1 = CreateHelix(helix1, vec3(0.25, 10.5, 1), vec3(-76.5, 7.245,     55), 90);
	helix_2 = CreateHelix(helix2, vec3(0.25, 10.5, 1), vec3(-76.5, 7.245,     25), 90);
	helix_3 = CreateHelix(helix3, vec3(0.25, 10.5, 1), vec3(-76.5, 7.245,     -5), 90);
	helix_4 = CreateHelix(helix4, vec3(0.25, 10.5, 1), vec3(-76.5, 7.245,    -35), 90);
	helix_5 = CreateHelix(helix5, vec3(0.25, 10.5, 1), vec3(-76.5, 7.245,    -60), 90);
	helix_6 = CreateHelix(helix6, vec3(0.25, 10.5, 1), vec3( -132,     4, -129.5),  0);
	helix_7 = CreateHelix(helix7, vec3(0.25, 10.5, 1), vec3( -102,     4, -129.5),  0);
	helix_8 = CreateHelix(helix8, vec3(0.25, 10.5, 1), vec3(  -72,     4, -129.5),  0);
	helix_9 = CreateHelix(helix9, vec3(0.25, 10.5, 1), vec3(  -42,     4, -129.5),  0);

	helix_10 = CreateHelix(helix10, vec3(0.25, 15.5, 1), vec3(100, 20, 93),90);
	helix_11 = CreateHelix(helix11, vec3(0.25, 1, 15.5), vec3(100, 20, 93),90);

	motor_1 = CreateMotor(motor1, vec3(-76.5, 7.245,    57), 90);
	motor_2 = CreateMotor(motor2, vec3(-76.5, 7.245,    27), 90);
	motor_3 = CreateMotor(motor3, vec3(-76.5, 7.245,    -3), 90);
	motor_4 = CreateMotor(motor4, vec3(-76.5, 7.245,   -33), 90);
	motor_5 = CreateMotor(motor5, vec3(-76.5, 7.245,   -60), 90);
	motor_6 = CreateMotor(motor6, vec3( -132,     4, -129.5), 0);
	motor_7 = CreateMotor(motor7, vec3( -102,     4, -129.5), 0);
	motor_8 = CreateMotor(motor8, vec3(  -72,     4, -129.5), 0);
	motor_9 = CreateMotor(motor9, vec3(  -42,     4, -129.5), 0);

	motor_10 = CreateMotor(motor10, vec3(100, 20, 105),270);
	motor_11 = CreateMotor(motor11, vec3(100, 20, 105),90);

	App->physics->AddConstraintHinge(*motor_1, *helix_1, vec3(0, 0, 0), vec3(0, 0, 0), vec3( 1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_2, *helix_2, vec3(0, 0, 0), vec3(0, 0, 0), vec3(-1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_3, *helix_3, vec3(0, 0, 0), vec3(0, 0, 0), vec3( 1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_4, *helix_4, vec3(0, 0, 0), vec3(0, 0, 0), vec3(-1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_5, *helix_5, vec3(0, 0, 0), vec3(0, 0, 0), vec3( 1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_6, *helix_6, vec3(0, 0, 0), vec3(0, 0, 0), vec3(-1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_7, *helix_7, vec3(0, 0, 0), vec3(0, 0, 0), vec3( 1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_8, *helix_8, vec3(0, 0, 0), vec3(0, 0, 0), vec3(-1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_9, *helix_9, vec3(0, 0, 0), vec3(0, 0, 0), vec3( 1, 0, 0), vec3(0, 0, 0), true, true);

	App->physics->AddConstraintHinge(*motor_10, *helix_10, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0), true, true);
	App->physics->AddConstraintHinge(*motor_11, *helix_11, vec3(0, 0, 0), vec3(0, 0, 0), vec3(-1, 0, 0), vec3(0, 0, 0), true, true);

	Windmill.height = 20;
	Windmill.radius = 7;
	Windmill.SetPos(100,10,100);
	Windmill.SetRotation(90, { 0,0,1 });
	Windmill.color = White;
	windmill = App->physics->AddBody(Windmill, 0);

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
		if (finalLap == false) {
			App->audio->PlayMusic("Audio/Music/ThemeF.ogg", 0);
		}
		finalLap = true;
	}

	if (laps <= 2) {
		if (finalLap == true)
			App->audio->PlayMusic("Audio/Music/Theme.ogg", 0);
		finalLap = false;
	}

	if (laps > 3 || lap_timer.Read()/1000 > 450) {
		App->player->vehicle->SetTransform(&App->player->matrix);
		App->player->vehicle->SetPos(0, 0, 0);
		App->camera->Move(0, 0, -10);
		App->player->brake = BRAKE_POWER * 10000;
		App->player->vehicle->Bababooey2();
		App->player->bababooey = false;
		App->player->game_paused = true;
		if (laps > 3) {
			if (lap_timer.Read() / 1000 < App->best_time) {
				App->Save_time(lap_timer.Read() / 1000);
				App->Load_time();
			}
			App->last_time = lap_timer.Read()/1000;
		}
		lap_timer.Start();
		lap_timer.Stop();
		laps = 1;
		char title[80];
		sprintf_s(title, "Time: %i Lap: %i/3 Last Time: %i Best Time: %i", App->scene_intro->lap_timer.Read() / 1000, App->scene_intro->laps, App->last_time, App->best_time);
		App->window->SetTitle(title);
	}

	if (App->input->GetKey(SDL_SCANCODE_M) == KEY_DOWN) {
		laps++;
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

	p2List_item <PhysBody3D*>* sphe_render_body = sphere_body.getFirst();
	p2List_item <Sphere*>* sphe_render = sphere.getFirst();
	while (sphe_render != nullptr) {
		sphe_render_body->data->GetTransform(&sphe_render->data->transform);
		sphe_render->data->Render();
		sphe_render = sphe_render->next;
		sphe_render_body = sphe_render_body->next;
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

	helix_10->GetTransform(&helix10.transform);
	helix10.Render();
	helix_11->GetTransform(&helix11.transform);
	helix11.Render();

	windmill->GetTransform(&Windmill.transform);
	Windmill.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("Hit!");
	if (body1 == check_1) {
		if (checkpoint == 6 && halfLap == true) {
			laps++;
			App->audio->PlayFx(fl);
			halfLap = false;
		}
		checkpoint = 0;
	}

	if (body1 == check_2) {
		App->audio->PlayFx(checkp);
		checkpoint = 1;
	}

	if (body1 == check_3) {
		App->audio->PlayFx(checkp);
		checkpoint = 2;
	}

	if (body1 == check_4) {
		App->audio->PlayFx(checkp);
		checkpoint = 3;
		halfLap = true;
	}

	if (body1 == check_5) {
		App->audio->PlayFx(checkp);
		checkpoint = 4;
	}

	if (body1 == check_6) {
		App->audio->PlayFx(checkp);
		checkpoint = 5;
	}

	if (body1 == check_7) {
		App->audio->PlayFx(checkp);
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

Cone* ModuleSceneIntro::CreateCone(float h, vec3 pos, float r) {
	Cone* cone = new Cone;
	cone->height = h;
	cone->SetPos(pos.x, pos.y, pos.z);
	cone->radius = r;
	cone->color = White;
	cone->SetRotation(90, vec3(0, 0, 1));
	return cone;
}

PhysBody3D* ModuleSceneIntro::CreateSphePhysbody(Sphere* sphe, Module* Callback) {

	PhysBody3D* sphe_pbody;
	sphe_pbody = App->physics->AddBody(*sphe, 0.0f);
	sphe_pbody->collision_listeners.add(Callback);
	return sphe_pbody;
}

Sphere* ModuleSceneIntro::CreateSphe(vec3 pos, float rad, Color color) {
	Sphere* sphe = new Sphere;
	sphe->SetPos(pos.x, pos.y, pos.z);
	sphe->radius = rad;
	sphe->color = color;
	return sphe;
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

PhysBody3D* ModuleSceneIntro::CreateHelix(Cube &cube, vec3 size, vec3 pos, float angle) {

	PhysBody3D* wall_pbody;
	cube.size = size;
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