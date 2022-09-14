#ifndef OOS3D_PROJECT_STRUCTURES_H_INCLUDED
#define OOS3D_PROJECT_STRUCTURES_H_INCLUDED

#include <wx/wx.h>
#include <wx/treectrl.h>
#include <wx/treebase.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <vector>
#include <irrlicht.h>
#include "GameEngine/Core/OOS3D_Core.h"
#include "wxIrrlicht.h"
#include "stage_view_events.h"

struct OOS3D_Project_Terrain
{
    uint32_t type;
    wxString name;

    int id;

    int engine_terrain;

    wxTreeItemId treeItem;

    //TO DO: Terrain Atributes
};

struct OOS3D_Project_Texture
{
    wxString fname;

    int id;

    int index;

    wxTreeItemId treeItem;
};

struct OOS3D_Project_Mesh
{
    wxString fname;

    int id;

    int index;

    wxTreeItemId treeItem;
};

struct OOS3D_Project_Actor
{
    wxString name;

    int id;

    IAnimatedMeshSceneNode* node;

    int index;

    int engine_actor;

    int mesh_id;
    int mesh_index;
    int stage_mesh_index;

    int hitbox_mesh_id;
    int hitbox_mesh_index;
    int stage_hitbox_mesh_index;

    int texture_id;
    int texture_index;

    wxTreeItemId treeItem;

    uint32_t type;

    double pos_x;
    double pos_y;
    double pos_z;

    double rot_x;
    double rot_y;
    double rot_z;

    double scale_x;
    double scale_y;
    double scale_z;

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

    ICameraSceneNode* node;

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

struct OOS3D_Project_Stage_Mesh
{
    int project_model_index = -1;
    int game_index = -1;

    IAnimatedMesh* mesh;
};

struct OOS3D_Project_Stage_Texture
{
    int project_model_index = -1;
    int game_index = -1;

    ITexture* texture;
};

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

    std::vector<OOS3D_Project_Stage_Mesh> models;
    std::vector<OOS3D_Project_Stage_Texture> textures;

    //Editor specific stuff
    ITexture* view_tool_overlay;
    StageEventReceiver* stage_events;
    ICameraSceneNode* stage_camera;
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
    std::vector<OOS3D_Project_Texture> Textures;

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

#define PROJECT_NODE_TYPE_NONE -1
#define PROJECT_NODE_TYPE_STAGE 1
#define PROJECT_NODE_TYPE_ACTOR 2
#define PROJECT_NODE_TYPE_TERRAIN 3
#define PROJECT_NODE_TYPE_LIGHT 4
#define PROJECT_NODE_TYPE_CAMERA 5
#define PROJECT_NODE_TYPE_EFFECT 6
#define PROJECT_NODE_TYPE_EVENT 7

class OOS3D_Project_treeItemData : public wxTreeItemData
{
    public:
        int project_stage_index;
        int game_stage_index;
        int node_type;
        int node_index; //index of type ie. actors, lights, etc.
        OOS3D_Project_treeItemData(int p_stage_index=-1, int g_stage_index=-1)
        {
            project_stage_index = p_stage_index;
            game_stage_index = g_stage_index;
        }
};


class OOS3D_Project_Node_Settings
{
    public:

        wxPropertyGrid* dataCtrl;
        OOS3D_Project* game_project;
        int stage_index;
        int node_type;
        int node_index;

        OOS3D_Project_Node_Settings(wxPropertyGrid* parentCtrl, OOS3D_Project* parent_game_project)
        {
            dataCtrl = parentCtrl;
            game_project = parent_game_project;
        }

        void setStage(int parent_stage_index)
        {
            stage_index = parent_stage_index;
        }

        void setNode(int n_type, int n_index)
        {
            node_type = n_type;
            node_index = n_index;
        }

        void displaySettings()
        {
            switch(node_type)
            {
                case PROJECT_NODE_TYPE_NONE:
                    dataCtrl->Clear();
                    break;
                case PROJECT_NODE_TYPE_ACTOR:
                    displayActorSettings();
                    break;
            }

        }

        void updateNodeObject()
        {
            switch(node_type)
            {
                case PROJECT_NODE_TYPE_NONE:
                    break;
                case PROJECT_NODE_TYPE_ACTOR:
                    updateNodeActor();
                    break;
            }
        }

        int getStageMeshIndex(int project_mesh_index)
        {
            int stage_mesh_index = -1;

            for(int i = 0; i < game_project->stages[stage_index].models.size(); i++)
            {
                if(game_project->stages[stage_index].models[i].project_model_index == project_mesh_index)
                {
                    stage_mesh_index = i;
                    break;
                }
            }

            if(stage_mesh_index < 0)
            {
                OOS3D_Project_Stage_Mesh stage_mesh;
                stage_mesh.project_model_index = project_mesh_index;
                stage_mesh.mesh = NULL;
                stage_mesh_index = game_project->stages[stage_index].models.size();
                game_project->stages[stage_index].models.push_back(stage_mesh);
            }

            //wxMessageBox(_("NEW MI:") + wxString::Format(_("%i"), stage_mesh_index));

            return stage_mesh_index;
        }

        void updateNodeActor()
        {
            OOS3D_Project_Actor* actor = &game_project->stages[stage_index].actors[node_index];

            actor->model = dataCtrl->GetProperty(_("Model"))->GetValueAsString();
            for(int i = 0; i < game_project->Models.size(); i++)
            {
                wxString gp_model = game_project->Models[i].fname;
                if(gp_model.compare(actor->model.Trim().substr(0, gp_model.length()))==0)
                {
                    actor->mesh_index = i;
                    actor->stage_mesh_index = getStageMeshIndex(i);
                    break;
                }
            }

            wxString hitbox_name = dataCtrl->GetProperty(_("HitBox"))->GetValueAsString();
            for(int i = 0; i < game_project->Models.size(); i++)
            {
                wxString gp_model = game_project->Models[i].fname;
                if(gp_model.compare(hitbox_name.Trim().substr(0, gp_model.length()))==0)
                {
                    actor->hitbox_mesh_index = i;
                    actor->stage_hitbox_mesh_index = getStageMeshIndex(i);
                    break;
                }
            }

            wxString texture_name = dataCtrl->GetProperty(_("Texture"))->GetValueAsString();
            for(int i = 0; i < game_project->Textures.size(); i++)
            {
                wxString gp_texture = game_project->Textures[i].fname;
                if(gp_texture.compare(texture_name.Trim().substr(0, gp_texture.length()))==0)
                {
                    actor->texture_index = i;
                    break;
                }
            }


            double x=0, y=0, z=0;
            wxString pos = dataCtrl->GetProperty(_("Position"))->GetValueAsString();
            wxString rot = dataCtrl->GetProperty(_("Rotation"))->GetValueAsString();
            wxString scale = dataCtrl->GetProperty(_("Scale"))->GetValueAsString();
            wxString arg_value = _("");


            //Get Position args
            arg_value = _("");
            int arg_n = 0;

            for(int i = 0; i < pos.length(); i++)
            {
                if(pos.substr(i, 1).compare(_(","))==0)
                {
                    switch(arg_n)
                    {
                        case 0:
                            arg_value.ToDouble(&x);
                            break;
                        case 1:
                            arg_value.ToDouble(&y);
                            break;
                        case 2:
                            arg_value.ToDouble(&z);
                            break;
                    }

                    arg_value = _("");
                    arg_n++;

                    if(arg_n > 2)
                        break;
                }
                else
                    arg_value += pos.substr(i, 1);

            }

            actor->pos_x = x;
            actor->pos_y = y;
            actor->pos_z = z;


            //Get Rotation args
            x=0;
            y=0;
            z=0;
            arg_value = _("");
            arg_n = 0;

            for(int i = 0; i < rot.length(); i++)
            {
                if(rot.substr(i, 1).compare(_(","))==0)
                {
                    switch(arg_n)
                    {
                        case 0:
                            arg_value.ToDouble(&x);
                            break;
                        case 1:
                            arg_value.ToDouble(&y);
                            break;
                        case 2:
                            arg_value.ToDouble(&z);
                            break;
                    }

                    arg_value = _("");
                    arg_n++;

                    if(arg_n > 2)
                        break;
                }
                else
                    arg_value += rot.substr(i, 1);

            }

            actor->rot_x = x;
            actor->rot_y = y;
            actor->rot_z = z;


            //Get Scale args
            x=0;
            y=0;
            z=0;
            arg_value = _("");
            arg_n = 0;

            for(int i = 0; i < scale.length(); i++)
            {
                if(scale.substr(i, 1).compare(_(","))==0)
                {
                    switch(arg_n)
                    {
                        case 0:
                            arg_value.ToDouble(&x);
                            break;
                        case 1:
                            arg_value.ToDouble(&y);
                            break;
                        case 2:
                            arg_value.ToDouble(&z);
                            break;
                    }

                    arg_value = _("");
                    arg_n++;

                    if(arg_n > 2)
                        break;
                }
                else
                    arg_value += scale.substr(i, 1);

            }

            actor->scale_x = x;
            actor->scale_y = y;
            actor->scale_z = z;

            //wxMessageBox(_("Actor POS = ") + wxString::Format(_("%f"), actor->pos_x) +_(", ") + wxString::Format(_("%f"), actor->pos_y) + _(", ") + wxString::Format(_("%f"), actor->pos_z));

        }

        void displayActorSettings()
        {
            dataCtrl->Clear();

            wxString actor_id = game_project->stages[stage_index].actors[node_index].name;

            int pos_x = game_project->stages[stage_index].actors[node_index].pos_x;
            int pos_y = game_project->stages[stage_index].actors[node_index].pos_y;
            int pos_z = game_project->stages[stage_index].actors[node_index].pos_z;
            wxString actor_pos = wxString::Format(_("%i"), pos_x) + _(", ") +
                                 wxString::Format(_("%i"), pos_y) + _(", ") +
                                 wxString::Format(_("%i"), pos_z);

            int rot_x = game_project->stages[stage_index].actors[node_index].rot_x;
            int rot_y = game_project->stages[stage_index].actors[node_index].rot_y;
            int rot_z = game_project->stages[stage_index].actors[node_index].rot_z;
            wxString actor_rot = wxString::Format(_("%i"), rot_x) + _(", ") +
                                 wxString::Format(_("%i"), rot_y) + _(", ") +
                                 wxString::Format(_("%i"), rot_z);

            int scale_x = game_project->stages[stage_index].actors[node_index].scale_x;
            int scale_y = game_project->stages[stage_index].actors[node_index].scale_y;
            int scale_z = game_project->stages[stage_index].actors[node_index].scale_z;
            wxString actor_scale = wxString::Format(_("%i"), scale_x) + _(", ") +
                                 wxString::Format(_("%i"), scale_y) + _(", ") +
                                 wxString::Format(_("%i"), scale_z);

            int actor_mesh_index = game_project->stages[stage_index].actors[node_index].mesh_index;

            wxString actor_mesh_name = _("");

            if(game_project->Models.size() > actor_mesh_index)
                actor_mesh_name = game_project->Models[actor_mesh_index].fname;

            int actor_texture_index = game_project->stages[stage_index].actors[node_index].texture_index;
            wxString actor_texture_name = _("");

            if(game_project->Textures.size() > actor_texture_index)
                actor_texture_name = game_project->Textures[actor_texture_index].fname;


            int actor_hitbox_index = game_project->stages[stage_index].actors[node_index].hitbox_mesh_index;

            wxString actor_hitbox_name = _("");

            if(game_project->Models.size() > actor_hitbox_index)
                actor_hitbox_name = game_project->Models[actor_hitbox_index].fname;

            dataCtrl->Append( new wxStringProperty(_("ActorID"), _("ActorID"), actor_id));
            dataCtrl->Append( new wxStringProperty(_("Position"), _("Position"), actor_pos));
            dataCtrl->Append( new wxStringProperty(_("Rotation"), _("Rotation"), actor_rot));
            dataCtrl->Append( new wxStringProperty(_("Scale"), _("Scale"), actor_scale));
            dataCtrl->Append( new wxStringProperty(_("Model"), _("Model"), actor_mesh_name));
            dataCtrl->Append( new wxStringProperty(_("Texture"), _("Texture"), actor_texture_name));
            dataCtrl->Append( new wxStringProperty(_("HitBox"), _("HitBox"), actor_hitbox_name));


            //cols.clear();

        }
};

#endif // OOS3D_PROJECT_STRUCTURES_H_INCLUDED
