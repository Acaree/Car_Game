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
	//struct
		//defwall
		//for
		//fichero
		pugi::xml_document track_file;
		pugi::xml_parse_result result = track_file.load_file("track.xml");
		pugi::xml_node wall_node = track_file.child("track").child("walls").child("wall");

		while (wall_node != nullptr) {
			Cube* cube=CreateCube(vec3(wall_node.attribute("x1").as_float(), wall_node.attribute("y1").as_float(), wall_node.attribute("z1").as_float()), vec3(wall_node.attribute("x2").as_float(), wall_node.attribute("y2").as_float(), wall_node.attribute("z2").as_float()), Color(wall_node.attribute("r").as_float(), wall_node.attribute("g").as_float(), wall_node.attribute("b").as_float()), wall_node.attribute("num").as_float(), vec3(wall_node.attribute("x3").as_float(), wall_node.attribute("y3").as_float(), wall_node.attribute("z3").as_float()));
			wall_body.add(CreateCubePhysbody(cube,wall_node.attribute("bool").as_bool(), this));
			wall.add(cube);
			wall_node = wall_node.next_sibling();
		}

		/*
		wall_1 = CreateWall(wall1, vec3(wall_node.attribute("x1").as_float(), wall_node.attribute("y1").as_float(), wall_node.attribute("z1").as_float()), vec3(wall_node.attribute("x2").as_float(), wall_node.attribute("y2").as_float(), wall_node.attribute("z2").as_float()), Blue, wall_node.attribute("num").as_float(), vec3(wall_node.attribute("x3").as_float(), wall_node.attribute("y3").as_float(), wall_node.attribute("z3").as_float()), wall_node.attribute("bool").as_bool(), this);
		//wall_1 = CreateWall(wall1 , vec3(1, 2, 200), vec3(-6, 1, 0), Blue, 0, vec3(0, 1, 0), false, this);
		//wall_2 = CreateWall(wall2, vec3(1, 2, 200), vec3(-6, 1, 0), Blue, 0, vec3(0, 1, 0), false, this);
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
		wall_17 = CreateWall(wall17, vec3(1, 2, 21), vec3(-66.025, 5.9, 266.82), Blue, -10, vec3(1, 0, 0), false, this);
		wall_18 = CreateWall(wall18, vec3(1, 2, 21), vec3(-80.3, 5.9, 266.82), Blue, -10, vec3(1, 0, 0), false, this);
		wall_19 = CreateWall(wall19, vec3(1, 2, 30), vec3(-66.025, 7.6, 291.175), Blue, 0, vec3(1, 0, 0), false, this);
		wall_20 = CreateWall(wall20, vec3(1, 2, 30), vec3(-80.3, 7.6, 291.175), Blue, 0, vec3(1, 0, 0), false, this);
		wall_21 = CreateWall(wall21, vec3(1, 2, 30), vec3(-71.19, 7.6, 320.44), Blue, -20, vec3(0, 1, 0), false, this);
		wall_22 = CreateWall(wall22, vec3(1, 2, 30), vec3(-85.399, 7.6, 320.1), Blue, -20, vec3(0, 1, 0), false, this);
		wall_23 = CreateWall(wall23, vec3(1, 2, 10), vec3(-76.29, 7.6, 339.37), Blue, 0, vec3(0, 1, 0), false, this);
		wall_24 = CreateWall(wall24, vec3(1, 2, 10), vec3(-90.55, 7.6, 339.28), Blue, 0, vec3(0, 1, 0), false, this);
		wall_25 = CreateWall(wall25, vec3(1, 2, 10), vec3(-72.22, 7.6, 346.43), Blue, 60, vec3(0, 1, 0), false, this);
		wall_26 = CreateWall(wall26, vec3(1, 2, 15), vec3(-83.9, 7.6, 348.4), Blue, 60, vec3(0, 1, 0), false, this);
		wall_27 = CreateWall(wall27, vec3(1, 2, 15), vec3(-67.7, 7.6, 356.725), Blue, 0, vec3(0, 1, 0), false, this);
		wall_28 = CreateWall(wall28, vec3(1, 2, 12.5), vec3(-77.65, 7.6, 357.975), Blue, 0, vec3(0, 1, 0), false, this);
		wall_29 = CreateWall(wall29, vec3(1, 2, 20), vec3(-67.7, 9.25, 373.5), Blue, -10, vec3(1, 0, 0), false, this);
		wall_30 = CreateWall(wall30, vec3(1, 2, 20), vec3(-77.65, 9.25, 373.5), Blue, -10, vec3(1, 0, 0), false, this);
		wall_31 = CreateWall(wall31, vec3(1, 2, 15.25), vec3(-67.7, 10.99, 390.5), Blue, 0, vec3(1, 0, 0), false, this);
		wall_32 = CreateWall(wall32, vec3(1, 2, 20.25), vec3(-77.65, 10.99, 393), Blue, 0, vec3(1, 0, 0), false, this);
		wall_33 = CreateWall(wall33, vec3(1, 2, 15.25), vec3(-63.95, 10.99, 404.45), Blue, 30, vec3(0, 1, 0), false, this);
		wall_34 = CreateWall(wall34, vec3(1, 2, 20.25), vec3(-72.55, 10.99, 412.1), Blue, 30, vec3(0, 1, 0), false, this);
		wall_35 = CreateWall(wall35, vec3(1, 2, 15.25), vec3(-54.87, 10.99, 416.25), Blue, 45, vec3(0, 1, 0), false, this);
		wall_36 = CreateWall(wall36, vec3(1, 2, 20.25), vec3(-60.5, 10.99, 428), Blue, 45, vec3(0, 1, 0), false, this);
		wall_37 = CreateWall(wall37, vec3(1, 2, 15.25), vec3(-43.15, 10.99, 425.2), Blue, 60, vec3(0, 1, 0), false, this);
		wall_38 = CreateWall(wall38, vec3(1, 2, 20.25), vec3(-44.75, 10.99, 440.2), Blue, 60, vec3(0, 1, 0), false, this);
		wall_39 = CreateWall(wall39, vec3(1, 2, 15.25), vec3(-29.45, 10.99, 430.85), Blue, 75, vec3(0, 1, 0), false, this);
		wall_40 = CreateWall(wall40, vec3(1, 2, 20.25), vec3(-26.3, 10.99, 447.85), Blue, 75, vec3(0, 1, 0), false, this);
		wall_41 = CreateWall(wall41, vec3(20, 2, 1), vec3(-12.25, 10.99, 432.79), Blue, 0, vec3(0, 1, 0), false, this);
		wall_42 = CreateWall(wall42, vec3(20.25, 2, 1), vec3(-6.5, 10.99, 450.5), Blue, 0, vec3(0, 1, 0), false, this);
		wall_43 = CreateWall(wall43, vec3(1, 2, 15.25), vec3(4, 10.99, 429.04), Blue, -60, vec3(0, 1, 0), false, this);
		wall_44 = CreateWall(wall44, vec3(1, 2, 20.25), vec3(12, 10.99, 445.5), Blue, -60, vec3(0, 1, 0), false, this);
		wall_45 = CreateWall(wall45, vec3(1, 2, 50), vec3(26.5, 10.99, 406.2), Blue, -40, vec3(0, 1, 0), false, this);
		wall_46 = CreateWall(wall46, vec3(1, 2, 56.5), vec3(38, 10.99, 419.65), Blue, -40, vec3(0, 1, 0), false, this);
		wall_47 = CreateWall(wall47, vec3(1, 2, 15), vec3(45.5, 10.99, 380.5), Blue, -25, vec3(0, 1, 0), false, this);
		wall_48 = CreateWall(wall48, vec3(1, 2, 15), vec3(62.025, 10.99, 394), Blue, -55, vec3(0, 1, 0), false, this);
		wall_49 = CreateWall(wall49, vec3(1, 2, 95), vec3(79.25, 10.99, 337.2), Blue, -40, vec3(0, 1, 0), false, this);
		wall_50 = CreateWall(wall50, vec3(1, 2, 95), vec3(98, 10.99, 354), Blue, -40, vec3(0, 1, 0), false, this);
		wall_51 = CreateWall(wall51, vec3(1, 2, 15), vec3(116.25, 10.99, 297.75), Blue, -65, vec3(0, 1, 0), false, this);
		wall_52 = CreateWall(wall52, vec3(1, 2, 15), vec3(130.5, 10.99, 310.5), Blue, -15, vec3(0, 1, 0), false, this);
		wall_53 = CreateWall(wall53, vec3(1, 2, 14), vec3(127.35, 10.99, 289.35), Blue, -40, vec3(0, 1, 0), false, this);
		wall_54 = CreateWall(wall54, vec3(1, 2, 15), vec3(137.25, 10.99, 297.7), Blue, -40, vec3(0, 1, 0), false, this);
		wall_55 = CreateWall(wall55, vec3(1, 2, 22), vec3(131.73, 10.99, 273.3), Blue, 0, vec3(0, 1, 0), false, this);
		wall_56 = CreateWall(wall56, vec3(1, 2, 30), vec3(142, 10.99, 277), Blue, 0, vec3(0, 1, 0), false, this);
		wall_57 = CreateWall(wall57, vec3(1, 2, 22), vec3(124.75, 10.99, 254.25), Blue, 40, vec3(0, 1, 0), false, this);
		wall_58 = CreateWall(wall58, vec3(1, 2, 30), vec3(132.5, 10.99, 250.5), Blue, 40, vec3(0, 1, 0), false, this);
		wall_59 = CreateWall(wall59, vec3(1, 2, 30), vec3(103.25, 10.99, 243.5), Blue, -100, vec3(0, 1, 0), false, this);
		wall_60 = CreateWall(wall60, vec3(1, 2, 30), vec3(123, 10.99, 224.35), Blue, 0, vec3(0, 1, 0), false, this);
		wall_61 = CreateWall(wall61, vec3(1, 2, 15), vec3(106, 10.99, 233), Blue, -100, vec3(0, 1, 0), false, this);
		wall_62 = CreateWall(wall62, vec3(1, 2, 15), vec3(113, 10.99, 227), Blue, 0, vec3(0, 1, 0), false, this);
		wall_63 = CreateWall(wall63, vec3(1, 2, 27), vec3(88.25, 10.99, 227), Blue, 0, vec3(0, 1, 0), false, this);
		wall_64 = CreateWall(wall64, vec3(1, 2, 28), vec3(109, 10.99, 209), Blue, -100, vec3(0, 1, 0), false, this);
		wall_65 = CreateWall(wall65, vec3(1, 2, 15), vec3(99, 10.99, 224.5), Blue, 0, vec3(0, 1, 0), false, this);
		wall_66 = CreateWall(wall66, vec3(1, 2, 15), vec3(106, 10.99, 218.5), Blue, -100, vec3(0, 1, 0), false, this);
		wall_67 = CreateWall(wall67, vec3(1, 2, 29), vec3(74.25, 10.99, 211.25), Blue, -100, vec3(0, 1, 0), false, this);
		wall_68 = CreateWall(wall68, vec3(1, 2, 29.25), vec3(95.5, 10.99, 192.35), Blue, 0, vec3(0, 1, 0), false, this);
		wall_69 = CreateWall(wall69, vec3(1, 2, 15), vec3(78, 10.99, 201), Blue, -100, vec3(0, 1, 0), false, this);
		wall_70 = CreateWall(wall70, vec3(1, 2, 15), vec3(85, 10.99, 195), Blue, 0, vec3(0, 1, 0), false, this);
		wall_71 = CreateWall(wall71, vec3(1, 2, 27), vec3(60.25, 10.99, 195), Blue, 0, vec3(0, 1, 0), false, this);
		wall_72 = CreateWall(wall72, vec3(1, 2, 29), vec3(81.5, 10.99, 177), Blue, -100, vec3(0, 1, 0), false, this);
		wall_73 = CreateWall(wall73, vec3(1, 2, 15), vec3(71, 10.99, 192.5), Blue, 0, vec3(0, 1, 0), false, this);
		wall_74 = CreateWall(wall74, vec3(1, 2, 15), vec3(78, 10.99, 186.5), Blue, -100, vec3(0, 1, 0), false, this);

		//After rhomb right
		wall_75 = CreateWall(wall75, vec3(1, 2, 75), vec3(23.25, 10.99, 188.525), Blue, -80, vec3(0, 1, 0), false, this);
		wall_76 = CreateWall(wall76, vec3(1, 2, 73), vec3(22.5, 10.99, 179), Blue, -80, vec3(0, 1, 0), false, this);
		wall_77 = CreateWall(wall77, vec3(1, 2, 78), vec3(-47, 10.99, 175.5), Blue, -120, vec3(0, 1, 0), false, this);
		wall_78 = CreateWall(wall78, vec3(1, 2, 73), vec3(-44.75, 10.99, 167.15), Blue, -120, vec3(0, 1, 0), false, this);
		wall_79 = CreateWall(wall79, vec3(1, 2, 58), vec3(-99.25, 10.99, 133.85), Blue, -140, vec3(0, 1, 0), false, this);
		wall_80 = CreateWall(wall80, vec3(1, 2, 53), vec3(-93, 10.99, 128.85), Blue, -140, vec3(0, 1, 0), false, this);
		wall_81 = CreateWall(wall81, vec3(1, 2, 28), vec3(-122.5, 10.99, 99), Blue, -160, vec3(0, 1, 0), false, this);
		wall_82 = CreateWall(wall82, vec3(1, 2, 23), vec3(-113.75, 10.99, 98), Blue, -160, vec3(0, 1, 0), false, this);
		wall_83 = CreateWall(wall83, vec3(1, 2, 26.5), vec3(-127.35, 10.99, 72.75), Blue, 0, vec3(0, 1, 0), false, this);
		wall_84 = CreateWall(wall84, vec3(1, 2, 28), vec3(-117.65, 10.99, 73.4), Blue, 0, vec3(0, 1, 0), false, this);
		wall_85 = CreateWall(wall85, vec3(1, 2, 20), vec3(-127.35, 9.25, 49.5), Blue, -10, vec3(1, 0, 0), false, this);
		wall_86 = CreateWall(wall86, vec3(1, 2, 20), vec3(-117.65, 9.25, 49.5), Blue, -10, vec3(1, 0, 0), false, this);
		wall_87 = CreateWall(wall87, vec3(1, 2, 20), vec3(-127.35, 7.6, 30), Blue, 0, vec3(0, 1, 0), false, this);
		wall_88 = CreateWall(wall88, vec3(1, 2, 20), vec3(-117.65, 7.6, 30), Blue, 0, vec3(0, 1, 0), false, this);
		wall_89 = CreateWall(wall89, vec3(1, 2, 15), vec3(-132.5, 7.6, 15), Blue, 45, vec3(0, 1, 0), false, this);
		wall_90 = CreateWall(wall90, vec3(1, 2, 30), vec3(-128, 7.6, 10), Blue, 45, vec3(0, 1, 0), false, this);
		wall_91 = CreateWall(wall91, vec3(1, 2, 15), vec3(-142.4, 7.6, 15), Blue, -45, vec3(0, 1, 0), false, this);
		wall_92 = CreateWall(wall92, vec3(1, 2, 30), vec3(-149.5, 7.6, 9.6), Blue, -45, vec3(0, 1, 0), false, this);
		wall_93 = CreateWall(wall93, vec3(1, 2, 20), vec3(-147.5, 7.6, 30), Blue, 0, vec3(0, 1, 0), false, this);
		wall_94 = CreateWall(wall94, vec3(1, 2, 20), vec3(-159, 7.6, 30), Blue, 0, vec3(0, 1, 0), false, this);
		wall_95 = CreateWall(wall95, vec3(1, 2, 21), vec3(-147.5, 5.9, 50.15), Blue, 10, vec3(1, 0, 0), false, this);
		wall_96 = CreateWall(wall96, vec3(1, 2, 21), vec3(-159, 5.9, 50.15), Blue, 10, vec3(1, 0, 0), false, this);
		wall_97 = CreateWall(wall97, vec3(1, 2, 11), vec3(-147.5, 4.25, 65), Blue, 0, vec3(0, 1, 0), false, this);
		wall_98 = CreateWall(wall98, vec3(1, 2, 11), vec3(-159, 4.25, 65), Blue, 0, vec3(0, 1, 0), false, this);
		wall_99 = CreateWall(wall99, vec3(1, 2, 23), vec3(-141.8, 4.25, 80), Blue, 30, vec3(0, 1, 0), false, this);
		wall_100 = CreateWall(wall100, vec3(1, 2, 28), vec3(-152.25, 4.25, 82.5), Blue, 30, vec3(0, 1, 0), false, this);
		wall_101 = CreateWall(wall101, vec3(1, 2, 20), vec3(-128.65, 4.25, 96), Blue, 50, vec3(0, 1, 0), false, this);
		wall_102 = CreateWall(wall102, vec3(1, 2, 30), vec3(-134, 4.25, 104), Blue, 50, vec3(0, 1, 0), false, this);
		wall_103 = CreateWall(wall103, vec3(1, 2, 20), vec3(-112, 4.25, 98.75), Blue, -70, vec3(0, 1, 0), false, this);
		wall_104 = CreateWall(wall104, vec3(1, 2, 30), vec3(-108.25, 4.25, 108.75), Blue, -70, vec3(0, 1, 0), false, this);
		wall_105 = CreateWall(wall105, vec3(1, 2, 28), vec3(-92.25, 4.25, 86.5), Blue, -50, vec3(0, 1, 0), false, this);
		wall_106 = CreateWall(wall106, vec3(1, 2, 30), vec3(-82.74, 4.25, 94), Blue, -50, vec3(0, 1, 0), false, this);
		wall_107 = CreateWall(wall107, vec3(1, 2, 140), vec3(-81.7, 4.25, 7.85), Blue, 0, vec3(0, 1, 0), false, this);
		wall_108 = CreateWall(wall108, vec3(1, 2, 150), vec3(-71.5, 4.25, 10), Blue, 0, vec3(0, 1, 0), false, this);
		wall_109 = CreateWall(wall109, vec3(1, 2, 25), vec3(-88, 4.25, -72.75), Blue, 30, vec3(0, 1, 0), false, this);
		wall_110 = CreateWall(wall110, vec3(1, 2, 30), vec3(-79, 4.25, -78), Blue, 30, vec3(0, 1, 0), false, this);
		wall_111 = CreateWall(wall111, vec3(1, 2, 25), vec3(-104.85, 4.25, -89.5), Blue, 60, vec3(0, 1, 0), false, this);
		wall_112 = CreateWall(wall112, vec3(1, 2, 30), vec3(-99, 4.25, -98), Blue, 60, vec3(0, 1, 0), false, this);
		wall_113 = CreateWall(wall113, vec3(1, 2, 22), vec3(-126, 4.25, -93.6), Blue, 100, vec3(0, 1, 0), false, this);
		wall_114 = CreateWall(wall114, vec3(1, 2, 30), vec3(-126, 4.25, -103), Blue, 100, vec3(0, 1, 0), false, this);
		wall_115 = CreateWall(wall115, vec3(1, 2, 20), vec3(-139.9, 4.25, -82.5), Blue, -20, vec3(0, 1, 0), false, this);
		wall_116 = CreateWall(wall116, vec3(1, 2, 30), vec3(-146, 4.25, -87), Blue, -20, vec3(0, 1, 0), false, this);
		wall_117 = CreateWall(wall117, vec3(1, 2, 20), vec3(-143.2, 4.25, -63.5), Blue, 0, vec3(1, 0, 0), false, this);
		wall_118 = CreateWall(wall118, vec3(1, 2, 20), vec3(-151, 4.25, -63.5), Blue, 0, vec3(1, 0, 0), false, this);
		wall_119 = CreateWall(wall119, vec3(1, 2, 20), vec3(-143.2, 2.5, -44), Blue, 10, vec3(1, 0, 0), false, this);
		wall_120 = CreateWall(wall120, vec3(1, 2, 20), vec3(-151, 2.5, -44), Blue, 10, vec3(1, 0, 0), false, this);
		wall_121 = CreateWall(wall121, vec3(1, 2, 30), vec3(-143.2, 1, -21), Blue, 0, vec3(0, 1, 0), false, this);
		wall_122 = CreateWall(wall122, vec3(1, 2, 30), vec3(-151, 1, -21), Blue, 0, vec3(0, 1, 0), false, this);
		wall_123 = CreateWall(wall123, vec3(1, 2, 30), vec3(-150.75, 1, 7), Blue, -30, vec3(0, 1, 0), false, this);
		wall_124 = CreateWall(wall124, vec3(1, 2, 20), vec3(-156, 1, 2.4), Blue, -30, vec3(0, 1, 0), false, this);
		wall_125 = CreateWall(wall125, vec3(1, 2, 30), vec3(-172, 1, 25), Blue, -70, vec3(0, 1, 0), false, this);
		wall_126 = CreateWall(wall126, vec3(1, 2, 20), vec3(-170, 1, 14), Blue, -70, vec3(0, 1, 0), false, this);
		wall_127 = CreateWall(wall127, vec3(1, 2, 30), vec3(-193.25, 1, 17.75), Blue, 30, vec3(0, 1, 0), false, this);
		wall_128 = CreateWall(wall128, vec3(1, 2, 20), vec3(-183.85, 1, 8.75), Blue, 30, vec3(0, 1, 0), false, this);
		wall_129 = CreateWall(wall129, vec3(1, 2, 100), vec3(-192, 1, -44), Blue, -10, vec3(0, 1, 0), false, this);
		wall_130 = CreateWall(wall130, vec3(1, 2, 100), vec3(-180, 1, -48.75), Blue, -10, vec3(0, 1, 0), false, this);
		wall_131 = CreateWall(wall131, vec3(1, 2, 30), vec3(-176, 1, -106), Blue, -30, vec3(0, 1, 0), false, this);
		wall_132 = CreateWall(wall132, vec3(1, 2, 20), vec3(-166.375, 1, -106.5), Blue, -30, vec3(0, 1, 0), false, this);
		wall_133 = CreateWall(wall133, vec3(1, 2, 25), vec3(-159, 1, -127), Blue, -50, vec3(0, 1, 0), false, this);
		wall_134 = CreateWall(wall134, vec3(1, 2, 15), vec3(-155.75, 1, -119.5), Blue, -50, vec3(0, 1, 0), false, this);
		wall_135 = CreateWall(wall135, vec3(1, 2, 124), vec3(-87.25, 1, -135), Blue, -90, vec3(0, 1, 0), false, this);
		wall_136 = CreateWall(wall136, vec3(1, 2, 124), vec3(-88.25, 1, -124.25), Blue, -90, vec3(0, 1, 0), false, this);
		wall_137 = CreateWall(wall137, vec3(1, 2, 39), vec3(-12.5, 1, -120.5), Blue, 40, vec3(0, 1, 0), false, this);
		wall_138 = CreateWall(wall138, vec3(1, 2, 32), vec3(-16.35, 1, -112.15), Blue, 40, vec3(0, 1, 0), false, this);

		//After rhomb left
		wall_139 = CreateWall(wall139, vec3(1, 2, 15), vec3(71, 10.99, 192.5), Blue, 0, vec3(0, 1, 0), false, this);
		wall_140 = CreateWall(wall140, vec3(1, 2, 15), vec3(78, 10.99, 186.5), Blue, -100, vec3(0, 1, 0), false, this);

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
	road_9 = CreateWall(road9, vec3(14, 0.2, 20), vec3(-73, 4.9, 266.82), White, -10, vec3(1, 0, 0), false, this);
	road_10 = CreateWall(road10, vec3(14, 0.2, 30), vec3(-73, 6.6, 291.71), White, 0, vec3(1, 0, 0), false, this);
	road_11 = CreateWall(road11, vec3(14, 0.2, 32), vec3(-77.75, 6.59, 318.75), White, -20, vec3(0, 1, 0), false, this);
	road_12 = CreateWall(road12, vec3(14, 0.2, 13), vec3(-83.25, 6.58, 338), White, 0, vec3(0, 1, 0), false, this);
	road_13 = CreateWall(road13, vec3(7, 0.2, 22), vec3(-79, 6.57, 346.7), White, 60, vec3(0, 1, 0), false, this);
	road_14 = CreateWall(road14, vec3(10, 0.2, 14.5), vec3(-73, 6.56, 356.975), White, 0, vec3(0, 1, 0), false, this);
	road_15 = CreateWall(road15, vec3(10, 0.2, 20), vec3(-73, 8.25, 373.8), White, -10, vec3(1, 0, 0), false, this);
	road_16 = CreateWall(road16, vec3(10, 0.2, 20), vec3(-73, 9.99, 393.63), White, 0, vec3(1, 0, 0), false, this);
	road_17 = CreateWall(road17, vec3(11, 0.2, 21), vec3(-67.5, 9.989, 409.5), White, 30, vec3(0, 1, 0), false, this);
	road_18 = CreateWall(road18, vec3(12, 0.2, 21), vec3(-56.5, 9.988, 423.1), White, 45, vec3(0, 1, 0), false, this);
	road_19 = CreateWall(road19, vec3(14, 0.2, 22.7), vec3(-42.5, 9.987, 434), White, 60, vec3(0, 1, 0), false, this);
	road_20 = CreateWall(road20, vec3(15, 0.2, 25), vec3(-26.25, 9.986, 439.75), White, 75, vec3(0, 1, 0), false, this);
	road_21 = CreateWall(road21, vec3(27, 0.2, 17), vec3(-8, 9.985, 441.75), White, 0, vec3(0, 1, 0), false, this);
	road_22 = CreateWall(road22, vec3(18, 0.2, 19), vec3(8, 9.984, 437.25), White, -60, vec3(0, 1, 0), false, this);
	road_23 = CreateWall(road23, vec3(17, 0.2, 60), vec3(30, 9.983, 415.2), White, -40, vec3(0, 1, 0), false, this);
	road_24 = CreateWall(road24, vec3(25, 0.2, 120), vec3(87.5, 9.982, 347.15), White, -40, vec3(0, 1, 0), false, this);
	road_25 = CreateWall(road25, vec3(15, 0.2, 19), vec3(131.5, 9.981, 294.75), White, -40, vec3(0, 1, 0), false, this);
	road_26 = CreateWall(road26, vec3(10, 0.2, 30), vec3(137, 9.98, 276), White, 0, vec3(0, 1, 0), false, this);
	road_27 = CreateWall(road27, vec3(9, 0.2, 30), vec3(129, 9.979, 253), White, 40, vec3(0, 1, 0), false, this);
	road_28 = CreateWall(road28, vec3(10, 0.2, 35), vec3(105.25, 9.978, 238.3), White, -100, vec3(0, 1, 0), false, this);
	road_29 = CreateWall(road29, vec3(10, 0.2, 30), vec3(117.95, 9.977, 224.35), White, 0, vec3(0, 1, 0), false, this);
	road_30 = CreateWall(road30, vec3(14, 0.2, 55), vec3(86.65, 9.976, 210), White, -100, vec3(0, 1, 0), false, this);
	road_31 = CreateWall(road31, vec3(14, 0.2, 55), vec3(92, 9.975, 205.35), White, 0, vec3(0, 1, 0), false, this);
	road_32 = CreateWall(road32, vec3(11, 0.2, 25), vec3(65.75, 9.974, 188), White, 0, vec3(0, 1, 0), false, this);
	road_33 = CreateWall(road33, vec3(10, 0.2, 25), vec3(74, 9.973, 181), White, -100, vec3(0, 1, 0), false, this);

	//After rhomb right
	road_34 = CreateWall(road34, vec3(10, 0.2, 79), vec3(22, 9.973, 184), White, -80, vec3(0, 1, 0), false, this);
	road_35 = CreateWall(road35, vec3(9, 0.2, 77), vec3(-48, 9.972, 170), White, -120, vec3(0, 1, 0), false, this);
	road_35 = CreateWall(road35, vec3(9, 0.2, 77), vec3(-48, 9.971, 170), White, -120, vec3(0, 1, 0), false, this);
	road_36 = CreateWall(road36, vec3(8.5, 0.2, 55), vec3(-97.4, 9.97, 130.25), White, -140, vec3(0, 1, 0), false, this);
	road_37 = CreateWall(road37, vec3(8.5, 0.2, 28), vec3(-119, 9.969, 97), White, -160, vec3(0, 1, 0), false, this);
	road_38 = CreateWall(road38, vec3(10, 0.2, 28), vec3(-122.25, 9.968, 73.3), White, 0, vec3(0, 1, 0), false, this);
	road_39 = CreateWall(road39, vec3(10, 0.2, 20), vec3(-122.25, 8.25, 49.5), White, -10, vec3(1, 0, 0), false, this);
	road_40 = CreateWall(road40, vec3(10, 0.2, 20), vec3(-122.25, 6.6, 30), White, 0, vec3(1, 0, 0), false, this);
	road_41 = CreateWall(road41, vec3(7, 0.2, 29), vec3(-131, 6.599, 12), White, 45, vec3(0, 1, 0), false, this);
	road_42 = CreateWall(road42, vec3(8, 0.2, 25), vec3(-148, 6.598, 14.45), White, -45, vec3(0, 1, 0), false, this);
	road_43 = CreateWall(road43, vec3(11, 0.2, 21), vec3(-153.25, 6.597, 30), White, 0, vec3(1, 0, 0), false, this);
	road_44 = CreateWall(road44, vec3(11, 0.2, 20), vec3(-153.25, 4.9, 50.15), White, 10, vec3(1, 0, 0), false, this);
	road_45 = CreateWall(road45, vec3(12, 0.2, 12), vec3(-153.25, 3.25, 65), White, 0, vec3(1, 0, 0), false, this);
	road_46 = CreateWall(road46, vec3(11, 0.2, 29), vec3(-147.5, 3.249, 80), White, 30, vec3(0, 1, 0), false, this);
	road_47 = CreateWall(road47, vec3(11, 0.2, 30), vec3(-130, 3.248, 101), White, 50, vec3(0, 1, 0), false, this);
	road_48 = CreateWall(road48, vec3(11, 0.2, 30), vec3(-110, 3.247, 103.25), White, -70, vec3(0, 1, 0), false, this);
	road_49 = CreateWall(road49, vec3(11, 0.2, 30), vec3(-86.25, 3.246, 89.25), White, -50, vec3(0, 1, 0), false, this);
	road_50 = CreateWall(road50, vec3(11, 0.2, 150), vec3(-76.5, 3.245, 9), White, 0, vec3(0, 1, 0), false, this);
	road_51 = CreateWall(road51, vec3(11, 0.2, 30), vec3(-84, 3.244, -76), White, 30, vec3(0, 1, 0), false, this);
	road_52 = CreateWall(road52, vec3(11, 0.2, 30), vec3(-102, 3.243, -93), White, 60, vec3(0, 1, 0), false, this);
	road_53 = CreateWall(road53, vec3(11, 0.2, 30), vec3(-126, 3.242, -98), White, 100, vec3(0, 1, 0), false, this);
	road_54 = CreateWall(road54, vec3(7, 0.2, 30), vec3(-143, 3.241, -85), White, -20, vec3(0, 1, 0), false, this);
	road_55 = CreateWall(road55, vec3(8, 0.2, 20), vec3(-147, 3.24, -63.5), White, 0, vec3(0, 1, 0), false, this);
	road_56 = CreateWall(road56, vec3(8, 0.2, 20), vec3(-147, 1.5, -43.75), White, 10, vec3(1, 0, 0), false, this);
	road_57 = CreateWall(road57, vec3(8, 0.2, 30), vec3(-147, 0, -21), White, 0, vec3(0, 1, 0), false, this);
	road_58 = CreateWall(road58, vec3(8, 0.2, 30), vec3(-154, -0.001, 5.45), White, -30, vec3(0, 1, 0), false, this);
	road_59 = CreateWall(road59, vec3(10, 0.2, 30), vec3(-174.7, -0.002, 21), White, -70, vec3(0, 1, 0), false, this);
	road_60 = CreateWall(road60, vec3(12, 0.2, 25), vec3(-189.25, -0.003, 12), White, 30, vec3(0, 1, 0), false, this);
	road_61 = CreateWall(road61, vec3(12, 0.2, 105), vec3(-186, -0.004, -47), White, -10, vec3(0, 1, 0), false, this);
	road_62 = CreateWall(road62, vec3(8, 0.2, 25), vec3(-171, -0.005, -107), White, -30, vec3(0, 1, 0), false, this);
	road_63 = CreateWall(road63, vec3(8, 0.2, 25), vec3(-156, -0.006, -124.5), White, -50, vec3(0, 1, 0), false, this);
	road_64 = CreateWall(road64, vec3(10, 0.2, 125), vec3(-87, -0.007, -129.5), White, -90, vec3(0, 1, 0), false, this);
	road_65 = CreateWall(road65, vec3(9, 0.2, 40), vec3(-14, -0.008, -117), White, 40, vec3(0, 1, 0), false, this);
	*/
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
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	//Wall
	p2List_item <PhysBody3D*>* wall_render_body = wall_body.getFirst();
	p2List_item <Cube*>* wall_render = wall.getFirst();
		while (wall_render != nullptr) {
			wall_render_body->data->GetTransform(&wall_render->data->transform);
			wall_render->data->Render();
			wall_render = wall_render->next;
			wall_render_body = wall_render_body->next;
		}
		//wall_2->GetTransform(&wall1.transform);
		//wall2.Render();
		/*
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

		wall_41->GetTransform(&wall41.transform);
		wall41.Render();

		wall_42->GetTransform(&wall42.transform);
		wall42.Render();

		wall_43->GetTransform(&wall43.transform);
		wall43.Render();

		wall_44->GetTransform(&wall44.transform);
		wall44.Render();

		wall_45->GetTransform(&wall45.transform);
		wall45.Render();

		wall_46->GetTransform(&wall46.transform);
		wall46.Render();

		wall_47->GetTransform(&wall47.transform);
		wall47.Render();

		wall_48->GetTransform(&wall48.transform);
		wall48.Render();

		wall_49->GetTransform(&wall49.transform);
		wall49.Render();

		wall_50->GetTransform(&wall50.transform);
		wall50.Render();

		wall_51->GetTransform(&wall51.transform);
		wall51.Render();

		wall_52->GetTransform(&wall52.transform);
		wall52.Render();

		wall_53->GetTransform(&wall53.transform);
		wall53.Render();

		wall_54->GetTransform(&wall54.transform);
		wall54.Render();

		wall_55->GetTransform(&wall55.transform);
		wall55.Render();

		wall_56->GetTransform(&wall56.transform);
		wall56.Render();

		wall_57->GetTransform(&wall57.transform);
		wall57.Render();

		wall_58->GetTransform(&wall58.transform);
		wall58.Render();

		wall_59->GetTransform(&wall59.transform);
		wall59.Render();

		wall_60->GetTransform(&wall60.transform);
		wall60.Render();

		wall_61->GetTransform(&wall61.transform);
		wall61.Render();

		wall_62->GetTransform(&wall62.transform);
		wall62.Render();

		wall_63->GetTransform(&wall63.transform);
		wall63.Render();

		wall_64->GetTransform(&wall64.transform);
		wall64.Render();

		wall_65->GetTransform(&wall65.transform);
		wall65.Render();

		wall_66->GetTransform(&wall66.transform);
		wall66.Render();

		wall_67->GetTransform(&wall67.transform);
		wall67.Render();

		wall_68->GetTransform(&wall68.transform);
		wall68.Render();

		wall_69->GetTransform(&wall69.transform);
		wall69.Render();

		wall_70->GetTransform(&wall70.transform);
		wall70.Render();

		wall_71->GetTransform(&wall71.transform);
		wall71.Render();

		wall_72->GetTransform(&wall72.transform);
		wall72.Render();

		wall_73->GetTransform(&wall73.transform);
		wall73.Render();

		wall_74->GetTransform(&wall74.transform);
		wall74.Render();

		wall_75->GetTransform(&wall75.transform);
		wall75.Render();

		wall_76->GetTransform(&wall76.transform);
		wall76.Render();

		wall_77->GetTransform(&wall77.transform);
		wall77.Render();

		wall_78->GetTransform(&wall78.transform);
		wall78.Render();

		wall_79->GetTransform(&wall79.transform);
		wall79.Render();

		wall_80->GetTransform(&wall80.transform);
		wall80.Render();

		wall_81->GetTransform(&wall81.transform);
		wall81.Render();

		wall_82->GetTransform(&wall81.transform);
		wall82.Render();

		wall_83->GetTransform(&wall83.transform);
		wall83.Render();

		wall_84->GetTransform(&wall84.transform);
		wall84.Render();

		wall_85->GetTransform(&wall85.transform);
		wall85.Render();

		wall_86->GetTransform(&wall86.transform);
		wall86.Render();

		wall_87->GetTransform(&wall87.transform);
		wall87.Render();

		wall_88->GetTransform(&wall88.transform);
		wall88.Render();

		wall_89->GetTransform(&wall89.transform);
		wall89.Render();

		wall_90->GetTransform(&wall90.transform);
		wall90.Render();

		wall_91->GetTransform(&wall91.transform);
		wall91.Render();

		wall_92->GetTransform(&wall92.transform);
		wall92.Render();

		wall_93->GetTransform(&wall93.transform);
		wall93.Render();

		wall_94->GetTransform(&wall94.transform);
		wall94.Render();

		wall_95->GetTransform(&wall95.transform);
		wall95.Render();

		wall_96->GetTransform(&wall96.transform);
		wall96.Render();

		wall_97->GetTransform(&wall97.transform);
		wall97.Render();

		wall_98->GetTransform(&wall98.transform);
		wall98.Render();

		wall_99->GetTransform(&wall99.transform);
		wall99.Render();

		wall_100->GetTransform(&wall100.transform);
		wall100.Render();

		wall_101->GetTransform(&wall101.transform);
		wall101.Render();

		wall_102->GetTransform(&wall102.transform);
		wall102.Render();

		wall_103->GetTransform(&wall103.transform);
		wall103.Render();

		wall_104->GetTransform(&wall104.transform);
		wall104.Render();

		wall_105->GetTransform(&wall105.transform);
		wall105.Render();

		wall_106->GetTransform(&wall106.transform);
		wall106.Render();

		wall_107->GetTransform(&wall107.transform);
		wall107.Render();

		wall_108->GetTransform(&wall108.transform);
		wall108.Render();

		wall_109->GetTransform(&wall109.transform);
		wall109.Render();

		wall_110->GetTransform(&wall110.transform);
		wall110.Render();

		wall_111->GetTransform(&wall111.transform);
		wall111.Render();

		wall_112->GetTransform(&wall112.transform);
		wall112.Render();

		wall_113->GetTransform(&wall113.transform);
		wall113.Render();

		wall_114->GetTransform(&wall114.transform);
		wall114.Render();

		wall_115->GetTransform(&wall115.transform);
		wall115.Render();

		wall_116->GetTransform(&wall116.transform);
		wall116.Render();

		wall_117->GetTransform(&wall117.transform);
		wall117.Render();

		wall_118->GetTransform(&wall118.transform);
		wall118.Render();

		wall_119->GetTransform(&wall119.transform);
		wall119.Render();

		wall_120->GetTransform(&wall120.transform);
		wall120.Render();

		wall_121->GetTransform(&wall121.transform);
		wall121.Render();

		wall_122->GetTransform(&wall122.transform);
		wall122.Render();

		wall_123->GetTransform(&wall123.transform);
		wall123.Render();

		wall_124->GetTransform(&wall124.transform);
		wall124.Render();

		wall_125->GetTransform(&wall125.transform);
		wall125.Render();

		wall_126->GetTransform(&wall126.transform);
		wall126.Render();

		wall_127->GetTransform(&wall127.transform);
		wall127.Render();

		wall_128->GetTransform(&wall128.transform);
		wall128.Render();

		wall_129->GetTransform(&wall129.transform);
		wall129.Render();

		wall_130->GetTransform(&wall130.transform);
		wall130.Render();

		wall_131->GetTransform(&wall131.transform);
		wall131.Render();

		wall_132->GetTransform(&wall132.transform);
		wall132.Render();

		wall_133->GetTransform(&wall133.transform);
		wall133.Render();

		wall_134->GetTransform(&wall134.transform);
		wall134.Render();

		wall_135->GetTransform(&wall135.transform);
		wall135.Render();

		wall_136->GetTransform(&wall136.transform);
		wall136.Render();

		wall_137->GetTransform(&wall137.transform);
		wall137.Render();

		wall_138->GetTransform(&wall138.transform);
		wall138.Render();
	}

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

	road_20->GetTransform(&road20.transform);
	road20.Render();

	road_21->GetTransform(&road21.transform);
	road21.Render();

	road_22->GetTransform(&road22.transform);
	road22.Render();

	road_23->GetTransform(&road23.transform);
	road23.Render();

	road_24->GetTransform(&road24.transform);
	road24.Render();

	road_25->GetTransform(&road25.transform);
	road25.Render();

	road_26->GetTransform(&road26.transform);
	road26.Render();

	road_27->GetTransform(&road27.transform);
	road27.Render();

	road_28->GetTransform(&road28.transform);
	road28.Render();

	road_29->GetTransform(&road29.transform);
	road29.Render();

	road_30->GetTransform(&road30.transform);
	road30.Render();

	road_31->GetTransform(&road31.transform);
	road31.Render();

	road_32->GetTransform(&road32.transform);
	road32.Render();

	road_33->GetTransform(&road33.transform);
	road33.Render();

	road_34->GetTransform(&road34.transform);
	road34.Render();

	road_35->GetTransform(&road35.transform);
	road35.Render();

	road_36->GetTransform(&road36.transform);
	road36.Render();

	road_37->GetTransform(&road37.transform);
	road37.Render();

	road_38->GetTransform(&road38.transform);
	road38.Render();

	road_39->GetTransform(&road39.transform);
	road39.Render();

	road_40->GetTransform(&road40.transform);
	road40.Render();

	road_41->GetTransform(&road41.transform);
	road41.Render();

	road_42->GetTransform(&road42.transform);
	road42.Render();

	road_43->GetTransform(&road43.transform);
	road43.Render();

	road_44->GetTransform(&road44.transform);
	road44.Render();

	road_45->GetTransform(&road45.transform);
	road45.Render();

	road_46->GetTransform(&road46.transform);
	road46.Render();

	road_47->GetTransform(&road47.transform);
	road47.Render();

	road_48->GetTransform(&road48.transform);
	road48.Render();

	road_49->GetTransform(&road49.transform);
	road49.Render();

	road_50->GetTransform(&road50.transform);
	road50.Render();

	road_51->GetTransform(&road51.transform);
	road51.Render();

	road_52->GetTransform(&road52.transform);
	road52.Render();

	road_53->GetTransform(&road53.transform);
	road53.Render();

	road_54->GetTransform(&road54.transform);
	road54.Render();

	road_55->GetTransform(&road55.transform);
	road55.Render();

	road_56->GetTransform(&road56.transform);
	road56.Render();

	road_57->GetTransform(&road57.transform);
	road57.Render();

	road_58->GetTransform(&road58.transform);
	road58.Render();

	road_59->GetTransform(&road59.transform);
	road59.Render();

	road_60->GetTransform(&road60.transform);
	road60.Render();

	road_61->GetTransform(&road61.transform);
	road61.Render();

	road_62->GetTransform(&road62.transform);
	road62.Render();

	road_63->GetTransform(&road63.transform);
	road63.Render();

	road_64->GetTransform(&road64.transform);
	road64.Render();

	road_65->GetTransform(&road65.transform);
	road65.Render();
	*/
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