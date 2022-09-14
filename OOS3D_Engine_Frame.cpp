#include <wx/imaglist.h>
#include <wx/stc/stc.h>
#include <wx/stdpaths.h>

#include "OOS3D_Engine_Frame.h"
#include "OOS3D_newProjectDialog.h"
#include "GameEngine/Core/OOS3D_Core.h"
#include "OOS3D_Project_Structures.h"

OOS3D_Engine_Frame::OOS3D_Engine_Frame( wxWindow* parent )
:
OOS3D_Engine( parent )
{
    app_path = wxStandardPaths::Get().GetExecutablePath();
    game_project = NULL;
    project_node_settings = NULL;

    wxFileName gfx_path = app_path;
    gfx_path.AppendDir(_("gfx"));

    wxFileName root_image = gfx_path;
    root_image.SetFullName(_("oos3d_icon.png"));

    project_tree_imageList = new wxImageList(16,16,true);
    project_tree_rootImage = project_tree_imageList->Add(wxBitmap(wxImage(root_image.GetFullPath())));
    project_tree_folderImage  = project_tree_imageList->Add(wxArtProvider::GetBitmap( wxART_FOLDER, wxART_MENU ));
    project_tree_fileImage = project_tree_imageList->Add(wxArtProvider::GetBitmap( wxART_NORMAL_FILE, wxART_MENU ));
    m_project_treeCtrl->AssignImageList(project_tree_imageList);

    asset_tree_imageList = new wxImageList(16,16,true);
    asset_tree_rootImage = asset_tree_imageList->Add(wxBitmap(wxImage(root_image.GetFullPath())));
    asset_tree_folderImage  = asset_tree_imageList->Add(wxArtProvider::GetBitmap( wxART_FOLDER, wxART_MENU ));
    asset_tree_fileImage = asset_tree_imageList->Add(wxArtProvider::GetBitmap( wxART_NORMAL_FILE, wxART_MENU ));
    m_assets_treeCtrl->AssignImageList(asset_tree_imageList);

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

    project_node_settings = new OOS3D_Project_Node_Settings(m_node_propertyGrid, game_project);

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
    m_assets_treeCtrl->DeleteAllItems();

    game_project->asset_root = m_assets_treeCtrl->AddRoot(_("Assets"), asset_tree_rootImage);


    game_project->models_treeItem = m_assets_treeCtrl->AppendItem(game_project->asset_root, _("Models"), asset_tree_folderImage);
    game_project->textures_treeItem = m_assets_treeCtrl->AppendItem(game_project->asset_root, _("Textures"), asset_tree_folderImage);
    game_project->audio_treeItem = m_assets_treeCtrl->AppendItem(game_project->asset_root, _("Audio"), asset_tree_folderImage);
    game_project->video_treeItem = m_assets_treeCtrl->AppendItem(game_project->asset_root, _("Video"), asset_tree_folderImage);
    game_project->scripts_treeItem = m_assets_treeCtrl->AppendItem(game_project->asset_root, _("Scripts"), asset_tree_folderImage);
    game_project->data_treeItem = m_assets_treeCtrl->AppendItem(game_project->asset_root, _("Data"), asset_tree_folderImage);

    m_project_treeCtrl->DeleteAllItems();

    game_project->project_root = m_project_treeCtrl->AddRoot(game_project->name, project_tree_rootImage);

    for(int stage_index = 0; stage_index < game_project->stages.size(); stage_index++)
    {
        OOS3D_Project_Stage stage = game_project->stages[stage_index];

        stage.stage_treeItem = m_project_treeCtrl->AppendItem(game_project->project_root, stage.name, project_tree_folderImage);

        //OOS3D_Project_treeItemData* old_data = (OOS3D_Project_treeItemData*)m_project_treeCtrl->GetItemData(stage.stage_treeItem);
        m_project_treeCtrl->SetItemData(stage.stage_treeItem, NULL);
        OOS3D_Project_treeItemData* stage_treeItem_data = new OOS3D_Project_treeItemData(stage_index, stage_index);
        m_project_treeCtrl->SetItemData(stage.stage_treeItem, stage_treeItem_data);

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

void OOS3D_Engine_Frame::OpenStageTab(int stage_n)
{
    game_project->stages[stage_n].render_panel = new wxIrrlicht(m_stage_auinotebook, wxID_ANY, false, wxPoint(ClientW(2), ClientH(2)), wxSize(ClientW(64), ClientH(36)));

    //game_project->stages[stage_n].stage_events = new StageEventReceiver();

    game_project->stages[stage_n].render_panel->m_view_tool = m_view_tool;
    game_project->stages[stage_n].render_panel->m_select_tool = m_select_tool;
    game_project->stages[stage_n].render_panel->m_boxSelect_tool = m_boxSelect_tool;
    game_project->stages[stage_n].render_panel->m_move_tool = m_move_tool;
    game_project->stages[stage_n].render_panel->m_rotate_tool = m_rotate_tool;
    game_project->stages[stage_n].render_panel->m_scale_tool = m_scale_tool;

    //game_project->stages[stage_n].render_panel->GetDevice()->setEventReceiver( game_project->stages[stage_n].stage_events );

    //game_project->stages[stage_n].render_panel->SetBackgroundColour(wxColour("red"));

    game_project->stages[stage_n].render_panel->InitIrr();
    game_project->stages[stage_n].render_panel->StartRendering();

    //Setup Test Scene
    irr::scene::ISceneManager* smgr = game_project->stages[stage_n].render_panel->GetDevice()->getSceneManager();
    video::IVideoDriver* driver = game_project->stages[stage_n].render_panel->GetDevice()->getVideoDriver();

    wxFileName asset_path(app_path);
    asset_path.AppendDir(_("AssetLibrary"));

    wxFileName gfx_path(app_path);
    gfx_path.AppendDir(_("gfx"));

    wxFileName view_tool_gfx_path = gfx_path;
    view_tool_gfx_path.SetFullName(_("view_stage_tool.png"));
    game_project->stages[stage_n].view_tool_overlay = driver->getTexture((path)view_tool_gfx_path.GetFullPath().ToStdString().c_str());
    game_project->stages[stage_n].render_panel->view_stage_tool_texture = game_project->stages[stage_n].view_tool_overlay;

    //load meshes
    for(int i = 0; i < game_project->stages[stage_n].models.size(); i++)
    {
        int mesh_index = game_project->stages[stage_n].models[i].project_model_index;
        if(mesh_index >= 0 && mesh_index < game_project->Models.size())
        {
            wxString fname = game_project->Models[mesh_index].fname;
            wxFileName mesh_path = asset_path;
            mesh_path.AppendDir(_("Mesh"));
            mesh_path.SetFullName(fname);
            game_project->stages[stage_n].models[i].mesh = smgr->getMesh((path)mesh_path.GetFullPath().ToStdString().c_str());
        }
    }

    //wxMessageBox(_("Stage opened so far"));


    //load actors
    for(int i = 0; i < game_project->stages[stage_n].actors.size(); i++)
    {
        int mesh_index = game_project->stages[stage_n].actors[i].stage_mesh_index;
        IAnimatedMesh* mesh = game_project->stages[stage_n].models[mesh_index].mesh;

        game_project->stages[stage_n].actors[i].node = smgr->addAnimatedMeshSceneNode( mesh );

        IAnimatedMeshSceneNode* node = game_project->stages[stage_n].actors[i].node;

        if (node)
        {
            node->setMaterialFlag(EMF_LIGHTING, false); //change this to true in game for lighting
            //node->setMD2Animation(scene::EMAT_STAND);

            int texture_index = game_project->stages[stage_n].actors[i].texture_index;

            if(texture_index >= 0 && texture_index < game_project->Textures.size())
            {
                wxFileName texture_path = asset_path;
                texture_path.AppendDir(_("Texture"));
                texture_path.SetFullName(game_project->Textures[texture_index].fname);
                node->setMaterialTexture( 0, driver->getTexture((path)texture_path.GetFullPath().ToStdString().c_str()) );
            }
        }
    }



    game_project->stages[stage_n].stage_camera = smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0)); //using this default camera for now

    m_stage_auinotebook->AddPage(game_project->stages[stage_n].render_panel, game_project->stages[stage_n].name, true);



}

void OOS3D_Engine_Frame::OnStageTabClosed( wxAuiNotebookEvent& event )
{
    wxIrrlicht* current_stage_panel = (wxIrrlicht*) m_stage_auinotebook->GetPage(event.GetSelection());
    for(int i = 0; i < game_project->stages.size(); i++)
    {
        if(current_stage_panel == game_project->stages[i].render_panel)
        {
            game_project->stages[i].render_panel->GetDevice()->drop();
            game_project->stages[i].render_panel = NULL;

            for(int n = 0; n < game_project->stages[i].models.size(); n++)
            {
                game_project->stages[i].models[n].mesh = NULL;
            }

            for(int n = 0; n < game_project->stages[i].actors.size(); n++)
            {
                game_project->stages[i].actors[n].node = NULL;
            }
            break;
        }
    }
}

void OOS3D_Engine_Frame::OnProjectTreeItemActivated( wxTreeEvent& event )
{
    OOS3D_Project_treeItemData* item_data = (OOS3D_Project_treeItemData*)m_project_treeCtrl->GetItemData(event.GetItem());
    if(!item_data)
        return;

    current_stage_index = item_data->project_stage_index;

    OpenStageTab(current_stage_index);

    //wxMessageBox(_("Stage set to ") + wxString::Format(_("%i"), current_stage_index));
}

void OOS3D_Engine_Frame::OnProjectTreeItemSelected( wxTreeEvent& event )
{
    OOS3D_Project_treeItemData* item_data = (OOS3D_Project_treeItemData*)m_project_treeCtrl->GetItemData(event.GetItem());

    if(!item_data)
        return;

    int stage_index = item_data->project_stage_index;

    project_node_settings->setStage(stage_index);
    project_node_settings->setNode(-1, -1);

    switch(item_data->node_type)
    {
        case PROJECT_NODE_TYPE_ACTOR:
            project_node_settings->setNode(PROJECT_NODE_TYPE_ACTOR, item_data->node_index);
            break;
    }

    project_node_settings->displaySettings();
}


void OOS3D_Engine_Frame::OnNodePropertyChanged( wxPropertyGridEvent& event )
{
    project_node_settings->updateNodeObject();
    int stage_index = project_node_settings->stage_index;
    int node_index = project_node_settings->node_index;

    irr::scene::ISceneManager* smgr = game_project->stages[stage_index].render_panel->GetDevice()->getSceneManager();
    video::IVideoDriver* driver = game_project->stages[stage_index].render_panel->GetDevice()->getVideoDriver();

    wxFileName asset_path(app_path);
    asset_path.AppendDir(_("AssetLibrary"));

    bool refresh_flag = false;
    int page_n = -1;

    for(int i = 0; i < m_stage_auinotebook->GetPageCount(); i++)
    {
        if(game_project->stages[stage_index].render_panel == (wxIrrlicht*)m_stage_auinotebook->GetPage(i))
        {
            page_n = i;
            refresh_flag = true;
        }
    }

    switch(project_node_settings->node_type)
    {
        case PROJECT_NODE_TYPE_ACTOR:
            if(game_project->stages[stage_index].actors[node_index].node)
            {
                game_project->stages[stage_index].actors[node_index].node->remove();
                game_project->stages[stage_index].actors[node_index].node = NULL;
            }

            if(refresh_flag)
            {

                int mesh_index = game_project->stages[stage_index].actors[node_index].stage_mesh_index;

                if(!game_project->stages[stage_index].models[mesh_index].mesh)
                {
                    int project_mesh_index = game_project->stages[stage_index].models[mesh_index].project_model_index;
                    wxString fname = game_project->Models[project_mesh_index].fname;
                    wxFileName mesh_path = asset_path;
                    mesh_path.AppendDir(_("Mesh"));
                    mesh_path.SetFullName(fname);
                    if(mesh_path.FileExists())
                    {
                        game_project->stages[stage_index].models[mesh_index].mesh = smgr->getMesh((path)mesh_path.GetFullPath().ToStdString().c_str());
                    }
                }


                mesh_index = game_project->stages[stage_index].actors[node_index].stage_mesh_index;

                IAnimatedMesh* mesh = game_project->stages[stage_index].models[mesh_index].mesh;

                game_project->stages[stage_index].actors[node_index].node = smgr->addAnimatedMeshSceneNode( mesh );

                IAnimatedMeshSceneNode* node = game_project->stages[stage_index].actors[node_index].node;

                if (node)
                {
                    node->setMaterialFlag(EMF_LIGHTING, false); //change this to true in game for lighting
                    //node->setMD2Animation(scene::EMAT_STAND);

                    int texture_index = game_project->stages[stage_index].actors[node_index].texture_index;

                    if(texture_index >= 0 && texture_index < game_project->Textures.size())
                    {
                        wxFileName texture_path = asset_path;
                        texture_path.AppendDir(_("Texture"));
                        texture_path.SetFullName(game_project->Textures[texture_index].fname);
                        node->setMaterialTexture( 0, driver->getTexture((path)texture_path.GetFullPath().ToStdString().c_str()) );
                    }
                }
            }
            break;
    }
}
