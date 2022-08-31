#ifndef OOS3D_PROJECT_STRUCTURES_H_INCLUDED
#define OOS3D_PROJECT_STRUCTURES_H_INCLUDED

#include <wx/wx.h>
#include <wx/treectrl.h>
#include <vector>
#include "GameEngine/Core/OOS3D_Core.h"
#include "wxIrrlicht.h"

struct OOS3D_Project_Terrain
{
    uint32_t type;
    wxString name;

    int id;

    int engine_terrain;

    wxTreeItemId treeItem;

    //TO DO: Terrain Atributes
};

struct OOS3D_Project_Mesh
{
    wxString name;
    wxString fname;

    int id;

    int index;

    wxTreeItemId treeItem;
};

struct OOS3D_Project_Actor
{
    wxString name;

    int id;

    int index;

    int engine_actor;

    int mesh_id;

    wxTreeItemId treeItem;

    uint32_t type;

    double init_x;
    double init_y;
    double init_z;

    bool init_pos_on_reload;

	wxString model;

	bool visible_flag;
	bool active_flag;

	wxString ctrl_script;

	bool collide_flag;
	bool physics_flag;

    //TO DO: Physics Attributes
};

struct OOS3D_Project_Light
{
    wxString name;

    int id;

    int engine_light;

    wxTreeItemId treeItem;

    uint32_t type;

    double init_x;
    double init_y;
    double init_z;

    bool init_pos_on_reload;

	bool active_flag;

	wxString ctrl_script;

    //TO DO: Physics Attributes
};

struct OOS3D_Project_Camera
{
    wxString name;

    int id;

    int engine_camera;

    wxTreeItemId treeItem;

    uint32_t type;

    double init_x;
    double init_y;
    double init_z;

    bool init_pos_on_reload;

    wxString ctrl_script;

    //TO DO: Physics Attributes
};

struct OOS3D_Project_Effect
{
    wxString name;

    int id;

    int engine_effect;

    wxTreeItemId treeItem;

    uint32_t type;

    double init_x;
    double init_y;
    double init_z;

    bool init_pos_on_reload;

    wxString ctrl_script;

    //TO DO: Physics Attributes
};

struct OOS3D_Project_Event
{
    wxString name;

    int id;

    int engine_event;

    wxTreeItemId treeItem;

    uint32_t type;

    double init_x;
    double init_y;
    double init_z;

    bool init_pos_on_reload;

    wxString ctrl_script;

    //TO DO: Physics Attributes
};

#define OOS3D_STAGE_TYPE_3D 0
#define OOS3D_STAGE_TYPE_2D 1

struct OOS3D_Project_Stage
{
    wxString name;

    int id;

    OOS3D_Stage engine_stage;

    wxString ctrl_script;

    int type;

    wxIrrlicht* render_panel;

    wxTreeItemId stage_treeItem;
    wxTreeItemId terrain_treeItem;
    wxTreeItemId actors_treeItem;
    wxTreeItemId lights_treeItem;
    wxTreeItemId cameras_treeItem;
    wxTreeItemId effects_treeItem;
    wxTreeItemId events_treeItem;

    std::vector<OOS3D_Project_Terrain> terrain;
    std::vector<OOS3D_Project_Actor> actors;
    std::vector<OOS3D_Project_Light> lights;
    std::vector<OOS3D_Project_Camera> cameras;
    std::vector<OOS3D_Project_Effect> effects;
    std::vector<OOS3D_Project_Event> events;
};

struct OOS3D_Project
{
    uint32_t engine_version;

    wxString name; //name of game

    //Window Settings
    uint32_t window_width;
    uint32_t window_height;

    bool fullscreen_flag;
    bool stencil_buffer_flag;
    bool vsync_flag;

    //Developer Info
    wxString developer_name;
    wxString developer_website;

    //Game Description
    wxString game_description; //Description and Notes from Developer

    int id_counter = 0;

    //Assets
    wxTreeItemId models_treeItem;
    wxTreeItemId textures_treeItem;
    wxTreeItemId audio_treeItem;
    wxTreeItemId video_treeItem;
    wxTreeItemId scripts_treeItem;
    wxTreeItemId data_treeItem;

    std::vector<OOS3D_Project_Mesh> Models;

    /*
    //Need to completely rethink how these resources are structured
    wxArrayString Textures;
    wxArrayString Audio;
    wxArrayString Video;
    wxArrayString Scripts;
    wxArrayString Data;
    */

    //Stages
    std::vector<OOS3D_Project_Stage> stages;

    //project tree root
    wxTreeItemId project_root;
    wxTreeItemId asset_root;


};

#endif // OOS3D_PROJECT_STRUCTURES_H_INCLUDED
