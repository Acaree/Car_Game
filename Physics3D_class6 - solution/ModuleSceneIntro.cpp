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

	wall1.size = vec3(1, 2, 100);
	wall1.SetPos(106, 1, 150);
	wall1.color = Black;
	//wall1.SetRotation(1, vec3(1,0,0));
	wall_1 = App->physics->AddBody(wall1, 0.0f);
	wall_1->SetAsSensor(false);
	wall_1->collision_listeners.add(this);

	wall2.size = vec3(1, 2, 100);
	wall2.SetPos(94, 1, 150);
	wall2.color = Black;
	//wall1.SetRotation(1, vec3(1,0,0));
	wall_2 = App->physics->AddBody(wall2, 0.0f);
	wall_2->SetAsSensor(false);
	wall_2->collision_listeners.add(this);

	wall3.size = vec3(1, 2, 20);
	wall3.SetPos(101.75, 1, 209);
	wall3.color = Black;
	wall3.SetRotation(-25, vec3(0, 1, 0));
	wall_3 = App->physics->AddBody(wall3, 0.0f);
	wall_3->SetAsSensor(false);
	wall_3->collision_listeners.add(this);

	wall4.size = vec3(1, 2, 20);
	wall4.SetPos(89.75, 1, 209);
	wall4.color = Black;
	wall4.SetRotation(-25, vec3(0, 1, 0));
	wall_4 = App->physics->AddBody(wall4, 0.0f);
	wall_4->SetAsSensor(false);
	wall_4->collision_listeners.add(this);

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

	wall_1->GetTransform(&wall1.transform);
	wall1.Render();

	wall_2->GetTransform(&wall1.transform);
	wall2.Render();

	wall_3->GetTransform(&wall3.transform);
	wall3.Render();

	wall_4->GetTransform(&wall4.transform);
	wall4.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("Hit!");
}

