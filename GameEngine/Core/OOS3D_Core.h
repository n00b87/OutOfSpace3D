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

struct OOS3D_Terrain
{
    std::string name;

    int id;

    ITerrainSceneNode* node;

    path heightMapFileName;

    vector3df init_pos;
	vector3df init_rot;
	vector3df init_scale;

	vector3df exit_pos;
	vector3df exit_rot;
	vector3df exit_scale;

	SColor init_vertexColor = SColor(255, 255, 255, 255);
	s32  maxLOD = 5;
	E_TERRAIN_PATCH_SIZE  patchSize = ETPS_17;
	s32  smoothFactor = 0;
	bool addAlsoIfHeightmapEmpty = false;

};

struct OOS3D_Texture
{
	std::string texture_file;
	ITexture* texture;

	vector3df init_pos;
	vector3df init_rot;
	vector3df init_scale;

	vector3df exit_pos;
	vector3df exit_rot;
	vector3df exit_scale;
};

#define OOS3D_MESH_TYPE_STATIC      0
#define OOS3D_MESH_TYPE_ANIMATED    1

struct OOS3D_Mesh
{
	int mesh_type;
	std::string mesh_file;

	IAnimatedMesh* node;

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

    IAnimatedMeshSceneNode* node;

	vector3df init_pos;
	vector3df init_rot;
	vector3df init_scale;

	vector3df exit_pos;
	vector3df exit_rot;
	vector3df exit_scale;

	bool init_pos_on_reload;

	OOS3D_Mesh* actor_mesh;

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

	ILightSceneNode* node;

	vector3df init_pos;
	vector3df init_rot;
	vector3df init_scale;

	vector3df exit_pos;
	vector3df exit_rot;
	vector3df exit_scale;

	bool init_pos_on_reload;

	bool cast_shadow_flag;

	//atributes here
};

struct OOS3D_Camera
{
	int camera_type;

	ICameraSceneNode* node;

	vector3df init_pos;
	vector3df init_rot;
	vector3df init_scale;

	vector3df exit_pos;
	vector3df exit_rot;
	vector3df exit_scale;

	bool init_pos_on_reload;

	//attributes here
};

struct OOS3D_Effect
{
	int effect_type;

	ISceneNode* node;

	vector3df init_pos;
	vector3df init_rot;
	vector3df init_scale;

	vector3df exit_pos;
	vector3df exit_rot;
	vector3df exit_scale;

	bool init_pos_on_reload;

	//attributes here
};

struct OOS3D_Event
{
	int event_type;

	vector3df init_pos;
	vector3df init_rot;
	vector3df init_scale;

	vector3df exit_pos;
	vector3df exit_rot;
	vector3df exit_scale;

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
	std::vector<OOS3D_Terrain> terrain;
};

struct OOS3D_Window
{
    IrrlichtDevice* device;
};


OOS3D_Window* OOS3D_WindowOpenEx(std::string game_name, SIrrlichtCreationParameters param);




int OOS3D_StartStage(IrrlichtDevice* device, OOS3D_Stage* stage)
{
    IVideoDriver* driver = device->getVideoDriver();
    ISceneManager* smgr = device->getSceneManager();
    IGUIEnvironment* guienv = device->getGUIEnvironment();

    smgr->clear();

    for(int terrain_index = 0; terrain_index < stage->terrain.size(); terrain_index++)
    {
        OOS3D_Terrain* terrain = &stage->terrain[terrain_index];

        terrain->node = smgr->addTerrainSceneNode(terrain->heightMapFileName,
                                                  0,
                                                  -1,
                                                  terrain->init_pos,
                                                  terrain->init_rot,
                                                  terrain->init_scale,
                                                  terrain->init_vertexColor,
                                                  terrain->maxLOD,
                                                  terrain->patchSize,
                                                  terrain->smoothFactor,
                                                  terrain->addAlsoIfHeightmapEmpty
                                                  );
    }

    for(int actor_index = 0; actor_index < stage->actors.size(); actor_index++)
    {
        OOS3D_Actor* actor = &stage->actors[actor_index];

        actor->node = smgr->addAnimatedMeshSceneNode( actor->actor_mesh->node );
    }

    return 0;
}

#endif
