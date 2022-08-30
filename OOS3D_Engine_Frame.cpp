#include <wx/imaglist.h>
#include <wx/stc/stc.h>
#include <wx/stdpaths.h>

#include "OOS3D_Engine_Frame.h"
#include "OOS3D_newProjectDialog.h"
#include "GameEngine/Core/OOS3D_Core.h"

OOS3D_Engine_Frame::OOS3D_Engine_Frame( wxWindow* parent )
:
OOS3D_Engine( parent )
{
    app_path = wxStandardPaths::Get().GetExecutablePath();
    game_project = NULL;

    wxFileName gfx_path = app_path;
    gfx_path.AppendDir(_("gfx"));

    wxFileName root_image = gfx_path;
    root_image.SetFullName(_("oos3d_icon.png"));

    project_tree_imageList = new wxImageList(16,16,true);
    project_tree_rootImage = project_tree_imageList->Add(wxBitmap(wxImage(root_image.GetFullPath())));
    project_tree_folderImage  = project_tree_imageList->Add(wxArtProvider::GetBitmap( wxART_FOLDER, wxART_MENU ));
    project_tree_fileImage = project_tree_imageList->Add(wxArtProvider::GetBitmap( wxART_NORMAL_FILE, wxART_MENU ));
    m_project_treeCtrl->AssignImageList(project_tree_imageList);
}

//Setup Test Project
void OOS3D_Engine_Frame::SetupTestProject()
{
    OOS3D_Project_Stage stage;
    stage.name = _("Start Stage");

    //stage.render_panel = new wxPanel(this);

    //stage.page->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( OOS3D_Engine_Frame::OnStageViewUpdate ), NULL, this );

    OOS3D_Project_Actor actor;
    for (int i = 0; i < 5; i++)
    {
        actor.name = _("Test Actor ") + wxString::Format(_("%i"), i);

        stage.actors.push_back(actor);
    }

    OOS3D_Project_Light light;
    for (int i = 0; i < 7; i++)
    {
        light.name = _("Test Light ") + wxString::Format(_("%i"), i);

        stage.lights.push_back(light);
    }

    OOS3D_Project_Camera camera;
    for (int i = 0; i < 4; i++)
    {
        camera.name = _("Test Camera ") + wxString::Format(_("%i"), i);

        stage.cameras.push_back(camera);
    }

    OOS3D_Project_Effect effect;
    for (int i = 0; i < 5; i++)
    {
        effect.name = _("Test Effect ") + wxString::Format(_("%i"), i);

        stage.effects.push_back(effect);
    }

    OOS3D_Project_Event event;
    for (int i = 0; i < 12; i++)
    {
        event.name = _("Test Event ") + wxString::Format(_("%i"), i);

        stage.events.push_back(event);
    }

    OOS3D_Project_Terrain terrain;
    for (int i = 0; i < 3; i++)
    {
        terrain.name = _("Test Terrain ") + wxString::Format(_("%i"), i);

        stage.terrain.push_back(terrain);
    }

    game_project->stages.push_back(stage);

    stage.actors.clear();
    stage.cameras.clear();
    stage.lights.clear();
    stage.terrain.clear();
    stage.effects.clear();
    stage.events.clear();

    stage.name = _("Second Stage");

    for (int i = 0; i < 2; i++)
    {
        actor.name = _("Test Actor ") + wxString::Format(_("%i"), i);

        stage.actors.push_back(actor);
    }

    for (int i = 0; i < 3; i++)
    {
        light.name = _("Test Light ") + wxString::Format(_("%i"), i);

        stage.lights.push_back(light);
    }

    for (int i = 0; i < 1; i++)
    {
        camera.name = _("Test Camera ") + wxString::Format(_("%i"), i);

        stage.cameras.push_back(camera);
    }

    for (int i = 0; i < 0; i++)
    {
        effect.name = _("Test Effect ") + wxString::Format(_("%i"), i);

        stage.effects.push_back(effect);
    }

    for (int i = 0; i < 4; i++)
    {
        event.name = _("Test Event ") + wxString::Format(_("%i"), i);

        stage.events.push_back(event);
    }

    for (int i = 0; i < 2; i++)
    {
        terrain.name = _("Test Terrain ") + wxString::Format(_("%i"), i);

        stage.terrain.push_back(terrain);
    }

    game_project->stages.push_back(stage);
    game_project->name = _("My Test Project");
}

void OOS3D_Engine_Frame::CreateProject(wxString project_name)
{
    if(game_project)
    {
        for(int i = 0; i < game_project->stages.size(); i++)
        {
            if(game_project->stages[i].render_panel)
            {
                if(game_project->stages[i].render_panel->GetDevice())
                {
                    game_project->stages[i].render_panel->GetDevice()->drop();
                }
            }
        }

        delete game_project;
    }

    game_project = new OOS3D_Project();
    game_project->name = project_name;
}

void OOS3D_Engine_Frame::OnNewProjectMenuSelect( wxCommandEvent& event )
{
    //Will need to add some code here to save current project

    OOS3D_newProjectDialog newProject_dlg(this);
    newProject_dlg.ShowModal();

    if(newProject_dlg.exit_status == NEWPROJECT_EXIT_STATUS_CANCEL)
        return;

    CreateProject(newProject_dlg.project_name);

    //This is only here for testing purposes and should be commented out before release
    //SetupTestProject();
    //---------------------------------------------------------------------------------

    SetupProjectTree();

}

void OOS3D_Engine_Frame::OnLoadProjectMenuSelect( wxCommandEvent& event )
{
// TODO: Implement OnLoadProjectMenuSelect
}

void OOS3D_Engine_Frame::OnSaveProjectMenuSelect( wxCommandEvent& event )
{
// TODO: Implement OnSaveProjectMenuSelect
}

void OOS3D_Engine_Frame::OnExitMenuSelect( wxCommandEvent& event )
{
// TODO: Implement OnExitMenuSelect

}


//New Project Setup
void OOS3D_Engine_Frame::SetupProjectTree()
{
    m_project_treeCtrl->DeleteAllItems();

    game_project->project_root = m_project_treeCtrl->AddRoot(game_project->name, project_tree_rootImage);

    for(int stage_index = 0; stage_index < game_project->stages.size(); stage_index++)
    {
        OOS3D_Project_Stage stage = game_project->stages[stage_index];

        stage.stage_treeItem = m_project_treeCtrl->AppendItem(game_project->project_root, stage.name, project_tree_folderImage);

        stage.terrain_treeItem = m_project_treeCtrl->AppendItem(stage.stage_treeItem, _("Terrain"), project_tree_folderImage);
        for(int terrain_index = 0; terrain_index < stage.terrain.size(); terrain_index++)
        {
            OOS3D_Project_Terrain terrain = stage.terrain[terrain_index];

            terrain.treeItem = m_project_treeCtrl->AppendItem(stage.terrain_treeItem, terrain.name, project_tree_fileImage);
        }

        stage.actors_treeItem = m_project_treeCtrl->AppendItem(stage.stage_treeItem, _("Actors"), project_tree_folderImage);
        for(int actor_index = 0; actor_index < stage.actors.size(); actor_index++)
        {
            OOS3D_Project_Actor actor = stage.actors[actor_index];

            actor.treeItem = m_project_treeCtrl->AppendItem(stage.actors_treeItem, actor.name, project_tree_fileImage);
        }

        stage.lights_treeItem = m_project_treeCtrl->AppendItem(stage.stage_treeItem, _("Lights"), project_tree_folderImage);
        for(int light_index = 0; light_index < stage.lights.size(); light_index++)
        {
            OOS3D_Project_Light light = stage.lights[light_index];

            light.treeItem = m_project_treeCtrl->AppendItem(stage.lights_treeItem, light.name, project_tree_fileImage);
        }

        stage.cameras_treeItem = m_project_treeCtrl->AppendItem(stage.stage_treeItem, _("Cameras"), project_tree_folderImage);
        for(int camera_index = 0; camera_index < stage.cameras.size(); camera_index++)
        {
            OOS3D_Project_Camera camera = stage.cameras[camera_index];

            camera.treeItem = m_project_treeCtrl->AppendItem(stage.cameras_treeItem, camera.name, project_tree_fileImage);
        }

        stage.effects_treeItem = m_project_treeCtrl->AppendItem(stage.stage_treeItem, _("Effects"), project_tree_folderImage);
        for(int effect_index = 0; effect_index < stage.effects.size(); effect_index++)
        {
            OOS3D_Project_Effect effect = stage.effects[effect_index];

            effect.treeItem = m_project_treeCtrl->AppendItem(stage.effects_treeItem, effect.name, project_tree_fileImage);
        }

        stage.events_treeItem = m_project_treeCtrl->AppendItem(stage.stage_treeItem, _("Events"), project_tree_folderImage);
        for(int event_index = 0; event_index < stage.events.size(); event_index++)
        {
            OOS3D_Project_Event event = stage.events[event_index];

            event.treeItem = m_project_treeCtrl->AppendItem(stage.events_treeItem, event.name, project_tree_fileImage);
        }
    }

    m_project_treeCtrl->Update();


    //TEST RENDER STUFF
    /*
    game_project->stages[0].render_panel = new wxIrrlicht(m_stage_auinotebook, wxID_ANY, false, wxPoint(ClientW(2), ClientH(2)), wxSize(ClientW(64), ClientH(36)));

    game_project->stages[0].render_panel->SetBackgroundColour(wxColour("red"));
    game_project->stages[0].render_panel->InitIrr();
    game_project->stages[0].render_panel->StartRendering();

    //Setup Test Scene
    irr::scene::ISceneManager* smgr = game_project->stages[0].render_panel->GetDevice()->getSceneManager();
    video::IVideoDriver* driver = game_project->stages[0].render_panel->GetDevice()->getVideoDriver();

    IAnimatedMesh* mesh = smgr->getMesh("gfx/media/sydney.md2");

    IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode( mesh );

    if (node)
    {
        node->setMaterialFlag(EMF_LIGHTING, false);
        node->setMD2Animation(scene::EMAT_STAND);
        node->setMaterialTexture( 0, driver->getTexture("gfx/media/sydney.bmp") );
    }

    smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));
    //----

    m_stage_auinotebook->AddPage(game_project->stages[0].render_panel, game_project->stages[0].name, true);
    */
}
