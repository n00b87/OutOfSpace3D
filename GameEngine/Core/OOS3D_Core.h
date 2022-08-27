#ifndef __OOS3D_CORE__
#define __OOS3D_CORE__

#include <irrlicht.h>
#include <string>
#include <vector>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


struct OOS3D_Texture
{
	std::string texture_file;
	ITexture* texture;
};

#define OOS3D_MESH_TYPE_STATIC      0
#define OOS3D_MESH_TYPE_ANIMATED    1

struct OOS3D_Mesh
{
	int mesh_type;
	std::string mesh_file;

	IAnimatedMesh* mesh;

	OOS3D_Texture mesh_texture;
	bool use_ext_texture;
};

struct OOS3D_Script_Arg
{
    std::string name;
    int arg_type;
    std::string str_val;
    double num_val;
};

struct OOS3D_Script
{
	int return_type;
	int (*script_obj)(double*,std::string*,std::vector<OOS3D_Script_Arg>);
	double num_return_value;
	std::string str_return_value;
};

struct OOS3D_Actor
{
    int id;

    std::string actor_file;

	vector3df init_pos;
	vector3df pos;

	bool init_pos_on_reload;

	OOS3D_Mesh actor_mesh;

	bool visible_flag;

	bool active_flag;

	OOS3D_Script actor_ctrl_script;

	bool collide_flag;
	bool physics_flag;

	// TO DO: physics attributes here
};

//Light Type:
/*
ELT_POINT - point light, it has a position in space and radiates light in all directions

ELT_SPOT - spot light, it has a position in space, a direction, and a limited cone of influence

ELT_DIRECTIONAL - directional light, coming from a direction from an infinite distance

ELT_COUNT - Only used for counting the elements of this enum.
*/

struct OOS3D_Light
{
	int light_type;

	vector3df pos;

	bool init_pos_on_reload;

	bool cast_shadow_flag;

	//atributes here
};

struct OOS3D_Camera
{
	int camera_type;

	vector3df pos;
	vector3df rot;
	vector3df scale;

	bool init_pos_on_reload;

	//attributes here
};

struct OOS3D_Effect
{
	int effect_type;

	vector3df pos;
	vector3df rot;
	vector3df scale;

	bool init_pos_on_reload;

	//attributes here
};

struct OOS3D_Event
{
	int event_type;

	bool init_pos_on_reload;
};

int stage_count = 0;

struct OOS3D_Stage
{
	int id;
	std::string stage_name;

	OOS3D_Script main_script;

	std::vector<OOS3D_Actor> actors;
	std::vector<OOS3D_Light> lights;
	std::vector<OOS3D_Camera> cameras;
	std::vector<OOS3D_Effect> effects;
	std::vector<OOS3D_Event> events;
};


struct OOS3D_Window
{
    IrrlichtDevice* device;
    IVideoDriver* driver;
    ISceneManager* smgr;
    IGUIEnvironment* guienv;
};

struct OOS3D_Game
{
	std::string name;

	OOS3D_Window window;

	OOS3D_Script main_script;
};


OOS3D_Window* OOS3D_WindowOpenEx(std::string game_name, SIrrlichtCreationParameters param);

#endif
