#include <wx/wx.h>
#include <wx/arrstr.h>
#include <wx/dir.h>

#include "../OOS3D_Project_Structures.h"
#include "../OOS3D_Engine_Frame.h"
#include "../OOS3D_newStageDialog.h"
#include "../OOS3D_ImportModelDialog.h"
#include "../OOS3D_addActorDialog.h"
#include "../wxIrrlicht.h"

void OOS3D_Engine_Frame::OnAddActorToolSelect( wxCommandEvent& event )
{
    if(!game_project)
        return;

    if(current_stage_index < 0 || current_stage_index >= game_project->stages.size())
        return;

    OOS3D_addActorDialog addActor_dlg(this);

    for(int i = 0; i < game_project->Models.size(); i++)
    {
        addActor_dlg.addModel(game_project->Models[i].fname);
    }

    /*for(int i = 0; i < game_project->Textures.size(); i++)
    {
        addActor_dlg.addModel(game_project->Textures[i].name);
    }*/

    addActor_dlg.ShowModal();

    if(addActor_dlg.exit_status==ADDACTOR_EXIT_STATUS_CANCEL)
        return;

    OOS3D_Project_Actor actor;
    actor.name = addActor_dlg.actor_id;

    if(addActor_dlg.model_index >= 0 && addActor_dlg.model_index < game_project->Models.size())
    {
        actor.mesh_id = game_project->Models[addActor_dlg.model_index].id;
        actor.mesh_index = addActor_dlg.model_index;

        wxString mesh_fname = game_project->Models[actor.mesh_index].fname.Trim();

        bool add_mesh_to_stage = true;
        for(int i = 0; i < game_project->stages[current_stage_index].models.size(); i++)
        {
            wxString stage_mesh_fname = _("");
            int project_model_index = game_project->stages[current_stage_index].models[i].project_model_index;

            if(project_model_index >= 0 && project_model_index < game_project->Models.size())
                stage_mesh_fname = game_project->Models[project_model_index].fname.Trim();

            if(mesh_fname.compare(stage_mesh_fname)==0)
            {
                add_mesh_to_stage = false;
                break;
            }
        }

        if(add_mesh_to_stage)
        {
            OOS3D_Project_Stage_Mesh stage_mesh;
            stage_mesh.project_model_index = actor.mesh_index;
            stage_mesh.mesh = NULL;
            game_project->stages[current_stage_index].models.push_back(stage_mesh);
        }
    }
    else
    {
        actor.mesh_id = -1;
        actor.mesh_index = -1;
    }

    actor.pos_x = 0;
    actor.pos_y = 0;
    actor.pos_z = 0;

    actor.rot_x = 0;
    actor.rot_y = 0;
    actor.rot_z = 0;

    actor.scale_x = 0;
    actor.scale_y = 0;
    actor.scale_z = 0;

    //Need to eventually add hitbox stuff here
    actor.hitbox_mesh_index = addActor_dlg.hitbox_index;
    actor.mesh_index = addActor_dlg.model_index;

    for(int i = 0; i < game_project->stages[current_stage_index].models.size(); i++)
    {
        if(actor.mesh_index == game_project->stages[current_stage_index].models[i].project_model_index)
        {
            actor.stage_mesh_index = i;
            break;
        }
    }


    for(int i = 0; i < game_project->stages[current_stage_index].models.size(); i++)
    {
        if(actor.hitbox_mesh_index == game_project->stages[current_stage_index].models[i].project_model_index)
        {
            actor.stage_hitbox_mesh_index = i;
            break;
        }
    }


    //wxMessageBox(_("DEBUG: ") + wxString::Format(_("%i"), actor.mesh_index));
    actor.index = game_project->stages[current_stage_index].actors.size();
    actor.id = game_project->id_counter;
    game_project->id_counter++;

    actor.treeItem = m_project_treeCtrl->AppendItem(game_project->stages[current_stage_index].actors_treeItem, actor.name, project_tree_fileImage);
    OOS3D_Project_treeItemData* actor_treeItem_data = new OOS3D_Project_treeItemData(current_stage_index, current_stage_index);
    actor_treeItem_data->node_type = PROJECT_NODE_TYPE_ACTOR;
    actor_treeItem_data->node_index = actor.index;
    m_project_treeCtrl->SetItemData(actor.treeItem, actor_treeItem_data);

    game_project->stages[current_stage_index].actors.push_back(actor);
}
