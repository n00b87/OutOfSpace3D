#include <wx/wx.h>
#include <wx/arrstr.h>
#include <wx/dir.h>

#include "../../OOS3D_Project_Structures.h"
#include "../../OOS3D_Engine_Frame.h"
#include "../../OOS3D_newStageDialog.h"
#include "../../OOS3D_ImportModelDialog.h"
#include "../../wxIrrlicht.h"

void OOS3D_Engine_Frame::CreateStage(wxString stage_name, int stage_type)
{
    for(int i = 0; i < game_project->stages.size(); i++)
    {
        if(game_project->stages[i].name.compare(_(stage_name))==0)
        {
            wxMessageBox(_("There is already a stage with this name."));
            return;
        }
    }

    OOS3D_Project_Stage stage;
    stage.name = stage_name;
    stage.type = stage_type;
    stage.id = game_project->id_counter;
    game_project->id_counter++;
    stage.render_panel = NULL;


    stage.stage_treeItem = m_project_treeCtrl->AppendItem(game_project->project_root, stage.name, project_tree_folderImage);

    stage.terrain_treeItem = m_project_treeCtrl->AppendItem(stage.stage_treeItem, _("Terrain"), project_tree_folderImage);
    stage.actors_treeItem = m_project_treeCtrl->AppendItem(stage.stage_treeItem, _("Actors"), project_tree_folderImage);
    stage.lights_treeItem = m_project_treeCtrl->AppendItem(stage.stage_treeItem, _("Lights"), project_tree_folderImage);
    stage.cameras_treeItem = m_project_treeCtrl->AppendItem(stage.stage_treeItem, _("Cameras"), project_tree_folderImage);
    stage.effects_treeItem = m_project_treeCtrl->AppendItem(stage.stage_treeItem, _("Effects"), project_tree_folderImage);
    stage.events_treeItem = m_project_treeCtrl->AppendItem(stage.stage_treeItem, _("Events"), project_tree_folderImage);

    game_project->stages.push_back(stage);

    m_project_treeCtrl->Update();
}

void OOS3D_Engine_Frame::OnNewStageMenuSelect( wxCommandEvent& event )
{
    if(!game_project)
        return;

    OOS3D_newStageDialog newStage_dlg(this);
    newStage_dlg.ShowModal();

    if(newStage_dlg.exit_status==NEWSTAGE_EXIT_STATUS_CANCEL)
        return;

    CreateStage(newStage_dlg.stage_name, newStage_dlg.stage_type);

}

void OOS3D_Engine_Frame::ImportModel(wxFileName fname, bool animation_flag, bool textue_flag, bool armature_flag, bool scene_flag)
{
    wxFileName mesh_path(app_path);
    mesh_path.AppendDir(_("AssetLibrary"));
    mesh_path.AppendDir(_("Mesh"));
    mesh_path.SetFullName(fname.GetFullName());

    OOS3D_Project_Mesh mesh;
    mesh.fname = _("AssetLibrary/Mesh/") + fname.GetFullName();
    mesh.id = game_project->id_counter;
    game_project->id_counter++;

    mesh.treeItem = m_assets_treeCtrl->AppendItem(game_project->models_treeItem, fname.GetFullName(), project_tree_fileImage);

    game_project->Models.push_back(mesh);

}

void OOS3D_Engine_Frame::OnImportMeshMenuSelect( wxCommandEvent& event )
{
    if(!game_project)
        return;

    OOS3D_importModelDialog importModel_dlg(this);
    importModel_dlg.ShowModal();

    if(importModel_dlg.exit_status==IMPORTMODEL_EXIT_STATUS_CANCEL)
        return;

    ImportModel(importModel_dlg.asset_fname,
                importModel_dlg.animation_flag,
                importModel_dlg.texture_flag,
                importModel_dlg.armature_flag,
                importModel_dlg.scene_flag
                );
}

void OOS3D_Engine_Frame::OnImportTextureMenuSelect( wxCommandEvent& event )
{

}

wxFileName OOS3D_Engine_Frame::openFileDialog(wxString title, wxString default_wildcard, int flag)
{
    wxFileDialog openFileDialog(this, title, "", "", default_wildcard, flag);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return wxFileName();     // the user changed idea...

    wxFileName fname(openFileDialog.GetPath());
    return fname;
}

wxArrayString OOS3D_Engine_Frame::openMultiFileDialog(wxString title, wxString default_wildcard, int flag)
{
    wxFileDialog openFileDialog(this, title, "", "", default_wildcard, flag);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return wxArrayString();     // the user changed idea...

    wxArrayString fnames;
    openFileDialog.GetPaths(fnames);
    return fnames;
}
