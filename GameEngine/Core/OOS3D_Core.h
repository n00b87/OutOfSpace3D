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
    int id;
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
    int id;
	int mesh_type;
	path mesh_file;

	IAnimatedMesh* node;

	int mesh_texture;
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
    std::string actor_name;

    int id;

    path actor_file;

    IAnimatedMeshSceneNode* node;

    int texture;
	bool use_ext_texture;

	vector3df init_pos;
	vector3df init_rot;
	vector3df init_scale;

	vector3df exit_pos;
	vector3df exit_rot;
	vector3df exit_scale;

	bool init_pos_on_reload;

	int mesh_id; //index for now

	IAnimatedMesh* mesh;

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


struct OOS3D_Game
{
    IrrlichtDevice* device;
    std::vector<OOS3D_Stage> stage;

    std::vector<OOS3D_Texture> texture;
    std::vector<OOS3D_Mesh> mesh;
};

OOS3D_Game game;

//returns vector index
int OOS3D_LoadMesh(IrrlichtDevice* device, path mesh_file)
{
    ISceneManager* smgr = device->getSceneManager();
    OOS3D_Mesh mesh;
    mesh.mesh_file = mesh_file;
    mesh.node = smgr->getMesh(mesh_file);

    if(!mesh.node)
        return -1;

    int vector_index = game.mesh.size();
    game.mesh.push_back(mesh);

    return vector_index;
}

int OOS3D_AddActor(IrrlichtDevice* device, int stage_index, std::string actor_name, int mesh_index)
{
    ISceneManager* smgr = device->getSceneManager();
    OOS3D_Actor actor;
    actor.mesh_id = mesh_index;
    IAnimatedMesh* mesh = game.mesh[mesh_index].node;
    actor.mesh = mesh;
    actor.node = smgr->addAnimatedMeshSceneNode( mesh );
    int actor_index = game.stage[stage_index].actors.size();
    game.stage[stage_index].actors.push_back(actor);
    return actor_index;
}


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

        actor->node = smgr->addAnimatedMeshSceneNode( actor->mesh );
    }

    return 0;
}

#endif
