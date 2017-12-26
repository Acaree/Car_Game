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
	Cube s;
	PhysBody3D* sensor;

	Cone cin;
	PhysBody3D *cinn;

	// Walls
	p2List<Cube*> wall;
	Cube wall1, wall2, wall3, wall4, wall5, wall6, wall7, wall8, wall9, wall10, wall11, wall12, wall13, wall14, wall15, wall16, wall17, wall18,
		wall19, wall20, wall21, wall22, wall23, wall24, wall25, wall26, wall27, wall28, wall29, wall30, wall31, wall32, wall33, wall34, wall35,
		wall36, wall37, wall38, wall39, wall40, wall41, wall42, wall43, wall44, wall45, wall46, wall47, wall48, wall49, wall50, wall51, wall52,
		wall53, wall54, wall55, wall56, wall57, wall58, wall59, wall60, wall61, wall62, wall63, wall64, wall65, wall66, wall67, wall68, wall69,
		wall70, wall71, wall72, wall73, wall74, wall75, wall76, wall77, wall78, wall79, wall80, wall81, wall82, wall83, wall84, wall85, wall86,
		wall87, wall88, wall89, wall90, wall91, wall92, wall93, wall94, wall95, wall96, wall97, wall98, wall99, wall100, wall101, wall102, wall103,
		wall104, wall105, wall106, wall107, wall108, wall109, wall110, wall111, wall112, wall113, wall114, wall115, wall116, wall117, wall118,
		wall119, wall120, wall121, wall122, wall123, wall124, wall125, wall126, wall127, wall128, wall129, wall130, wall131, wall132, wall133,
		wall134, wall135, wall136, wall137, wall138;

	p2List<PhysBody3D*> wall_body;
	PhysBody3D *wall_1, *wall_2, *wall_3, *wall_4, *wall_5, *wall_6, *wall_7, *wall_8, *wall_9, *wall_10, *wall_11, *wall_12, *wall_13, *wall_14,
		*wall_15, *wall_16, *wall_17, *wall_18, *wall_19, *wall_20, *wall_21, *wall_22, *wall_23, *wall_24, *wall_25, *wall_26, *wall_27, *wall_28,
		*wall_29, *wall_30, *wall_31, *wall_32, *wall_33, *wall_34, *wall_35, *wall_36, *wall_37, *wall_38, *wall_39, *wall_40, *wall_41, *wall_42,
		*wall_43, *wall_44, *wall_45, *wall_46, *wall_47, *wall_48, *wall_49, *wall_50, *wall_51, *wall_52, *wall_53, *wall_54, *wall_55, *wall_56,
		*wall_57, *wall_58, *wall_59, *wall_60, *wall_61, *wall_62, *wall_63, *wall_64, *wall_65, *wall_66, *wall_67, *wall_68, *wall_69, *wall_70,
		*wall_71, *wall_72, *wall_73, *wall_74, *wall_75, *wall_76, *wall_77, *wall_78, *wall_79, *wall_80, *wall_81, *wall_82, *wall_83, *wall_84,
		*wall_85, *wall_86, *wall_87, *wall_88, *wall_89, *wall_90, *wall_91, *wall_92, *wall_93, *wall_94, *wall_95, *wall_96, *wall_97, *wall_98,
		*wall_99, *wall_100, *wall_101, *wall_102, *wall_103, *wall_104, *wall_105, *wall_106, *wall_107, *wall_108, *wall_109, *wall_110, *wall_111,
		*wall_112, *wall_113, *wall_114, *wall_115, *wall_116, *wall_117, *wall_118, *wall_119, *wall_120, *wall_121, *wall_122, *wall_123, *wall_124,
		*wall_125, *wall_126, *wall_127, *wall_128, *wall_129, *wall_130, *wall_131, *wall_132, *wall_133, *wall_134, *wall_135, *wall_136, *wall_137,
		*wall_138;

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
