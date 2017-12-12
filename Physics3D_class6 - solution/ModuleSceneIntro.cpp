#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

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

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	// Walls--------------------------------------------------------------------
	{

		wall_1 = CreateWall(wall1, vec3(1, 2, 200), vec3(6, 1, 0), Blue, 0, vec3(0, 1, 0), false, this);
		wall_2 = CreateWall(wall2, vec3(1, 2, 200), vec3(-6, 1, 0), Blue, 0, vec3(0, 1, 0), false, this);
		wall_3 = CreateWall(wall3, vec3(1, 2, 20), vec3(6, 2.5, 100), Blue, -10, vec3(1, 0, 0), false, this);
		wall_4 = CreateWall(wall4, vec3(1, 2, 20), vec3(-6, 2.5, 100), Blue, -10, vec3(1, 0, 0), false, this);
		wall_5 = CreateWall(wall5, vec3(1, 2, 50), vec3(6, 4.25, 134.75), Blue, 0, vec3(0, 1, 0), false, this);
		wall_6 = CreateWall(wall6, vec3(1, 2, 50), vec3(-6, 4.25, 134.75), Blue, 0, vec3(0, 1, 0), false, this);
		wall_7 = CreateWall(wall7, vec3(1, 2, 40), vec3(-2.5, 4.25, 178.1), Blue, -25, vec3(0, 1, 0), false, this);
		wall_8 = CreateWall(wall8, vec3(1, 2, 30), vec3(-12.3, 4.25, 173.1), Blue, -25, vec3(0, 1, 0), false, this);
		wall_9 = CreateWall(wall9, vec3(1, 2, 40), vec3(-30, 4.25, 203.25), Blue, -70, vec3(0, 1, 0), false, this);
		wall_10 = CreateWall(wall10, vec3(1, 2, 50), vec3(-41.9, 4.25, 195), Blue, -70, vec3(0, 1, 0), false, this);
		wall_11 = CreateWall(wall11, vec3(1, 2, 30), vec3(-56, 4.25, 222.85), Blue, -30, vec3(0, 1, 0), false, this);
		wall_12 = CreateWall(wall12, vec3(1, 2, 20), vec3(-70.1, 4.25, 212), Blue, -30, vec3(0, 1, 0), false, this);
		wall_13 = CreateWall(wall13, vec3(1, 2, 10), vec3(-64.75, 4.25, 240.55), Blue, -15, vec3(0, 1, 0), false, this);
		wall_14 = CreateWall(wall14, vec3(1, 2, 20), vec3(-77.7, 4.25, 230.3), Blue, -15, vec3(0, 1, 0), false, this);
		wall_15 = CreateWall(wall15, vec3(1, 2, 12), vec3(-66.025, 4.25, 251.25), Blue, 0, vec3(0, 1, 0), false, this);
		wall_16 = CreateWall(wall16, vec3(1, 2, 17.2), vec3(-80.3, 4.25, 248.6), Blue, 0, vec3(0, 1, 0), false, this);
		wall_17 = CreateWall(wall17, vec3(1, 2, 21), vec3(-66.025, 7.625, 266.82), Blue, -20, vec3(1, 0, 0), false, this);
		wall_18 = CreateWall(wall18, vec3(1, 2, 21), vec3(-80.3, 7.625, 266.82), Blue, -20, vec3(1, 0, 0), false, this);
		wall_19 = CreateWall(wall19, vec3(1, 2, 30), vec3(-66.025, 11.035, 291.175), Blue, 0, vec3(1, 0, 0), false, this);
		wall_20 = CreateWall(wall20, vec3(1, 2, 30), vec3(-80.3, 11.035, 291.175), Blue, 0, vec3(1, 0, 0), false, this);
		wall_21 = CreateWall(wall21, vec3(1, 2, 30), vec3(-71.19, 11.035, 320.44), Blue, -20, vec3(0, 1, 0), false, this);
		wall_22 = CreateWall(wall22, vec3(1, 2, 30), vec3(-85.399, 11.035, 320.1), Blue, -20, vec3(0, 1, 0), false, this);
		wall_23 = CreateWall(wall23, vec3(1, 2, 10), vec3(-76.29, 11.035, 339.37), Blue, 0, vec3(0, 1, 0), false, this);
		wall_24 = CreateWall(wall24, vec3(1, 2, 10), vec3(-90.55, 11.035, 339.28), Blue, 0, vec3(0, 1, 0), false, this);
		wall_25 = CreateWall(wall25, vec3(1, 2, 10), vec3(-72.22, 11.035, 346.43), Blue, 60, vec3(0, 1, 0), false, this);
		wall_26 = CreateWall(wall26, vec3(1, 2, 15), vec3(-83.9, 11.035, 348.4), Blue, 60, vec3(0, 1, 0), false, this);
		wall_27 = CreateWall(wall27, vec3(1, 2, 15), vec3(-67.7, 11.035, 356.725), Blue, 0, vec3(0, 1, 0), false, this);
		wall_28 = CreateWall(wall28, vec3(1, 2, 12.5), vec3(-77.65, 11.035, 357.975), Blue, 0, vec3(0, 1, 0), false, this);
		wall_29 = CreateWall(wall29, vec3(1, 2, 20), vec3(-67.7, 13.655, 373.5), Blue, -15, vec3(1, 0, 0), false, this);
		wall_30 = CreateWall(wall30, vec3(1, 2, 20), vec3(-77.65, 13.655, 373.5), Blue, -15, vec3(1, 0, 0), false, this);
		wall_31 = CreateWall(wall31, vec3(1, 2, 15.25), vec3(-67.7, 16.2, 390.5), Blue, 0, vec3(1, 0, 0), false, this);
		wall_32 = CreateWall(wall32, vec3(1, 2, 20.25), vec3(-77.65, 16.2, 393), Blue, 0, vec3(1, 0, 0), false, this);
		wall_33 = CreateWall(wall33, vec3(1, 2, 15.25), vec3(-63.95, 16.2, 404.45), Blue, 30, vec3(0, 1, 0), false, this);
		wall_34 = CreateWall(wall34, vec3(1, 2, 20.25), vec3(-72.55, 16.2, 412.1), Blue, 30, vec3(0, 1, 0), false, this);
		wall_35 = CreateWall(wall35, vec3(1, 2, 15.25), vec3(-54.87, 16.2, 416.25), Blue, 45, vec3(0, 1, 0), false, this);
		wall_36 = CreateWall(wall36, vec3(1, 2, 20.25), vec3(-60.5, 16.2, 428), Blue, 45, vec3(0, 1, 0), false, this);
		wall_37 = CreateWall(wall37, vec3(1, 2, 15.25), vec3(-43.15, 16.2, 425.2), Blue, 60, vec3(0, 1, 0), false, this);
		wall_38 = CreateWall(wall38, vec3(1, 2, 20.25), vec3(-44.75, 16.2, 440.2), Blue, 60, vec3(0, 1, 0), false, this);
		wall_39 = CreateWall(wall39, vec3(1, 2, 15.25), vec3(-43.15, 16.2, 425.2), Blue, 75, vec3(0, 1, 0), false, this);
		wall_40 = CreateWall(wall40, vec3(1, 2, 20.25), vec3(-44.75, 16.2, 440.2), Blue, 75, vec3(0, 1, 0), false, this);


	}

	// Road--------------------------------------------------------------------

	road_1 = CreateWall(road1, vec3(12, 0.2, 200), vec3(0, 0, 0), White, 0, vec3(0, 1, 0), false, this);
	road_2 = CreateWall(road2, vec3(12, 0.2, 20), vec3(0, 1.5, 100), White, -10, vec3(1, 0, 0), false, this);
	road_3 = CreateWall(road3, vec3(12, 0.2, 50), vec3(0, 3.25, 134.75), White, 0, vec3(1, 0, 0), false, this);
	road_4 = CreateWall(road4, vec3(11, 0.2, 42), vec3(-7, 3.24, 175), White, -25, vec3(0, 1, 0), false, this);
	road_5 = CreateWall(road5, vec3(12, 0.2, 55), vec3(-39, 3.23, 200), White, -70, vec3(0, 1, 0), false, this);
	road_6 = CreateWall(road6, vec3(17, 0.2, 30), vec3(-64, 3.22, 218.75), White, -30, vec3(0, 1, 0), false, this);
	road_7 = CreateWall(road7, vec3(15, 0.2, 15), vec3(-71.5, 3.21, 237), White, -15, vec3(0, 1, 0), false, this);
	road_8 = CreateWall(road8, vec3(15, 0.2, 15), vec3(-73, 3.2, 249.9), White, 0, vec3(0, 1, 0), false, this);
	road_9 = CreateWall(road9, vec3(14, 0.2, 20), vec3(-73, 6.625, 266.82), White, -20, vec3(1, 0, 0), false, this);
	road_10 = CreateWall(road10, vec3(14, 0.2, 30), vec3(-73, 10.035, 291.175), White, 0, vec3(1, 0, 0), false, this);
	road_11 = CreateWall(road11, vec3(14, 0.2, 32), vec3(-77.75, 10.034, 318.75), White, -20, vec3(0, 1, 0), false, this);
	road_12 = CreateWall(road12, vec3(14, 0.2, 13), vec3(-83.25, 10.033, 338), White, 0, vec3(0, 1, 0), false, this);
	road_13 = CreateWall(road13, vec3(7, 0.2, 22), vec3(-79, 10.032, 346.7), White, 60, vec3(0, 1, 0), false, this);
	road_14 = CreateWall(road14, vec3(10, 0.2, 14.5), vec3(-73, 10.031, 356.975), White, 0, vec3(0, 1, 0), false, this);
	road_15 = CreateWall(road15, vec3(10, 0.2, 20), vec3(-73, 12.6, 373.8), White, -15, vec3(1, 0, 0), false, this);
	road_16 = CreateWall(road16, vec3(10, 0.2, 20), vec3(-73, 15.185, 393.45), White, 0, vec3(1, 0, 0), false, this);
	road_17 = CreateWall(road17, vec3(11, 0.2, 21), vec3(-67.5, 15.184, 409.5), White, 30, vec3(0, 1, 0), false, this);
	road_18 = CreateWall(road18, vec3(12, 0.2, 21), vec3(-56.5, 15.183, 423.1), White, 45, vec3(0, 1, 0), false, this);
	road_19 = CreateWall(road19, vec3(14, 0.2, 22.7), vec3(-42.5, 15.182, 434), White, 60, vec3(0, 1, 0), false, this);

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
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	//Wall
	wall_1->GetTransform(&wall1.transform);
	wall1.Render();

	wall_2->GetTransform(&wall1.transform);
	wall2.Render();

	wall_3->GetTransform(&wall3.transform);
	wall3.Render();

	wall_4->GetTransform(&wall4.transform);
	wall4.Render();

	wall_5->GetTransform(&wall5.transform);
	wall5.Render();

	wall_6->GetTransform(&wall6.transform);
	wall6.Render();

	wall_7->GetTransform(&wall7.transform);
	wall7.Render();

	wall_8->GetTransform(&wall8.transform);
	wall8.Render();

	wall_9->GetTransform(&wall9.transform);
	wall9.Render();

	wall_10->GetTransform(&wall10.transform);
	wall10.Render();

	wall_11->GetTransform(&wall11.transform);
	wall11.Render();

	wall_12->GetTransform(&wall12.transform);
	wall12.Render();

	wall_13->GetTransform(&wall13.transform);
	wall13.Render();

	wall_14->GetTransform(&wall14.transform);
	wall14.Render();

	wall_15->GetTransform(&wall15.transform);
	wall15.Render();

	wall_16->GetTransform(&wall16.transform);
	wall16.Render();

	wall_17->GetTransform(&wall17.transform);
	wall17.Render();

	wall_18->GetTransform(&wall18.transform);
	wall18.Render();

	wall_19->GetTransform(&wall19.transform);
	wall19.Render();

	wall_20->GetTransform(&wall20.transform);
	wall20.Render();

	wall_21->GetTransform(&wall22.transform);
	wall21.Render();

	wall_22->GetTransform(&wall22.transform);
	wall22.Render();

	wall_23->GetTransform(&wall23.transform);
	wall23.Render();

	wall_24->GetTransform(&wall24.transform);
	wall24.Render();

	wall_25->GetTransform(&wall25.transform);
	wall25.Render();

	wall_26->GetTransform(&wall26.transform);
	wall26.Render();

	wall_27->GetTransform(&wall27.transform);
	wall27.Render();

	wall_28->GetTransform(&wall28.transform);
	wall28.Render();

	wall_29->GetTransform(&wall29.transform);
	wall29.Render();

	wall_30->GetTransform(&wall30.transform);
	wall30.Render();

	wall_31->GetTransform(&wall31.transform);
	wall31.Render();

	wall_32->GetTransform(&wall32.transform);
	wall32.Render();

	wall_33->GetTransform(&wall33.transform);
	wall33.Render();

	wall_34->GetTransform(&wall34.transform);
	wall34.Render();

	wall_35->GetTransform(&wall35.transform);
	wall35.Render();

	wall_36->GetTransform(&wall36.transform);
	wall36.Render();

	wall_37->GetTransform(&wall37.transform);
	wall37.Render();

	wall_38->GetTransform(&wall38.transform);
	wall38.Render();

	wall_39->GetTransform(&wall39.transform);
	wall39.Render();

	wall_40->GetTransform(&wall40.transform);
	wall40.Render();


	//Road
	road_1->GetTransform(&road1.transform);
	road1.Render();

	road_2->GetTransform(&road2.transform);
	road2.Render();

	road_3->GetTransform(&road3.transform);
	road3.Render();

	road_4->GetTransform(&road4.transform);
	road4.Render();

	road_5->GetTransform(&road5.transform);
	road5.Render();

	road_6->GetTransform(&road6.transform);
	road6.Render();

	road_7->GetTransform(&road7.transform);
	road7.Render();

	road_8->GetTransform(&road8.transform);
	road8.Render();

	road_9->GetTransform(&road9.transform);
	road9.Render();

	road_10->GetTransform(&road10.transform);
	road10.Render();

	road_11->GetTransform(&road11.transform);
	road11.Render();

	road_12->GetTransform(&road12.transform);
	road12.Render();

	road_13->GetTransform(&road13.transform);
	road13.Render();

	road_14->GetTransform(&road14.transform);
	road14.Render();

	road_15->GetTransform(&road15.transform);
	road15.Render();

	road_16->GetTransform(&road16.transform);
	road16.Render();

	road_17->GetTransform(&road17.transform);
	road17.Render();

	road_18->GetTransform(&road18.transform);
	road18.Render();

	road_19->GetTransform(&road19.transform);
	road19.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("Hit!");
}

PhysBody3D* ModuleSceneIntro::CreateWall(Cube &cube, vec3 size, vec3 pos, Color color, float angle, vec3 pivot, bool isSensor, Module* Callback) {

	PhysBody3D* wall_pbody;
	cube.size = size;
	cube.SetPos(pos.x,pos.y,pos.z);
	cube.color = color;
	cube.SetRotation(angle, pivot);
	wall_pbody = App->physics->AddBody(cube, 0.0f);
	wall_pbody->SetAsSensor(isSensor);
	wall_pbody->collision_listeners.add(Callback);
	return wall_pbody;
}