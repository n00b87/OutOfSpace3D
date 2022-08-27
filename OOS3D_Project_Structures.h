#ifndef OOS3D_PROJECT_STRUCTURES_H_INCLUDED
#define OOS3D_PROJECT_STRUCTURES_H_INCLUDED

#include <wx/wx.h>
#include <vector>
#include "GameEngine/Core/OOS3D_Core.h"
#include "wxIrrlicht.h"

struct OOS3D_Project_Terrain
{
    uint32_t type;
    wxString name;

    wxTreeItemId treeItem;

    //TO DO: Terrain Atributes
};

struct OOS3D_Project_Actor
{
    wxString name;

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

    wxTreeItemId treeItem;

    uint32_t type;

    double init_x;
    double init_y;
    double init_z;

    bool init_pos_on_reload;

    //TO DO: Physics Attributes
};

struct OOS3D_Project_Effect
{
    wxString name;

    wxTreeItemId treeItem;

    uint32_t type;

    double init_x;
    double init_y;
    double init_z;

    bool init_pos_on_reload;

    //TO DO: Physics Attributes
};

struct OOS3D_Project_Event
{
    wxString name;

    wxTreeItemId treeItem;

    uint32_t type;

    double init_x;
    double init_y;
    double init_z;

    bool init_pos_on_reload;

    //TO DO: Physics Attributes
};

struct OOS3D_Project_Stage
{
    wxString name;

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

    //Assets
    wxArrayString Models;
    wxArrayString Textures;
    wxArrayString Audio;
    wxArrayString Video;
    wxArrayString Scripts;
    wxArrayString Data;

    //Stages
    std::vector<OOS3D_Project_Stage> stages;

    //project tree root
    wxTreeItemId project_root;


};

#endif // OOS3D_PROJECT_STRUCTURES_H_INCLUDED
