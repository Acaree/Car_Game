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

	wall1.size = vec3(1, 2, 200);
	wall1.SetPos(6, 1, 0);
	wall1.color = Blue;
	wall_1 = App->physics->AddBody(wall1, 0.0f);
	wall_1->SetAsSensor(false);
	wall_1->collision_listeners.add(this);

	wall2.size = vec3(1, 2, 200);
	wall2.SetPos(-6, 1, 0);
	wall2.color = Blue;
	wall_2 = App->physics->AddBody(wall2, 0.0f);
	wall_2->SetAsSensor(false);
	wall_2->collision_listeners.add(this);

	wall3.size = vec3(1, 2, 20);
	wall3.SetPos(6, 2.5, 100);
	wall3.color = Blue;
	wall3.SetRotation(-10, vec3(1, 0, 0));
	wall_3 = App->physics->AddBody(wall3, 0.0f);
	wall_3->SetAsSensor(false);
	wall_3->collision_listeners.add(this);

	wall4.size = vec3(1, 2, 20);
	wall4.SetPos(-6, 2.5, 100);
	wall4.color = Blue;
	wall4.SetRotation(-10, vec3(1, 0, 0));
	wall_4 = App->physics->AddBody(wall4, 0.0f);
	wall_4->SetAsSensor(false);
	wall_4->collision_listeners.add(this);

	wall5.size = vec3(1, 2, 50);
	wall5.SetPos(6, 4.25, 134.75);
	wall5.color = Blue;
	wall_5 = App->physics->AddBody(wall5, 0.0f);
	wall_5->SetAsSensor(false);
	wall_5->collision_listeners.add(this);

	wall6.size = vec3(1, 2, 50);
	wall6.SetPos(-6, 4.25, 134.75);
	wall6.color = Blue;
	wall_6 = App->physics->AddBody(wall6, 0.0f);
	wall_6->SetAsSensor(false);
	wall_6->collision_listeners.add(this);

	wall7.size = vec3(1, 2, 40);
	wall7.SetPos(-2.5, 4.25, 178.1);
	wall7.color = Blue;
	wall7.SetRotation(-25, vec3(0, 1, 0));
	wall_7 = App->physics->AddBody(wall7, 0.0f);
	wall_7->SetAsSensor(false);
	wall_7->collision_listeners.add(this);

	wall8.size = vec3(1, 2, 30);
	wall8.SetPos(-12.3, 4.25, 173.1);
	wall8.color = Blue;
	wall8.SetRotation(-25, vec3(0, 1, 0));
	wall_8 = App->physics->AddBody(wall8, 0.0f);
	wall_8->SetAsSensor(false);
	wall_8->collision_listeners.add(this);

	wall9.size = vec3(1, 2, 40);
	wall9.SetPos(-30, 4.25, 203.25);
	wall9.color = Blue;
	wall9.SetRotation(-70, vec3(0, 1, 0));
	wall_9 = App->physics->AddBody(wall9, 0.0f);
	wall_9->SetAsSensor(false);
	wall_9->collision_listeners.add(this);

	wall10.size = vec3(1, 2, 50);
	wall10.SetPos(-41.9, 4.25, 195);
	wall10.color = Blue;
	wall10.SetRotation(-70, vec3(0, 1, 0));
	wall_10 = App->physics->AddBody(wall10, 0.0f);
	wall_10->SetAsSensor(false);
	wall_10->collision_listeners.add(this);

	wall11.size = vec3(1, 2, 30);
	wall11.SetPos(-56, 4.25, 222.85);
	wall11.color = Blue;
	wall11.SetRotation(-30, vec3(0, 1, 0));
	wall_11 = App->physics->AddBody(wall11, 0.0f);
	wall_11->SetAsSensor(false);
	wall_11->collision_listeners.add(this);

	wall12.size = vec3(1, 2, 20);
	wall12.SetPos(-70.1, 4.25, 212);
	wall12.color = Blue;
	wall12.SetRotation(-30, vec3(0, 1, 0));
	wall_12 = App->physics->AddBody(wall12, 0.0f);
	wall_12->SetAsSensor(false);
	wall_12->collision_listeners.add(this);

	wall13.size = vec3(1, 2, 10);
	wall13.SetPos(-64.75, 4.25, 240.55);
	wall13.color = Blue;
	wall13.SetRotation(-15, vec3(0, 1, 0));
	wall_13 = App->physics->AddBody(wall13, 0.0f);
	wall_13->SetAsSensor(false);
	wall_13->collision_listeners.add(this);

	wall14.size = vec3(1, 2, 20);
	wall14.SetPos(-77.7, 4.25, 230.3);
	wall14.color = Blue;
	wall14.SetRotation(-15, vec3(0, 1, 0));
	wall_14 = App->physics->AddBody(wall14, 0.0f);
	wall_14->SetAsSensor(false);
	wall_14->collision_listeners.add(this);

	wall15.size = vec3(1, 2, 12);
	wall15.SetPos(-66.025, 4.25, 251.25);
	wall15.color = Blue;
	wall_15 = App->physics->AddBody(wall15, 0.0f);
	wall_15->SetAsSensor(false);
	wall_15->collision_listeners.add(this);

	wall16.size = vec3(1, 2, 17.2);
	wall16.SetPos(-80.3, 4.25, 248.6);
	wall16.color = Blue;
	wall_16 = App->physics->AddBody(wall16, 0.0f);
	wall_16->SetAsSensor(false);
	wall_16->collision_listeners.add(this);

	wall17.size = vec3(1, 2, 21);
	wall17.SetPos(-66.025, 7.625, 266.82);
	wall17.color = Blue;
	wall17.SetRotation(-20, vec3(1, 0, 0));
	wall_17 = App->physics->AddBody(wall17, 0.0f);
	wall_17->SetAsSensor(false);
	wall_17->collision_listeners.add(this);

	wall18.size = vec3(1, 2, 21);
	wall18.SetPos(-80.3, 7.625, 266.82);
	wall18.color = Blue;
	wall18.SetRotation(-20, vec3(1, 0, 0));
	wall_18 = App->physics->AddBody(wall18, 0.0f);
	wall_18->SetAsSensor(false);
	wall_18->collision_listeners.add(this);

	// Road--------------------------------------------------------------------
	road1.size = vec3(12, 0.2, 20);
	road1.SetPos(0, 1.5, 100);
	road1.color = White;
	road1.SetRotation(-10, vec3(1, 0, 0));
	road_1 = App->physics->AddBody(road1, 0.0f);
	road_1->SetAsSensor(false);
	road_1->collision_listeners.add(this);

	road2.size = vec3(12, 0.2, 50);
	road2.SetPos(0, 3.25, 134.75);
	road2.color = White;
	road_2 = App->physics->AddBody(road2, 0.0f);
	road_2->SetAsSensor(false);
	road_2->collision_listeners.add(this);

	road3.size = vec3(11, 0.2, 42);
	road3.SetPos(-7, 3.24, 175);
	road3.color = White;
	road3.SetRotation(-25, vec3(0, 1, 0));
	road_3 = App->physics->AddBody(road3, 0.0f);
	road_3->SetAsSensor(false);
	road_3->collision_listeners.add(this);

	road4.size = vec3(12, 0.2, 55);
	road4.SetPos(-39, 3.23, 200);
	road4.color = White;
	road4.SetRotation(-70, vec3(0, 1, 0));
	road_4 = App->physics->AddBody(road4, 0.0f);
	road_4->SetAsSensor(false);
	road_4->collision_listeners.add(this);

	road5.size = vec3(17, 0.2, 30);
	road5.SetPos(-64, 3.22, 218.75);
	road5.color = White;
	road5.SetRotation(-30, vec3(0, 1, 0));
	road_5 = App->physics->AddBody(road5, 0.0f);
	road_5->SetAsSensor(false);
	road_5->collision_listeners.add(this);

	road6.size = vec3(15, 0.2, 15);
	road6.SetPos(-71.5, 3.21, 237);
	road6.color = White;
	road6.SetRotation(-15, vec3(0, 1, 0));
	road_6 = App->physics->AddBody(road6, 0.0f);
	road_6->SetAsSensor(false);
	road_6->collision_listeners.add(this);

	road7.size = vec3(15, 0.2, 15);
	road7.SetPos(-73, 3.2, 249.9);
	road7.color = White;
	road_7 = App->physics->AddBody(road7, 0.0f);
	road_7->SetAsSensor(false);
	road_7->collision_listeners.add(this);

	road8.size = vec3(14, 0.2, 20);
	road8.SetPos(-73, 6.625, 266.82);
	road8.color = White;
	road8.SetRotation(-20, vec3(1, 0, 0));
	road_8 = App->physics->AddBody(road8, 0.0f);
	road_8->SetAsSensor(false);
	road_8->collision_listeners.add(this);

	road9.size = vec3(14, 0.2, 20);
	road9.SetPos(-73, 10.035, 286.175);
	road9.color = White;
	road_9 = App->physics->AddBody(road9, 0.0f);
	road_9->SetAsSensor(false);
	road_9->collision_listeners.add(this);

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

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("Hit!");
}

