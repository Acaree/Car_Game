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

	pugi::xml_document track_file;
	pugi::xml_parse_result result = track_file.load_file("track.xml");
	pugi::xml_node wall_node = track_file.child("track").child("walls").child("wall");
	pugi::xml_node road_node = track_file.child("track").child("roads").child("road");

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

	cin.height = 5;
	cin.SetPos(87.5, 12.482, 347.15);
	cin.radius = 2;
	cin.color = Grey;
	cin.SetRotation(90, vec3(0, 0, 1));
	cinn = App->physics->AddBody(cin, 0.0f);
	cinn->collision_listeners.add(this);

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

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("Hit!");
}

PhysBody3D* ModuleSceneIntro::CreateCubePhysbody(Cube* cube,bool isSensor, Module* Callback) {

	PhysBody3D* wall_pbody;
	wall_pbody = App->physics->AddBody(*cube, 0.0f);
	wall_pbody->SetAsSensor(isSensor);
	wall_pbody->collision_listeners.add(Callback);
	return wall_pbody;
}

Cube* ModuleSceneIntro::CreateCube(vec3 size, vec3 pos, Color color, float angle, vec3 pivot) {
	Cube* cube= new Cube;
	cube->size = size;
	cube->SetPos(pos.x, pos.y, pos.z);
	cube->color = color;
	cube->SetRotation(angle, pivot);
	return cube;
}